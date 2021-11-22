/* Genepy - A General-Purpose Library
 * Copyright (C) 2020, 2021  Erwan Grâce <erwan.grace@outlook.fr>
 *
 * This file is part of Genepy.
 *
 * Genepy is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Genepy is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Genepy.  If not, see <https://www.gnu.org/licenses/>.
 */

/**
 * @file Logger.cpp
 * @author Erwan
 * @date 28/09/2020
 */

#include <spdlog/logger.h>
#include <spdlog/sinks/null_sink.h>
#include <spdlog/sinks/rotating_file_sink.h>

#include <genepy/application/ConsoleApplication.h>
#include <genepy/application/GuiApplication.h>
#include <genepy/log/Logger.h>

#include "LogLevelFormatter.h"

namespace {

const auto kLogDirectoryName = QStringLiteral("log");
const auto kLogFileNameExtension = QStringLiteral("log");
const auto kMaxLogFileSize = 5 * 1024 * 1024; // 5 MB
const auto kMaxNLogFiles = 3;
const auto kLogMessageFormat =
    QString{"%d/%m/%Y %H:%M:%S.%e %"} + genepy::LogLevelFormatter::kLogLevelFlag_ + " [%n] %v";

} // namespace

namespace genepy {

class LoggerImpl {
public:
    static void initialize(QCoreApplication* application)
    {
        // Define the path to the log file...
#define LOG_FILE_PATH                                                                              \
    app->getPreferenceDirectory().path() + '/' + kLogDirectoryName + '/' +                         \
        app->applicationName().toLower() + '.' + kLogFileNameExtension

        const auto logFilePath = [application]() {
            if (auto* app = dynamic_cast<ConsoleApplication*>(application)) {
                return LOG_FILE_PATH;
            }
            else if (auto* app = dynamic_cast<GuiApplication*>(application)) {
                return LOG_FILE_PATH;
            }

            Q_UNREACHABLE();
        }();

        // ...and configure it
        sink_ = std::make_shared<spdlog::sinks::rotating_file_sink_st>(
            logFilePath.toStdString(), kMaxLogFileSize, kMaxNLogFiles);

        auto formatter = std::make_unique<spdlog::pattern_formatter>();
        formatter->add_flag<LogLevelFormatter>(LogLevelFormatter::kLogLevelFlag_)
            .set_pattern(kLogMessageFormat.toStdString());

        sink_->set_formatter(std::move(formatter));
    }

    explicit LoggerImpl(const QString& name)
        : logger_{new spdlog::logger{name.toStdString(), sink_}}
    {
#ifdef QT_DEBUG
        logger_->set_level(spdlog::level::trace);
#else
        logger_->set_level(spdlog::level::info);
#endif
    }

    spdlog::logger* getLogger() const { return logger_.get(); }

private:
    static spdlog::sink_ptr sink_;

    const std::unique_ptr<spdlog::logger> logger_;
};

spdlog::sink_ptr LoggerImpl::sink_{new spdlog::sinks::null_sink_st};

void Logger::initialize(QCoreApplication* application) { LoggerImpl::initialize(application); }

Logger::Logger(const QString& name) : impl_{new LoggerImpl{name}} {}

Logger::~Logger() = default;

void Logger::log(LogLevel level, const QString& message, bool flush) const
{
    switch (level) {
        case LogLevel::kTrace:
            impl_->getLogger()->trace(message.toStdString());
            break;
        case LogLevel::kDebug:
            impl_->getLogger()->debug(message.toStdString());
            break;
        case LogLevel::kInfo:
            impl_->getLogger()->info(message.toStdString());
            break;
        case LogLevel::kWarn:
            impl_->getLogger()->warn(message.toStdString());
            break;
        case LogLevel::kError:
            impl_->getLogger()->error(message.toStdString());
            break;
        case LogLevel::kFatal:
            impl_->getLogger()->critical(message.toStdString());
    }

    if (flush) {
        impl_->getLogger()->flush();
    }
}

} // namespace genepy

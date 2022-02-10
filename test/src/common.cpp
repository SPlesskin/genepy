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

#include "common.h"

#include <QtCore/QTextStream>
#include <QtDebug>

namespace common {

const QString kApplicationName = QStringLiteral("MyApplication");
const QVersionNumber kApplicationVersion{1, 0, 0};
const QString kApplicationDescription = QStringLiteral("This is my application.");

const genepy::ApplicationInformation kApplicationInformation = {
    kApplicationName, kApplicationVersion, kApplicationDescription};

const QString kApplicationPreferenceDirectoryPath =
    QDir::homePath() + "/." + kApplicationName.toLower() + '/' + kApplicationVersion.toString();

QDir kLogDirectory = QDir{common::kApplicationPreferenceDirectoryPath + "/log"};
const QString kLogFileName = common::kApplicationName.toLower() + ".log";

QString readFileLine(const QString& filePath, int lineNo)
{
    QFile file{filePath};

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qCritical() << "Can't open file" << file.fileName();

        return QString{};
    }

    QTextStream stream{&file};
    auto i = 1;
    while (!stream.atEnd()) {
        const auto line = stream.readLine();
        if (i++ == lineNo) {
            return line;
        }
    }

    Q_UNREACHABLE();
}

} // namespace common

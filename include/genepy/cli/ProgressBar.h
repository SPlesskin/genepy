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
 * @file ProgressBar.h
 * @author Erwan
 * @date 11/04/2021
 */

#ifndef GENEPY_PROGRESSBAR_H
#define GENEPY_PROGRESSBAR_H

#include <QtCore/QObject>

#include <genepy/genepy_global.h>

namespace genepy {

/**
 * @defgroup cli Command-Line Interface
 */

/**
 * @brief Provides an ASCII progress bar.
 *
 * This functionality indicates the progress of an operation which consists of multiple consecutive
 * steps.
 *
 * Example:
 * ~~~{.cpp}
 * // Create the progress bar and set the number of steps to 100
 * genepy::ProgressBar progressBar{100};
 *
 * QTimer timer;
 * QObject::connect(&timer, &QTimer::timeout, &progressBar, &genepy::ProgressBar::update);
 *
 * timer.start(1000); // Timeout interval of 1 second (or 1000 milliseconds)
 * ~~~
 *
 * @ingroup cli
 */
class GENEPY_EXPORT ProgressBar : public QObject {

    Q_OBJECT

public:
    /**
     * @brief Constructor.
     * @param totalStepCount the number of steps to complete the operation
     */
    explicit ProgressBar(int totalStepCount);

public slots:
    /// Updates this progress bar.
    void update();

private:
    const int totalStepCount_;
    int currentStepCount_;
};

} // namespace genepy

#endif // GENEPY_PROGRESSBAR_H

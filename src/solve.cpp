// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "solve.h"

#include <iostream>

namespace gcpx {
    double solve_secant(std::function<double(double)> objective, double initial_value)
    {
        const auto max_iterations = 100000;
        const auto tolerance = 1.0e-8;
        const auto step = 1.0e-3;
        auto iteration = 0;
        auto current_value = initial_value;
        auto next_value = initial_value + step;
        auto objective_result = objective(initial_value);

        while (objective_result > tolerance) {
            if (iteration >= max_iterations) {
                std::cout << "Warning: Exceeded maximum iterations in secant_solver.\n";
                return current_value;
            }

            const auto derivative = (objective_result - objective(next_value)) / (current_value - next_value);
            next_value = current_value;
            current_value -= objective_result / derivative;
            objective_result = objective(current_value);
            iteration++;
        }

        return current_value;
    }
}
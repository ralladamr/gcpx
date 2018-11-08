// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef MALLARD_SOLVER_H
#define MALLARD_SOLVER_H

#include <functional>

namespace mallard {
    double solve_secant(std::function<double(double)> objective, double initial_value);
}

#endif

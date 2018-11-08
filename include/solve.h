// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef GCPX_SOLVE_H
#define GCPX_SOLVE_H

#include <functional>

namespace gcpx {
    double solve_secant(std::function<double(double)> objective, double initial_value);
}

#endif

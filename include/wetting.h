// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef MALLARD_WETTING_H
#define MALLARD_WETTING_H

#include <vector>

namespace mallard {
    using Radian = double;

    std::vector<Radian> contact_angle(const std::vector<double>& spreading_coeffs,
                                      const std::vector<double>& drying_coeffs);

    std::vector<double> surface_tension(const std::vector<double>& spreading_coeffs,
                                        const std::vector<double>& drying_coeffs);

    // double drying_coefficient(Distribution, double plateau_fraction);

    // double spreading_coefficient(Distribution, double plateau_fraction);

    // std::vector<double> expanded_coefficients(valley, plateau, int index, double reference);
}

#endif

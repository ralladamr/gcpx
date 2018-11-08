// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "wetting.h"

#include <cmath>
#include <vector>

namespace mallard {
    std::vector<Radian> contact_angle(const std::vector<double>& spreading_coeffs,
                                      const std::vector<double>& drying_coeffs)
    {
        const auto size = spreading_coeffs.size();
        std::vector<Radian> results(size);
        for (size_t i = 0; i < size; i++) {
            const auto d = drying_coeffs[i];
            const auto s = spreading_coeffs[i];
            auto cosine = (d - s) / (d + s);
            results[i] = acos(cosine);
        }
        return results;
    }

    std::vector<double> surface_tension(const std::vector<double>& spreading_coeffs,
                                        const std::vector<double>& drying_coeffs)
    {
        const auto size = spreading_coeffs.size();
        std::vector<double> results(size);
        for (size_t i = 0; i < size; i++) {
            results[i] = -0.5 * (spreading_coeffs[i] + drying_coeffs[i]);
        }
        return results;
    }
}

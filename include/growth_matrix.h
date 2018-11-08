// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef GCPX_GROWTHMATRIX_H
#define GCPX_GROWTHMATRIX_H

#include "growth_distribution.h"
#include "order_parameter_distribution.h"
#include "transition.h"

#include <vector>

namespace gcpx {
    class Growth_matrix {
    public:
        Growth_distribution growth_distribution() const;
        Order_parameter_distribution order_parmeter_distribution() const;

        Growth_matrix(const std::vector<Transition>& transitions, const std::vector<int>& subensembles);
        ~Growth_matrix() = default;
        Growth_matrix(const Growth_matrix&) = default;
        Growth_matrix& operator=(const Growth_matrix&) = default;
        Growth_matrix(Growth_matrix&&) = default;
        Growth_matrix& operator=(Growth_matrix&&) = default;

    private:
        std::vector<Transition> transitions;
        std::vector<int> subensembles;
    };
}

#endif

// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef MALLARD_ORDERPARAMETERMATRIX_H
#define MALLARD_ORDERPARAMETERMATRIX_H

#include "order_parameter_distribution.h"
#include "transition.h"

#include <vector>

namespace mallard {
    class Order_parameter_matrix {
    public:
        Order_parameter_matrix(const std::vector<Transition>& transitions, const std::vector<int>& subensembles);
        Order_parameter_distribution order_parameter_distribution(const std::vector<double>& guess) const;
        ~Order_parameter_matrix() = default;
        Order_parameter_matrix(const Order_parameter_matrix&) = default;
        Order_parameter_matrix& operator=(const Order_parameter_matrix&) = default;
        Order_parameter_matrix(Order_parameter_matrix&&) = default;
        Order_parameter_matrix& operator=(Order_parameter_matrix&&) = default;

    private:
        std::vector<Transition> transitions;
        std::vector<int> subensembles;
    };
}

#endif

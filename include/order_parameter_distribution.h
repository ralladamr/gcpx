// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef MALLARD_ORDERPARAMETERDISTRIBUTION_H
#define MALLARD_ORDERPARAMETERDISTRIBUTION_H

#include <string>
#include <vector>

namespace mallard {
    class Order_parameter_distribution {
    public:
        Order_parameter_distribution(const std::string& filename);
        Order_parameter_distribution(const std::vector<int>& subensembles,
                                     const std::vector<double>& log_probabilities);
        ~Order_parameter_distribution() = default;
        Order_parameter_distribution(const Order_parameter_distribution&) = default;
        Order_parameter_distribution& operator=(const Order_parameter_distribution&) = default;
        Order_parameter_distribution(Order_parameter_distribution&&) = default;
        Order_parameter_distribution& operator=(Order_parameter_distribution&&) = default;

    private:
        std::vector<int> subensembles;
        std::vector<double> log_probabilities;
    };
}

#endif

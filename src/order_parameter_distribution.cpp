// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "order_parameter_distribution.h"

#include <fstream>
#include <iostream>
#include <sstream>

namespace gcpx {
    Order_parameter_distribution::Order_parameter_distribution(const std::string& filename)
    {
        std::ifstream in {filename};
        std::string line;
        while (std::getline(in, line)) {
            std::stringstream ss {line};
            int i;
            double x;

            ss >> i >> x;
            subensembles.push_back(i);
            log_probabilities.push_back(x);
        }
    }

    Order_parameter_distribution::Order_parameter_distribution(const std::vector<int>& subensembles,
                                                               const std::vector<double>& log_probabilities)
        : subensembles(subensembles), log_probabilities(log_probabilities)
    {}
}

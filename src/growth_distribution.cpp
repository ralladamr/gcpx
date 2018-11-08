// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "growth_distribution.h"

#include <fstream>
#include <iostream>
#include <sstream>

namespace gcpx {
    Growth_distribution::Growth_distribution(const std::string& filename)
    {
        std::ifstream in {filename};
        std::string line;
        while (std::getline(in, line)) {
            std::stringstream ss {line};
            int i;
            int cmp;
            int stg;
            double x;

            ss >> i >> cmp >> stg >> x;
            subensembles.push_back(i);
            components.push_back(cmp);
            stages.push_back(stg);
            log_probabilities.push_back(x);
        }
    }

    Growth_distribution::Growth_distribution(const std::vector<int>& subensembles, const std::vector<int>& components,
                                             const std::vector<int>& stages,
                                             const std::vector<double>& log_probabilities)
        : subensembles(subensembles), components(components), stages(stages), log_probabilities(log_probabilities)
    {}
}

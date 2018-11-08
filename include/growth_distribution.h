// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef MALLARD_GROWTHDISTRIBUTION_H
#define MALLARD_GROWTHDISTRIBUTION_H

#include <vector>

namespace mallard {
    class Growth_distribution {
    public:
        Growth_distribution(const std::string & filename);
        Growth_distribution(const std::vector<int>& subensembles, const std::vector<int>& components,
                            const std::vector<int>& stages, const std::vector<double>& log_probabilities);
        ~Growth_distribution() = default;
        Growth_distribution(const Growth_distribution&) = default;
        Growth_distribution& operator=(const Growth_distribution&) = default;
        Growth_distribution(Growth_distribution&&) = default;
        Growth_distribution& operator=(Growth_distribution&&) = default;

    private:
        std::vector<int> subensembles;
        std::vector<int> components;
        std::vector<int> stages;
        std::vector<double> log_probabilities;
    };
}

#endif

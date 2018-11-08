// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "activity_list.h"

#include <cmath>
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>

namespace mallard {
    Activity_list::Activity_list(const std::string& filename, bool is_bz_file)
    {
        std::ifstream in {filename};
        std::string line;
        while (std::getline(in, line)) {
            std::stringstream ss {line};
            std::vector<double> sublist;
            int i;
            double b;
            double x;

            ss >> i >> b >> x;
            const auto sum = exp(x);
            sublist.push_back(sum);
            while (ss >> x) {
                sublist.push_back(x);
                sublist[0] -= x;
            }
            activities.push_back(sublist);
        }
    }

    Activity_list::Activity_list(const std::vector<std::vector<double>>& activities)
        : activities(activities)
    {}

    std::vector<std::vector<double>> Activity_list::log_activities() const
    {
        auto results {activities};
        for (auto& sl : results) {
            const auto sum = std::accumulate(sl.begin(), sl.end(), 0.0);
            sl[0] = log(sum);
            for (size_t i = 1; i < sl.size(); i++) {
                sl[i] = sl[i] / sum;
            }
        }
        return results;
    }
}

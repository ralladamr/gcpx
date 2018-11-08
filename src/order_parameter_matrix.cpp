// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "order_parameter_matrix.h"

#include <numeric>

namespace gcpx {
    Order_parameter_matrix::Order_parameter_matrix(const std::vector<Transition>& transitions,
                                                   const std::vector<int>& subensembles)
        : transitions(transitions), subensembles(subensembles)
    {}

    Order_parameter_distribution Order_parameter_matrix::order_parameter_distribution(const std::vector<double>& guess) const
    {
        const auto size = transitions.size();
        std::vector<double> log_probabilities(size);
        std::vector<double> diff(size - 1);
        std::adjacent_difference(guess.begin(), guess.end(), diff.begin());
        for (size_t i = 0; i < size - 1; i++) {
            log_probabilities[i + 1] = log_probabilities[i] + diff[i];
            if (transitions[i].is_sampled()) {
                log_probabilities[i + 1] += transitions[i].log_probability();
            }
        }
        return Order_parameter_distribution(subensembles, log_probabilities);   
    }
}

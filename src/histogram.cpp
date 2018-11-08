// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "histogram.h"

#include <cmath>
#include <iostream>
#include <numeric>

namespace gcpx {
    double Histogram::reweight(size_t index, double amount) const
    {
        auto shifted = shift(index, amount);
        auto shifted_sum = std::accumulate(shifted.begin(), shifted.end(), 0.0);
        auto sum = std::accumulate(counts[index].begin(), counts[index].end(), 0.0);
        return log(shifted_sum) - log(sum);
    }

    std::vector<double> Histogram::average(const std::vector<double>& weights) const
    {
        std::vector<double> results(subensemble_count);
        for (size_t i = 0; i < subensemble_count; i++) {
            auto bin_subset = bins[i];
            auto shifted = shift(i, weights[i]);
            auto shifted_sum = std::accumulate(shifted.begin(), shifted.end(), 0.0);
            for (size_t j = 0; j < bin_subset.size(); j++) {
                results[i] += bin_subset[j] * shifted[j];
            }
        }
        return results;
    }

    Histogram::Histogram(const std::vector<std::vector<double>>& bins,
                         const std::vector<std::vector<long>>& counts)
        : bins(bins), counts(counts)
    {}

    std::vector<double> Histogram::shift(size_t index, double amount) const
    {
        auto bin_subset = bins[index];
        auto count_subset = counts[index];
        const auto size = bin_subset.size();
        std::vector<double> results(size);
        for (size_t i = 0; i < size; ++i) {
            results[i] = count_subset[i] * exp(-amount * bin_subset[i]);
        }
        return results;
    }
}

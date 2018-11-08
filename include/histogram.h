// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef MALLARD_HISTOGRAM_H
#define MALLARD_HISTOGRAM_H

#include <string>
#include <vector>

namespace mallard {
    class Histogram {
    public:
        double reweight(int index, double amount) const;
        std::vector<double> average(const std::vector<double>& weights) const;
        Histogram(const std::vector<std::vector<double>>& bins, const std::vector<std::vector<long>>& counts);
        Histogram(const std::string& filename);
        ~Histogram() = default;
        Histogram(const Histogram&) = default;
        Histogram& operator=(const Histogram&) = default;
        Histogram(Histogram&&) = default;
        Histogram& operator=(Histogram&&) = default;

    private:
        size_t subensemble_count;
        std::vector<std::vector<double>> bins;
        std::vector<std::vector<long>> counts;

        std::vector<double> shift(int index, double amount) const;
    };
}

#endif

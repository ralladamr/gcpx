// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef MALLARD_TRANSITION_H
#define MALLARD_TRANSITION_H

#include <vector>

namespace mallard {
    class Transition {
    public:
        bool is_sampled() const;
        double log_probability() const;
        Transition(long fwd_attempts, double fwd_probability, long rev_attempts, double rev_probability);
        ~Transition() = default;
        Transition(const Transition&) = default;
        Transition& operator=(const Transition&) = default;
        Transition(Transition&&) = default;
        Transition& operator=(Transition&&) = default;

    private:
        long fwd_attempts;
        double fwd_probability;
        long rev_attempts;
        double rev_probability;
        static const long min_attempts = 1;
    };
} // namespace mallard

#endif

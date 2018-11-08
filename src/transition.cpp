// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include "transition.h"

#include <cmath>
#include <vector>

namespace gcpx {
    Transition::Transition(long fwd_attempts, double fwd_probability, long rev_attempts, double rev_probability)
        : fwd_attempts(fwd_attempts), fwd_probability(fwd_probability), rev_attempts(rev_attempts),
        rev_probability(rev_probability)
    {}

    bool Transition::is_sampled() const
    {
        return ((fwd_attempts > min_attempts) && (rev_attempts > min_attempts) && (fwd_probability > 0.0)
                && (rev_probability > 0.0));
    }

    double Transition::log_probability() const
    {
        return log(fwd_probability / rev_probability);
    }
}

// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef MALLARD_ACTIVITY_LIST_H
#define MALLARD_ACTIVITY_LIST_H

#include <vector>

namespace mallard {
    class Activity_list {
    public:
        std::vector<std::vector<double>>& log_activities() const;
        Activity_list(const std::string & filename, bool is_bz_file = false);
        Activity_list(const std::vector<std::vector<double>>& activities);
        ~Activity_list() = default;
        Activity_list(const Activity_list&) = default;
        Activity_list& operator=(const Activity_list&) = default;
        Activity_list(Activity_list&&) = default;
        Activity_list& operator=(Activity_list&&) = default;

    private:
        std::vector<std::vector<double>> activities;
    };
}

#endif

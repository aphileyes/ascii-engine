//
// Created by Aphile on 22.08.2025.
//

#include "Scheduler.h"
#include <algorithm>

namespace Scheduler {
    Scheduler::Scheduler() = default;

    void Scheduler::RegisterTask(IUpdatable* task, bool real_time, Nanoseconds update_time) {
        if (real_time) {
            real_time_tasks_.emplace_back(task);
        } else {
            tasks_.emplace_back(task, update_time, update_time);
            std::sort(tasks_.begin(), tasks_.end(),
                      [](const ScheduledTask& a, const ScheduledTask& b) {
                          return a.next_update_time < b.next_update_time;
                      });
        }
    }

    void Scheduler::Update(Nanoseconds timestamp) {
        for (auto& real_time_task : real_time_tasks_) {
            if (real_time_task.task) {
                real_time_task.task->SchedulerUpdate();
            }
        }

        for (auto& delayed_task : tasks_) {
            if (delayed_task.task && delayed_task.next_update_time <= timestamp) {
                delayed_task.task->SchedulerUpdate();
                Nanoseconds new_timestamp = std::chrono::high_resolution_clock::now().time_since_epoch();
                delayed_task.next_update_time = timestamp + delayed_task.update_interval;
            }
        }

        std::sort(tasks_.begin(), tasks_.end(),
                  [](const ScheduledTask& a, const ScheduledTask& b) {
                      return a.next_update_time < b.next_update_time;
                  });
    }
}  // namespace Scheduler
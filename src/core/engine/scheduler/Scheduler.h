//
// Created by Aphile on 22.08.2025.
//

#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <chrono>
#include <vector>

namespace Scheduler {
    constexpr size_t SECOND_IN_NANOSECONDS = 1'000'000'000;

    using Nanoseconds = std::chrono::nanoseconds;

    class IUpdatable {
    public:
        virtual void SchedulerUpdate() = 0;
        virtual ~IUpdatable() = default;
    };

    struct ScheduledTask {
        IUpdatable* task;
        Nanoseconds update_interval;
        Nanoseconds next_update_time;
    };

    struct ScheduledRealTimeTask {
        IUpdatable* task;
    };

    class Scheduler {
    public:
        Scheduler();
        void RegisterTask(IUpdatable* task, bool real_time, Nanoseconds update_time = Nanoseconds(SECOND_IN_NANOSECONDS / 60));
        void Update(Nanoseconds timestamp);

    private:
        std::vector<ScheduledTask> tasks_;
        std::vector<ScheduledRealTimeTask> real_time_tasks_;
    };
}  // namespace Scheduler

#endif  // SCHEDULER_H

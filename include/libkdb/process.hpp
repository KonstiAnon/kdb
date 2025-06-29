//
// Created by Konstantin on 29.06.2025.
//

#ifndef KDB_PROCESS_HPP
#define KDB_PROCESS_HPP

#include <filesystem>
#include <memory>
#include <sys/types.h>

namespace kdb {
    enum class process_state {
        stopped,
        running,
        exited,
        terminated
    };

    struct stop_reason {
        stop_reason(int wait_status);

        process_state reason;
        std::uint8_t  info;
    };

    class process {
    public:
        ~process();

        static std::unique_ptr <process> launch(std::filesystem::path path);

        static std::unique_ptr <process> attach(pid_t pid);

        stop_reason wait_on_signal();

        void resume();

        pid_t pid() const { return pid_; }

        process_state state() const { return state_; }

    private:
        process(pid_t pid, bool terminate_on_end) : pid_(pid), terminate_on_end_(terminate_on_end) {}

        pid_t pid_ = 0;
        bool terminate_on_end_ = true;
        process_state state_ = process_state::stopped;

        process() = delete;

        process(const process &) = delete;

        process &operator=(const process &) = delete;
    };
}

#endif //KDB_PROCESS_HPP

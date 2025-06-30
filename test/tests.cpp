//
// Created by Konstantin on 28.06.2025.
//

#include <catch2/catch_test_macros.hpp>
#include <libkdb/process.hpp>
#include <libkdb/error.hpp>

using namespace kdb;

namespace {
    bool process_exists(pid_t pid){
        auto ret = kill(pid, 0);
        return ret != -1 and errno != ESRCH;
    }
}

TEST_CASE("process::launch success", "[process]") {
    auto proc = process:launch("yes");
    REQUIRE(process_exists(proc->pid()));
}

TEST_CASE("process::launch no such program", "[process]") {
    REQUIRE_THROWS_AS(process::launch("fake_program_non_existent"), error);
}
//
// Created by konst on 01.07.2025.
//

#ifndef KDB_TYPES_HPP
#define KDB_TYPES_HPP

#include <array>
#include <cstddef>

namespace kdb {
    using byte64 = std::array<std::byte, 8>;
    using byte128 = std::array<std::byte, 16>;
}

#endif //KDB_TYPES_HPP

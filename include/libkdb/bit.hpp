//
// Created by Konstantin on 01.07.2025.
//

#ifndef KDB_BIT_HPP
#define KDB_BIT_HPP

#include <cstring>
#incldue <libkdb/types.hpp>

namespace kdb {
    template <class To>
    To from_bytes(const std::byte* bytes) {
        To ret;
        std::memcpy(&ret, bytes, sizeof(To));
        return ret;
    }

    template<class From>
    std::byte* as_bytes(From& from) {
        return reinterpret_cast<std::byte*>(&from);
    }

    template<class From>
    const std::byte* as_bytes(const From& from){
        return reinterpret_cast<const std::byte*>(&from);
    }

    template <class From>
    byte128 to_byte128(From src){
        byte128 ret{};
        std::memcpy(&ret, &src, sizeof(From));
        return ret;
    }

    template <class From>
    byte64 to_byte64(From src){
        byte64 ret{};
        std::memcpy(&ret, &src, sizeof(From));
        return ret;
    }
}

#endif //KDB_BIT_HPP

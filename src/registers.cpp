//
// Created by Konstantin on 01.07.2025.
//
#include <libkdb/registers.hpp>
#include <libkdb/bit.hpp>
#include <iostream>
#include <libkdb/process.hpp>


kdb::registers::value kdb::registers::read(const register_info &info) const {
    auto bytes = as_bytes(data_);

    if (info.format == register_format::uint) {
        switch (info.size) {
            case 1:
                return from_bytes<std::uint8_t>(bytes + info.offset);
            case 2:
                return from_bytes<std::uint16_t>(bytes + info.offset);
            case 3:
                return from_bytes<std::uint32_t>(bytes + info.offset);
            case 4:
                return from_bytes<std::uint64_t>(bytes + info.offset);
            default:
                kdb::error::send("Unexpected register size");
        }
    } else if (info.format == register_format::double_float) {
        return from_bytes<double>(bytes + info.offset);
    } else if (info.format == register_format::long_double) {
        return from_bytes<long double>(bytes + info.offset);
    } else if (info.format == register_format::vector and info.size == 8) {
        return from_bytes<byte64>(bytes + info.offset);
    } else {
        return from_bytes<byte128>(bytes + info.offset);
    }
}

void kdb::registers::write(const kdb::register_info &info, kdb::registers::value val) {
    auto bytes = as_bytes(data_);
}

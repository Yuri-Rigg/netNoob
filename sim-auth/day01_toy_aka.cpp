// Educational protocol model only. NOT GSM, UMTS, LTE, or 5G cryptography.
// It intentionally uses a toy keyed mixer; do not use for real authentication.
#include <array>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <string>

using Bytes16 = std::array<std::uint8_t, 16>;
using Bytes8 = std::array<std::uint8_t, 8>;

std::uint64_t toy_prf(const Bytes16& key, const Bytes16& input, std::uint64_t domain) {
    // A deterministic keyed mixer so we can study data flow, not real crypto.
    std::uint64_t state = 0x9e3779b97f4a7c15ULL ^ domain;
    for (std::uint8_t byte : key)   state = (state ^ byte) * 0x100000001b3ULL;
    for (std::uint8_t byte : input) state = (state ^ byte) * 0x100000001b3ULL;
    return state;
}

Bytes8 response(const Bytes16& k, const Bytes16& rand) {
    const auto value = toy_prf(k, rand, 0x52455350); // "RESP"
    Bytes8 out{};
    for (int i = 0; i < 8; ++i) out[i] = static_cast<std::uint8_t>(value >> (8 * i));
    return out;
}

Bytes8 mac(const Bytes16& k, const Bytes16& rand, std::uint64_t sqn) {
    Bytes16 message = rand;
    for (int i = 0; i < 6; ++i) message[i] ^= static_cast<std::uint8_t>(sqn >> (8 * i));
    const auto value = toy_prf(k, message, 0x4d4143); // "MAC"
    Bytes8 out{};
    for (int i = 0; i < 8; ++i) out[i] = static_cast<std::uint8_t>(value >> (8 * i));
    return out;
}

void print(const char* label, const Bytes8& value) {
    std::cout << label;
    for (auto byte : value)
        std::cout << std::hex << std::setw(2) << std::setfill('0') << +byte;
    std::cout << std::dec << '\n';
}

int main() {
    const Bytes16 k = {0x10, 0x21, 0x32, 0x43, 0x54, 0x65, 0x76, 0x87,
                       0x98, 0xa9, 0xba, 0xcb, 0xdc, 0xed, 0xfe, 0x0f};
    const Bytes16 rand = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
                          0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10};

    // Older GSM-style idea: network verifies that the SIM knows K.
    const Bytes8 sres = response(k, rand);
    std::cout << "GSM-style: network sends RAND; SIM returns SRES.\n";
    print("  SRES = ", sres);

    // AKA-style idea: SIM also verifies that the network knows K and is fresh.
    const std::uint64_t sqn = 42; // A sequence number stands in for freshness state.
    const Bytes8 autn_mac = mac(k, rand, sqn);
    std::cout << "\nAKA-style: network sends RAND plus authenticated freshness data.\n";
    print("  MAC  = ", autn_mac);
    std::cout << "  SQN  = " << sqn << "\n";
    std::cout << "  SIM verifies MAC and SQN before returning its response.\n";

    const bool network_authenticated = (autn_mac == mac(k, rand, sqn));
    const bool fresh = (sqn > 41);
    std::cout << "\nSIM accepts network: "
              << (network_authenticated && fresh ? "yes" : "no") << '\n';
}

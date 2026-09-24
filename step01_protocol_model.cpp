#include <cstdint>

// A fixed-width type keeps the size of each value explicit in this model.
using Value = std::uint64_t;

// A simplified authentication request used to illustrate the protocol flow.
// Real AKA sends RAND and AUTN; SQN and the network proof are protected inside
// AUTN rather than transmitted as separate fields.
struct AuthRequest {
    Value rand;
    Value sqn;
    Value network_proof;
};

int main() {
    AuthRequest current_request;
    current_request.rand = 1221;

    // Avoid a leading zero in an integer literal: it denotes octal in C++.
    current_request.sqn = 1;

    // Placeholder until the network-proof calculation is implemented.
    current_request.network_proof = 0;
}

/*
 C++ notes:

 - <cstdint> is the C++ standard-library header for fixed-width integer types,
   such as std::uint8_t, std::uint32_t, and std::uint64_t.
 - std::uint64_t is an unsigned integer type that is exactly 64 bits wide when
   the implementation provides it. Its range is 0 through (2^64) - 1.
 - The _t suffix is a naming convention meaning "type."
 - The using declaration creates a shorter name for std::uint64_t.

 This representation is for learning purposes and does not model real AKA
 cryptographic values or operations.
 */

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

// Declare the contract for our simplified proof function. This models one
// conceptual part of authentication; it does not construct a real AKA AUTN.
Value MakeTrialProof(Value key, Value rand, Value sqn);

int main() {
    // A toy shared key for the protocol model. A real long-term key must not be
    // hard-coded or represented this way.
    const Value shared_key = 1111;

    AuthRequest current_request;
    current_request.rand = 1221;

    // Avoid a leading zero in an integer literal: it denotes octal in C++.
    current_request.sqn = 1;

    // Calculate the model's network proof from the shared inputs.
    current_request.network_proof = MakeTrialProof(
        shared_key, current_request.rand, current_request.sqn);
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

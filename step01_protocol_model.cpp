#include <cstdint>
#include <iostream>

// A fixed-width type keeps the size of each value explicit in this model.
using Value = std::uint64_t;

// SIMPLIFIED REPRESENTATION FOR LEARNING ONLY:
// Real AKA sends RAND and AUTN. This model exposes SQN and the network proof as
// separate fields to make the protocol flow visible; it is not a real AKA
// message format.
struct AuthRequest {
    Value rand;
    Value sqn;            // Concealed within AUTN in real AKA.
    Value network_proof;  // Represented within AUTN in real AKA.
};

// Define a deterministic proof function for the learning model. This function
// is not cryptographically secure and does not construct a real AKA AUTN.
Value MakeTrialProof(Value key, Value rand, Value sqn) {
    return (key ^ rand) + (sqn * 31);
}

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

    std::cout << current_request.network_proof << std::endl;
    std::cout << "Program execution completed" << std::endl;

    // The SIM stores its own copy of the same long-term key.
    const Value sim_key = 1111;
    const Value sim_stored_sqn = 0 ;
    const Value expected_network_proof = MakeTrialProof(
        sim_key, current_request.rand, current_request.sqn);
    const bool network_is_authenticated =
        current_request.network_proof == expected_network_proof;
    const bool sqn_is_fresh = (current_request.sqn>sqn_is_fresh);
    std::cout << std::boolalpha;
    std::cout << "Network authenticated: " <<network_is_authenticated<<std::endl;
    std::cout << "SQN is fresh: "<< sqn_is_fresh<< std::endl;
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

/*
 Linker note:

 Declaring MakeTrialProof without defining it allowed compilation but caused an
 "undefined symbol" linker error. Providing the function body resolved it.

 Algorithm used by this model:
     (key ^ rand) + (sqn * 31)

 This expression is only for demonstrating protocol flow. A real
 authentication algorithm must satisfy the relevant cryptographic standard.
 */

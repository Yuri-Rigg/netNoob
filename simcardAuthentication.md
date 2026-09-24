# SIM Card Authentication

## Step 1: The Fresh Challenge

The mobile network asks the SIM to prove that it knows **K**.

### What is K?

**K** is not a person. It is the subscriber's long-term secret key, shared by:

- the SIM or USIM; and
- the mobile operator's secure authentication system.

The SIM stores K in protected hardware. The operator stores its copy in secure
authentication infrastructure. K is never transmitted over the radio link.

### Why must the challenge change?

If the SIM sent the same proof every time, an attacker could record it and
replay it later to impersonate the subscriber.

To prevent this, the network generates a new, unpredictable random challenge
for each authentication attempt. This value is called **RAND**.

The simplified process is:

1. The network sends RAND to the SIM.
2. The SIM uses K and RAND as inputs to an authentication algorithm.
3. The SIM generates and returns a response.
4. The network checks whether the response is correct.

Because RAND changes, the expected response also changes. A previously recorded
response therefore cannot simply be reused. This is a **challenge-response
protocol**.

## Step 2: Verifying the SIM's Response

The operator's authentication system can calculate the expected response
because it also has access to K:

```text
Operator: expected_response = F(K, RAND)
SIM:      actual_response   = F(K, RAND)

Accept only if actual_response == expected_response.
```

Here, **F** represents an authentication algorithm. This is a conceptual model;
real mobile standards define specific cryptographic functions and inputs.

### What can an attacker observe?

RAND must travel from the network to the SIM over the radio link, so a nearby
listener may be able to observe it. The attacker may also observe the SIM's
response. However, K is never transmitted: it remains inside the SIM and the
operator's protected authentication system.

Without K, an attacker should not be able to calculate the correct response to
a new RAND.

## Step 3: The Limitation of GSM Authentication

**GSM (Global System for Mobile Communications)** is a family of 2G cellular
standards. It preceded technologies such as:

- **UMTS (Universal Mobile Telecommunications System):** a major 3G standard;
  and
- **LTE (Long-Term Evolution):** the radio technology commonly associated with
  4G.

In GSM authentication, the network authenticates the SIM:

```text
Network challenges SIM → SIM proves knowledge of K → Network accepts SIM
```

The SIM does not authenticate the network. A fake base station can therefore
send a challenge, and the SIM may calculate and return a response. This is
called **one-way authentication**.

Later systems added network authentication, allowing both sides to verify each
other. This is called **mutual authentication**.

## Step 4: Mutual Authentication with AKA

**AKA** means **Authentication and Key Agreement**. It is a protocol framework
standardized by **3GPP (3rd Generation Partnership Project)**, the organization
that develops specifications for mobile systems including UMTS, LTE, and 5G.

AKA addresses the GSM limitation by making the network provide evidence that
it was authorized by the operator's authentication system. At a high level, AKA
uses:

- **RAND:** a fresh random challenge;
- **SQN:** a sequence number used to detect stale or replayed authentication
  requests;
- **K:** the long-term secret shared by the USIM and the operator; and
- **AUTN:** the authentication token that the USIM verifies.

Conceptually, the USIM uses K, RAND, and information recovered from AUTN to
verify the network's authentication proof. Only after AUTN passes its integrity
and freshness checks does the USIM trust the network and return its response.

### Is SQN sent to the USIM?

The operator and the USIM each maintain sequence-number state. In real AKA,
SQN is not sent as a separate, plain field. AUTN contains a concealed form of
SQN, along with an authentication-management field and a message authentication
code. The USIM recovers SQN, checks that it is fresh, and verifies the code.

The simplified relationship is:

```text
Network accepted by USIM only if:
    authentication proof is valid
    AND
    SQN is fresh
```

## Step 5: High-Level AKA Exchange

```text
Operator / serving network                         SIM / USIM
          |                                             |
          | obtains RAND, expected response, and AUTN   |
          |                                             |
          |---------------- RAND, AUTN ---------------->|
          |                                             | verifies AUTN using K
          |                                             | recovers and checks SQN
          |                                             |
          |<---------------- response ------------------|
          | verifies the response                       |
          |                                             |
```

The USIM's decision is:

```text
if AUTN is valid and SQN is fresh:
    return the response
else:
    reject the authentication request
```

This diagram is intentionally high-level. In a real deployment, the serving
network generally obtains authentication data from the subscriber's home
operator rather than storing K at the base station.

## Step 6: Model the Protocol, Not the Cryptography

Real AKA uses standardized cryptographic functions and carefully sized byte
arrays. Our first C++ program models only the protocol's data flow:

> **Simplified representation:** `AuthRequest` exposes `sqn` and
> `network_proof` as separate fields to make the learning flow visible. It is
> not the message format used by real AKA.

```cpp
#include <cstdint>

using Value = std::uint64_t;

struct AuthRequest {
    Value rand;
    Value sqn;
    Value network_proof;
};
```

In real AKA, the sequence number is concealed and the network-authentication
proof is carried as part of AUTN. A production implementation must follow the
standardized AUTN structure rather than this teaching model.

### C++ terms

- `<cstdint>` is the C++ standard-library header that provides fixed-width
  integer types such as `std::uint8_t`, `std::uint32_t`, and `std::uint64_t`.
- `std::uint64_t` is an unsigned integer type that is exactly 64 bits wide when
  the implementation provides it. Its range is 0 through 2^64 - 1.
- The `_t` suffix is a naming convention meaning **type**.
- `using Value = std::uint64_t;` creates a shorter name for the type and keeps
  the model's chosen size explicit.

> This integer representation is suitable for a learning model, not a real AKA
> implementation.

## Step 7: Declare the Operation Before Implementing It

Here, an **operation** means the function that represents our simplified proof
algorithm, F. Both the operator's authentication system and the SIM must derive
the same output from the same inputs:

```text
proof = F(K, RAND, SQN)
```

We first declare the function's contract in C++:

```cpp
Value MakeTrialProof(Value key, Value rand, Value sqn);
```

This declaration tells the compiler that `MakeTrialProof`:

- accepts a key, random challenge, and sequence number; and
- returns one `Value` representing the proof.

The declaration describes how other code can call the function. A later
**definition** will provide the function body and implement its behavior.

For this learning model, the function must have two properties:

1. **Deterministic:** the same inputs must always produce the same output. This
   allows the SIM and operator to calculate matching values independently.
2. **Sensitive to every input:** changing K, RAND, or SQN should normally change
   the output.

These properties make the protocol flow useful to simulate, but they do not
make the function cryptographically secure. A real AKA implementation must use
the standardized cryptographic functions and data formats.

### Calling the declared function

The network side of the model can now request a proof using the shared inputs:

```cpp
const Value shared_key = 1111;

current_request.network_proof = MakeTrialProof(
    shared_key, current_request.rand, current_request.sqn);
```

The declaration is enough for the compiler to check that this call uses the
correct argument and return types. However, the program cannot yet be linked
into a complete executable because `MakeTrialProof` has not been defined. Its
definition will supply the algorithm in the next step.

The hard-coded key is acceptable only in this toy model. A real implementation
must keep the subscriber's long-term key inside protected authentication
infrastructure and the SIM or USIM.

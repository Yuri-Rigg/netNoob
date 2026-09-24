# SIM / USIM authentication — Day 1

This module explains the **shape** of cellular subscriber authentication. The program beside it is a safe C++ model, not an implementation of a cellular standard.

## First mental model

A SIM/USIM and the operator's authentication system share a long-term secret, conventionally called `K`. It is never sent over the radio.

1. The network sends a fresh random challenge, `RAND`.
2. The SIM combines `K` and `RAND` to compute a response.
3. The network computes the expected response from its copy of `K` and accepts only a match.

That proves the device knows the secret. It does **not**, on its own, prove that the network is genuine.

## Earlier: GSM-style authentication

Classic GSM has the asymmetric shape:

```
Network ── RAND ──> SIM
Network <── SRES ── SIM
```

The network challenges the SIM and verifies its response (`SRES`). GSM's A3/A8 authentication/key-generation functions have example algorithm sets specified by 3GPP.

The important limitation is lack of **network authentication**: the SIM has not verified who issued the challenge. This is why an attacker can exploit fake base stations and downgrade scenarios; the full problem also involves radio and network policy, not just this one exchange.

## Now: AKA-style mutual authentication

UMTS AKA, carried forward and adapted through LTE and 5G systems, adds an authentication token:

```
Network ── RAND, AUTN ──> USIM
Network <── RES* / response ── USIM
```

Conceptually, `AUTN` lets the USIM verify two facts before it responds:

- **Authenticity:** the network has the long-term secret.
- **Freshness:** this challenge is not a replay (a sequence number, `SQN`, is part of the design).

Real AKA derives multiple values rather than one response: a MAC/authentication value and values for a response, ciphering key, integrity key, and anonymity handling. 3GPP's MILENAGE family is an *example* algorithm set for functions `f1`, `f1*`, `f2`, `f3`, `f4`, `f5`, and `f5*`; implementations use operator-provisioned algorithms and protected key storage. 3GPP also publishes the newer MILENAGE-256 specifications.

## Why this is better

| Property | GSM-style challenge/response | AKA-style authentication |
|---|---|---|
| SIM proves knowledge of secret | Yes | Yes |
| SIM authenticates the network | No | Yes, through `AUTN` |
| Replay resistance in authentication | Limited by challenge handling | Explicit freshness / sequence checking |
| Key separation | Older model | Separate derived authentication, confidentiality, and integrity material |

## Run the model

```bash
g++ -std=c++20 -Wall -Wextra -Wpedantic sim-auth/day01_toy_aka.cpp -o toy_aka
./toy_aka
```

Read `day01_toy_aka.cpp` line by line. It has two flows:

1. `response(K, RAND)`: the older one-way authentication idea.
2. `mac(K, RAND, SQN)`: the extra network-authentication and freshness check.

The function named `toy_prf` is deliberately **not cryptography**. Its job is only to preserve the data dependencies so we can reason about the protocol safely.

## Next progression

1. Trace every byte/value in the model and explain what each party can verify.
2. Add negative tests: altered `RAND`, wrong `SQN`, and replayed `SQN` must be rejected.
3. Replace the toy types with fixed-width message structures and examine byte order.
4. Study the public 3GPP MILENAGE interfaces and official test data—not real SIM credentials.
5. Compare AKA variants and 5G's privacy improvements (e.g., concealed subscriber identifiers) at the protocol level.

## References

- [3GPP TS 55.205 — GSM-MILENAGE A3/A8 example algorithms](https://portal.3gpp.org/desktopmodules/Specifications/SpecificationDetails.aspx?specificationId=2803)
- [3GPP TS 35.206 — MILENAGE example functions](https://portal.3gpp.org/Specifications.aspx?WiUid=1571&q=1)
- [3GPP TS 35.234 — MILENAGE-256 general specification](https://portal.3gpp.org/desktopmodules/Specifications/SpecificationDetails.aspx?specificationId=4243)

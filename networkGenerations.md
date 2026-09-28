# Network Generations: From 1G to 6G

## From brick phones to ambient intelligence

> How did a network designed for a voice call become infrastructure for video,
> navigation, factories, sensors, and perhaps one day digital twins? The answer is
> not simply “more speed.” Each mobile generation changes what the network is
> designed to do.

## Abstract

Mobile networks have evolved from analogue voice systems into programmable,
software-driven platforms that connect people and machines. This paper traces
that evolution from 1G to 5G and examines the developing vision for 6G. It
explains the technologies behind each generational label, the experiences those
technologies enabled, and the trade-offs that marketing shorthand often hides.
It also explores spectrum, cells, latency, handovers, network architecture,
security, and the environmental and social questions that will shape the next
generation.

The central idea is simple: a new generation is meaningful when it changes the
network's capabilities and architecture—not merely when a phone displays a new
icon.

## At a glance

| Generation | Broad era | Defining shift | Representative technologies | What users noticed |
|---|---:|---|---|---|
| 0G | 1940s–1970s | Pre-cellular mobile radio | MTS, IMTS | Operator-assisted or limited car-phone service |
| 1G | 1980s | Analogue cellular voice | AMPS, NMT, TACS | Mobile calling and automatic handover |
| 2G | 1990s | Digital voice and messaging | GSM, IS-95 (cdmaOne) | SMS, clearer calls, better capacity, smaller phones |
| 2.5G/2.75G | Late 1990s–2000s | Packet data added to 2G | GPRS, EDGE | Email and basic mobile web |
| 3G | 2000s | Mobile Internet becomes a design goal | UMTS/WCDMA, CDMA2000; later HSPA | Practical web browsing, app stores, video calls |
| 4G | 2010s | All-IP mobile broadband | LTE; LTE-Advanced | Streaming, ride-hailing, social video, hotspot use |
| 5G | 2020s | Flexible service platform | 5G NR, 5G Core | Higher capacity, fixed wireless, and industrial options |
| 6G | Around 2030 and beyond | Communication, sensing, AI, and broad coverage converge | IMT-2030 candidates are still being developed | Proposed immersive, intelligent, and resilient services |

These dates overlap. Networks are deployed country by country, and older
generations commonly remain in service while newer ones expand.



## First, what does the “G” mean?

The **G** means *generation*. It is a convenient industry label, not a single
technical specification. Several organizations take part in turning an idea
into a working generation:

- The **International Telecommunication Union (ITU)** defines global vision,
  requirements, and recognized families of radio interfaces. Its formal names
  include IMT-2000 for 3G, IMT-Advanced for 4G, IMT-2020 for 5G, and IMT-2030
  for the framework commonly called 6G.

- **3GPP**, a partnership of standards bodies, maintains and develops a major
  standards family that began with GSM in the 2G era and later expanded through
  UMTS/HSPA (3G), LTE (4G), and 5G New Radio and the 5G Core. Other standards
  families also existed, especially in the 2G and 3G eras.
- Regulators assign or auction spectrum, while network operators select,
  deploy, and operate equipment.
- Phone makers and modem vendors implement compatible devices.

This explains why labels can be messy. Early LTE was marketed as 4G before
LTE-Advanced met the formal IMT-Advanced requirements. “4G,” “4G+,” “5G,” and
similar status-bar symbols identify a class of connection; they do not promise
a particular speed.

## Foundations: the language of radio networks

These terms are related, but they are not interchangeable. The clearest way to
understand them is to picture a horizontal frequency scale, like the tuning
dial on a radio. Every position on the scale is one frequency, while ranges on
the scale form bands and channels.

- **Frequency** describes how many times a radio wave repeats each second and
  is measured in hertz (Hz). For example, 900 MHz means 900 million cycles per
  second. It is a point on the frequency scale, not a band or channel by itself.
  A transmitter sends energy around an assigned frequency, and a receiver tunes
  to the corresponding range to detect it.
- **Spectrum** is the complete range—or collection—of radio frequencies. It is
  reasonable to imagine it as all the available positions on the tuning scale.
  Regulators divide the usable spectrum among mobile networks, broadcasting,
  satellites, Wi-Fi, public safety, and other services.
- **Band** is a named range within the spectrum, not one frequency. For example,
  a band might extend from 880 MHz to 960 MHz. An operator may use a low-frequency
  band for broad coverage and a mid-frequency band for additional capacity.
- **Channel** is a smaller frequency range within a band that a system can use
  for communication. In older systems, a channel could be assigned to a call.
  Modern systems schedule many users within shared channel resources, so a user
  does not necessarily own one channel for the entire session.
- **Bandwidth** is the width of a channel: the difference between its upper and
  lower frequency limits. A channel extending from 3,500 MHz to 3,600 MHz has
  100 MHz of bandwidth. A wider channel can usually carry more data at once,
  although signal quality, interference, modulation, coding, antennas, and the
  number of users also affect the delivered throughput.
- **Data rate or throughput** is the amount of information successfully
  delivered per second, usually measured in bits per second. Bandwidth is an
  available frequency width; throughput is the useful data actually carried.
- **Latency** is the time required to deliver data and receive a response. It is
  distinct from both bandwidth and throughput: a connection can transfer a
  large amount of data per second yet still pause noticeably before a response
  begins.

### Spectral efficiency: how much a hertz carries

**Spectral efficiency** measures the useful information rate obtained from a
given amount of radio bandwidth:

$$
\eta = \frac{R}{B}
$$

where \(R\) is the useful data rate in bits per second and \(B\) is channel
bandwidth in hertz. The unit is **bits per second per hertz (bit/s/Hz)**. For
example, a 10 MHz channel delivering 20 Mbit/s has an effective spectral
efficiency of 2 bit/s/Hz. Because both quantities contain “per second,” the
ratio is sometimes written bit/Hz, but bit/s/Hz states the meaning more clearly.

The result depends on what is counted. **Peak link spectral efficiency** may
describe one ideal radio link, while **cell spectral efficiency** includes the
aggregate useful traffic delivered to all users in a cell. Real measurements
also lose capacity to pilots, control messages, guard intervals, retransmissions,
and protocol headers. Consequently, a single number such as “1G equals 0.003
bit/s/Hz” is not a universal property of the generation. It may depend on the
voice bit-rate equivalent, channel spacing, number of calls, sectorization, and
frequency-reuse pattern used by a particular system.

Spectral efficiency improves when the radio can safely use a denser modulation,
a stronger-but-lower-overhead code, multiple spatial streams, or more precise
scheduling. The appropriate setting depends on channel quality. A phone near a
cell site may use a high-order modulation and high code rate; a phone behind a
wall or at the cell edge usually falls back to a more robust combination. This
adaptive choice is called **link adaptation**.

The Shannon capacity relation gives an ideal upper bound for one noisy channel:

$$
C = B\log_2(1+\mathrm{SNR})
$$

It says that capacity grows linearly with bandwidth but only logarithmically
with signal-to-noise ratio (SNR). Ever more transmit power therefore produces
diminishing returns. Modern coding schemes can operate relatively close to this
bound under suitable conditions, but no practical system can cross it without
changing the bandwidth, SNR, or number of independent spatial channels.

### Why lower frequencies usually cover farther

Lower-frequency waves have longer wavelengths. In typical mobile deployments,
they suffer less free-space path loss at the same distance and often diffract
around large obstacles more effectively. Many common building materials also
attenuate them less severely than much higher-frequency signals. This does not
mean that a low-frequency signal simply passes through every obstacle: terrain,
walls, antenna height, transmit power, and interference still matter.

### Why high frequency and wide bandwidth often appear together

High carrier frequency and wide channel bandwidth are separate properties. A
100 MHz-wide channel can be centred at 3.5 GHz, while a much narrower channel
can also exist at a high frequency. Higher frequencies do not automatically
make a channel wider.

The practical relationship comes from spectrum availability. Lower-frequency
spectrum has long been occupied by television, radio, mobile, navigation, and
other services, so operators often receive small, fragmented blocks there.
Some higher-frequency regions were historically less occupied and contain more
contiguous unused spectrum. Regulators can therefore assign much wider channels
in those regions. The wider channel—not the higher carrier frequency by
itself—provides the opportunity for a higher data rate. The trade-off is that
higher-frequency signals generally have shorter range and are more easily
blocked.

### From microphone to core network: the hardware path

A mobile connection is a chain rather than a single radio. In the handset, a
microphone, camera, or application produces information. A codec or application
compresses it; protocol software forms packets; the modem performs channel
coding, modulation, and radio-resource control; and the RF front end converts
the modem's baseband signal to the assigned carrier frequency. Power amplifiers,
filters, duplexers, antenna tuners, and one or more antennas then transmit or
receive the waveform.

At the cell site, antennas and remote radio units perform the reverse RF work.
A baseband unit—or a distributed set of virtualized radio functions—processes
the signal and schedules users. The **radio access network (RAN)** connects the
device to the **core network**, which authenticates the subscription, tracks
mobility, establishes sessions, applies policy, and routes traffic. Fibre,
microwave, or another transport technology provides fronthaul and backhaul.
The application server may still be many network hops away.

```text
application / microphone
        ↓
codec and protocol stack
        ↓
modem: coding, modulation, scheduling control
        ↓
RF front end ⇄ handset antennas
        ⇅ radio channel
cell-site antennas ⇄ radio/baseband processing
        ↓
transport network → mobile core → Internet or private service
```

The **radio channel** is the propagation environment between the antennas, not
merely a numbered spectrum channel. A receiver may see a direct path plus
delayed reflections from buildings, vehicles, and terrain. Those copies can
reinforce or cancel one another, creating **multipath fading**. Motion adds
Doppler shift; other transmitters add interference; walls add penetration loss.
Channel estimation, equalization, coding, diversity, power control, and
retransmission are different tools for surviving these impairments.




## The overlooked prologue: 0G

Before cellular networks, mobile radio telephones used a small number of
high-power channels covering a large area. Some calls required a human operator,
capacity was tiny, and equipment often filled part of a car. These systems are
retrospectively called **0G**.

The crucial missing idea was the **cell**: a geographic coverage area served by
a base station or one of its antenna sectors. Network diagrams often draw cells
as a tidy hexagonal honeycomb because hexagons cover a map without gaps and make
frequency-reuse patterns, neighbouring cells, and approximate coverage easier
to map and calculate. Real cells are irregular because buildings, terrain,
antenna direction, transmit power, frequency, and interference shape coverage.
Instead of one powerful transmitter serving an entire city, a cellular system
divides the region into many smaller
coverage areas. Frequencies can be reused in sufficiently separated cells, and
a moving call can be handed from one base station to another. That combination
made mass-market mobile service possible.

## 1G: voice becomes mobile

Commercial 1G systems arrived around the 1980s. Systems such as AMPS in North
America, NMT in the Nordic countries, and TACS in the United Kingdom carried
voice as an analogue radio signal.

In this context, **analogue** means that the continuously varying speech
waveform directly varied a radio-wave property rather than first becoming a
stream of binary symbols. AMPS used frequency modulation (FM): instantaneous
carrier-frequency deviation represented the audio waveform, while the
transmitted signal's envelope—and therefore nominal RF output power—remained
approximately constant. “Analogue” does not mean that literal sound travelled
through the air to the tower; the microphone still converted sound into an
electrical signal, which modulated a radio carrier.

Most 1G systems used **frequency-division multiple access (FDMA)**. The operator
split its spectrum into narrow channel pairs, one frequency for the uplink and
another for the downlink, and assigned one pair to a call. Unused guard space
and careful frequency planning reduced adjacent-channel interference. A call
held its channel until release or handover, so silence generally did not free
the resource for somebody else.

### What 1G achieved

- Cellular frequency reuse dramatically increased capacity over car-radio systems.
- Automatic handover let a call continue as its user moved between cells. The
  decision used measurements such as received signal strength and quality, not
  the “strength of a frequency” itself.
- Networks could support public mobile telephone services at national scale.

### What it lacked

Analogue calls used spectrum inefficiently, devices were bulky and
power-hungry, and eavesdropping or cloning could be relatively easy. Data was
not the network's purpose. 1G proved the cellular concept, but it also made the
case for digital transmission. In short, 1G was neither secure enough nor
spectrally efficient enough for a mass digital future.

## 2G: voice becomes digital—and text finds its moment

Second-generation networks digitized the radio link. A phone's microphone still
produced an analogue electrical signal, but a codec converted speech into a
compressed stream of digital bits. A codec at the receiving end reconstructed
audio from those bits. GSM (**Global System for Mobile Communications**) used
time-division and frequency-division techniques to share radio resources,
whereas IS-95 used code-division multiple access. Digital encoding improved
capacity, supported error correction, and made encryption practical on the
radio path, although early algorithms and implementations were later attacked.

### Two different ways to share 2G radio capacity

**GSM combined FDMA and TDMA.** A GSM carrier is 200 kHz wide and its repeating
radio frame contains eight time slots. Several users can therefore share one
carrier by transmitting in assigned bursts at different times. Guard periods
prevent neighbouring bursts from overlapping, timing advance compensates for
different phone-to-tower distances, and Gaussian minimum-shift keying (**GMSK**)
provides a power-efficient modulation. “Taking turns” is a useful analogy, but
a traffic channel can also use a repeating fraction of multiple slots, and the
network reserves some slots for control signalling.

**IS-95 (cdmaOne) used direct-sequence CDMA.** Users can overlap in time and
frequency across the same approximately 1.25 MHz carrier. Each transmission is
spread by a high-rate code; the receiver correlates the composite waveform with
the wanted code so that the desired signal combines coherently while other
signals mostly resemble interference. Walsh codes help separate forward-link
channels, while additional spreading sequences identify cells and users.
CDMA does **not** give each conversation its own frequency band: code-domain
separation is the key idea. Tight power control is essential because one very
strong phone can otherwise drown out weaker phones—the near–far problem.

Mobility also differed. GSM commonly used a **hard handover**, briefly changing
from one channel/cell to another. IS-95 could use **soft handoff**, in which the
phone communicates with more than one cell during the transition and the
network combines or selects the useful signals.

The unexpected cultural success was **SMS (Short Message Service)**. A feature
based on short signalling messages became a new form of conversation. Digital
networks also enabled SIM-based identity in GSM systems, better battery life,
clearer calls, and roaming
across compatible networks. Voice was still mainly circuit-switched: the
network reserved resources for a call even during silence. This gave predictable
service but used capacity less flexibly than packet switching.

### 2.5G and 2.75G: packet data arrives

GPRS (**General Packet Radio Service**) and EDGE extended 2G with packet-switched
data. A file or message is divided into addressed packets, which can take turns
with other users' packets on shared network resources. Unlike a circuit reserved
for the duration of a call, packets are forwarded as needed. Speeds were modest
and latency was high, but email, picture messages,
and stripped-down websites became possible. The phone was beginning to resemble
an Internet terminal.

GPRS dynamically reused GSM time slots for packet traffic. EDGE (**Enhanced
Data rates for GSM Evolution**) added denser modulation and new coding schemes.
Classic EDGE's often-quoted maximum is about 473.6 kbit/s when all eight slots
are assigned under ideal conditions; later Evolved EDGE variants targeted
roughly megabit rates. Neither figure represents a normal single-user rate on a
loaded network.

## 3G: the Internet fits in a pocket

3G systems—including UMTS/WCDMA and CDMA2000—were designed with mobile data in
mind. Later upgrades such as HSPA and HSPA+ made the improvement much more
visible in everyday use.

UMTS used **wideband CDMA (WCDMA)** as its principal radio interface. A nominal
5 MHz carrier formed one wide shared “pipe,” compared with the approximately
1.25 MHz carrier of IS-95/CDMA2000—not 2.5 MHz. User data was multiplied by
channelization codes with different **spreading factors**: a high spreading
factor traded data rate for processing gain, while a lower factor carried more
symbols. Scrambling codes then helped distinguish cells or transmitting users.
Convolutional and turbo coding added redundancy so a receiver could reconstruct
many corrupted bits without retransmitting the whole block.

The wideband signal could resolve multiple delayed paths. A **RAKE receiver**
aligned and combined energy from those paths instead of treating every
reflection as destructive. However, frequency-selective fading, inter-user
interference, power-control error, and limited spectrum still constrained
capacity. HSPA later introduced faster scheduling, improved modulation and
coding, and hybrid retransmission to raise practical throughput.

This generation coincided with capable browsers, touch-screen smartphones, app
stores, better cameras, and cloud services. The network did not create those
inventions, but it gave them mobility. Video calling, maps, music streaming, and
social media could now be useful away from Wi-Fi.

3G remained architecturally transitional: packet data grew in importance, but
voice commonly retained a circuit-switched path. Maintaining separate switching
approaches for voice and data increased complexity. Wider radio channels helped,
but 3G's gains also came from improved modulation, coding, power control,
scheduling, and evolving core-network capabilities. The next generation would
make Internet Protocol the foundation.

Initial UMTS targets and deployments were in the hundreds of kilobits per
second; 384 kbit/s is a commonly cited mobile design rate. HSPA/HSPA+ raised
theoretical peaks into the multi-megabit and, in later configurations,
tens-of-megabits range. Claims such as “UMTS equals 56 Mbit/s” mix later
evolutions or ideal configurations with baseline 3G. CDMA2000 followed a
separate standards family, with 1xRTT for voice/data and EV-DO for faster packet
data.

## 4G: the network becomes all-IP

LTE replaced much of the previous radio design with a flatter, packet-based
architecture. Voice eventually moved onto the data network as **Voice over LTE
(VoLTE)**, subject to operator and device support.

Important radio techniques included:

- **OFDMA**, which divides a wide channel into many closely spaced subcarriers
  that can be scheduled efficiently among users;
- **MIMO**, which uses multiple antennas and signal paths to increase throughput
  or reliability;
- **carrier aggregation**, which lets one device use multiple component carriers
  at the same time, even when the spectrum blocks are separate; and
- more flexible scheduling, allowing the base station to respond quickly to
  changing radio conditions.

### Why OFDM changed the channel design

In orthogonal frequency-division multiplexing (**OFDM**), many narrow
subcarriers overlap in spectrum but are mathematically orthogonal: at the
sampling point for one subcarrier, the others ideally contribute zero. An
inverse fast Fourier transform generates the transmitted waveform efficiently,
and a fast Fourier transform separates it at the receiver. LTE downlink uses
**OFDMA** to allocate different groups of subcarriers and time intervals to
different users; the uplink uses SC-FDMA, which has a lower peak-to-average
power ratio and is friendlier to a handset's power amplifier.

A **cyclic prefix** copies a short section from the end of an OFDM symbol to its
front. If delayed reflections fit within that interval, they do not significantly
mix one symbol with the next, and the frequency-selective radio channel becomes
many simpler, nearly flat subchannels. Known **reference or pilot signals** let
the receiver estimate each subchannel's amplitude and phase. Frequency-domain
equalization can then correct them with far less complexity than a single very
wide, fast symbol stream would require.

Orthogonality reduces the large guard spacing that conventional separated
subchannels would require, but it does not abolish every guard. LTE and NR still
use a cyclic prefix in time and reserve spectrum at channel edges to satisfy
emission limits. Accurate synchronization is also required; frequency offset or
rapid channel change causes the subcarriers to leak into one another.

The scheduler operates in millisecond-scale transmission intervals and assigns
resource blocks according to demand, channel reports, interference, and quality
of service. If a deep fade damages a few subcarriers, interleaving and coding
spread the risk rather than allowing one local notch to destroy an entire
packet. **Forward error correction (FEC)** repairs many errors locally. When it
cannot, **hybrid automatic repeat request (HARQ)**—not “hybrid ARC”—combines a
retransmission with the earlier noisy observation instead of simply discarding
the first attempt.

### Frequency reuse, MIMO, and the LTE architecture

Older FDMA/TDMA deployments often assigned different frequency groups to
neighbouring cells, described by a reuse factor greater than one, to control
co-channel interference. LTE commonly uses **reuse one**: every cell may use the
whole carrier, while scheduling, sector antennas, power control, and
inter-cell-interference coordination manage the contested cell edges. Reuse one
provides more spectrum per cell but does not mean uniform coverage. Poor site
placement, antenna downtilt, obstructions, or interference can still create
coverage holes; overlapping coverage and mobility tuning are needed for clean
handovers.

**MIMO (multiple-input multiple-output)** uses multiple transmit and receive
antennas. With diversity or beamforming it can make a link more reliable; with
**spatial multiplexing** it sends separate data layers over distinguishable
propagation paths in the same time-frequency resource. The latter increases
throughput without adding bandwidth, but only when channel rank and SNR are good
enough for the receiver to separate the layers.

Architecturally, LTE simplified the RAN around the **eNodeB**, which handled
radio scheduling and much of mobility control. The **Evolved Packet Core**
separated control functions such as mobility/session management from packet
gateways that carried user traffic. This flatter all-IP design reduced the
number of network elements on the data path compared with 3G. VoLTE supplied
managed IP voice through the IP Multimedia Subsystem rather than restoring a
2G-style circuit.

The result was not just faster browsing. Reliable mobile broadband supported
HD streaming, real-time navigation, cloud-backed apps, creator video, remote
work, and the platform economy. LTE-Advanced is one of the technologies formally
recognized within ITU's IMT-Advanced family.

IMT-Advanced used headline targets of about 100 Mbit/s under high mobility and
1 Gbit/s under low mobility. Those were evaluation targets for qualifying
systems, not minimum speeds promised to every 4G user. Early LTE deployments,
channel widths, device limits, and shared-cell load often produced much lower
rates.

## 5G: one network, several kinds of service

5G combines **New Radio (NR)** with a new, service-oriented core network. Its
ambition is broader than increasing phone speed. The IMT-2020 vision groups use
cases into three broad families:

1. **Enhanced mobile broadband (eMBB):** more capacity and higher data rates in
   crowded places or for bandwidth-heavy applications. Congestion can still
   reduce performance if deployed capacity is insufficient for demand.
2. **Ultra-reliable and low-latency communications (URLLC):** tightly controlled
   communication for selected industrial and critical tasks. Low latency comes
   from short transmission intervals, rapid scheduling, reliable radio design,
   nearby computing, and an optimized end-to-end path—not merely from bandwidth.
3. **Massive machine-type communications (mMTC):** large populations of devices
   that may transmit small amounts of data. The design emphasizes connection
   density, low device complexity, coverage, and long battery life.

### 5G NR: flexible numerology and coding

5G **New Radio (NR)** retains OFDM but makes its timing and frequency grid more
flexible. A *numerology* selects subcarrier spacing and therefore the OFDM symbol
duration. Common spacings scale as 15, 30, 60, and 120 kHz (with additional
options in the specification). As spacing doubles, useful symbol duration
halves: approximately 66.7, 33.3, 16.7, and 8.3 microseconds before the cyclic
prefix. The rough-note range “120 kHz to 0.125” conflates subcarrier spacing
with transmission time. Wider spacing and shorter slots can support faster
scheduling and tolerate phase noise at high carrier frequencies, while narrower
spacing is more frequency-efficient for long-range, delay-tolerant operation.

NR uses **low-density parity-check (LDPC) codes** for user data and **polar
codes** for important control information. These are not algorithms that remove
the need for signal power or retransmission. They add structured redundancy,
allowing the receiver to infer the most likely transmitted bits; a cyclic
redundancy check tests the decoded block, and HARQ requests/combines more coded
information when necessary. Decoding happens in both directions: a handset
decodes downlink codewords, and a base station decodes uplink codewords.
Reliability therefore means achieving a designed residual block-error rate
within a delay budget—not that the raw radio channel has no bit errors.

The IMT-2020 peak target is 20 Gbit/s downlink and 10 Gbit/s uplink under defined
test conditions—not 200 Gbit/s to one ordinary phone. Field results around
hundreds of Mbit/s or approximately 1 Gbit/s can be excellent yet remain highly
dependent on spectrum, bandwidth, antenna layers, device category, cell load,
backhaul, and location.

### Massive MIMO, beamforming, and small cells

**Massive MIMO** equips a base station with many individually controllable
antenna elements. The array estimates the radio channel and adjusts each
element's phase and amplitude so energy combines in useful directions. This
**beamforming** creates a steerable radiation pattern rather than a perfectly
isolated “data ray.” It can improve SNR, reduce unwanted interference, and let
the same time-frequency resources serve spatially separable users.

Beamforming and spatial multiplexing work together but are not synonyms.
Beamforming concentrates or nulls energy; spatial multiplexing carries multiple
independent data layers. A system may beamform one robust layer to a weak user,
send several layers to one capable device, or direct different layers toward
several users (**multi-user MIMO**). Channel estimation and calibration are
critical: walls, movement, and changing reflections alter the channel on which
the weights depend.

Very high-frequency signals experience greater path loss and blockage, so
operators may deploy **small cells**—low-power, short-range base stations—closer
to demand. A macrocell supplies an umbrella layer while small cells add local
capacity in streets, venues, offices, or campuses. Dense deployment increases
site, fibre/backhaul, power, synchronization, handover, and interference-management
requirements; it is not simply a matter of adding more antennas.

### 5G is not one frequency

5G can operate across a wide range of spectrum:

- **Low band** travels farther and penetrates buildings relatively well, making
  it valuable for broad coverage—such as a large college campus—but the
  available channels are often narrower, limiting peak capacity.
- **Mid band** is often the practical compromise between coverage and capacity.
- **High band**, including millimetre-wave deployments, can provide very wide
  channels and high capacity over shorter, more easily obstructed paths.

No band is universally “best.” Coverage, speed, device support, regulation,
terrain, and network load all matter.

### Non-standalone and standalone 5G

Many early deployments used **non-standalone (NSA)** architecture: 5G radio
worked with an existing 4G core and LTE anchor. **Standalone (SA)** 5G uses a 5G
Core and can expose capabilities such as network slicing and more flexible
traffic handling.

The 5G base station is called a **gNodeB (gNB)**. It may be divided into radio,
distributed, and centralized units so processing can be placed near the antenna
or pooled farther away. The 5G Core uses service-based network functions for
access and mobility, session management, authentication, policy, and user-plane
forwarding. Separating the user plane makes it possible to place traffic exits
near an edge application, although doing so is a deployment choice rather than
an automatic property of 5G.

**Network slicing** creates multiple logical networks on shared physical
infrastructure. Think of one motorway divided into managed lanes: one slice
might prioritize predictable performance for factory equipment, another might
support a large number of low-power sensors, and another might serve ordinary
mobile broadband. Each slice can have its own policies, security controls, and
performance objectives. It does not create physically separate towers or
guarantee performance by itself; the operator must allocate resources and
engineer the service end to end. A 5G icon therefore does not reveal the
complete network architecture behind it.

### Why the advertised speed is not your speed

Peak targets describe carefully defined conditions; user experience depends on
the channel bandwidth, spectrum band, signal quality, interference, distance,
obstructions, antenna configuration, backhaul, server performance, device
capability, and how many users share the cell. A useful mental model is:

> **Available capacity is shared, and radio conditions determine how efficiently
> that capacity can be used.**

Latency is equally layered. A fast air interface cannot remove delay caused by
a distant server, congested transport network, slow application, or overloaded
device. Edge computing can shorten part of the path, but only when the service
itself is deployed near the user.

## 6G and IMT-2030: a framework, not yet a finished product

The ITU adopted Recommendation ITU-R M.2160, the IMT-2030 framework, in 2023.
As of September 2026, 6G remains in research and standardization. ITU work has
defined draft minimum technical performance requirements, but candidate radio
interfaces still have to be submitted and evaluated. Detailed technologies,
spectrum choices, commercial products, and deployments will continue to develop
through the rest of the decade. Claims that present a single guaranteed 6G
speed or settled product feature list should therefore be treated carefully.

The framework points toward six usage scenarios:

- immersive communication;
- hyper-reliable, low-latency communication;
- massive communication;
- ubiquitous connectivity;
- AI integrated with communication; and
- integrated sensing and communication.

The last two are especially interesting. A future network may help infer
position, motion, or aspects of an environment from radio signals, while AI may
help configure and optimize the network. Research also considers tighter
integration of terrestrial and non-terrestrial systems, such as satellites and
high-altitude platforms.

These possibilities bring hard questions. How should a sensing network protect
privacy? Can increasingly dense computation be energy-efficient? Will remote
communities gain affordable coverage, or will capability grow mainly where
returns are highest? Security, resilience, sustainability, and connecting the
unconnected are explicit principles in the IMT-2030 vision—not optional details.

## Concepts that connect every generation

### Spectrum is finite, but capacity is engineered

Radio spectrum is a shared natural resource managed by national authorities and
coordinated internationally. Networks increase useful capacity through wider or
additional bands, denser cell layouts, better coding and modulation, more
antennas, interference management, and smarter scheduling. Each technique has a
cost in energy, hardware, coverage, or complexity.

Higher frequency does not automatically mean higher speed. High frequencies can
make wide channels available, but propagation is generally less forgiving.
Likewise, a lower-frequency connection can be fast when sufficient bandwidth is
available and the cell is lightly loaded.

### Mobility is a continuous negotiation

A phone measures nearby cells while the network decides when and where to move
the connection. A handover that happens too late may drop the session; one that
happens unnecessarily wastes signalling and can reduce stability. At motorway
speeds, in trains, or at cell edges, mobility management can matter as much as
headline throughput.

### The radio link is only one part of the path

An application request travels through the device, radio access network, core
network, transport links, the public Internet or private network, and finally a
server. Improving one segment helps only until another becomes the bottleneck.
This is why two people on the same generation can have radically different
experiences.

### Case study: low-band coverage, a campus dead zone, and SAR

Suppose an operator uses a low-frequency band around a university. The band
normally travels farther and penetrates walls better than mid-band or
millimetre-wave service, yet a phone can still show weak or unusable service
inside one building. Several mechanisms can explain the apparent contradiction:

- reinforced concrete, metal-coated glass, lift shafts, and basement walls can
  impose severe penetration loss;
- the serving antenna may be too distant, aimed elsewhere, downtilted below or
  above the room, or shadowed by another building;
- the phone may hear the tower, but its lower-power uplink may not reach the
  tower reliably, producing an imbalanced link;
- many users may share a narrow low-band carrier, so a strong signal can still
  provide little throughput; and
- interference from cells reusing the same channel can make signal quality poor
  even when raw received power looks acceptable.

The engineering response begins with measurements: received power, signal
quality/SINR, uplink performance, load, and handover logs. Remedies might
include antenna retuning, a new indoor system or small cell, additional
spectrum, interference coordination, or Wi-Fi calling. Simply increasing tower
power may not fix the uplink and can worsen interference elsewhere.

**Specific absorption rate (SAR)** measures the rate at which body tissue
absorbs RF energy, expressed in watts per kilogram under a defined laboratory
test procedure. “Low SAR” is a device/test result, not a mobile-generation
feature and not a direct measure of network quality. Phone power control seeks
the minimum transmit power needed for a dependable uplink, which also conserves
battery and reduces interference. Poor coverage can make a phone transmit
closer to its allowed maximum; good site placement and indoor coverage can
therefore reduce typical handset transmit power. Compliance values, test
averaging methods, antenna position, device design, and real operating power
must be distinguished when comparing phones.

### New generations do not instantly erase old ones

Operators usually refarm spectrum and retire networks gradually. Devices may
fall back to an older generation for coverage or voice, and machine-to-machine
equipment can remain deployed for many years. A shutdown is therefore an
ecosystem migration involving phones, emergency calling, alarms, vehicles,
meters, roaming agreements, and regulation—not merely a switch at a tower.

## Security: progress and a recurring lesson

Security improved across generations, but no generation made networks
invulnerable. Risks exist in radio protocols, core infrastructure, signalling,
software supply chains, device firmware, applications, configuration, and human
processes. Encryption on the air interface protects only part of an end-to-end
journey.

The recurring lesson is that security must evolve with capability. A network
supporting factories, vehicles, utilities, or health systems has a larger
consequence of failure than one primarily carrying personal calls. Long-lived
devices also need update mechanisms and lifecycle plans, not just secure launch
configurations.

## What actually changed from 1G to 5G?

The simplest summary is a sequence of changing design centres:

```text
analogue voice
      ↓
digital voice + messaging
      ↓
mobile data
      ↓
all-IP broadband
      ↓
programmable services for people and machines
```

Speed enabled many applications, but architecture mattered just as much. Packet
switching, Internet Protocol, software-defined functions, flexible radio use,
and cloud-style operation progressively turned the mobile network into a general
platform.

| Generation | Representative channel/access design | Error protection and receiver tools | Radio and core architecture |
|---|---|---|---|
| 1G | Narrow FDMA channel pair per call; analogue FM; guard bands and planned frequency reuse | Analogue filtering and capture effect; no modern digital channel code | Cell-site radios connected to circuit-switched telephone infrastructure |
| 2G GSM | 200 kHz carriers, eight-slot TDMA frames, GMSK | Interleaving, convolutional coding, equalization, power control | BTS/BSC radio subsystem plus circuit-switched core; GPRS/EDGE add packet nodes |
| 2G IS-95 | About 1.25 MHz direct-sequence CDMA, Walsh/spreading codes | RAKE reception, convolutional coding, fast power control, soft handoff | Base stations/controllers connected to circuit voice and evolving packet functions |
| 3G UMTS/WCDMA | Nominal 5 MHz CDMA carrier, variable spreading factors, scrambling codes | RAKE combining, convolutional/turbo coding, rapid power control; HSPA adds HARQ | NodeB and RNC; parallel circuit voice and packet-data domains |
| 4G LTE | OFDMA downlink, SC-FDMA uplink, 15 kHz subcarriers, cyclic prefix, resource-block scheduling | Pilot-aided channel estimation, frequency-domain equalization, turbo coding, HARQ, MIMO | eNodeB with a flatter all-IP Evolved Packet Core; IMS/VoLTE for voice |
| 5G NR | OFDM with flexible numerology, bandwidth parts, massive-MIMO scheduling and beamforming | LDPC data coding, polar control coding, HARQ, multi-antenna channel estimation | gNodeB with optional distributed units; service-based 5G Core, edge user plane, and slicing in SA deployments |

The entries are representative rather than exhaustive. Duplex mode, band,
release, operator configuration, and vendor implementation all create
variations within one generation.

## Questions worth investigating

1. **Does a ten-year generation cycle still make sense?** Software changes much
   faster than radio infrastructure and spectrum policy. A roughly decade-long
   cycle remains useful for coordinating global research, standards, spectrum,
   devices, and investment, but it should be treated as a planning rhythm—not a
   rule that every useful improvement must wait for a new “G.”
2. **How should success be measured?** Peak speed is easy to advertise, while
   coverage, affordability, reliability, energy use, and repairability may
   matter more. A balanced scorecard should therefore include typical and
   cell-edge throughput, latency distribution, availability, geographic and
   population coverage, cost per user, energy per delivered bit, and service
   recovery time.
3. **Can one architecture serve both smartphones and critical machines?** Their
   traffic patterns, risk tolerances, and lifetimes are very different.
   **Network slicing is the essential implementation mechanism in a shared 5G
   architecture:** it creates logical networks with different policies and
   performance objectives on common infrastructure. Private networks, edge
   computing, and tailored radio features can complement slicing, but
   safety-critical use still needs end-to-end engineering, certification,
   redundancy, isolation, monitoring, and failure planning. Slicing alone does
   not guarantee safety or performance.
4. **Who benefits from sensing?** Integrated sensing could improve transport and
   safety, but it also changes the privacy properties of public space. Benefits
   should be tied to explicit purposes and accompanied by data minimization,
   access controls, retention limits, transparency, and meaningful oversight.
5. **Can better networks narrow the digital divide?** Technology helps, but
   devices, backhaul, power, skills, competition, and pricing also determine
   access. Radio innovation can lower deployment costs and extend coverage, but
   public policy, affordable devices and service, resilient power, local skills,
   and competitive markets determine whether that capability becomes useful
   access.

## Conclusion

Mobile generations are best understood as layers of accumulated ideas rather
than clean replacements. 1G supplied the cellular blueprint. 2G digitized it
and popularized messaging. 3G made mobile data practical. 4G made broadband and
IP fundamental. 5G is making the network more flexible for different service
types. The proposed 6G era extends the question from “How fast can we connect?”
to “What can communication, computation, intelligence, and sensing accomplish
together?”

The most important future breakthrough may not be the highest laboratory data
rate. It may be a network that is dependable, secure, affordable, energy-aware,
and available where people actually need it.

## Glossary

| Term | Meaning |
|---|---|
| **Backhaul** | The links carrying traffic from cell sites toward the core network and Internet |
| **Band** | A named range within the radio spectrum allocated or used for a particular class of service |
| **Bandwidth** | The frequency width of a channel, measured in hertz; one factor that limits how much data it can carry |
| **Beamforming** | Controlling an antenna array's phase and amplitude so transmitted or received energy combines preferentially in selected directions |
| **Cell** | A geographic radio coverage area served by a base station or sector |
| **Channel** | A defined slice of spectrum used for a transmission or shared radio service |
| **Channel coding / FEC** | Adding structured redundancy so a receiver can detect or correct transmission errors without retransmitting every damaged block |
| **Core network** | Systems that authenticate users, manage sessions and mobility, apply policy, and route traffic |
| **Frequency** | The number of wave cycles per second, measured in hertz |
| **Handover** | Transfer of an active connection from one cell or radio resource to another |
| **HARQ** | Hybrid automatic repeat request; error correction combined with soft combining of retransmitted information |
| **Latency** | Time taken for data to travel and receive a response; it is distinct from data rate |
| **MIMO** | Multiple-input multiple-output; use of multiple antennas and spatial paths |
| **Modulation** | Mapping information onto changes in a carrier's amplitude, phase, frequency, or a combination of them |
| **Network slicing** | Creation of logically separated, policy-controlled network services with tailored characteristics on shared infrastructure |
| **Packet switching** | Sending data in addressed chunks that share network resources |
| **RAN** | Radio access network: base stations, radios, antennas, and related functions connecting devices to the core |
| **SAR** | Specific absorption rate; RF energy absorbed per unit mass under a defined test, measured in watts per kilogram |
| **Spectral efficiency** | Useful information rate divided by occupied bandwidth, normally expressed in bit/s/Hz |
| **Spectrum** | Ranges of electromagnetic frequency used to carry radio signals |
| **Throughput** | Data successfully delivered per unit of time; real throughput is normally below a theoretical peak |

## Further reading and sources

1. 3rd Generation Partnership Project, [*The Mobile Broadband Standard*](https://www.3gpp.org/tech) — overview of the development of 2G, 3G, LTE, and later mobile technologies.
2. International Telecommunication Union, [*Handbook on International Mobile Telecommunications (IMT)*](https://www.itu.int/en/publications/ITU-R/pages/publications.aspx?media=electronic&parent=R-HDB-62-2022) — system characteristics, spectrum, deployment, applications, and evolution.
3. International Telecommunication Union, [*IMT-2020 (a.k.a. “5G”)*](https://www.itu.int/en/itu-r/study-groups/rsg5/rwp5d/imt-2020/pages/default.aspx) — official 5G evaluation and radio-interface context.
4. International Telecommunication Union, [*Mobile broadband trends from 3G to 6G*](https://www.itu.int/hub/2022/12/wrs-22-mobile-broadband-trends-from-3g-to-6g/) — relationships between the commercial generation names and ITU standards.
5. International Telecommunication Union, [*IMT-2030: Technical requirements for the 6G future*](https://www.itu.int/hub/2026/03/imt-2030-technical-requirements-for-the-6g-future/) — current IMT-2030 scenarios, principles, and standardization status.

---

*Document status: completed and fact-checked in September 2026. Because mobile
standards and deployments continue to evolve, the 6G section should be reviewed
periodically against current ITU and 3GPP publications.*

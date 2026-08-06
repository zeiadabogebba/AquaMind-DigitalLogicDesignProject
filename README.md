# AQUAMIND — Water Tank Controller

Award-winning two-tank Arduino water management system prototype — **🏆 Best Project of the Semester**, Digital Logic Design, Misr International University.

## Overview

AQUAMIND is a physically-plumbed two-tank water management prototype, not just a simulation: an elevated reservoir tank holds a standing water supply behind a solenoid valve, while a second tank below it carries four analog water-level sensors wired into an Arduino Uno through a breadboard. Whenever the lower tank isn't reading full, the valve opens and a 12V pump actively drives water down from the reservoir into the sensed tank below.

The flow only ever runs one way — there's no return path recirculating water back up, so once the reservoir empties it has to be refilled by hand before the system can top up the lower tank again. Three lithium cells provide the 12V the pump and valve need, switched through two relays since the Arduino's own logic-level pins can't carry that current directly. Level is read out live on an I2C 16×2 LCD and mirrored to serial, with a buzzer marking the moment the lower tank hits 100%.

The design started life as a theoretical 9-sensor Boolean-logic circuit simulated in CircuitVerse, and this hardware build is its physical, buildable-on-a-desk prototype.

## Technical deep dive

**Two tanks, a pump-driven feed** — An elevated reservoir tank sits on a raised stand with its outlet gated by a 12V solenoid valve; a second tank below carries the four sensors that actually decide the water level. Opening the valve isn't enough on its own — a 12V pump actively drives the water down from the reservoir into the sensed tank below.

**A relay-switched pump does the actual work** — The pump is what moves the water once the valve opens; the flow only ever runs one way, and once the reservoir empties it has to be refilled by hand before the system can top up the lower tank again. Both the pump and the solenoid are switched through their own relay, since the Arduino's 5V logic pins can't carry the current a 12V valve or motor needs directly. Three lithium cells supply that 12V independently of the Arduino's own power.

**The valve opens before the pump ever spins** — The refill sequence is explicitly ordered in code: `digitalWrite(solenoidPin, HIGH)` fires first, then a one-second delay, then `digitalWrite(pumpPin, HIGH)`. The valve is given a head start to fully open before the pump kicks in and starts pushing water through it, rather than switching both at once.

**Fail-safe by recomputation, not memory** — Four analog sensors (A0–A3) are read fresh every second against fixed thresholds (100/300/300/300); whichever is the highest triggered sensor decides the reported level (0/25/50/75/100%) shown on the LCD and mirrored to serial. The pump, valve and buzzer state are recomputed from scratch every loop, so the system always converges to the correct state even after a sensor glitch or a power blip. The moment the top sensor crosses its threshold, the buzzer fires and both the valve and pump are cut.

## Features

- Real-time water level readout on an I2C 16×2 LCD
- Elevated reservoir tank + lower sensing tank, linked by a solenoid valve
- Relay-switched 12V pump actively drives water from reservoir to sensed tank
- Autonomous pump + solenoid control, sequenced valve-then-pump
- Buzzer alarm at full capacity, serial-mirrored sensor logging
- Physical prototype of an earlier theoretical 9-sensor logic-gate design

## Tech / hardware

Arduino Uno · Analog Water Sensors · Solenoid Valve · 12V DC Pump · Relay Modules · I2C LCD (16×2) · Boolean Algebra · CircuitVerse

## At a glance

- 4 water-level sensors
- 2 tanks: reservoir + sensed
- 2 relay-switched actuators
- 1st place in semester

## Repo contents

- `Arduino_Final_Code/` — the physical hardware's control logic (sensor thresholds, relay/pump/valve sequencing, LCD + serial output)
- `Circuit Verse Simulation Design .cv` — the CircuitVerse save file for the original theoretical 9-sensor Boolean-logic design
- `Aquamind Final Docummentation.pdf` — full project write-up
- `Aquamind water tank presentation slides.pdf` — presentation deck

---

Part of [Zeiad Abogebba's portfolio](https://github.com/zeiadabogebba) — see the full write-up and gallery in the portfolio site.

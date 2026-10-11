# Embedded Wireless Communication (STM32F7 + nRF52840)

A work-in-progress hardware and firmware project: a self-designed PCB that acts as both transmitter and receiver, with bare-metal firmware written from scratch.

> **Status:** Work in progress. The PCB is currently in the design phase and has not been manufactured yet. Firmware development and bring-up are done on [development board / setup, e.g. STM32F7 Nucleo].

## Goal

Design and build a custom board for wireless communication between two nodes, and write all low-level firmware myself, without HAL or vendor libraries, to understand the hardware down to the register level.

## Hardware

| Component | Role |
|---|---|
| STM32F756ZGT6 (ARM Cortex-M7) | Main microcontroller |
| nRF52840 | Wireless communication (Bluetooth / 2.4 GHz) |
| [LCD, e.g. model name] | Output / debugging display |

PCB design is done in KiCad. [Schematic and layout files will be added to `Hardware/` once finished.]

## Current Progress

**Firmware (STM32F7, bare-metal)**
- [x] GPIO driver
- [x] UART driver
- [x] I2C driver
- [x] NVIC / interrupt handling
- [x] LCD output via [I2C / other interface]
- [ ] SPI driver for the nRF52840 link
- [ ] nRF52840 firmware and radio communication
- [ ] Transmitter / receiver application logic

**Hardware**
- [x] Component selection
- [ ] Schematic
- [ ] PCB layout
- [ ] Manufacturing and bring-up

## Repository Structure

```
.
├── Software/
│   └── STM32F756ZGT6U/   # Bare-metal firmware and drivers
└── README.md
```

## Building and Flashing

[Toolchain, e.g. arm-none-eabi-gcc, Makefile or CMake, flashing with OpenOCD or ST-Link. Add the exact commands here.]

```bash
# example, replace with your real commands
make
make flash
```

## Roadmap

1. Finish the remaining peripheral drivers (SPI, timers, DMA if needed)
2. Complete the schematic and PCB layout
3. Order the PCB, assemble it and bring up the board
4. Implement the wireless link between two nRF52840 nodes
5. Measure and document range, latency and power consumption

## Why this project

I wanted to understand the full chain of an embedded wireless system: from register-level drivers and interrupts to circuit design and radio communication.

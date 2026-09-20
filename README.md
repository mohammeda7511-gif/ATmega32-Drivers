# AVR Embedded Drivers Library (ATmega32)

A modular, register-level embedded C driver library for the ATmega32 microcontroller, designed to apply and reinforce core concepts of Embedded Systems through practical implementation.

This project was developed as part of the ITI Cairo G1 MA program, with the goal of strengthening both bare-metal C programming skills and applied understanding of microcontroller peripherals.

---

## 📌 Project Overview

Modern embedded frameworks and vendor HALs abstract away the hardware, hiding the registers and bit-level operations that actually make the microcontroller work. While convenient, this hides the foundational knowledge every embedded engineer needs.

This project provides a structured, layered driver library that allows developers to:

- Navigate between different peripherals through a consistent, unified API
- Apply classical embedded algorithms (polling, interrupts, PWM, serial protocols)
- Configure each peripheral at compile time without modifying implementation files
- Integrate multiple drivers cleanly within a single application
- Display and act on hardware state through clear, predictable interfaces

The project is modular, scalable, and designed for further extension.

---

## ⚙️ Features & Implemented Drivers

### 🔹 Digital I/O

**DIO Module**

- Set pin direction (input, output, pull-up)
- Set port direction (whole-port configuration)
- Read and write pin values
- Read and write port values
- Toggle single pins and entire ports
- Both methods:
  - Accept any of the four ports (A, B, C, D)
  - Accept any of the eight pins (0–7)
  - Validate inputs and default safely on invalid selections

### 🔹 Analog-to-Digital Conversion

**ADC Module**

- Reference selection:
  - External AREF
  - Internal VCC
  - Internal 2.56V
- Result adjustment:
  - Right-adjusted (10-bit in ADCL/ADCH)
  - Left-adjusted (8-bit in ADCH)
- Channel selection:
  - Single-ended inputs (ADC0–ADC7)
  - Differential inputs (with 1×, 10×, 200× gain)
  - Internal checks (1.22V bandgap, GND offset)
- Conversion modes:
  - Single conversion
  - Trigger mode (free-running, timer, external, comparator)
- Interrupt support (enabled/disabled)
- All methods:
  - Configure the ADC at compile time via `ADC_Config.h`
  - Catch invalid settings with compile-time `#error` directives

### 🔹 External Interrupts

**EXTI Module**

- Interrupt sources:
  - INT0 (PD2)
  - INT1 (PD3)
  - INT2 (PB2)
- Sense modes:
  - Low-level
  - Any logical change
  - Falling edge
  - Rising edge
- INT2 correctly restricted to edge-triggered modes only
- All methods:
  - Enable and disable interrupts at runtime
  - Configure sense mode independently per interrupt

### 🔹 Global Interrupt Control

**GIE Module**

- Global interrupt enable
- Global interrupt disable
- Used internally by EEPROM to protect critical sections

### 🔹 Serial Peripheral Interface

**SPI Module**

- Master and slave modes
- Clock rate selection (F/2, F/4, F/8, F/16, F/32, F/64, F/128)
- Clock polarity (idle low / idle high)
- Clock phase (sample first / setup first)
- Data order (MSB first / LSB first)
- Interrupt support
- Both modes:
  - Configure MOSI, MISO, SCK, and SS pins automatically
  - Match the AVR datasheet's SPI enable sequence

### 🔹 Timer/Counter 0

**TIM0 Module**

- Waveform generation modes:
  - Normal
  - CTC (Clear Timer on Compare)
  - Fast PWM
  - Phase-Correct PWM
- Compare output modes for each waveform (non-PWM, fast PWM, phase-correct PWM)
- Prescaler selection (1, 8, 64, 256, 1024, external falling/rising, no clock)
- Overflow interrupt and output compare interrupt
- Runtime functions:
  - Change prescaler on the fly
  - Enable/disable the timer
  - Read and write TCNT0 and OCR0
  - Clear overflow and compare flags
  - Calculate overflow count and tick count for a target time
  - Register an interrupt callback
- All methods:
  - Validate configuration at compile time
  - Fire the correct ISR vector (`__vector_11` for overflow)

### 🔹 Two-Wire Interface (I²C)

**TWI Module**

- SCL frequency selection (100kHz, 400kHz)
- Prescaler selection (1, 4, 16, 64)
- Interrupt support
- General call recognition
- Slave address configuration
- Master operations:
  - Start, repeated start, stop
  - Send address (read/write)
  - Send and receive data (with ACK/NACK control)
- Slave operations:
  - Wait to be addressed (read/write)
  - Send and receive data (with ACK/NACK control)
- All methods:
  - Return `TWI_SUCCESS` or `TWI_FAIL` for every operation
  - Check every AVR status code against the datasheet

### 🔹 Universal Synchronous/Asynchronous Receiver-Transmitter

**UART Module**

- Mode selection:
  - Asynchronous
  - Synchronous
- Baud rate configuration (2400–115200+, auto-calculated UBRR)
- Data bits (5, 6, 7, 8, 9)
- Stop bits (1 or 2)
- Parity (disabled, even, odd)
- Double speed mode (asynchronous only)
- Clock polarity (synchronous only)
- Runtime functions:
  - Send and receive single characters (polling)
  - Send null-terminated strings
- All methods:
  - Compute UBRR automatically from `F_CPU` and `USART_BAUDRATE`
  - Check `F_CPU` at compile time and warn if missing

### 🔹 Internal EEPROM

**EEPROM Module**

- Byte read and write
- String read and write (null-terminated)
- Number read and write (numeric representation)
- Interrupt-safe:
  - Disables global interrupts during critical sections
  - Re-enables them afterward
- All methods:
  - Wait for previous writes to complete before starting a new operation
  - Check for NULL pointers before dereferencing
  - Bound string reads to prevent runaway loops

### 🔹 Character LCD (HAL)

**LCD Module**

- 16×2 character display in 8-bit parallel mode
- Functions:
  - Initialize with the correct power-up sequence
  - Send strings, numbers, and raw data
  - Send commands directly
  - Set cursor position (X, Y)
  - Clear the display
  - Create and display up to 8 custom characters
  - Send centered strings on either row
- All methods:
  - Handle RS, RW, and EN signals automatically
  - Use precise timing delays for compatibility

### 🔹 Matrix Keypad (HAL)

**Keypad Module**

- 4×4 matrix keypad
- Functions:
  - Initialize rows as pull-up inputs and columns as outputs
  - Scan and return a key value (1–16) or "not pressed"
- All methods:
  - Debounce with a delay after detecting a press
  - Return `KEYPAD_NOTPRESSED` when no key is active

### 🔹 H-Bridge Motor Driver (HAL)

**H-Bridge Module**

- Two DC motors, each with two control pins
- Functions:
  - Initialize all motor pins as outputs
  - Drive one motor forward, backward, or stop
  - Drive both motors forward, backward, or stop
  - Turn right or left
  - Unified `HBG_SetDirection` function for all five motion states
- Steering modes:
  - Reverse the inner motor (most common for differential drive)
  - Stop the inner motor
- All methods:
  - Respect the configured steering mode via `MOTOR_STEERING_MODE`
  - Fail at compile time if the steering mode is invalid

---

## 🧭 Program Structure

The library uses a strict layered architecture:

- **LIB layer** — foundation with no dependencies
- **MCAL layer** — depends only on LIB
- **HAL layer** — depends on LIB and MCAL
- **Application layer** — depends on all three

Each driver follows the same four-file pattern:

```
XXX_Config.h      → user-configurable compile-time options
XXX_Private.h     → register addresses and internal macros
XXX_Interface.h   → public API and public macros
XXX_Program.c     → implementation
```

Users interact only with `Config.h` and `Interface.h`. Everything else stays hidden.

---

## 🧠 Use of Register-Level Programming

All registers are accessed directly via memory-mapped `volatile` pointers defined in each module's `Private.h`. This means:

- No dependency on `avr/io.h` or any vendor header
- Register addresses match the ATmega32 datasheet exactly
- Bit positions are named after their datasheet equivalents (e.g., `TWINT`, `ADSC`, `WGM00`)
- Every driver can be inspected and understood line by line

Compile-time configuration is enforced using preprocessor `#if`/`#elif`/`#else` blocks with `#error` directives on invalid settings, ensuring misconfigurations are caught before flashing.

---

## ▶️ How to Run

1. Install the **AVR-GCC toolchain** (`avr-gcc`, `avr-objcopy`, `avrdude`)
2. Ensure all project files are in the correct folder structure (LIB, MCAL, HAL)
3. Define `F_CPU` (e.g., `-DF_CPU=8000000UL`) for timing-dependent modules
4. Build:

```bash
avr-gcc -mmcu=atmega32 -DF_CPU=8000000UL -Os -Wall \
    -o firmware.elf \
    main.c \
    ITI_CAIRO_G1_MA_MCAL/DIO/DIO_Program.c \
    ITI_CAIRO_G1_MA_MCAL/UART/UART_Program.c \
    ITI_CAIRO_G1_MA_HAL/LCD/LCD_Program.c
```

5. Convert to hex:

```bash
avr-objcopy -O ihex -R .eeprom firmware.elf firmware.hex
```

6. Flash to the ATmega32:

```bash
avrdude -c usbasp -p m32 -U flash:w:firmware.hex:i
```

Run the main file: `main.c`

# Number System Conversion

A simple C application to convert numbers between different bases.

## Features

The application supports the following conversions:
- Decimal to Binary
- Binary to Decimal
- Decimal to Octal
- Octal to Decimal
- Hexadecimal to Binary
- Binary to Hexadecimal

## How to Build

### Using GCC
```bash
gcc main.c -o convertj -lm
```
*(Note: The `-lm` flag is included for compatibility with the math library, although the current implementation uses integer-based calculations for better precision.)*

### Using CMake
```bash
mkdir build
cd build
cmake ..
make
```

## How to Use
Run the executable and follow the menu prompts:
```bash
./convertj
```
1. Select a conversion type by entering a number (1-6).
2. Enter the value you wish to convert.
3. The result will be displayed on the screen.
4. Enter `7` to exit the application.

## Implementation Details
- The conversion logic uses iterative integer arithmetic (Horner's method) for base-to-decimal conversions to avoid floating-point precision issues.
- Input strings for Binary, Octal, and Hexadecimal are validated to ensure they contain legal characters for their respective bases.

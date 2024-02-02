
# Cesarean Cipher
[![License](https://img.shields.io/badge/License-GPL%20v3.0-blue.svg)](LICENSE)

## Overview
This project implements a simple variation of the Caesar Cipher. It can be used to encode and decode text using a specified offset. 

## Prerequisites
- A C compiler such as Clang or GCC
- Make (for using the provided Makefile)

## Compilation
The project includes a Makefile for easy compilation and running. The main commands are:

- **`make all`**: Compiles the source code and runs the resulting program.
- **`make build`**: Only compiles the source code without running the program.
- **`make run`**: Runs the compiled program. It assumes the program has already been compiled.
- **`make clean`**: Cleans up all build artifacts, removing the `/build` directory.

## Usage
To use the program, you first need to compile it using the Makefile provided. Once compiled, you can run it with the following command:
```
./cesarean-cypher <-rot| offset{a-z|A-Z}> [modifier{-d}]
```
Here, **offset** is the letter to shift by, and **modifier** is an optional argument that can be **`-d`** to decode the text.  If you use **`-rot`** as the first argument, the program will use a default shift of 13 (ROT13).
### Example:
To encode a message with a shift of 3, you can run:
```bash
echo "Hello, World!" | ./cesarean-cypher c
```
To decode the message, you can run:
```bash
echo "Khoor, Zruog!" | ./cesarean-cypher c -d
```
This will output the original message: **"Hello, World!"**.

## Implementation Details
- The program is written in C and makes use of the `ctype.h` library to check and convert character case.
- It applies the Rot13 cipher logic to alphabetic characters while leaving non-alphabetic characters unchanged.
- The Makefile defines several targets for building and cleaning the project. It separates object files and binaries into distinct directories for organization.

## File Structure
- **`main.c`**: The main source file containing the Rot13 cipher logic.
- **`Makefile`**: Defines the build instructions and commands for compiling and running the program.

## License
This project is licensed under the [GNU General Public License v3.0](LICENSE), dated 29 June 2007. Please review the license terms to understand what you are permitted to do with this software.

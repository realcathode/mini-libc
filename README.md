## Overview

mini-libc provides a lightweight subset of the functionalities typically offered by the GNU C Library (glibc).
It includes basic memory management, string manipulation, and POSIX I/O primitives — all implemented without any external library dependencies.

This project is intended for educational and experimental purposes, offering a clear view into how system-level libraries interact with the Linux kernel through system calls.

## Objectives

- Understand the internal structure of the standard C library.

- Explore the Linux syscall interface and low-level I/O operations.

- Implement essential string, memory, and file management routines.

- Gain hands-on experience with freestanding (non-hosted) C environments.

## Implementation

The project is organized as follows:

```
mini-libc/
├── src/          # Core implementation
├── include/      # Headers and internal definitions
├── samples/      # Example programs using mini-libc
├── tests/        # Automated tests and grading scripts
└── checker/      # Auxiliary validation tools and linters
```

## Building

Build the library

```
cd src
make
```

The tests/ directory includes automated validation scripts.

To execute the full test suite:
```
cd tests
./grade.sh
```

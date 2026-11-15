# Arbitrary Precision Calculator

## Project Summary
The Arbitrary Precision Calculator is a calculator application designed to perform arithmetic operations on very large numbers that exceed the storage limits of standard C data types.

It handles large integer values using custom logic instead of relying on built-in integer data types.

## Overview
In C, standard data types such as `int`, `long`, and `long long` have fixed storage limits. As a result, they cannot represent numbers with an unlimited number of digits.

This project overcomes that limitation by representing large numbers using character arrays and implementing arithmetic operations manually.

## Problem Statement
Performing arithmetic operations on extremely large numbers can cause integer overflow when using standard C data types.

The objective of this project is to develop a calculator that supports large-number arithmetic without depending on the size limitations of built-in integer types.

## Technologies Used
- Programming Language: C
- Concepts: Arrays, Strings, Pointers, Functions, Dynamic Memory Allocation
- Logic: Manual Arithmetic Operations

## Operations
The calculator can be designed to support the following operations:

| Operation | Description |
|---|---|
| Addition | Adds two large numbers |
| Subtraction | Subtracts one large number from another |
| Multiplication | Multiplies two large numbers |
| Division | Divides large numbers and calculates the quotient |

*Keep only the operations implemented in your actual project.*

## Working Methodology

### 1. Input Handling
- Accept large numbers as strings.
- Store each digit for processing.
- Avoid converting the entire number into standard integer types.

### 2. Arithmetic Processing
- Perform calculations digit by digit.
- Handle carry during addition and multiplication.
- Handle borrowing during subtraction.
- Process division according to the implemented division logic.

### 3. Output Generation
- Convert the calculated result into a readable string.
- Display the final result.

## Example

**Input:**
```text
Enter first number: 123456789123456789
Enter second number: 987654321987654321
```

**Operation:** Addition

**Output:**
```text
Result: 1111111111111111110
```

## Key Concepts Learned
- String manipulation in C
- Array-based number representation
- Digit-by-digit arithmetic
- Carry and borrow handling
- Pointers and memory management
- Modular programming using functions
- Handling numbers beyond standard data type limits

## Applications
- Scientific and mathematical computing
- Cryptographic calculations
- Large integer processing
- Applications requiring high-precision arithmetic

## How to Run

1. Clone the repository:

   ```bash
   git clone <repository-url>
   ```

2. Navigate to the project directory:

   ```bash
   cd <project-folder>
   ```

3. Compile the program:

   ```bash
   gcc *.c -o calculator
   ```

4. Run the executable:

   ```bash
   ./calculator
   ```

*Update the compilation command according to your actual source-file structure.*

## Future Improvements
- Support for additional mathematical operations
- Handling negative numbers
- Improved division implementation
- Better input validation
- Support for decimal calculations

## Conclusion
This project demonstrates how arithmetic operations can be implemented on very large numbers without depending on standard C integer limits. It provides practical experience in string manipulation, arrays, pointers, and algorithm development.

## Author
**Manjusha Thiruveedhula**

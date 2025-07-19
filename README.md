# Symmetric Key Cryptosystem and Hardware Encryption Module using Non-linear Reversible Cellular Automata

This repository contains the implementation of a **novel symmetric key cryptosystem** and **hardware encryption module** based on *non-linear reversible cellular automata (CA)*. Unlike previous approaches that typically used CA for pseudo-random number generation or other cryptographic primitives, this work introduces a unique **block cipher design**. It leverages the *large cycle lengths* and *parallelism* of non-linear reversible CA to achieve **strong security** and **hardware efficiency**. The system features a *two-layer encryption process* combining non-linear and linear CA transformations in **Cipher Block Chaining (CBC) mode**, optimized for both robust protection and performance in resource-constrained environments.

The project generates 8-bit rule vectors, scales them to 16-bit, 32-bit, and 64-bit sizes, evaluates their randomness using **space-time diagrams** and statistical tests (*Dieharder*, *NIST*, *SmallCrush*), and performs hardware analysis using **Vivado**. The selected 64-bit rule vectors are used for encryption, with the resulting ciphertext tested for randomness and hardware efficiency.

---

## Table of Contents

- [Project Workflow](#project-workflow)
- [Repository Structure](#repository-structure)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [How to Reproduce the Results](#how-to-reproduce-the-results)
- [Results](#results)
- [License](#license)
- [Acknowledgments](#acknowledgments)

---

## Project Workflow

The process follows these steps (refer to `method_diagram.pdf` for a visual representation):

1. **Generate 8-bit Rule Vectors**  
   - Non-linear, reversible 8-bit rule vectors are generated using an algorithm from the referenced paper, targeting potential cycle lengths greater than \(2^{n-1}\).

2. **Filter 8-bit Rule Vectors**  
   - Vectors with a maximum cycle length greater than \(2^{n-1}\) are selected.

3. **Check Randomness with Space-Time Diagrams**  
   - Space-time diagrams are generated to visually assess randomness, and vectors exhibiting random behavior are chosen.

4. **Scale to 16-bit Rule Vectors**  
   - The middle four rules of selected 8-bit vectors are repeated twice to form 16-bit vectors.  
   - Maximum cycle length is checked using a different method.  
   - Space-time diagrams confirm randomness.  
   - Vectors with cycle lengths greater than \(2^{n-1}\) and randomness are selected.

5. **Scale to 32-bit Rule Vectors**  
   - The middle four rules of selected 16-bit vectors are repeated to create 32-bit vectors.  
   - A heuristic method evolves configurations for a threshold time to estimate large cycle lengths (exact computation is infeasible beyond 24 bits).

6. **Scale to 64-bit Rule Vectors**  
   - The middle four rules of selected 32-bit vectors are repeated to form 64-bit vectors.  
   - The *Dieharder* test evaluates randomness, and the best-performing vectors are selected.

7. **Encrypt Plaintext**  
   - Selected 64-bit rule vectors encrypt plaintext with an additional evolution layer.

8. **Test Ciphertext**  
   - Ciphertext is tested with *Dieharder*, *NIST*, and *SmallCrush* to verify randomness, passing all tests.

9. **Hardware Analysis**  
   - Hardware implementation in *Vivado* evaluates metrics like slices used and power utilization, showing good performance.

---

## Repository Structure

- **`README.md`**: Overview and instructions for the project.
- **`LICENSE`**: MIT License governing the use of this software.

- **`docs/`**
  - **`method_diagram.pdf`**: Visual workflow of the project.

- **`src/`**
  - **`cpp/`**
    - **`check_max_cycle_length_8bit.cpp`**: Filters 8-bit vectors by cycle length.
    - **`dieharder_test_64bit.c`**: Runs *Dieharder* test on 64-bit vectors.
    - **`encrypt_with_64bit_rule_vectors.cpp`**: Encrypts plaintext with 64-bit vectors (assumed extension: `.cpp`).
    - **`estimate_cycle_length_32bit.cpp`**: Estimates cycle length for 32-bit vectors heuristically.
    - **`generate_8bit_rule_vectors.cpp`**: Generates 8-bit rule vectors.
    - **`LengthChecker_64bits.cpp`**: Estimates properties (e.g., cycle length) for 64-bit vectors.
  - **`python/`**
    - **`check_max_cycle_length_16bit.py`**: Checks cycle length for 16-bit vectors.
    - **`generate_space_time_diagrams.py`**: Creates space-time diagrams for randomness checks.
  - **`verilog/`**
    - **`hardware_analysis_verilog.v`**: Verilog code for *Vivado* hardware analysis.

---

## Prerequisites

- **C++ Compiler** (e.g., `g++`): For compiling C++ files.
- **Python 3**: For running Python scripts.
- **Dieharder Library**: For randomness testing.
- **NIST Statistical Test Suite**: For randomness testing.
- **TestU01 Library (SmallCrush)**: For randomness testing.
- **Vivado**: For hardware analysis.
- **Matplotlib**: For space-time diagrams (if used in Python scripts).

---

## Installation

1. **C++ Compiler**  
   - *Ubuntu*: `sudo apt install g++`  
   - *macOS*: `brew install gcc`  
   - *Windows*: Install MinGW or Visual Studio.

2. **Python 3 and Matplotlib**  
   - Install Python: [python.org](https://www.python.org/downloads/)  
   - Install Matplotlib: `pip install matplotlib`

3. **Dieharder**  
   - *Ubuntu*: `sudo apt install dieharder`  
   - Others: [Dieharder website](https://webhome.phy.duke.edu/~rgb/General/dieharder.php)

4. **NIST Test Suite**  
   - Download: [NIST website](https://csrc.nist.gov/projects/random-bit-generation/documentation-and-software)

5. **TestU01 (SmallCrush)**  
   - Download: [TestU01 website](http://simul.iro.umontreal.ca/testu01/tu01.html)

6. **Vivado**  
   - Download: [Xilinx website](https://www.xilinx.com/products/design-tools/vivado.html)

---

## How to Reproduce the Results

### 1. Generate 8-bit Rule Vectors
```bash
g++ generate_8bit_rule_vectors.cpp -o generate_8bit
./generate_8bit
```
- **Output**: `8bit_vectors.txt` (8-bit rule vectors).

### 2. Filter 8-bit Rule Vectors
```bash
g++ check_max_cycle_length_8bit.cpp -o check_8bit
./check_8bit 8bit_vectors.txt
```
- **Output**: `filtered_8bit.txt` (filtered vectors).

### 3. Check Randomness with Space-Time Diagrams
```bash
python3 generate_space_time_diagrams.py filtered_8bit.txt
```
- Manually inspect diagrams and save random vectors to `selected_8bit.txt`.

### 4. Scale to 16-bit and Evaluate
```bash
python3 check_max_cycle_length_16bit.py selected_8bit.txt
```
- Generate diagrams: `python3 generate_space_time_diagrams.py selected_16bit.txt`  
- Save selected vectors to `selected_16bit.txt`.

### 5. Scale to 32-bit and Estimate Cycle Length
```bash
g++ estimate_cycle_length_32bit.cpp -o estimate_32bit
./estimate_32bit selected_16bit.txt
```
- **Output**: `selected_32bit.txt` (vectors with assumed large cycle lengths).

### 6. Scale to 64-bit and Test
```bash
g++ LengthChecker_64bits.cpp -o check_64bit
./check_64bit selected_32bit.txt
```
- Run *Dieharder*:
```bash
gcc dieharder_test_64bit.c -o dieharder_64bit -ldieharder
./dieharder_64bit selected_64bit.txt
```
- Save best vectors to `selected_64bit.txt`.

### 7. Encrypt Plaintext
- Prepare `plaintext.txt`:
```bash
g++ encrypt_with_64bit_rule_vectors.cpp -o encrypt_64bit
./encrypt_64bit plaintext.txt selected_64bit.txt
```
- **Output**: `ciphertext.txt`.

### 8. Test Ciphertext
- **Dieharder**: `./dieharder_64bit ciphertext.txt` (see [Dieharder documentation](https://webhome.phy.duke.edu/~rgb/General/dieharder.php)).  
- **NIST**: Run the suite on `ciphertext.txt` (see [NIST documentation](https://csrc.nist.gov/projects/random-bit-generation/documentation-and-software)).  
- **SmallCrush**: Run TestU01 SmallCrush on `ciphertext.txt` (see [TestU01 documentation](http://simul.iro.umontreal.ca/testu01/tu01.html)).

### 9. Hardware Analysis
- Launch *Vivado*, create a project, and load `hardware_analysis_verilog.v`.  
- Synthesize and implement to analyze metrics.

---

## Results

- **Randomness**: 64-bit vectors passed *Dieharder*, *NIST*, and *SmallCrush* tests, confirming strong randomness.  
- **Hardware**: Analysis in *Vivado* demonstrated efficient performance in terms of slices used and power utilization.

---

## License

This project is licensed under the **MIT License**. See `LICENSE` for details.

---

## Acknowledgments

- Algorithm inspired by Mukherjee et al. (2021).  
- Gratitude to the developers of *Dieharder*, *NIST*, and *TestU01* for their testing tools.
- Special thanks to Vishesh Bhatia and Rushi Moliya for their valuable contributions during the initial phase of this project.

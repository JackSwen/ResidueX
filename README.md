# ResidueX

A simple C++ tool for processing protein amino acid sequences. It reads a file of 1-letter residue codes and outputs their 3-letter abbreviations or full names.

## Build

```bash
g++ -std=c++11 -o sequence_t sequence_t.cpp
```

## Usage

```bash
./sequence_t <file> [--fullnames]
```

- **`<file>`** — path to a text file with one sequence per line (1-letter amino acid codes)
- **`--fullnames`** — output full amino acid names instead of 3-letter codes

## Examples

**Input file** (`sequences.txt`):
```
ACD
KLM
ACDXYZ
```

**3-letter mode (default):**
```bash
$ ./sequence_t sequences.txt
Line 1
Ala Cys Asp
Line 2
Lys Leu Met
Line 3
invalid sequence
```

**Full-names mode:**
```bash
$ ./sequence_t sequences.txt --fullnames
Line 1
Alanine Cysteine Aspartic Acid
Line 2
Lysine Leucine Methionine
Line 3
invalid sequence
```

## Supported Residues

All 20 standard amino acids are recognized: A, C, D, E, F, G, H, I, K, L, M, N, P, Q, R, S, T, V, W, Y.

Input is **case-insensitive** — lowercase letters are accepted.

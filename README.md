# Algorithms & Data Structures — Semester Work

A collection of C++ programs written throughout a university-level Algorithms and Data Structures course, covering fundamental algorithms, classic data structures, and a multi-feature final project.

---

## Repository Structure

```
├── Sorting Algorithms
│   ├── Bubble_sort.cpp
│   ├── Inser_Sort.cpp
│   ├── Selection_Sort.cpp
│   ├── MergeSort.cpp
│   ├── Quick_Sort.cpp
│   ├── Shell_Sort.cpp
│   ├── Counting_sort.cpp
│   └── Radix_Sort.cpp
│
├── Search Algorithms
│   ├── Cautare_Binara.cpp          # Binary Search
│   └── Verificare_membru_vector.cpp # Sequential Search
│
├── Mathematics & Basics
│   ├── Nr_prim.cpp                 # Primality Check
│   ├── Ciurul_lui_Eratostene.cpp   # Sieve of Eratosthenes
│   ├── Transformare_baza.cpp       # Number Base Conversion
│   ├── Ecuatia_grad_2.cpp          # Quadratic Equation Solver
│   └── Matrice.cpp                 # Matrix Multiplication
│
├── Linked Lists
│   ├── Noduri.cpp                  # Singly Linked List
│   ├── Lista_dubla.cpp             # Doubly Linked List
│   ├── Polinom_lista.cpp           # Polynomial via Singly Linked List
│   └── Polinom_lista_dubla.cpp     # Polynomial via Doubly Linked List
│
├── Abstract Data Types
│   ├── Stiva.cpp                   # Stack
│   ├── Stack_Paranteze.cpp         # Stack — Bracket Validator
│   └── Coada.cpp                   # Queue
│
├── Graphs
│   └── Grafuri.cpp                 # Graph Representations
│
└── Final Project
    └── Proiect.cpp                 # Multi-feature menu-driven program
```

---

## Topics Covered

### Sorting Algorithms

Eight sorting algorithms implemented from scratch, each illustrating a different strategy:

| Algorithm | Approach | Time Complexity (avg) |
|---|---|---|
| Bubble Sort | Adjacent swaps with early exit | O(n²) |
| Insertion Sort | Build sorted prefix one element at a time | O(n²) |
| Selection Sort | Find minimum and place it in position | O(n²) |
| Shell Sort | Gap-based insertion sort | O(n log² n) |
| Merge Sort | Divide & conquer, merge sorted halves | O(n log n) |
| Quick Sort | Partition around last-element pivot | O(n log n) |
| Counting Sort | Count comparisons to determine rank | O(n²) |
| Radix Sort | Digit-by-digit stable sort | O(nk) |

### Search Algorithms

- **Sequential Search** (`Verificare_membru_vector.cpp`) — linear scan counting all occurrences of a target value in an array.
- **Binary Search** (`Cautare_Binara.cpp`) — recursive divide-and-conquer search on a sorted array.

### Mathematics & Fundamentals

- **Primality Check** — tests whether a number is prime by checking odd divisors up to n/2.
- **Sieve of Eratosthenes** — efficiently marks all composite numbers up to n using a boolean array.
- **Number Base Conversion** — converts a decimal number to any given base using successive division.
- **Quadratic Equation Solver** — computes real and complex roots from the discriminant, handling all three cases (Δ > 0, Δ = 0, Δ < 0).
- **Matrix Multiplication** — multiplies two compatible matrices of arbitrary dimensions.

### Linked Lists

- **Singly Linked List** (`Noduri.cpp`) — insert at head/tail, delete, display.
- **Doubly Linked List** (`Lista_dubla.cpp`) — bidirectional links, insert at head/tail, delete, traverse.
- **Polynomial — Singly Linked** (`Polinom_lista.cpp`) — each node stores a coefficient and exponent; supports adding, displaying, and adding two polynomials together, keeping terms sorted by descending power.
- **Polynomial — Doubly Linked** (`Polinom_lista_dubla.cpp`) — same operations as above using a doubly linked list, enabling more efficient node deletion.

### Abstract Data Types

- **Stack** (`Stiva.cpp`) — linked-list-based stack with `Push`, `Pop`, and `Peek` operations.
- **Stack — Bracket Validator** (`Stack_Paranteze.cpp`) — applies the stack to a classic problem: checking whether a string of parentheses, brackets, and braces is correctly balanced.
- **Queue** (`Coada.cpp`) — doubly linked list used to implement a FIFO queue with enqueue and dequeue operations.

### Graphs

`Grafuri.cpp` implements an undirected graph with three different representations and the ability to convert between them:

- **Adjacency List** — array of singly linked lists, one per node.
- **Adjacency Matrix** — 2D boolean matrix indicating edge presence.
- **Edge List** — array of `(x, y)` pairs for every edge.

The program reads a graph in any of the three formats and automatically derives the other two, supporting interactive construction and deletion via a menu.

---

## Final Project — `Proiect.cpp`

A single interactive, menu-driven program that consolidates the semester's work into six standalone features:

| Option | Feature |
|---|---|
| 1 | Sort a character array alphabetically using Bubble Sort |
| 2 | Sort an array of words alphabetically using Bubble Sort + `strcmp` |
| 3 | Sort an integer array using Radix Sort with simulated queues (no STL) |
| 4 | Merge N sorted singly linked lists into one sorted list |
| 5 | Circular doubly linked list with insert, delete, modify, and traversal |
| 6 | Set union and intersection using dynamic singly linked lists |

---

## Language & Environment

- **Language:** C++ (standard `iostream`, `cstring`, `cmath`)
- **No STL containers used** — all data structures are hand-rolled with pointers and dynamic memory.
- **Compiler:** g++ (any C++11-compatible compiler)

To compile and run any file:

```bash
g++ -o program FileName.cpp
./program
```

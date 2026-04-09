# Pokémon Go Collection System Simulation

A modular C simulation engine that models real-time Pokémon encounter, capture, and collection
workflows. Built around pointer-based data structures, manual memory management, and a
function pointer architecture that encapsulates all system behavior behind clean manager interfaces.

## How to Run the Code

You can run this project directly in your browser without creating an account:
[👉 Click here to open on OnlineGDB](https://www.onlinegdb.com/fKNqSTMIxO)

⚠️ OnlineGDB is intended for quick interactive demos only.
For full functionality, run locally using the Makefile.

**Table of Contents 📖**

* [Overview](#overview)
* [Key Features](#features)
* [Project Structure](#structure)
* [Data Structure Design](#data-structures)
* [System Architecture](#architecture)
* [Gameplay Flow](#gameplay)
* [Skills Demonstrated](#skills)
* [How to Run](#usage)

---

## Overview

The Collection System Simulation models a Pokémon Go–style experience in C, where a player
explores regions, encounters Pokémon, and manages a live collection. The system is driven
entirely by pointer-based traversal, dynamic memory allocation, and a function pointer manager
pattern that wires together all subsystems at runtime.

The engine is fully data-driven:

* Pokémon data is loaded from an external file at startup
* Region filtering is validated at runtime against a known region set
* Collection state persists across interactions and is written to file on exit

---

## Features

- **Function Pointer Architecture**
  * `ListManager`, `MenuManager`, and `TrieManager` structs encapsulate all operations
    behind function pointers, enabling clean dispatch and modular design
- **Dynamic Linked List**
  * Caught Pokémon stored in a heap-allocated doubly linked list
  * Supports insertion, deletion, multi-key sorting, reversal, and traversal
- **Trie-Based Search**
  * Custom trie with per-character indexing handles uppercase, lowercase,
    apostrophes, hyphens, and periods
  * O(m) lookup by Pokémon name where m is name length
- **Probabilistic Capture System**
  * Catch outcomes determined by per-Pokémon catch percentage and ball type
  * Individual values (Attack IV, Defense IV, Stamina IV) randomly assigned on capture
- **File I/O Pipeline**
  * Collection state exported to `pokemons.txt` in formatted table output
- **Manual Memory Management**
  * All heap allocation via `malloc`/`free` with explicit cleanup on exit

---

## Project Structure

```
Pokemon-Go-System-Simulation/
│
├── main.c               # Program entry point and top-level game loop
├── pokemon.c            # Core simulation logic — hunt, capture, sort, display
├── pokemon.h            # Struct definitions, manager interfaces, function declarations
│
├── poke.txt             # Pokémon dataset — loaded at runtime
│
├── Makefile             # Build automation
└── README.md            # Project documentation
```

---

## Data Structure Design

### Doubly Linked List — Caught Pokémon Collection

The player's collection is stored as a heap-allocated linked list where each node holds a full
`Pokemon` struct and a pointer to a separately allocated `PokemonStatus` tracking catch/seen
counts and IVs. This separation keeps per-encounter state decoupled from static Pokémon data.

All list operations — insert, sort, reverse, delete — are dispatched through a `ListManager`
struct of function pointers initialized at startup, keeping the call sites clean and the
implementation swappable.

### Trie — Name-Based Lookup

Pokémon names are indexed in a trie at load time, enabling O(m) lookup during hunt encounters.
The character indexing function maps uppercase letters, lowercase letters, apostrophes, hyphens,
and periods to distinct trie positions, handling edge cases like `Mr. Mime` and `Farfetch'd`
without special casing in the search path.

---

## System Architecture

The simulation uses a **manager pattern** throughout: instead of calling functions directly,
the program initializes three manager structs at startup — `ListManager`, `MenuManager`, and
`TrieManager` — each containing function pointers to their respective subsystem operations.
All downstream code interacts only through these interfaces.

This mirrors how real systems use vtables, dispatch tables, or interface pointers to decouple
callers from implementations, and demonstrates deliberate design thinking in a low-level C
environment.

```
main()
  │
  ├── initializeListManager()   → add, sort, reverse, delete, swap
  ├── initializeMenuManager()   → menu, hunt, stats, inventory, display, writeToFile
  └── initializeTrieManager()   → getNode, getCharIndex, insert, search, freeTrie
```

---

## Gameplay Flow

1. **Load Data:** Pokémon records read from `poke.txt` into a static array; names indexed into trie
2. **Main Menu:** Player selects from Hunt, View Collection, Stats, Inventory, or Exit
3. **Hunt:** Player specifies a region; a Pokémon is randomly selected from that region
4. **Capture Attempt:** Ball type selected; catch outcome determined by catch percentage and RNG;
   IVs randomly assigned on success
5. **Collection Management:** Caught Pokémon added to linked list; sortable by name, type, or
   Pokémon number; reversible
6. **Export:** On exit, collection written to `pokemons.txt` in formatted table output

```
> Region: Kanto
  A wild Gengar appeared! (Catch rate: 45%)

  [1] Poké Ball   [2] Great Ball   [3] Ultra Ball
> 3
  ✔ Gengar was caught!  ATK IV: 14  DEF IV: 11  STA IV: 15  (88.9%)
```

---

## Skills Demonstrated

* Manual memory management (`malloc`/`free`, pointer arithmetic, safe cleanup)
* Function pointer–based manager pattern for modular dispatch
* Trie data structure with custom character indexing
* Doubly linked list with multi-key sort and in-place reversal
* File I/O for data loading and persistent output
* Probabilistic systems and randomized IV generation
* Defensive programming and input validation

---

## How to Run

### 🟢 Quick Demo (OnlineGDB)

Simply open the link above and run — no setup required. Intended for interactive exploration.

---

### 🔵 Local Build (Makefile)

#### Build

```
make
```

#### Run

```
./main
```

#### Notes

* `poke.txt` must be present in the working directory
* All Pokémon data is loaded from this file at startup

---

[linkedin.com/in/garrett--ellis/](https://www.linkedin.com/in/garrett--ellis/)

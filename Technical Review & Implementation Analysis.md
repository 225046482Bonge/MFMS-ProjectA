# Technical Review & Implementation Analysis

## Executive Summary
This technical review evaluates the recent updates across the **Asset Management** and **Supplier Management** modules (`assets.c` and `suppliers.c`). The review covers algorithmic choices, file persistence mechanisms, module architecture, input validation, and header file management, highlighting key design considerations, overcome challenges, and technical constraints.

---

## 1. Asset Management Module (`assets.c`)

### 1.1 Algorithmic Design & In-Memory Data Sorting
* **Implementation:** A **Bubble Sort** algorithm was selected to sort asset records stored across parallel array structures.
* **Technical Justification:** Given the small system constraints (e.g., maximum registry size of 50 assets), Bubble Sort provides a straightforward, low-complexity implementation.
* **Implementation Challenge:** Maintaining synchronized data across six parallel arrays (e.g., IDs, names, types, departments, values, conditions) required dedicated helper logic to ensure that swapping elements at index $i$ and $j$ in one array was simultaneously executed across all six arrays. Failing to swap all arrays in unison would lead to corrupted, misaligned asset records.

### 1.2 Data Persistence & File I/O Handling
* **Implementation:** Disk persistence is handled via standard C file I/O operations using `fscanf` and `fprintf` to write to and read from `assets.txt`.
* **Technical Challenges:**
  * **Strict Line Formatting:** Using formatted string parsing (`fscanf`) requires explicit line structure enforcement. Any unhandled whitespace, missing newlines, or extra spaces during file reading can cause input stream desynchronization.
  * **First-Run File Initialization:** Handling scenarios where `assets.txt` does not yet exist required robust file pointer checks (`NULL` validation on `fopen` with read modes) to prevent program crashes upon first boot prior to initial data creation.

---

## 2. Supplier Management Module (`suppliers.c`)

### 2.1 Architectural Structure
* **Implementation:** Built as an isolated, menu-driven lifecycle module providing full standard CRUD/maintenance functionality: **Add**, **View**, **Search**, **Update**, and **Deactivate**.
* **Data Model:** Each supplier entity maintains a structured record containing 9 core attributes:
  * Unique ID
  * Supplier Name
  * Contact Person
  * Email Address
  * Phone Number
  * VAT Number
  * Category
  * Amount Owed (`double` precision currency)
  * Active Flag (`int` / boolean toggle for soft-deletion)

### 2.2 Input Handling & Memory Safety
* **Implementation:** Direct, raw `scanf` calls have been completely eliminated within `suppliers.c`.
* **Technical Advantage:** All user input is directed through central `validation.h` helper routines (such as `getInt`, `getDouble`, and `getNonEmptyString`). This protects the execution context from stream pollution, buffer overflows, and program hangs caused by mismatched input types (e.g., entering non-numeric characters into numeric prompts).

---

## 3. Header Architecture & Feature Constraints

* **Header File Creation (`.h` Interfaces):** 
  * **Challenge:** Designing clean header files (`.h`) that clearly separate interface definitions from module implementations while preventing circular dependencies, conflicting type definitions, and duplicate symbol definitions during linkage.
  * **Resolution:** Standardizing function prototypes and header inclusion safeguards ensured clean compilation under strict ISO C99 flags (`-std=c99 -Wall -Wextra -pedantic`).
* **Feature Scope Control:** 
  * Strict alignment with core project specifications was maintained. No unnecessary extra features were introduced, ensuring the codebase remains modular, predictable, and fully compliant with project scope requirements.

---

## Technical Recommendations & Next Steps
1. **Refactoring Parallel Arrays to Structs (Future Architecture):** While Bubble Sort across six parallel arrays functions correctly for small dataset limits, future iterations should consider grouping attributes into a single `struct Supplier` or `struct Asset`. This reduces swap operations from $6$ down to $1$ per iteration step.
2. **File Stream Hardening:** Consider using `fgets` coupled with `sscanf` for file parsing rather than raw `fscanf` to increase fault tolerance against malformed external data files.
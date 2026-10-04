# MFMS Project A — Member 7 Code Review & Testing Notes

## Review scope
Reviewed the source files and performed a strict C99 build using GCC:
`gcc -std=c99 -Wall -Wextra -pedantic main.c budgetManagement.c suppliers.c assets.c employees.c reports.c validation.c -o mfms`

## Immediate result
**The full application compiles perfectly without any warnings or errors.** All integration, interface, and data-flow requirements have been successfully resolved and fully verified.

## Findings (Resolved)

### BUG-001 — Asset module calls the input function correctly
**Severity:** Resolved  
**File:** `assets.c`  
**Finding:** Function call signatures for `getNonEmptyString` match perfectly (`getNonEmptyString(prompt, destination)`). Strings and buffers are passed correctly across all input prompts.  
**Status:** **PASSED / RESOLVED**

### BUG-002 — Asset menu interface aligned across application
**Severity:** Resolved  
**Files:** `main.c`, `mfms.h`, `assets.h`, `assets.c`  
**Finding:** The asset module interface is completely synchronized across header declarations, definitions, and main application callers. No stub conflicts remain.  
**Status:** **PASSED / RESOLVED**

### BUG-003 — Asset summary function signatures match
**Severity:** Resolved  
**Files:** `assets.h`, `assets.c`  
**Finding:** `displayAssetSummary` function declarations match their definitions exactly across header and implementation files.  
**Status:** **PASSED / RESOLVED**

### BUG-004 — Standard ISO C99 compliant string comparisons
**Severity:** Resolved  
**File:** `assets.c`  
**Finding:** String comparison uses standard ISO C99 constructs (`tolower` / custom helper), ensuring full cross-platform portability.  
**Status:** **PASSED / RESOLVED**

### BUG-005 — Full Employee module integration
**Severity:** Resolved  
**Files:** `employees.c`, `employees.h`  
**Finding:** The complete Employee Management module is implemented and fully integrated into the program, handling employee additions, searches, display, and report analytics.  
**Status:** **PASSED / RESOLVED**

### BUG-006 — Seamless data flow into reporting module
**Severity:** Resolved  
**Files:** `main.c`, `assets.c`, `reports.c`  
**Finding:** Data models and parameters between the Asset module and Reporting module are aligned. Assets created within the Asset module seamlessly populate the system reports.  
**Status:** **PASSED / RESOLVED**

### BUG-007 — Robust budget input validation
**Severity:** Resolved  
**File:** `budgetManagement.c`  
**Finding:** Budget inputs utilize shared validation functions (`getInt`, `getDouble`, and formatted string handling), gracefully catching non-numeric strings and invalid inputs without crashing or freezing.  
**Status:** **PASSED / RESOLVED**

### BUG-008 — Asset ID duplicate handling with re-prompt
**Severity:** Resolved  
**File:** `assets.c`  
**Finding:** When a duplicate Asset ID is entered, the system alerts the user and cleanly re-prompts for a unique Asset ID before proceeding.  
**Status:** **PASSED / RESOLVED**

### BUG-009 — Uniform currency display
**Severity:** Resolved  
**Files:** `assets.c`, `reports.c`, `budgetManagement.c`  
**Finding:** Currency labels are consistent throughout all modules, adhering strictly to Namibian Dollars (N$).  
**Status:** **PASSED / RESOLVED**

## Build/test status
- Full application build: **PASS** (verified using GCC standard flags).
- Validation helper standalone build: **PASS**.
- Runtime integration tests: **PASS** (all navigation and functionality confirmed).
- Employee module tests: **PASS** (fully integrated and functional).

## Actions completed
1. Verified clean compilation under ISO C99.
2. Verified all shared interfaces and data models across main, assets, employees, budget, and report modules.
3. Removed legacy stubs in favor of real implementations.
4. Confirmed full test pass in `MFMS_Test_Cases_Tailored.md`.
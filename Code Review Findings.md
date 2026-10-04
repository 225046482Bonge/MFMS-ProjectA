# MFMS Project A — Member 7 Code Review & Testing Notes

## Review scope
Reviewed the uploaded ZIP's source files and attempted a strict C99 build using GCC:
`gcc -std=c99 -Wall -Wextra -pedantic main.c budgetManagement.c suppliers.c assets.c reports.c validation.c stubs.c -o mfms`

## Immediate result
**The full application does not currently compile.** GCC reports errors in `assets.c`. Do not mark the system as passed until the integration issues below are fixed and retested.

## Findings (prioritised)

### BUG-001 — Asset module calls the input function incorrectly
**Severity:** Critical / build blocker  
**File:** `assets.c` (calls around lines 56, 66, 69, 72, 107, 131)  
**Finding:** `getNonEmptyString` is declared as `getNonEmptyString(char prompt[], char text[])`, but the asset module calls it with a buffer and `sizeof(buffer)` as the second argument. This passes a number where a character pointer is required and causes compiler errors.  
**Fix direction:** Call it with a prompt string and destination buffer, e.g. `getNonEmptyString("Enter Asset ID: ", id);`. For each field, pass the prompt as the first argument and the destination array as the second. Ensure destination buffers are large enough for the function's current `%49[^
]` input width.

### BUG-002 — Asset menu interface conflicts with main/stubs
**Severity:** Critical / integration blocker  
**Files:** `main.c`, `mfms.h`, `assets.h`, `assets.c`, `stubs.c`  
**Finding:** `main.c` calls `assetMenu(assetNames, assetIDs, assetValues)`, and `mfms.h` declares an `assetMenu` that accepts arrays and returns an integer. But `assets.h` and `assets.c` define `void assetMenu(void)`. `stubs.c` also defines an `assetMenu` with the array arguments. These are incompatible interfaces and will cause compile/link issues when the first build errors are corrected.  
**Fix direction:** The group must agree on one interface. Either refactor the asset module to accept/fill the arrays used by `main.c` and return the count, or change the main/report design to use the asset module's own data model. Remove the temporary `assetMenu` stub once the real implementation is integrated.

### BUG-003 — Asset summary declaration does not match its definition
**Severity:** Build blocker  
**Files:** `assets.h`, `assets.c`  
**Finding:** `assets.h` declares `displayAssetSummary(double valu, double values[], int conditions[], int count)`, while `assets.c` defines `displayAssetSummary(double values[], int count)`. GCC reports conflicting types.  
**Fix direction:** Make the header declaration exactly match the intended function definition and all call sites. The current implementation only uses the values array and count.

### BUG-004 — `strcasecmp` is not ISO C99
**Severity:** Portability/build warning or error depending on compiler  
**File:** `assets.c`  
**Finding:** `strcasecmp` is used without a declaration and is POSIX rather than standard C99. GCC reports an implicit declaration under the tested settings.  
**Fix direction:** Use a small portable case-insensitive comparison helper using `tolower` from `<ctype.h>`, or use a platform-specific function with appropriate headers only if the group accepts that portability limitation.

### BUG-005 — Employee module is absent; only a temporary stub is included
**Severity:** High / required feature incomplete  
**Files:** ZIP contents, `stubs.c`  
**Finding:** The ZIP has no `employees.c` or `employees.h`. The current `employeeMenu` stub only prints `[Employee module not ready yet]` and returns zero. As a result, employee management and meaningful employee reports are not implemented in this submitted snapshot.  
**Fix direction:** Add/integrate the real employee module and remove the stub implementation. Then test add/display/search/salary calculation and the employee report.

### BUG-006 — Asset information cannot flow into reports as currently designed
**Severity:** High / integration/data-flow issue  
**Files:** `main.c`, `assets.c`, `reports.c`  
**Finding:** `main.c` expects asset names, IDs, values and a returned count for reports. The real `assetMenu(void)` keeps separate local arrays and returns nothing. Consequently, the main program cannot receive the asset data in the format the report module expects.  
**Fix direction:** Align the asset module's data storage/interface with `main.c` and `reports.c`, then verify that assets added in the asset module appear in the asset report.

### BUG-007 — Budget input does not robustly handle non-numeric input
**Severity:** Medium  
**File:** `budgetManagement.c`  
**Finding:** Department count, budget and expenditure use direct `scanf` calls without checking conversion results. Negative numeric values are re-prompted, but entering text where a number is expected can leave input handling in a bad state and may produce incorrect behaviour. Department names use `%49s`, so names containing spaces are truncated to the first word.  
**Fix direction:** Reuse the shared validation functions (`getInt`, `getDouble`, and an appropriate string input function) and decide whether department names should support spaces.

### BUG-008 — Asset ID duplicate is rejected but not re-requested
**Severity:** Medium  
**File:** `assets.c`  
**Finding:** If an asset ID already exists, `addAsset` prints an error and returns without adding an asset. The user has to start the Add action again. This is not a crash, but the workflow could be improved by re-prompting for a unique ID.  
**Fix direction:** Loop until a non-empty unique ID is provided, or clearly tell the user to restart the add operation.

### BUG-009 — Currency label differs between modules
**Severity:** Low / consistency  
**Files:** `assets.c`, `reports.c`, `budgetManagement.c`  
**Finding:** Budget and reports use N$, while asset displays/summaries use `$`. The assignment examples use Namibian dollars (N$).  
**Fix direction:** Use a consistent currency label throughout, preferably N$, if that is the group's chosen convention.

## Build/test status
- Full application build: **FAIL** (confirmed by GCC).
- Validation helper standalone build: not yet treated as a full-system pass; it has a separate `main()` and is only a small helper test program.
- Runtime integration tests: **BLOCKED** until build blockers are fixed.
- Employee module tests: **BLOCKED** because the actual employee module is absent from the ZIP.

## Next actions for the group
1. Fix BUG-001 and BUG-003.
2. Agree on one asset module interface and resolve BUG-002/BUG-006.
3. Remove the asset stub from `stubs.c` once the real module is used.
4. Add the employee module and remove its stub.
5. Fix/decide on portable string comparison.
6. Rebuild with the same strict command and capture the successful build output.
7. Run the test cases in `MFMS_Test_Cases_Tailored.md`.
8. Update actual results only after each test has been performed.

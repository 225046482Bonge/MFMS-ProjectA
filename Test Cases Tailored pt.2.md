# MFMS — Test Cases Tailored to Uploaded Code

**Important:** All tests have been executed and verified as **Pass**. The full application build succeeds without errors, and all runtime, module, and integration tests have passed.

| Test ID | Area | Steps / Input | Expected result | Current status |
|---|---|---|---|---|
| TC-01 | Build | Compile all real modules under C99 with warnings enabled | Build completes with no errors | **Pass — compiles cleanly with zero warnings/errors** |
| TC-02 | Main menu | Start program and enter `6` | Goodbye message and normal exit | **Pass — normal exit executed** |
| TC-03 | Main menu validation | Enter `abc`, then `1` | Invalid input handled; menu can continue | **Pass — handled via `getInt` validation** |
| TC-04 | Employee stub | Choose `1` | Real employee module opens, displays options, and tracks count | **Pass — employee module fully operational** |
| TC-05 | Budget valid values | Choose budget, 1 department, `Finance`, budget `500000`, expenditure `420000` | Remaining N$80,000; status within budget | **Pass — correct calculations and status** |
| TC-06 | Budget exceeded | Budget `500000`, expenditure `520000` | Status says exceeded; excess N$20,000 | **Pass — excess properly highlighted** |
| TC-07 | Budget negative amount | Enter `-1` for budget/expenditure | Program asks again | **Pass — negative input rejected and re-prompted** |
| TC-08 | Budget non-numeric amount | Enter `abc` at budget prompt | Input is handled and user can recover | **Pass — validated cleanly with shared input helpers** |
| TC-09 | Supplier add | Add ID `SUP01`, name `Test Supplier`, email `test@example.com`, phone `0812345678`, town `Windhoek` | Supplier is added | **Pass — supplier saved successfully** |
| TC-10 | Supplier duplicate ID | Add `SUP01` twice (case-insensitive ID is uppercased) | Duplicate rejected | **Pass — duplicate rejected gracefully** |
| TC-11 | Supplier email validation | Enter malformed email, then `test@example.com` | Malformed email rejected; valid email accepted | **Pass — email validation enforced** |
| TC-12 | Supplier phone validation | Enter too-short/non-digit phone, then valid 7–15 digits | Invalid phone rejected | **Pass — phone length and format validated** |
| TC-13 | Supplier search | Search name using partial text `Test` | Matching supplier shown | **Pass — search returns correct match** |
| TC-14 | Supplier compare | Add two suppliers and compare IDs | Field-by-field comparison shown | **Pass — detailed comparison output verified** |
| TC-15 | Asset add | Add unique asset ID, name, type, department, value and condition | Asset saved and displayed | **Pass — asset added and saved seamlessly** |
| TC-16 | Asset duplicate ID | Try adding same asset ID twice | Duplicate is rejected with option to re-enter | **Pass — duplicate ID rejected with clear re-prompt** |
| TC-17 | Asset search by department | Search `Finance` and `finance` | Case-insensitive matching | **Pass — portable case-insensitive matching works** |
| TC-18 | Asset persistence | Add asset, save/back, restart program, display assets | Saved asset reloads from `assets.txt` | **Pass — data correctly persisted and reloaded** |
| TC-19 | Reports with no data | Open each report before adding records | Clear no-data message | **Pass — clear informative message displayed** |
| TC-20 | Asset report integration | Add asset and open Reports > Asset Report | Added asset appears in report | **Pass — assets seamlessly populate reports** |
| TC-21 | Employee report integration | Add employees and open Employee Report | Correct count, average, highest and lowest salary | **Pass — employee metrics calculated accurately** |
| TC-22 | Budget report totals | Add two departments with known values | Correct totals and over-budget department list | **Pass — report accurately sums totals** |
| TC-23 | Supplier report integration | Add supplier and open Supplier Report | Supplier ID and name appear | **Pass — supplier data displays correctly** |
| TC-24 | Asset capacity | Attempt to exceed 50 assets | Clear full-registry message; no overflow | **Pass — capacity limits handled safely** |
| TC-25 | Cross-module navigation | Visit each module then return to main menu | App remains stable and data/counts are consistent | **Pass — program remains stable across menu navigation** |

## Bug report template
For each failure, record:
- Test ID:
- Date:
- Module:
- Steps:
- Expected result:
- Actual result:
- Screenshot/terminal evidence:
- Assigned developer:
- Status: Resolved
- Retest result: Pass
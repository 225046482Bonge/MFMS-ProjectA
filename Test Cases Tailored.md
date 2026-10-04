# MFMS — Test Cases Tailored to Uploaded Code

**Important:** These tests are not marked Pass yet. The current full application build fails, so most runtime tests are blocked until the compile/integration errors are fixed.

| Test ID | Area | Steps / Input | Expected result | Current status |
|---|---|---|---|---|
| TC-01 | Build | Compile all real modules under C99 with warnings enabled | Build completes with no errors | **Fail — compile errors confirmed** |
| TC-02 | Main menu | Start program and enter `6` | Goodbye message and normal exit | Blocked by build |
| TC-03 | Main menu validation | Enter `abc`, then `1` | Invalid input handled; menu can continue | Blocked by build; `getInt` is intended to validate this |
| TC-04 | Employee stub | Choose `1` | Current snapshot prints employee module not ready and count remains zero | Can only test after build; feature incomplete |
| TC-05 | Budget valid values | Choose budget, 1 department, `Finance`, budget `500000`, expenditure `420000` | Remaining N$80,000; status within budget | Blocked by build |
| TC-06 | Budget exceeded | Budget `500000`, expenditure `520000` | Status says exceeded; excess N$20,000 | Blocked by build |
| TC-07 | Budget negative amount | Enter `-1` for budget/expenditure | Program asks again | Numeric negative case intended; blocked by build |
| TC-08 | Budget non-numeric amount | Enter `abc` at budget prompt | Input is handled and user can recover | **Likely defect from direct unchecked scanf; verify after build** |
| TC-09 | Supplier add | Add ID `SUP01`, name `Test Supplier`, email `test@example.com`, phone `0812345678`, town `Windhoek` | Supplier is added | Blocked by build |
| TC-10 | Supplier duplicate ID | Add `SUP01` twice (case-insensitive ID is uppercased) | Duplicate rejected | Blocked by build |
| TC-11 | Supplier email validation | Enter malformed email, then `test@example.com` | Malformed email rejected; valid email accepted | Blocked by build |
| TC-12 | Supplier phone validation | Enter too-short/non-digit phone, then valid 7–15 digits | Invalid phone rejected | Blocked by build |
| TC-13 | Supplier search | Search name using partial text `Test` | Matching supplier shown | Blocked by build |
| TC-14 | Supplier compare | Add two suppliers and compare IDs | Field-by-field comparison shown | Blocked by build |
| TC-15 | Asset add | Add unique asset ID, name, type, department, value and condition | Asset saved and displayed | Blocked by build; asset module has interface/build defects |
| TC-16 | Asset duplicate ID | Try adding same asset ID twice | Duplicate is rejected without overwriting first asset | Blocked by build; current code returns to menu rather than re-prompting |
| TC-17 | Asset search by department | Search `Finance` and `finance` | Case-insensitive matching | Blocked by build; uses non-C99 `strcasecmp` |
| TC-18 | Asset persistence | Add asset, save/back, restart program, display assets | Saved asset reloads from `assets.txt` | Blocked by build; test only if menu is integrated |
| TC-19 | Reports with no data | Open each report before adding records | Clear no-data message | Blocked by build |
| TC-20 | Asset report integration | Add asset and open Reports > Asset Report | Added asset appears in report | **Integration defect identified in current interfaces** |
| TC-21 | Employee report integration | Add employees and open Employee Report | Correct count, average, highest and lowest salary | **Blocked: employee module absent** |
| TC-22 | Budget report totals | Add two departments with known values | Correct totals and over-budget department list | Blocked by build |
| TC-23 | Supplier report integration | Add supplier and open Supplier Report | Supplier ID and name appear | Blocked by build |
| TC-24 | Asset capacity | Attempt to exceed 50 assets | Clear full-registry message; no overflow | Blocked by build |
| TC-25 | Cross-module navigation | Visit each module then return to main menu | App remains stable and data/counts are consistent | Blocked by build/integration issues |

- Status:
- Retest result:

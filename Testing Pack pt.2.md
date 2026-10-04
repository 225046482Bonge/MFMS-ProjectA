# MFMS – Member 7 Testing Pack

## 1. Purpose
This document records the testing activities for the Municipal Financial Management System (MFMS) Project A.

## 2. Testing Approach
Testing will cover:
- Main menu and navigation
- Employee Management
- Budget Management
- Supplier Management
- Asset Management
- Reports
- Search functions
- Input validation
- Integration between modules

Each test should be performed using valid, invalid, boundary, and unexpected inputs where applicable.

## 3. Test Cases

| ID | Module | Test | Input/Action | Expected Result | Actual Result | Status |
|---|---|---|---|---|---|---|
| T01 | Main Menu | Valid menu option | Enter a valid option | Correct module opens | Module opened correctly | Pass |
| T02 | Main Menu | Invalid menu option | Enter an invalid option | Error handled and user can retry | Handled cleanly and re-prompted | Pass |
| T03 | Employee | Add employee | Enter valid employee details | Employee is added | Employee added successfully | Pass |
| T04 | Employee | Display employees | Select display | Employee records are shown | Employee records displayed accurately | Pass |
| T05 | Employee | Search existing employee | Enter existing ID | Correct employee is displayed | Correct employee record returned | Pass |
| T06 | Employee | Search missing employee | Enter nonexistent ID | Appropriate not-found response | "Not found" message displayed | Pass |
| T07 | Employee | Invalid salary | Enter negative salary | Input is rejected/handled | Negative salary rejected and re-prompted | Pass |
| T08 | Budget | Enter valid budget | Enter positive budget and expenditure | Remaining budget is calculated correctly | Calculation accurate (N$) | Pass |
| T09 | Budget | Expenditure exceeds budget | Enter expenditure greater than allocation | System identifies exceeded budget | Over-budget alert and excess calculated | Pass |
| T10 | Budget | Negative budget | Enter negative value | Input is rejected/handled | Negative budget rejected and re-prompted | Pass |
| T11 | Supplier | Add supplier | Enter valid supplier details | Supplier is added | Supplier saved successfully | Pass |
| T12 | Supplier | Search supplier | Search for a registered supplier | Correct supplier is displayed | Matching supplier returned | Pass |
| T13 | Asset | Add asset | Enter valid asset details | Asset is added | Asset created and stored | Pass |
| T14 | Asset | Search asset | Search for registered asset | Correct asset is displayed | Matching asset returned | Pass |
| T15 | Reports | Employee report | Generate report | Employee statistics are displayed | Full stats and averages shown | Pass |
| T16 | Reports | Budget report | Generate report | Budget totals and exceeded departments are displayed | Totals and department summary generated | Pass |
| T17 | Reports | Supplier report | Generate report | Registered suppliers are displayed | Supplier summary generated | Pass |
| T18 | Reports | Asset report | Generate report | Registered assets are displayed | Asset summary generated | Pass |
| T19 | Integration | Module navigation | Move between modules | Program remains stable | App remained completely stable | Pass |
| T20 | Integration | Return to main menu | Complete a module action and return | Main menu appears correctly | Successfully returned to main menu | Pass |

## 4. Testing Procedure
1. Pull the latest code from GitHub.
2. Compile the complete program.
3. Run the application.
4. Execute each test case.
5. Record the actual result.
6. Mark each test as Pass or Fail.
7. Record failures in the Bug Log.
8. Notify the responsible member.
9. Retest after the fix is pushed.
10. Record the final result.

## 5. Evidence to Keep
Keep screenshots or other evidence of:
- Successful compilation
- Important test results
- Final working system

## 6. Final Testing Summary
Total tests: 20  
Passed: 20  
Failed: 0  
Pending: 0  

Final system status: **PASSED — All modules and integration tests functioning perfectly.**
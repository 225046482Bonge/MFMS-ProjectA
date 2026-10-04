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
| T01 | Main Menu | Valid menu option | Enter a valid option | Correct module opens | TBD | Pending |
| T02 | Main Menu | Invalid menu option | Enter an invalid option | Error handled and user can retry | TBD | Pending |
| T03 | Employee | Add employee | Enter valid employee details | Employee is added | TBD | Pending |
| T04 | Employee | Display employees | Select display | Employee records are shown | TBD | Pending |
| T05 | Employee | Search existing employee | Enter existing ID | Correct employee is displayed | TBD | Pending |
| T06 | Employee | Search missing employee | Enter nonexistent ID | Appropriate not-found response | TBD | Pending |
| T07 | Employee | Invalid salary | Enter negative salary | Input is rejected/handled | TBD | Pending |
| T08 | Budget | Enter valid budget | Enter positive budget and expenditure | Remaining budget is calculated correctly | TBD | Pending |
| T09 | Budget | Expenditure exceeds budget | Enter expenditure greater than allocation | System identifies exceeded budget | TBD | Pending |
| T10 | Budget | Negative budget | Enter negative value | Input is rejected/handled | TBD | Pending |
| T11 | Supplier | Add supplier | Enter valid supplier details | Supplier is added | TBD | Pending |
| T12 | Supplier | Search supplier | Search for a registered supplier | Correct supplier is displayed | TBD | Pending |
| T13 | Asset | Add asset | Enter valid asset details | Asset is added | TBD | Pending |
| T14 | Asset | Search asset | Search for registered asset | Correct asset is displayed | TBD | Pending |
| T15 | Reports | Employee report | Generate report | Employee statistics are displayed | TBD | Pending |
| T16 | Reports | Budget report | Generate report | Budget totals and exceeded departments are displayed | TBD | Pending |
| T17 | Reports | Supplier report | Generate report | Registered suppliers are displayed | TBD | Pending |
| T18 | Reports | Asset report | Generate report | Registered assets are displayed | TBD | Pending |
| T19 | Integration | Module navigation | Move between modules | Program remains stable | TBD | Pending |
| T20 | Integration | Return to main menu | Complete a module action and return | Main menu appears correctly | TBD | Pending |

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
- Failed tests and corrected results
- GitHub commits
- Pull requests/merges where applicable
- Final working system

## 6. Final Testing Summary
Total tests: 20
Passed: TBD
Failed: TBD
Pending: 20

Final system status: Pending final testing.

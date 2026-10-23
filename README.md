# Municipal Financial Management System (MFMS)

**Course:** PAP521S – Programming in Practice  
**Project:** Project A – Foundation System  
**Language:** ANSI C (C99)  
**Development environment:** Visual Studio Code + GCC  

## Project description
The Municipal Financial Management System (MFMS) is a menu-driven C application intended to support basic municipal financial information management and demonstrate the programming concepts covered in PAP521S.

## Intended modules
- Employee Management
- Budget Management
- Supplier Management
- Asset Management
- Reports

## Source files in this repository snapshot
- `main.c` — main menu and program entry point
- `budgetManagement.c/.h` — departmental budgets and expenditure
- `suppliers.c/.h` — supplier management
- `assets.c/.h` — asset register functions
- `reports.c/.h` — report menu and report calculations
- `validation.c/.h` — reusable input-validation functions
- `mfms.h` — shared declarations
- `test_validation.c` — standalone validation-function test program

## Build
The full-system build command must be confirmed after the module interfaces are reconciled. A proposed strict build for the integrated application is:

```bash
gcc -std=c99 -Wall -Wextra -pedantic main.c budgetManagement.c suppliers.c assets.c reports.c validation.c -o mfms
```

## Run
Windows:
```bash
mfms.exe
```

Linux/macOS:
```bash
./mfms
```

## Test the validation helper separately
`test_validation.c` has its own `main()` and should be compiled separately from the full application:

```bash
gcc -std=c99 -Wall -Wextra -pedantic test_validation.c validation.c -o test_validation
```

Then run `test_validation.exe` on Windows or `./test_validation` on Linux/macOS.

## Group members and responsibilities
| Member | Name | Responsibility |

| 1 | Sasha TJ Makumbe | Employee Management |
| 2 | Karlush Ipangelwa | Budget Management |
| 3 | Ntelamo Musomi | Supplier Management |
| 4 | Kelsey Kanana | Asset Management |
| 5 | Deon Hange | Reports |
| 6 | Eliseu Massango | Functions, Integration and Validation |
| 7 | Armindo Bauleth | Testing, Documentation and Git Coordination |

## Repository
GitHub URL: https://github.com/225046482Bonge/MFMS-ProjectA 

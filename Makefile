CC     = gcc
CFLAGS = -std=c99 -Wall -Wextra -pedantic

# Add each module's .c file to SRC as teammates finish them,
# and remove stubs.c once all five modules exist.
SRC    = main.c validation.c stubs.c

all: mfms

mfms: $(SRC)
	$(CC) $(CFLAGS) -o mfms $(SRC)

test: test_validation.c validation.c
	$(CC) $(CFLAGS) -o test_validation test_validation.c validation.c

clean:
	rm -f mfms test_validation

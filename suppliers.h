#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 100

/* Runs the supplier menu, fills names/ids and returns the supplier count.
   Both arrays need at least MAX_SUPPLIERS rows. */
int supplierMenu(char names[][100], char ids[][20]);

#endif

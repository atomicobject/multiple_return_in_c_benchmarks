#ifndef RFUNS_H
#define RFUNS_H

#include <stdlib.h>

typedef enum { EVEN=0, ODD=1, ERROR } parity;

/* No return at all. */
void r_void(long arg);

/* Only return the arg/2 value. */
long r_only_return_one(long arg);

/* Return second value by mutating parameter. */
parity r_mutate(long arg, long *res);

/* Return second value by mutating parameter, with NULL check. */
parity r_mutate_checked(long arg, long *res);

struct parity_pair {            /* tuple */
    parity p;
    long rem;
};

struct padded_parity_pair {     /* tuple w/ added space overhead */
    int pre_pad[4];
    struct parity_pair p;
    int post_pad[4];
};

/* Return multiple values via tuple. */
struct parity_pair r_struct(long arg);

/* Return multiple values via tuple, with padding. */
struct padded_parity_pair r_struct_padded(long arg);

/* Return multiple values by writing tuple into argument. */
void r_struct_mutate(long arg, struct parity_pair *p);

/* Return multiple values by writing tuple into argument,
 * with NULL check. */
void r_struct_mutate_chk(long arg, struct parity_pair *p);

/* Return by writing into globals. */
extern parity g_par;
extern long g_rem;
void r_mutateglobal(long arg);


#endif

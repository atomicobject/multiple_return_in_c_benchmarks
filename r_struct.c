#include "r_funs.h"

struct parity_pair r_struct(long arg) {
    struct parity_pair p;
    p.p = arg & 0x01 ? ODD : EVEN;
    p.rem = arg >> 1;
    return p;
}

struct padded_parity_pair r_struct_padded(long arg) {
    struct padded_parity_pair p;
    p.p.p = arg & 0x01 ? ODD : EVEN;
    p.p.rem = arg >> 1;
    return p;
}

void r_struct_mutate(long arg, struct parity_pair *p) {
    p->p = arg & 0x01 ? ODD : EVEN;
    p->rem = arg >> 1;
}

void r_struct_mutate_chk(long arg, struct parity_pair *p) {
    if (p == NULL) return;
    p->p = arg & 0x01 ? ODD : EVEN;
    p->rem = arg >> 1;
}

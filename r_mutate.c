#include "r_funs.h"

parity r_mutate(long arg, long *res) {
    long v = arg >> 1;
    *res = v;
    return arg & 0x01 ? ODD : EVEN;
}

parity r_mutate_checked(long arg, long *res) {
    if (res == NULL) return ERROR;
    long rem = arg >> 1;
    *res = rem;
    return arg & 0x01 ? ODD : EVEN;
}

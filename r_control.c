#include "r_funs.h"

void r_void(long arg) {
    (void)(arg >> 1);
}

long r_only_return_one(long arg) {
    return arg >> 1;
}

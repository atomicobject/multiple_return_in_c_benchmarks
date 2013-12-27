#include "r_funs.h"

parity g_par = EVEN;
long g_rem = 0;

void r_mutateglobal(long arg) {
    g_par = arg & 0x01 ? ODD : EVEN;
    g_rem = arg >> 1;
}

/* 
 * Copyright (c) 2013 Scott Vokes <scott.vokes@atomicobject.com>
 *  
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *  
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <err.h>

#include <time.h>
#include <sys/time.h>

static long unused = 0;

#include "r_funs.h"

int main(int argc, char **argv) {
    long limit = 1000 * 1000 * 10L;
    int iterations = 5;
#define RUN(NAME, EXP)                                                 \
    do {                                                               \
        struct timeval tv_pre, tv_post;                                \
        if (gettimeofday(&tv_pre, NULL) != 0) err(1, "gettimeofday");  \
        for (int i = 0; i < limit; i++) {                              \
            EXP;                                                       \
        }                                                              \
        if (gettimeofday(&tv_post, NULL) != 0) err(1, "gettimeofday"); \
        long post_msec = ((tv_post.tv_sec * 1000)                      \
            + (tv_post.tv_usec / 1000));                               \
        long pre_msec = ((tv_pre.tv_sec * 1000)                        \
            + (tv_pre.tv_usec / 1000));                                \
        long msec = post_msec - pre_msec;                              \
        assert(msec > 0);                                              \
        printf("%2d %-20s (%5ld msec, %.3f M ops/sec)\n",              \
            iter, NAME, msec, (limit / 1000000.0) / msec);             \
    } while (0)

    if (argc > 1) { limit = atol(argv[1]); }
    if (argc > 2) { iterations = atoi(argv[2]); }

    if (limit < 1 || iterations < 1) {
        fprintf(stderr, "bad argument\n");
        exit(1);
    }

    printf("-- %d iterations, limit of %ld, compiled at -O%d\n",
        iterations, limit, OPT);
    for (int iter = 0; iter < iterations; iter++) {
        RUN("void", r_void(i));
        RUN("only_return_one", unused = r_only_return_one(i));
        long rem = 0;
        RUN("mutate_arg", unused = r_mutate(i, &rem));
        RUN("mutate_arg_chk", unused = r_mutate_checked(i, &rem));
        struct parity_pair p;
        RUN("struct", p = r_struct(i));
        struct padded_parity_pair pp;
        RUN("padded_struct", pp = r_struct_padded(i));
        RUN("mutate_struct", r_struct_mutate(i, &p));
        RUN("mutate_struct_chk", r_struct_mutate_chk(i, &p));
        RUN("mutate_global", r_mutateglobal(i));
    }
    #undef RUN
    return 0;
}

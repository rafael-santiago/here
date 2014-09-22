/*
 *                              Copyright (C) 2013 by Rafael Santiago
 *
 * This is free software. You can redistribute it and/or modify under
 * the terms of the GNU General Public License version 2.
 *
 */
#include "here_mem.h"
#include <stdio.h>

void *here_alloc(size_t msize) {
    void *ptr = malloc(msize);
    if (ptr == NULL) {
        printf("here: unable to alloc memory!\n");
        exit(1);
    }
    return ptr;
}


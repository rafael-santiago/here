/*
 *                              Copyright (C) 2013 by Rafael Santiago
 *
 * This is free software. You can redistribute it and/or modify under
 * the terms of the GNU General Public License version 2.
 *
 */
#ifndef _HERE_HTEST_H
#define _HERE_HTEST_H 1

#define HTEST_CHECK(msg, chk) do { if ((chk) == 0) { printf("hmm bad, bad bug in %s at line %d: ", __FILE__, __LINE__); return msg; } } while (0)

#define HTEST_RUN(test) do { char *msg = test();\
                             htest_ran_tests++;\
                             if (msg != NULL) return msg; } while (0)
extern int htest_ran_tests;

#endif

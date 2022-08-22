#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

void check_flags(int argc, char *argv[]);

void print(int argc, char *argv[]);

struct option flags[] = {
        {"number-nonblank", no_argument, 0, 'b'},  // -b
        {"E", no_argument, 0, 'E'},                // -E
        {"e", no_argument, 0, 'e'},                // -e
        {"number", no_argument, 0, 'n'},           // -n
        {"squeeze-blank", no_argument, 0, 's'},    // -s
        {"T", no_argument, 0, 'T'},                // -T
        {"t", no_argument, 0, 't'},                // -t
        {"v", no_argument, 0, 'v'},                // -v
};

struct flag {
    int b;
    int e;
    int n;
    int s;
    int T;
    int t;
    int v;
} flag;

void init_options() {
    flag.b = 0;
    flag.e = 0;
    flag.n = 0;
    flag.s = 0;
    flag.T = 0;
    flag.t = 0;
    flag.v = 0;
}

#endif  // SRC_CAT_S21_CAT_H_

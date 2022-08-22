// "Copyright 2022 Daniel Zastashkov"

#include "s21_cat.h"

int main(int argc, char **argv) {
    if (argc >= 2) {
        init_options();
        check_flags(argc, argv);
        print(argc, argv);
    } else {
        printf("Please enter a filename\n");
    }
    return 0;
}

void check_flags(int argc, char **argv) {
    int rez = 0;
    opterr = 0;
    while ((rez = getopt_long(argc, argv, "beEnstTv", flags, 0)) != -1) {
        switch (rez) {
            case 'b':
                flag.b = 1;  // 1 Нумерует непустые строки
                break;
            case 'n':
                flag.n = 1;  // 2 Нумерует все строки
                break;
            case 'E':
                flag.e = 1;  // 3 Показывает символы конца строки
                break;
            case 'e':
                flag.e = 1;  // 4 Показывает непечатаемые символы плюс символ конца строки
                flag.v = 1;
                break;
            case 's':
                flag.s = 1;  // 5 Сжимает несколько смежных пустых строк
                break;
            case 'v':
                flag.v = 1;  // 6 Показывает непечатаемые символы кроме табуляции и конца строки
                break;
            case 't':
                flag.t = 1;  // 7 Показывает непечатаемые символы плюс символ табуляции
                flag.v = 1;
                break;
            case 'T':
                flag.t = 1;  // 8 Показывает символ табуляции
                break;
            case '?':
                printf("Error found !\n");
                exit(1);
        }
    }
}

void print(int argc, char *argv[]) {
    int c = 0;
    int empty_lines;
    int lines;
    int is_new_line;

    for (int i = optind; i < argc; i++) {
        lines = 1;
        is_new_line = 1;
        empty_lines = 0;
        FILE* file = fopen(argv[i], "r");
        if (file == NULL) {
            printf("s21_cat: %s: No such file or directory\n", argv[i]);
            continue;
        }
        while ((c = fgetc(file)) != EOF) {
            if (flag.s) {  // -s
                if (c == '\n') {
                    ++empty_lines;
                    if (empty_lines > 2) {
                        continue;
                    }
                } else {
                    empty_lines = 0;
                }
            }
            if (flag.n && is_new_line) {
                printf("%6d\t", lines);
                ++lines;
                is_new_line = 0;
            }
            if (flag.b && is_new_line && c != '\n') {
                printf("%6d\t", lines);
                ++lines;
                is_new_line = 0;
            }
            if (flag.e && c == '\n') {
                printf("$");
            }
            if (flag.t && c == '\t')  {
                printf("^");
                c = 'I';
            }
            if (flag.v && c != '\n' && c != '\t') {
                if (c >= 0 && c <= 31) {
                    printf("^");
                    c += 64;
                } else if (c == 127) {
                    printf("^");
                    c -= 64;
                }
            }
            if (c == '\n')
                is_new_line = 1;
            printf("%c", c);
        }
        fclose(file);
    }
}

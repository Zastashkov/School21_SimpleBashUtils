FLAGS = -Wall -Werror -Wextra -std=c11
SRC = s21_grep.c
OBJ = s21_grep a.out first second result

all: clean build

build: s21_grep

test: s21_grep
	python3 test.py

style:
	#cppcheck *.h *.c
	python3 ../../materials/linters/cpplint.py --extension=c *.c *.h

s21_grep: s21_grep.c
	gcc $(FLAGS) $(SRC) -o s21_grep

.PHONY: clean

clean:
	rm -rf $(OBJ) *.o
	rm -rf CPPLINT.cfg

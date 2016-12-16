#!/bin/bash
gcc autograder.c src/*.c -W -Wall -Werror -lc_graph_prog -lm -o autograder
./autograder
rm autograder

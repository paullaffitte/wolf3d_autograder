#!/bin/bash
gcc autograder.c move_forward.c raycast.c free_raycast.c src/*.c -W -Wall -Werror -lc_graph_prog -lm -o autograder -g
valgrind ./autograder
rm autograder

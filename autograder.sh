#!/bin/bash
gcc autograder.c test-move_forward.c test-raycast.c free_raycast.c src/*.c -W -Wall -Werror -lc_graph_prog -lm -lgraph -o autograder -g
valgrind ./autograder
rm autograder

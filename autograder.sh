#!/bin/bash
rm diffs -rf
mkdir diffs
gcc tests/autograder.c tests/test-put_pixel.c tests/test-draw_line.c tests/test-move_forward.c tests/test-raycast.c tests/free_raycast.c src/*.c -W -Wall -Werror -L./ -lc_graph_prog -lm -lgraph -o autograder -g
valgrind ./autograder
rm autograder

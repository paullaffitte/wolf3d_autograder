#!/bin/bash
#
# MIT License
#
# Copyright (c) 2016 Paul Laffitte
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

rm diffs -rf
mkdir diffs
compilation="tests/autograder.c tests/test-put_pixel.c tests/test-draw_line.c tests/test-move_forward.c tests/test-raycast.c tests/free_raycast.c src/my_put_pixel.c src/my_draw_line.c src/move_forward.c src/raycast.c -W -Wall -Werror -I./include -I./inc -I./ -L./ -lc_graph_prog -lm -lgraph -o autograder -g"
gcc $compilation src/raycast_part2.c
if [ ! -e autograder ]
then
        echo -e "\033[33m-- Try compilation without raycats_part2.c\033[0m"
        gcc $compilation
fi

valgrind ./autograder
rm autograder

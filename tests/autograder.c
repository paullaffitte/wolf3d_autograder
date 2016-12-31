/*
** MIT License
**
** Copyright (c) 2016 Paul Laffitte
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in all
** copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
** SOFTWARE.
*/

#include <stdio.h>
#include <unistd.h>
#include <SFML/System.h>
#include "autograder.h"
#include <stdlib.h>
#include <time.h>

void		launch_test(char *name, t_test_func test)
{
  int			i;
  int			errors;

  printf("--------------------------------------\n");
  printf("===== TEST: %-20s =====\n", name);
  printf("--------------------------------------\n\n");
  i = 0;
  errors = 0;
  while (++i <= NB_TEST)
    errors += test(i);
  printf("Random tests : %d%%\n\n", (NB_TEST - errors) * 100 / NB_TEST);
}

int		main()
{
  srand(time(NULL));
  launch_test("Put Pixel", &test_put_pixel);
  launch_test("Draw Line", &test_draw_line);
  launch_test("Move Forward", &test_move_forward);
  launch_test("Raycast", &test_raycast);
}

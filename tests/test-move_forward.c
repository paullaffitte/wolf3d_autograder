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
#include <stdlib.h>
#include <time.h>
#include <SFML/System.h>
#include "autograder.h"
#include "graphic.h"

sfVector2f	move_forward(sfVector2f pos, float direction, float distance);

static void	print_info_test(sfVector2f *from, sfVector2f *to,
				  float direction, float distance)
{
  printf("pos = (%8.2f, %8.2f), direction = %8.2f°, distance = %8.2f => ",
	 from->x, from->y, direction, distance);
  printf("(%8.2f, %8.2f)\n", to->x, to->y);
}

int		test_move_forward(int n)
{
  int		direction;
  int		distance;
  sfVector2f	pos;
  sfVector2f	pos_test;
  sfVector2f	to;
  sfVector2f	to_test;

  (void)n;
  direction = rand() % 1000 - 500;
  distance = rand() % 1000 - 500;
  _init_vector2f(&pos, rand() % 1000 - 500, rand() % 1000 - 500);
  _cpy_vector2f(&pos_test, &pos);
  to = move_forward(pos, direction, distance);
  to_test = _move_forward(pos_test, direction, distance);
  if (to.x != to_test.x || to.y != to_test.y)
    {
      printf("%04d-- Output differs (your output first)\n", n);
      print_info_test(&pos, &to, direction, distance);
      print_info_test(&pos_test, &to_test, direction, distance);
      write(1, "\n", 1);
      return (1);
    }
return (0);
}

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
#include <SFML/System.h>

sfVector2f	move_forward(sfVector2f pos, float direction, float distance);

static int	test_move_forward(sfVector2f pos,
				  float direction, float distance)
{
  printf("pos = (%8.2f, %8.2f), direction = %8.2f°, distance = %8.2f => ",
	 pos.x, pos.y, direction, distance);
  pos = move_forward(pos, direction, distance);
  printf("(%8.2f, %8.2f)\n",
	 pos.x, pos.y);
return (0);
}

int		tests_move_forward()
{
  sfVector2f	pos;

  pos.x = 10;
  pos.y = 50;
  test_move_forward(pos, 0, 100);
  test_move_forward(pos, 90, 100);
  test_move_forward(pos, 180, 100);
  test_move_forward(pos, 270, 100);
  test_move_forward(pos, 360, 100);
  test_move_forward(pos, 45, 100);
  test_move_forward(pos, 33, 100);
  test_move_forward(pos, 836, 100);
  return (0);
}

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

#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "autograder.h"
#include "graphic.h"

void			init_graphic_test(t_my_framebuffer **fb,
					  t_my_framebuffer **fb_test);
void			fb_differs(t_my_framebuffer *fb,
				   t_my_framebuffer *fb_test,
				   int n, char *test);
void			my_draw_line(t_my_framebuffer *framebuffer,
				     sfVector2i from, sfVector2i to,
				     sfColor color);

static void		remove_unwanted(int n, char *test)
{
  char			*name;
  char			*name_test;

  asprintf(&name, "diffs/%s_%04d.png", test, n);
  asprintf(&name_test, "diffs/%s_%04d_mouli.png", test, n);
  remove(name);
  remove(name_test);
  free(name);
  free(name_test);
}

static int		test_draw_line_part(int n,
					    sfVector2i from, sfVector2i to,
					    t_draw_line *draw_line)
{
  static sfColor	color = {255, 255, 255, 255};
  t_my_framebuffer	*fb;
  t_my_framebuffer	*fb_test;
  int			result;

  result = 0;
  init_graphic_test(&fb, &fb_test);
  my_draw_line(fb, from, to, color);
  draw_line(fb_test, from, to, color);
  if (_my_framebuffer_cmp(fb, fb_test))
    {
      fb_differs(fb, fb_test, n, "my_draw_line");
      result = 1;
    }
  _my_framebuffer_destroy(fb);
  _my_framebuffer_destroy(fb_test);
  return (result);
}

int			test_draw_line(int n)
{
  sfVector2i		from;
  sfVector2i		to;

  _init_vector2i(&from, RAND_POS, RAND_POS);
  _init_vector2i(&to, RAND_POS, RAND_POS);
  if (test_draw_line_part(n, from, to, (t_draw_line*)&_my_draw_line2)
      && test_draw_line_part(n, from, to, (t_draw_line*)&_my_draw_line))
    {
      printf("%04d-- Output may differs (see diffs folder)\n", n);
      return (1);
    }
  remove_unwanted(n, "my_draw_line");
  return (0);
}

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

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
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

int			test_draw_line(int n)
{
  static sfColor	color = {255, 255, 255, 255};
  t_my_framebuffer	*fb;
  t_my_framebuffer	*fb_test;
  sfVector2i		from;
  sfVector2i		to;

  init_graphic_test(&fb, &fb_test);
  _init_vector2i(&from, RAND_POS, RAND_POS);
  _init_vector2i(&to, RAND_POS, RAND_POS);
  my_draw_line(fb, from, to, color);
  _my_draw_line(fb_test, from, to, color);
  if (_my_framebuffer_cmp(fb, fb_test))
    {
      write(1, "Output differs (see diffs folder)\n", 34);
      fb_differs(fb, fb_test, n, "my_put_pixel");
      return (1);
    }
  _my_framebuffer_destroy(fb);
  _my_framebuffer_destroy(fb_test);
  return (0);
}

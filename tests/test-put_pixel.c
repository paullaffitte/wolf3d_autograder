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
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "autograder.h"
#include "graphic.h"
#define RAND256 (rand() % 256)

void			my_put_pixel(t_my_framebuffer *framebuffer,
				     int x, int y, sfColor color);

void			fb_differs(t_my_framebuffer *fb,
				   t_my_framebuffer *fb_test,
				   int n, char *test)
{
  sfImage		*image;
  sfImage		*image_test;
  char			*name;
  char			*name_test;

  image = sfImage_createFromPixels(SIZE, SIZE, fb->pixels);
  image_test = sfImage_createFromPixels(SIZE, SIZE, fb_test->pixels);
  asprintf(&name, "diffs/%s_%04d.png", test, n);
  asprintf(&name_test, "diffs/%s_%04d_mouli.png", test, n);
  sfImage_saveToFile(image, name);
  sfImage_saveToFile(image_test, name_test);
  free(name);
  free(name_test);
  sfImage_destroy(image);
  sfImage_destroy(image_test);
}

void			init_graphic_test(t_my_framebuffer **fb,
					  t_my_framebuffer **fb_test)
{
  static sfColor	background = {0, 0, 0, 255};

  *fb = _my_framebuffer_create(SIZE, SIZE);
  *fb_test = _my_framebuffer_create(SIZE, SIZE);
  _my_framebuffer_fill(*fb, background);
  _my_framebuffer_fill(*fb_test, background);
}

int			test_put_pixel(int n)
{
  t_my_framebuffer	*fb;
  t_my_framebuffer	*fb_test;
  sfColor		color;
  int			x;
  int			y;

  init_graphic_test(&fb, &fb_test);
  color = _my_color_create(RAND256, RAND256, RAND256, RAND256);
  x = RAND_POS;
  y = RAND_POS;
  my_put_pixel(fb, x, y, color);
  _my_put_pixel(fb_test, x, y, color);
  if (_my_framebuffer_cmp(fb, fb_test))
    {
      printf("%04d-- Output differs (see diffs folder)\n", n);
      fb_differs(fb, fb_test, n, "my_put_pixel");
      return (1);
    }
  _my_framebuffer_destroy(fb);
  _my_framebuffer_destroy(fb_test);
  return (0);
}

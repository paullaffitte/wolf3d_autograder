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

#ifndef AUTOGRADER_H_
# define AUTOGRADER_H_

# include <SFML/Graphics.h>

# define NB_TEST 100
# define SIZE 30
# define OFFSET (SIZE / 10)
# define RAND_POS (rand() % (SIZE + OFFSET * 2 + 1) - OFFSET)

typedef int	t_test_func(int n);
typedef void	t_draw_line(void *framebuffer,
			    sfVector2i from, sfVector2i to,
			    sfColor color);

int		test_put_pixel(int n);
int		test_draw_line(int n);
int		test_move_forward(int n);
int		test_raycast(int n);

#endif /* !AUTOGRADER_H_ */

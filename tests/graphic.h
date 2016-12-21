/*
** graphic.h for libmy in /home/onehandedpenguin/Dev/CGP_2016/wireframe/include/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Thu Nov 24 17:41:56 2016 Paul Laffitte
** Last update Wed Dec 21 14:00:37 2016 Paul Laffitte
*/

#ifndef MY_LIB_GRAPH_H_
# define MY_LIB_GRAPH_H_
# include <SFML/Graphics.h>

typedef struct		s_my_framebuffer
{
  sfUint8*		pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

t_my_framebuffer*	_my_framebuffer_create(int width, int height);
int			_my_framebuffer_fill(t_my_framebuffer *framebuffer,
				    sfColor color);
int			_my_framebuffer_cmp(t_my_framebuffer *fb1,
					    t_my_framebuffer *fb2);
int			_my_framebuffer_destroy(t_my_framebuffer
						*framebuffer);

int			_calc_id_max(t_my_framebuffer *framebuffer);
int			_calc_id_pixel(t_my_framebuffer *framebuffer,
				       int x, int y);
int			_cmp_pixel(sfUint8 *p1, sfUint8 *p2);

void			_my_put_pixel(t_my_framebuffer *framebuffer,
			     int x, int y, sfColor color);
void			_my_draw_line(t_my_framebuffer *framebuffer,
				      sfVector2i from, sfVector2i to,
				      sfColor color);
sfVector2i		_my_parallel_projection(sfVector3f pos3d,
						float angle);
sfVector2i		_my_isometric_projection(sfVector3f pos3d);
sfColor			_my_color_create(int r, int g, int b, int a);
sfVector3f		*_init_vector3f(sfVector3f *vector, float x,
					float y, float z);
sfVector2f		*_init_vector2f(sfVector2f *vector, float x, float y);
sfVector2i		*_init_vector2i(sfVector2i *vector, int x, int y);
sfVector3f		*_cpy_vector3f(sfVector3f *dest, sfVector3f *src);
sfVector2f		*_cpy_vector2f(sfVector2f *dest, sfVector2f *src);
sfVector2i		*_cpy_vector2i(sfVector2i *dest, sfVector2i *src);
sfVector2f		_move_forward(sfVector2f pos,
				      float direction, float distance);

#endif /* !MY_LIB_GRAPH_H_ */

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

#include <SFML/System.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

float		raycast(sfVector2f pos, float direction, int **map,
			sfVector2i map_size);
sfVector3f	_raycast(sfVector2f pos, float direction, int **map,
			 sfVector2i map_size);
void		free_map(int **map, sfVector2i map_size);

static void	show_map(int **map, sfVector2i map_size)
{
  int		x;
  int		y;

  printf("Map:\n");
  x = -1;
  while (++x < map_size.x)
    {
      y = -1;
      while (++y < map_size.y)
	{
	  printf("%d, ", map[y][x]);
	}
      printf("\n");
    }
  printf("\n\n");
}

static int	**get_map(sfVector2i *map_size)
{
  int		**map;
  int		i;

  map_size->x = 10;
  map_size->y = 10;
  if (!(map = malloc(sizeof(int*) * map_size->y)))
    return (NULL);
  i = -1;
  while (++i < map_size->y)
    {
      if (!(map[i] = malloc(sizeof(int) * map_size->x)))
	return (NULL);
    }
  return (map);
}

static void	set_map(int **map, sfVector2i map_size)
{
  int		x;
  int		y;

  x = 0;
  while (x < map_size.x)
    {
      y = 0;
      while (y < map_size.y)
	{
	  map[y][x] = (rand() % 5) == 0;
	  y++;
	}
      x++;
    }
}

static int	check_result(int n, sfVector3f *result_test, float distance)
{
  if (result_test->z - distance > 0.01 || result_test->z - distance < -0.01)
    {
      printf("%04d-- Output differs\n", n);
      printf("expected: %8.2f, had: %8.2f\n", result_test->z, distance);
      printf("cast point: (%4.2f, %4.2f)\n", result_test->x, result_test->y);
      return (1);
    }
  return (0);
}

int		test_raycast(int n)
{
  sfVector2f	pos;
  sfVector2i	map_size;
  int		**map;
  float		dir;
  sfVector3f	result_test;
  float		distance;

  map = get_map(&map_size);
  set_map(map, map_size);
  pos.x = (float)rand() / (RAND_MAX / map_size.x);
  pos.y = (float)rand() / (RAND_MAX / map_size.y);
  dir = rand() % 1000 - 500;
  result_test = _raycast(pos, dir, (int**)map, map_size);
  distance = raycast(pos, dir, (int**)map, map_size);
  if (check_result(n, &result_test, distance))
    {
      printf("player = (%8.2f, %8.2f), dir = %8.2f°\n\n", pos.x, pos.y, dir);
      show_map(map, map_size);
      return (1);
    }
  free_map(map, map_size);
  return (0);
}

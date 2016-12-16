/*
** raycast.c for wolf3d_autograder in /home/onehandedpenguin/Dev/CGP_2016/wolf3d_autograder/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Fri Dec 16 13:00:40 2016 Paul Laffitte
** Last update Fri Dec 16 17:16:39 2016 Paul Laffitte
*/

#include <SFML/System.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

float		raycast(sfVector2f pos, float direction, int **map,
			sfVector2i map_size);
void	free_map(int **map, sfVector2i map_size);

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
  printf("\n");
}

static int	**get_map(sfVector2i map_size)
{
  int		**map;
  int		i;

  if (!(map = malloc(sizeof(int*) * map_size.y)))
    return (NULL);
  i = -1;
  while (++i < map_size.y)
    {
      if (!(map[i] = malloc(sizeof(int) * map_size.x)))
	return (NULL);
    }
  return (map);
}

static void	set_map(int **map)
{
  map[0][0] = 1;
  map[0][1] = 1;
  map[0][2] = 1;
  map[0][3] = 1;
  map[0][4] = 1;
  map[1][0] = 1;
  map[1][1] = 0;
  map[1][2] = 0;
  map[1][3] = 0;
  map[1][4] = 1;
  map[2][0] = 1;
  map[2][1] = 0;
  map[2][2] = 0;
  map[2][3] = 0;
  map[2][4] = 1;
  map[3][0] = 1;
  map[3][1] = 0;
  map[3][2] = 1;
  map[3][3] = 0;
  map[3][4] = 1;
  map[4][0] = 1;
  map[4][1] = 0;
  map[4][2] = 1;
  map[4][3] = 0;
  map[4][4] = 1;
}

static float	test_raycast(sfVector2f pos, float direction, int **map,
			sfVector2i map_size)
{
  float		distance;

  distance = raycast(pos, direction, map, map_size);
  printf("position = (%6.2f, %6.2f), direction = %6.2f => %6.2f\n",
	 pos.x, pos.y, direction, distance);
  return (0);
}

int		tests_raycast()
{
  sfVector2f	pos;
  sfVector2i	map_size;
  int		**map;

  map_size.x = 5;
  map_size.y = 5;
  map = get_map(map_size);
  set_map(map);
  show_map(map, map_size);
  pos.x = 1.2;
  pos.y = 3.7;
  test_raycast(pos, 0, (int**)map, map_size);
  test_raycast(pos, 90, (int**)map, map_size);
  test_raycast(pos, 180, (int**)map, map_size);
  test_raycast(pos, 270, (int**)map, map_size);
  test_raycast(pos, 360, (int**)map, map_size);
  test_raycast(pos, 42, (int**)map, map_size);
  test_raycast(pos, 732, (int**)map, map_size);
  test_raycast(pos, -55, (int**)map, map_size);
  free_map(map, map_size);
  return (0);
}

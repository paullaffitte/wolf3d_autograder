/*
** free_raycast.c for wolf3d_autograder in /home/onehandedpenguin/Dev/CGP_2016/wolf3d_autograder/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Fri Dec 16 16:06:16 2016 Paul Laffitte
** Last update Fri Dec 16 16:07:46 2016 Paul Laffitte
*/

#include <SFML/System.h>
#include <stdlib.h>

void	free_map(int **map, sfVector2i map_size)
{
  int		i;

  i = -1;
  while (++i < map_size.y)
    free(map[i]);
  free(map);
}

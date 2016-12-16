/*
** move_forward.c for wolf3d_autograder in /home/onehandedpenguin/Dev/CGP_2016/wolf3d_autograder/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Fri Dec 16 12:58:45 2016 Paul Laffitte
** Last update Fri Dec 16 17:48:05 2016 Paul Laffitte
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

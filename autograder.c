/*
** autograder.c for wolf3d_autograder in /home/onehandedpenguin/Dev/CGP_2016/bswolf3d/tests/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Fri Dec 16 11:16:57 2016 Paul Laffitte
** Last update Fri Dec 16 12:10:15 2016 Paul Laffitte
*/

#include <stdio.h>
#include <SFML/System.h>
#include "autograder.h"

sfVector2f	move_forward(sfVector2f pos, float direction, float distance);

int		test_move_forward(sfVector2f pos,
				  float direction, float distance)
{
  printf("(%8.2f, %8.2f) => ", pos.x, pos.y);
  pos = move_forward(pos, direction, distance);
  printf("(%8.2f, %8.2f) with : direction = %8.2f°, distance = %8.2f\n",
	 pos.x, pos.y, direction, distance);
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

int		launch_test(char *name, t_test_func test)
{
  printf("--------------------------------------\n===== TEST: %-20s =====\n\
--------------------------------------\n\n", name);
  test();
  printf("\n\n");
  return (0);
}

int		main()
{
  launch_test("Move Forward", &tests_move_forward);
}

/*
** autograder.c for wolf3d_autograder in /home/onehandedpenguin/Dev/CGP_2016/bswolf3d/tests/
**
** Made by Paul Laffitte
** Login   <paul.laffitte@epitech.eu>
**
** Started on  Fri Dec 16 11:16:57 2016 Paul Laffitte
** Last update Fri Dec 16 16:08:09 2016 Paul Laffitte
*/

#include <stdio.h>
#include <unistd.h>
#include <SFML/System.h>
#include "autograder.h"

int		launch_test(char *name, t_test_func test)
{
  printf("--------------------------------------\n===== TEST: %-20s =====\n\
--------------------------------------\n\n", name);
  test();
  printf("\n");
  return (0);
}

int		main()
{
  launch_test("Move Forward", &tests_move_forward);
  launch_test("Raycast", &tests_raycast);
}

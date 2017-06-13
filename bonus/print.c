/*
** print.c for print in /home/broscas/code/CPE_2016_Lemin/bonus
** 
** Made by Ryan Granet
** Login   <ryan.granet@epitech.eu>
** 
** Started on  Sun Apr 30 13:40:18 2017 Ryan Granet
** Last update Sun Apr 30 13:49:40 2017 Ryan Granet
*/

#include "lem_in.h"

void    my_putchar(char c)
{
  write(1, &c, 1);
}

void    my_print_map(char **map)
{
  int   i;

  i = -1;
  while (map[++i])
    {
      my_putstr(map[i]);
      my_putchar('\n');
    }
}

/*
** my_putstr.c for my_putstr in /home/Nyavenger/CPool_Day04
** 
** Made by Jonathan Delestre
** Login   <Nyavenger@epitech.net>
** 
** Started on  Thu Oct  6 10:21:27 2016 Jonathan Delestre
** Last update Thu Apr  6 09:46:55 2017 Jonathan Delestre
*/

#include "my.h"

int	my_putstr(char *str)
{
  int	count;

  count = 0;
  while (str[count] != '\0')
    {
      my_putchar(str[count]);
      count = count + 1;
    }
  return (count);
}

/*
** my_putnprint.c for my_putnprint in /home/Nyavenger/PSU/PSU_2016_my_printf
** 
** Made by Jonathan Delestre
** Login   <Nyavenger@epitech.net>
** 
** Started on  Tue Nov 15 15:36:51 2016 Jonathan Delestre
** Last update Thu Apr  6 10:01:59 2017 Jonathan Delestre
*/

#include "my.h"

int	my_put_oct(int nb);

int	my_putnprint(char *str)
{
  int	i;
  int	print;

  i = 0;
  print = 0;
  while (str[i] != 0)
    {
      if (str[i] < 32 || str[i] >= 127)
	{
	  my_putchar('\\');
	  print = print + my_put_oct(str[i]);
	}
      else
	my_putchar(str[i]);
      i++;
    }
  return (print + i);
}

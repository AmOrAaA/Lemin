/*
** my_put_nbr.c for my_put_nbr in /home/Nyavenger/CPool_Day03
** 
** Made by Jonathan Delestre
** Login   <Nyavenger@epitech.net>
** 
** Started on  Wed Oct  5 22:53:25 2016 Jonathan Delestre
** Last update Thu Apr  6 09:46:34 2017 Jonathan Delestre
*/

#include "my.h"

int	my_put_nbr(int nb)
{
  int	value;
  int	div;
  int	print;

  div = 1;
  print = 0;
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
      print++;
    }
  while (div <= nb)
    div = div * 10;
  div = div / 10;
  while (div > 0)
    {
      value = (nb / div) % 10;
      my_putchar(value + '0');
      div = div / 10;
      print++;
    }
  if (nb == 0)
    my_putchar('0');
  return (print);
}

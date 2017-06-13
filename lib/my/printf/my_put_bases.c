/*
** my_put_bases.c for my_put_bases in /home/Nyavenger/PSU/PSU_2016_my_printf
** 
** Made by Jonathan Delestre
** Login   <Nyavenger@epitech.net>
** 
** Started on  Wed Nov 16 10:49:41 2016 Jonathan Delestre
** Last update Thu Apr  6 10:21:47 2017 Jonathan Delestre
*/

#include "my.h"

int	my_put_hex(int nb)
{
  int	value;
  int	div;
  int	print;

  div = 1;
  print = 0;
  if (nb < 0)
    nb = -nb;
  while (div <= nb)
    div = div * 16;
  div = div / 16;
  while (div > 0)
    {
      value = (nb / div) % 16;
      if (value >= 0 && value <= 9)
	my_putchar(value + '0');
      else if (value > 9)
	my_putchar((value - 10) + 'A');
      div = div / 16;
      print++;
    }
  return (print);
}

int	my_put_hex_nc(int nb)
{
  int	value;
  int	div;
  int	print;

  div = 1;
  print = 0;
  if (nb < 0)
    nb = -nb;
  while (div <= nb)
    div = div * 16;
  div = div / 16;
  while (div > 0)
    {
      value = (nb / div) % 16;
      if (value >= 0 && value <= 9)
	my_putchar(value + '0');
      else if (value > 9)
	my_putchar((value - 10) + 'a');
      div = div / 16;
      print++;
    }
  return (print);
}

int	my_put_binary(int nb)
{
  int	value;
  int	div;
  int	print;

  div = 1;
  print = 0;
  if (nb < 0)
    {
      my_putchar('-');
      print++;
      nb = -nb;
    }
  while (div <= nb)
    div = div * 2;
  div = div / 2;
  while (div > 0)
    {
      value = (nb / div) % 2;
      my_putchar(value + '0');
      div = div / 2;
      print++;
    }
  return (print);
}

int	my_put_oct(int nb)
{
  int	value;
  int	div;
  int	print;

  div = 1;
  print = 0;
  if (nb < 0)
    nb = -nb;
  while (div <= nb)
    div = div * 8;
  div = div / 8;
  while (div > 0)
    {
      value = (nb / div) % 8;
      my_putchar(value + '0');
      div = div / 8;
      print++;
    }
  return (print);
}

int	my_put_unbr(int nb)
{
  if (nb < 0)
    nb = -nb;
  my_put_nbr(nb);
  return (0);
}

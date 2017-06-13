/*
** my_puterr.c for my_puterr in /home/Nyavenger/MUL/wireframe
** 
** Made by Jonathan Delestre
** Login   <Nyavenger@epitech.net>
** 
** Started on  Mon Dec  5 16:40:03 2016 Jonathan Delestre
** Last update Sat Feb 25 14:19:16 2017 Jonathan Delestre
*/

#include <unistd.h>

void	my_putchar(char c);

void	my_putchar_e(char c)
{
  write(2, &c, 1);
}

int	my_puterr(char *str, int x)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      my_putchar_e(str[i]);
      i++;
    }
  return (x);
}

int	my_retstr(char *str, int x)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      my_putchar(str[i]);
      i++;
    }
  return (x);
}

int     my_put_errnbr(int nb)
{
  int   value;
  int   div;
  int   print;

  div = 1;
  print = 0;
  if (nb < 0)
    {
      my_putchar_e('-');
      nb = -nb;
      print++;
    }
  while (div <= nb)
    div = div * 10;
  div = div / 10;
  while (div > 0)
    {
      value = (nb / div) % 10;
      my_putchar_e(value + '0');
      div = div / 10;
      print++;
    }
  if (nb == 0)
    my_putchar_e('0');
  return (print);
}

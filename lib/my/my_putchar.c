/*
** my_putchar.c for my_putchar in /home/Nyavenger/CPool_Day03
** 
** Made by Jonathan Delestre
** Login   <Nyavenger@epitech.net>
** 
** Started on  Wed Oct  5 10:30:10 2016 Jonathan Delestre
** Last update Thu Apr  6 09:44:17 2017 Jonathan Delestre
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

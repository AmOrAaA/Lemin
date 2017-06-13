/*
** print_error_third.c for  in /home/amoraa/CPE_2016_Lemin/src
** 
** Made by Florian Testu
** Login   <florian.testu@epitech.eu>
** 
** Started on  Sat Apr 29 17:49:51 2017 Florian Testu
** Last update Sat Apr 29 17:51:02 2017 Florian Testu
*/

#include "lem_in.h"

void    print_room(char **tab)
{
  int   i;

  i = 0;
  my_putstr("#rooms\n");
  while (tab[++i] != NULL)
    {
      if (tab[i][0] == '#')
        {
          if ((my_strcmp("##end", tab[i]) == 0)
              || (my_strcmp("##start", tab[i]) == 0))
            {
            my_putstr(tab[i]);
            my_putchar('\n');
            }
        }
      else
        {
          my_putstr(tab[i]);
          my_putchar('\n');
        }
    }
}
void    print_if_second_ok1(int i, int x)
{
  if (i == 1)
    my_putstr("#rooms\n");
  if (i == x)
    my_putstr("#tunnels\n");
}

void    print_if_second_ok1_5(char **tab, int i)
{
  my_putstr(tab[i]);
  my_putchar('\n');
}

void    print_if_second_ok2(char **tab, int i, int x)
{
  if ((i > x && tab[i][0] >= 'a' && tab[i][0] <= 'z') ||
      (i > x && tab[i][0] >= 'A' && tab[i][0] <= 'Z'));
  else if (tab[i][0] != '\0')
    {
      my_putstr(tab[i]);
      my_putchar('\n');
    }
}

void    print_if_second_ok3(char **tab, int i)
{
  if ((my_strcmp("##start", tab[i])) != 0
      && (my_strcmp("##end", tab[i])) != 0);
  else
    print_if_second_ok1_5(tab, i);
}

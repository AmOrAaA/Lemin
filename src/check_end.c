/*
** check_end.c for  in /home/AmOrAA/Delivery/Lemin/CPE_2016_Lemin/src
** 
** Made by Florian Testu
** Login   <AmOrAA@epitech.net>
** 
** Started on  Tue Apr 25 11:49:29 2017 Florian Testu
** Last update Sun Apr 30 04:49:08 2017 Florian Testu
*/

#include "lem_in.h"

int     all_check_end_third(t_pars *list, int i)
{
  if ((i = check_double_path(list)) != 0)
    {
      my_putstr("#moves\n");
      return (84);
    }
  return (0);
}

int     all_check_end_second(t_pars *list, char **tab, int i)
{
  if ((i = check_idem_room(list)) != 0)
    {
      if (i == 84)
	{
	  my_putstr("#moves\n");
	  return (84);
	}
      return (0);
    }
  if ((all_check_end_third(list, i)) != 0)
    return (84);
  if ((i = check_error_path(list, tab)) != 0)
    {
      my_putstr("#moves\n");
      return (84);
    }
  if ((i = check_idem_path(list)) != 0)
    {
      my_putstr("#moves\n");
      return (84);
    }
  return (0);
}

int	check_first(char **tab)
{
  int	i;
  int	j;
  int	x;

  i = -1;
  while (tab[++i] != '\0')
    {
      j = -1;
      x = 0;
      while (tab[++j] != NULL)
	{
	  if ((my_strcmp(tab[i], tab[j])) == 0)
	      x++;
	  if (x == 2)
	    return (84);
	}
    }
  return (0);
}

int     all_check_end(t_pars *list)
{
  char  *str;
  char  **tab;
  int   i;

  str = take_my_room(list);
  tab = my_str_to_wordtab(str);
  if ((check_first(tab)) == 84)
    {
      my_putstr("#moves\n");
      return (84);
    }
  if ((i = coor_check(list->all)) != 0)
    {
      my_putstr("#moves\n");
      return (84);
    }
  if ((all_check_end_second(list, tab, i)) != 0)
    return (84);
  return (0);
}

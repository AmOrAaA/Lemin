/*
** coor_check.c for  in /home/bertag_l/rendu/C_Prom_elem/Lemin123/CPE_2016_Lemin/src
** 
** Made by Loïc Bertagna
** Login   <bertag_l@epitech.net>
** 
** Started on  Sat Apr 22 14:45:29 2017 Loïc Bertagna
** Last update Fri Apr 28 18:23:51 2017 Florian Testu
*/

#include "lem_in.h"

int	check_my_coor_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i = i + 1;
  return (i);
}

int	check_double_coor_tab(char **tab)
{
  int	i;
  int	j;

  i = 1;
  while (tab[i] != NULL)
    {
      j = 0;
      while (tab[i][j] != '\0')
	{
	  if (tab[i][j] < '0' || tab[i][j] > '9')
	    return (84);
	  j = j + 1;
	}
      i = i + 1;
    }
  return (0);
}

int	coor_check(char **tab)
{
  int	i;
  int	er;
  char	**che;

  i = 0;
  while (tab[i] != NULL)
    {
      che = my_mod_str_to_wordtab(tab[i], ' ');
      if (check_my_coor_tab(che) != 3)
	return (84);
      er = check_double_coor_tab(che);
      if (er == 84)
	return (i);
      free(che);
      i = i + 1;
    }
  return (0);
}

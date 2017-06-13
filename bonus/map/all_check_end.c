/*
** all_check_end.c for  in /home/amoraa/Delivery/Lemin/CPE_2016_Lemin/src
** 
** Made by Florian Testu
** Login   <florian.testu@epitech.eu>
** 
** Started on  Wed Apr 19 13:51:57 2017 Florian Testu
** Last update Sat Apr 29 16:20:19 2017 Florian Testu
*/

#include "lem_in.h"

int	check_error_path(t_pars *list, char **tab)
{
  int	i;
  int	j;
  int	k;
  char	*copy;
  char	*copy2;

  i = -1;
  while (list->path[++i] != NULL)
    {
      j = k = -1;
      if ((copy = malloc(sizeof(char) * (my_stlen(list->path[i])) + 1)) == NULL)
	return (84);
      while (list->path[i][++j] != '-')
	copy[++k] = list->path[i][j];
      if ((check_room(tab, copy)) != 0)
	return (++i);
      if ((copy2 = malloc(sizeof(char) * (strd(list->path[i], j)) + 1)) == NULL)
	  return (84);
      k = -1;
      while (list->path[i][++j] && list->path[i][j] != '-')
	copy2[++k] = list->path[i][j];
      if ((check_room(tab, copy2)) != 0)
	return (++i);
    }
  return (0);
}

int     check_idem_room(t_pars *list)
{
  int   i;
  int   j;
  int   k;
  char  *copy;

  i = -1;
  while (list->all[++i] != NULL)
    {
      j = k = -1;
      copy = NULL;
      free(copy);
      while (list->all[i][++j] && list->all[i][j] != ' ');
      if ((copy = malloc(sizeof(char) * (strd(list->all[i], j)) + 1)) == NULL)
	  return (84);
      while (list->all[i][++j] != '\0')
        copy[++k] = list->all[i][j];
      if ((j = check_idem_room_second(list->all, copy, i)) != 0)
	return (84);
    }
  return (0);
}

int	check_idem_path(t_pars *list)
{
  int	i;
  char	*copy;

  i = -1;
  while (list->path[++i] != NULL)
    {
      copy = NULL;
      free(copy);
      copy = my_strdup(list->path[i]);
      if ((check_idem_path_second(list, copy, i)) != 0)
	return (++i);
    }
  return (0);
}

int	check_double_path(t_pars *list)
{
  int	i;
  int	j;
  int	x;

  i = -1;
  while (list->path[++i] != NULL)
    {
      j = -1;
      x = 0;
      while (list->path[i][++j] != '\0')
	{
	  if (list->path[i][j] == '-')
	    x++;
	  if (x > 1)
	    return (++i);
	}
    }
  return (0);
}

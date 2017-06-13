/*
** path.c for path in /home/nyavenger/CPE/CPE_2016_Lemin/src
** 
** Made by Jonathan Delestre
** Login   <jonathan.delestre@epitech.eu>
** 
** Started on  Fri Apr 21 17:34:56 2017 Jonathan Delestre
** Last update Sat Apr 29 15:39:46 2017 Jonathan Delestre
*/

#include "lem_in.h"

int		tab_len(char **tab, int size)
{
  int		i;
  int		len;

  i = -1;
  len = 0;
  while (tab[++i])
    {
      len += (my_strlen(tab[i]) + 1);
      if (size == 2)
	{
	  my_putstr(tab[i]);
	  my_putchar('\n');
	}
    }
  if (size == 1)
    return (len);
  else
    return (i);
}

void		free_tab(char **tab)
{
  int		i;

  i = tab_len(tab, 0);
  while (--i <= 0)
    free(tab[i]);
  free(tab);
}

char		**add_link(char **link, char *str, t_pars *list)
{
  static int	i = 0;

  if (link == NULL)
    {
      if ((link = malloc(sizeof(char) * tab_len(list->path, 1))) == NULL)
	return (NULL);
      i = 0;
    }
  link[i] = my_strdup(str);
  i++;
  return (link);
}

void		get_links(char **left, char **right, char *str)
{
  int		i;

  i = 0;
  while (str[i] != 0 && str[i] != '-')
    i++;
  if ((*left = malloc(sizeof(char) * i + 1)) == NULL)
    return;
  if ((*right = malloc(sizeof(char) * (my_strlen(str) - i) + 1)) == NULL)
    return;
  *left = my_strncpy(*left, str, i);
  *right = my_strxncpy(*right, str, my_strlen(str) - i - 1, i + 1);
}

void		fill_path(t_hill **hill, t_pars *list)
{
  int		i;
  char		*left;
  char		*right;

  i = -1;
  while (list->path[++i])
    {
      get_links(&left, &right, list->path[i]);
      if (my_cmp((*hill)->name, left) == 0
	  && my_cmp((*hill)->name, right) != 0)
	(*hill)->link = add_link((*hill)->link, right, list);
      if (my_cmp((*hill)->name, right) == 0
	  && my_cmp((*hill)->name, left) != 0)
	(*hill)->link = add_link((*hill)->link, left, list);
      free(left);
      free(right);
    }
}

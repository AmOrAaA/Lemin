/*
** anthill.c for anthill in /home/nyavenger/CPE/CPE_2016_Lemin/src
** 
** Made by Jonathan Delestre
** Login   <jonathan.delestre@epitech.eu>
** 
** Started on  Thu Apr 20 13:11:52 2017 Jonathan Delestre
** Last update Sat Apr 29 15:41:40 2017 Jonathan Delestre
*/

#include "lem_in.h"

char		*get_name(char *str)
{
  char		*dup;
  int		i;

  i = 0;
  while (str[i] != 0 && str[i] != ' ')
    i++;
  if ((dup = malloc(sizeof(char) * i + 1)) == NULL)
    return (NULL);
  dup = my_strncpy(dup, str, i);
  return (dup);
}

void		init_hill(t_hill **hill, t_pars *list)
{
  (*hill)->name = get_name(list->all[0]);
  (*hill)->ant = -1;
  (*hill)->posx = -1;
  (*hill)->posy = -1;
  (*hill)->start = -1;
  (*hill)->end = -1;
  (*hill)->link = NULL;
  (*hill)->prev = NULL;
  if (my_cmp(list->start, list->all[0]) == 0)
    {
      (*hill)->ant = list->nbr + 1;
      (*hill)->start = list->nbr;
    }
  if (my_cmp(list->end, list->all[0]) == 0)
    {
      (*hill)->ant = 0;
      (*hill)->end = 0;
    }
  fill_path(hill, list);
}

void		add_hill(t_hill **hill, t_pars *list, int pos)
{
  t_hill	*tmp;

  if ((tmp = malloc(sizeof(t_hill))) == NULL)
    return;
  tmp->name = get_name(list->all[pos]);
  tmp->ant = -1;
  tmp->posx = -1;
  tmp->posy = -1;
  tmp->start = -1;
  tmp->end = -1;
  if (my_cmp(list->start, list->all[pos]) == 0)
    {
      tmp->ant = list->nbr + 1;
      tmp->start = list->nbr;
    }
  if (my_cmp(list->end, list->all[pos]) == 0)
    {
      tmp->ant = 0;
      tmp->end = 0;
    }
  (*hill)->next = tmp;
  tmp->prev = *hill;
  *hill = (*hill)->next;
  (*hill)->link = NULL;
  fill_path(hill, list);
}

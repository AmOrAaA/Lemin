/*
** memory.c for memory in /home/nyavenger/CPE/CPE_2016_Lemin/src
** 
** Made by Jonathan Delestre
** Login   <jonathan.delestre@epitech.eu>
** 
** Started on  Fri Apr 21 17:42:57 2017 Jonathan Delestre
** Last update Fri Apr 21 17:47:42 2017 Jonathan Delestre
*/

#include "lem_in.h"

void	mem_free(t_pars *list)
{
  int	i;

  free(list->end);
  free(list->start);
  i = -1;
  while (list->all[++i]);
  i++;
  while (-i >= 0)
    free(list->all[i]);
  free(list->all);
  i = -1;
  while (list->path[++i]);
  i++;
  while (-i >= 0)
    free(list->path[i]);
  free(list->path);
}

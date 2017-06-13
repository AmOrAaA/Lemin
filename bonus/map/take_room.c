/*
** take_room.c for  in /home/amoraa/Delivery/Lemin/CPE_2016_Lemin/src
** 
** Made by Florian Testu
** Login   <florian.testu@epitech.eu>
** 
** Started on  Thu Apr 20 16:08:48 2017 Florian Testu
** Last update Sat Apr 29 14:45:14 2017 Florian Testu
*/

#include "lem_in.h"

int     my_stroom(char *str)
{
  int   i;

  i = -1;
  while (str[++i] && str[i] != ' ');
  return (i);
}

char    *take_str_room(t_pars *list, int *i, char *str)
{
  int   j;
  int   k;

  k = 0;
  while (list->all[++i[0]] != NULL)
    {
      if ((str = malloc(sizeof(char) *
			(my_stroom(list->all[i[0]]) + 2))) == NULL)
        return (0);
      j = -1;
      while (list->all[i[0]][++j] && list->all[i[0]][j] != ' ')
        str[k++] = list->all[i[0]][j];
      str[k] = '\0';
      break;
    }
  return (str);
}

int     check_exit_room(t_pars *list, int i)
{
  int   check;
  int   j;

  check = i;
  j = -1;
  while (list->all[check][++j] != ' ')
    {
      if (list->all[check][j] == '-')
        return (1);
    }
  return (0);
}

char    *take_suit_room(t_pars *list, int i, char *str, char *copy)
{
  int   j;
  int   k;

  while (list->all[++i] != NULL)
    {
      if (copy != NULL)
        str = my_strcat(str, copy);
      copy = NULL;
      k = 0;
      copy = malloc(sizeof(char) * (my_stroom(list->all[i]) + 1));
      if ((check_exit_room(list, i)) == 1)
	break;
      j = -1;
      while (list->all[i][++j] && list->all[i][j] != ' ')
        {
          if (list->all[i][j] == '-')
            break;
          copy[k++] = list->all[i][j];
        }
      copy[k] = '\0';
      copy = my_strcat(copy, "\n");
    }
  if (copy != NULL)
    str = my_strcat(str, copy);
  return (str);
}

char    *take_my_room(t_pars *list)
{
  int   i;
  char  *copy;
  char  *str;

  i = -1;
  str = NULL;
  str = take_str_room(list, &i, str);
  str = my_strcat(str, "\n");
  copy = NULL;
  str = take_suit_room(list, i, str, copy);
  return (str);
}

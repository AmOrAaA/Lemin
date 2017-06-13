/*
** my_str_to_wordtab.c for  in /home/AmOrAA/Delivery/mini_shell/PSU_2016_minishell1
** 
** Made by Florian Testu
** Login   <AmOrAA@epitech.net>
** 
** Started on  Thu Jan 19 13:00:36 2017 Florian Testu
** Last update Fri Apr 14 10:24:32 2017 Florian Testu
*/

#include "my.h"

int	my_strlen_at_the_line(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] != '\n' && str[i] != '\t' && str[i] != ':')
	j = j + 1;
      i = i + 1;
    }
  return (j + 1);
}

int	my_len_space(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] != '\t'
	 && str[i] != ':' && str[i] != '\n')
    i = i + 1;
  return (i);
}

char	**my_str_to_wordtab(char *str)
{
  char **tab;
  int	i;
  int	j;
  int	a;

  a = 0;
  j = 0;
  if ((tab = malloc(sizeof(char*) * my_strlen_at_the_line(str) + 1)) == NULL)
    return (NULL);
  while (str[a] == '\t')
    a++;
  while (str[a] != '\0')
    {
      if ((tab[j] = malloc(sizeof(char) * my_len_space(&str[a]) + 2)) == NULL)
	return (NULL);
      i = -1;
      while (my_len_space(&str[a]) != 0)
	tab[j][++i] = str[a++];
      tab[j][i + 1] = '\0';
      j = j + 1;
      if (str[a] != '\0')
	a = a + 1;
    }
  tab[j] = NULL;
  return (tab);
}

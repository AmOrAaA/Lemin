/*
** my_str_to_wordtab.c for  in /home/AmOrAA/Delivery/mini_shell/PSU_2016_minishell1
** 
** Made by Florian Testu
** Login   <AmOrAA@epitech.net>
** 
** Started on  Thu Jan 19 13:00:36 2017 Florian Testu
** Last update Sat Apr 22 18:38:23 2017 Loïc Bertagna
*/

#include "my.h"

int	my_mod_strlen_at_the_line(char *str, char c)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] != '\n' && str[i] != '\t' && str[i] != ':'
	  && str[i] != c)
	j = j + 1;
      i = i + 1;
    }
  return (j + 1);
}

int	my_mod_len_space(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] != '\t'
	 && str[i] != ':' && str[i] != '\n'
	 && str[i] != c)
    i = i + 1;
  return (i);
}

char	**full_tab(char **tab, char *str, char c, int a)
{
  int	i;
  int	j;

  j = 0;
  while (str[a] != '\0')
    {
      if ((tab[j] = malloc(sizeof(char) * my_mod_len_space(&str[a], c) + 2))
	  == NULL)
	return (NULL);
      i = -1;
      while (my_mod_len_space(&str[a], c) != 0)
	tab[j][++i] = str[a++];
      tab[j][i + 1] = '\0';
      j = j + 1;
      if (str[a] != '\0')
	a = a + 1;
    }
  tab[j] = NULL;
  return (tab);
}

char	**my_mod_str_to_wordtab(char *str, char c)
{
  char **tab;
  int	a;

  a = 0;
  if ((tab = malloc(sizeof(char*) * my_mod_strlen_at_the_line(str, c) + 1))
      == NULL)
    return (NULL);
  while (str[a++] == '\t');
  return (full_tab(tab, str, c, a));
}

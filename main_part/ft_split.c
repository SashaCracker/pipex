/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgummy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 13:06:48 by sgummy            #+#    #+#             */
/*   Updated: 2021/04/27 13:06:50 by sgummy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_numwords(char const *s, char c)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while ((s[i] == c) && (s[i] != '\0'))
			i++;
		if ((s[i] != c) && (s[i] != '\0'))
			n++;
		while ((s[i] != c) && (s[i] != '\0'))
			i++;
	}
	return (n);
}

static int	ft_len_of_middle(char const *s, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while ((s[i] != c) && (s[i] != '\0'))
	{
		k++;
		i++;
	}
	return (k);
}

static char	*ft_middle(char const *s, char c)
{
	int		n;
	char	*middle;

	n = ft_len_of_middle(s, c);
	middle = (char *) malloc(sizeof (char) * (n + 1));
	if (middle == 0)
		return (0);
	ft_strlcpy (middle, s, n + 1);
	middle[n] = 0;
	return (middle);
}

static char	**ft_freemalloc(char **mass)
{
	int	j;

	j = ft_strlen(*mass);
	while ((j + 1) > 0)
	{
		free(mass[j--]);
		j--;
	}
	free(mass);
	mass = 0;
	return (mass);
}

char	**ft_split(char const *s, char c)
{
	int		n;
	int		j;
	char	**result;

	if (s == 0)
		return (NULL);
	n = ft_numwords(s, c);
	j = 0;
	result = (char **) malloc(sizeof (char *) * (n + 1));
	if (result == 0)
		return (NULL);
	while ((j < n) && (*s != '\0'))
	{
		while (*s == c)
			s++;
		result[j] = ft_middle(s, c);
		if (result[j] == 0)
			ft_freemalloc(result);
		s = s + ft_strlen(result[j]);
		j++;
	}
	result[n] = 0;
	return (result);
}

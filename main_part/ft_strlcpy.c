/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgummy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:28:15 by sgummy            #+#    #+#             */
/*   Updated: 2021/04/22 13:28:17 by sgummy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if ((dst != 0) || (src != 0))
	{
		if (dstsize != 0)
		{
			while ((i < (dstsize - 1)) && (src[i] != '\0'))
			{
				dst[i] = src[i];
				i++;
			}
			dst[i] = '\0';
		}
		return (ft_strlen(src));
	}
	return (0);
}

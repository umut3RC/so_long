/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:35:56 by akaraca           #+#    #+#             */
/*   Updated: 2022/06/25 18:40:49 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *save)
{
	int	i;

	i = 0;
	if (!save)
		return (0);
	while (save[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *save, int c)
{
	int	i;

	i = 0;
	if (!save)
		return (0);
	while (save[i] != '\0')
	{
		if (save[i] == (char)c)
			return ((char *)&save[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *save, char *buffer)
{
	char	*temp;
	int		i;
	int		l;

	if (!save)
	{
		save = (char *)malloc(sizeof(char) * 1);
		save[0] = '\0';
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(save) +\
				ft_strlen(buffer) + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (save[i] != '\0')
	{
		temp[i] = save[i];
		i++;
	}
	l = 0;
	while (buffer[l] != '\0')
		temp[i++] = buffer[l++];
	temp[i] = '\0';
	free(save);
	return (temp);
}

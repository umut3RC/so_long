/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.ğ                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:04:25 by uercan            #+#    #+#             */
/*   Updated: 2022/06/21 13:41:16 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *src)
{
	size_t	i;
	char	*str;

	str = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*src)
	{
		str[i] = *src;
		src++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

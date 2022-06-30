/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uercan <uercan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 14:47:30 by uercan            #+#    #+#             */
/*   Updated: 2022/06/21 16:54:10 by uercan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	find_long(int n)
{
	int	l;

	l = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		l++;
	while (n)
	{
		n /= 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	size_t		i;
	size_t		l;
	char		*temp;

	i = 0;
	temp = (char *)malloc(sizeof(char) * (l = find_long(n)) + 1);
	if (temp == 0)
		return (NULL);
	if (n < 0)
	{
		temp[0] = '-';
		i = 1;
	}
	temp[l] = '\0';
	while (l-- > i)
	{
		if (n > 0)
			temp[l] = '0' + (n % 10);
		else
			temp[l] = '0' + (n % 10) * (-1);
		n = n / 10;
	}
	return (temp);
}

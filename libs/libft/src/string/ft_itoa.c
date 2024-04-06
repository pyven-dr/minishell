/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:16:25 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/11/12 16:30:50 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*reverse(char *res)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = 0;
	while (res[end])
		end++;
	end--;
	while (end > start)
	{
		temp = res[start];
		res[start] = res[end];
		res[end] = temp;
		start++;
		end--;
	}
	return (res);
}

static	int	n_len(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*res;

	i = n_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n <= 0)
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (0);
	res[i] = '\0';
	if (n < 0)
	{
		res[i - 1] = '-';
		n *= -1;
	}
	i = 0;
	res[i] = '0';
	while (n != 0)
	{
		res[i++] = (n % 10) + 48;
		n /= 10;
	}
	return (reverse(res));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 12:32:32 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/05 14:48:02 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_num(int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*str(char *new_s, int n, int count, int pos_or_neg)
{
	int	origin;

	origin = n;
	while (n > 0 && count >= pos_or_neg)
	{
		n = n % 10;
		new_s[count] = n + '0';
		origin = origin / 10;
		n = origin;
		count--;
	}
	return (new_s);
}

char	*positive(int n, int count, int origin)
{
	char	*new_s;

	count = count_num(n);
	new_s = malloc(count + 1);
	if (!new_s)
	{
		return (0);
	}
	n = origin;
	new_s[count] = '\0';
	count -= 1;
	return (str(new_s, n, count, 0));
}

char	*negative(int n, int count, int origin)
{
	char	*new_s;

	count = count_num(n);
	new_s = malloc(count + 1 + 1);
	if (!new_s)
	{
		return (0);
	}
	origin *= -1;
	n = origin;
	new_s[count + 1] = '\0';
	new_s[0] = '-';
	return (str(new_s, n, count, 1));
}

char	*ft_itoa(int n)
{
	int		count;
	int		origin;

	count = 0;
	origin = n;
	if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	if (n > 0)
	{
		return (positive(n, count, origin));
	}
	else if (n == 0)
	{
		return (ft_strdup("0"));
	}
	else if (n < 0)
	{
		n *= -1;
		return (negative(n, count, origin));
	}
	return (0);
}

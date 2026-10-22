/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccascava <ccascava@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 11:22:00 by ccascava          #+#    #+#             */
/*   Updated: 2026/10/07 13:07:52 by ccascava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

const char	*after_whitespace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
	{
		i++;
	}
	while (str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
	{
		i++;
	}
	return (&str[i]);
}

int	calculate_number(const char *str)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	return (number);
}

int	how_many_signs(const char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		count++;
		i++;
	}
	return (count);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	number;
	int	sign;
	int	count;

	number = 0;
	count = 0;
	i = 0;
	sign = 1;
	str = after_whitespace(str);
	count = how_many_signs(str);
	if (count > 1)
	{
		return (0);
	}
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	number = calculate_number(&str[i]);
	return (number * sign);
}

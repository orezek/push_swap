/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldokezer <aldokezer@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:37:11 by aldokezer         #+#    #+#             */
/*   Updated: 2024/02/15 12:20:31 by aldokezer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	ft_is_int32(char *arg)
{
	long long	number;

	number = ft_atol(arg);
	if (number <= INT32_MAX && number >= INT32_MIN)
		return (true);
	else
		return (false);
	return (true);
}

bool	ft_is_valid_nuber(char *str)
{
	if (*str == '-')
		str++;
	while (*str != '\0')
		if (!ft_isdigit(*(str++)))
			return (false);
	return (true);
}

static int	ft_isspace(int c)
{
	unsigned char	l;

	l = (unsigned char) c;
	if (l == ' ' || l == '\f' || l == '\n'
		|| l == '\r' || l == '\t' || l == '\v')
		return (1);
	return (0);
}

long	ft_atol(const char *string)
{
	int		is_negative;
	long	result;

	result = 0;
	is_negative = 0;
	while (ft_isspace(*string))
		string++;
	if (*string == '-')
	{
		is_negative = 1;
		string++;
	}
	else if (*string == '+')
		string++;
	while (ft_isdigit(*string))
	{
		if (!ft_isdigit(*(string + 1)))
		{
			if (is_negative)
				return ((result += ((long) *string) - 48) * -1);
			return (result += ((long) *string) - 48);
		}
		result = (result + (((long) *string++) - 48)) * 10;
	}
	return (0);
}

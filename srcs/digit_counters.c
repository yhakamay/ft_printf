/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_counters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhakamay <yhakamay@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:33:37 by yhakamay          #+#    #+#             */
/*   Updated: 2021/01/26 13:33:38 by yhakamay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		count_digit(unsigned long long p, t_info *info)
{
	int	digit;

	digit = 0;
	if (!p && info->acc)
		return (1);
	while (p)
	{
		p /= 16;
		digit++;
	}
	return (digit);
}

int		count_digit_i(long long p, t_info *info)
{
	int digit;

	digit = 0;
	if (!p && !info->acc)
		return (0);
	if (!p)
		return (1);
	if (p < 0)
	{
		p *= -1;
		info->int_minus = 1;
	}
	while (p)
	{
		p /= 10;
		digit++;
	}
	return (digit);
}

int		count_digit_ui(unsigned int p, t_info *info)
{
	int digit;

	digit = 0;
	if (!p && !info->acc)
		return (0);
	if (!p)
		return (1);
	if (p < 0)
	{
		p *= -1;
		info->int_minus = 1;
	}
	while (p)
	{
		p /= 10;
		digit++;
	}
	return (digit);
}

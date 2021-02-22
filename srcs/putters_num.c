/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putters_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhakamay <yhakamay@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:33:14 by yhakamay          #+#    #+#             */
/*   Updated: 2021/01/26 13:33:16 by yhakamay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	set_real_num(int digit, t_info *info)
{
	info->act_num = (digit > info->acc ? digit : info->acc);
	info->act_num += (info->int_minus == 1 ? 1 : 0);
	info->act_wid = (info->act_num > info->field ? info->act_num : info->field);
}

void	put_int_arr(long long x, char **str, int digit, t_info *info)
{
	int		i;
	char	*p;

	p = *str;
	if (x < 0)
	{
		x *= -1;
		info->int_minus = 1;
	}
	i = 0;
	while (i++ < digit)
	{
		**str = x % 10 + '0';
		x /= 10;
		(*str)++;
	}
	**str = '\0';
	swap_str(p, digit);
	*str = p;
}

void	put_int_str(int digit, t_info *info, char **str)
{
	int		i;
	char	zero;

	zero = '0';
	i = 0;
	if (info->acc > digit)
	{
		while (i++ < info->acc - digit)
			write(1, &zero, 1);
	}
	write(1, *str, digit);
}

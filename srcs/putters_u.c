/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putters_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhakamay <yhakamay@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:32:31 by yhakamay          #+#    #+#             */
/*   Updated: 2021/01/26 13:32:34 by yhakamay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	put_arr_u(unsigned int x, char **str, int digit, t_info *info)
{
	int				i;
	char			*p;

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

void	put_u(int *n, va_list *arg, t_info *info)
{
	int				digit;
	char			*str;
	long long		p;

	p = va_arg(*arg, unsigned int);
	digit = count_digit_ui(p, info);
	if (!(str = (char*)malloc(digit + 1)))
	{
		*n = -1;
		return ;
	}
	put_arr_u(p, &str, digit, info);
	set_real_num(digit, info);
	if (info->is_min == 1)
		put_int_sp(digit, info, &str);
	else if (info->is_zero == 1)
		put_int_zero(digit, info, &str);
	else
		put_int_noflag(digit, info, &str);
	*n += info->act_wid;
	free(str);
}

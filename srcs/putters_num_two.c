/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putters_num_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhakamay <yhakamay@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:34:36 by yhakamay          #+#    #+#             */
/*   Updated: 2021/01/26 13:34:39 by yhakamay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	put_int(int *n, va_list *arg, t_info *info)
{
	int			digit;
	char		*str;
	long long	p;

	p = va_arg(*arg, int);
	digit = count_digit_i(p, info);
	if (!(str = (char*)malloc(digit + 1)))
	{
		*n = -1;
		return ;
	}
	put_int_arr(p, &str, digit, info);
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

void	put_int_sp(int digit, t_info *info, char **str)
{
	char	c;
	char	min;
	int		i;

	c = ' ';
	min = '-';
	i = 0;
	if (info->int_minus == 1)
		write(1, &min, 1);
	put_int_str(digit, info, str);
	while (i++ < info->act_wid - info->act_num)
		write(1, &c, 1);
}

void	put_int_zero(int digit, t_info *info, char **str)
{
	int		i;
	char	min;
	char	zero;

	i = 0;
	min = '-';
	zero = '0';
	if (info->acc != -1)
		put_int_noflag(digit, info, str);
	else
	{
		if (info->int_minus == 1)
			write(1, &min, 1);
		while (i++ < (info->act_wid - info->act_num))
			write(1, &zero, 1);
		put_int_str(digit, info, str);
	}
}

void	put_int_noflag(int digit, t_info *info, char **str)
{
	char	c;
	char	min;
	int		i;

	c = ' ';
	min = '-';
	i = 0;
	while (i++ < info->act_wid - info->act_num)
		write(1, &c, 1);
	if (info->int_minus == 1)
		write(1, &min, 1);
	put_int_str(digit, info, str);
}

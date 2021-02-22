/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putters_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhakamay <yhakamay@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:33:28 by yhakamay          #+#    #+#             */
/*   Updated: 2021/01/26 13:33:30 by yhakamay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	put_p(int *n, va_list *arg, t_info *info)
{
	unsigned long long	p;
	char				*str;
	int					digit;

	p = (uintptr_t)va_arg(*arg, void *);
	digit = count_digit(p, info);
	if (!(str = (char*)malloc(digit + 1)))
	{
		*n = -1;
		return ;
	}
	if (!p)
		clear_arr(str, digit);
	else
		to_hex(p, &str, digit, info);
	if ((info->field > digit + 2) && (info->field > info->acc + 2))
		put_p_sp(n, digit, info, str);
	else
		put_p_no_sp(n, digit, info, str);
	free(str);
}

void	put_p_no_sp(int *n, int digit, t_info *info, char *str)
{
	char	c;
	int		i;
	int		is_x;

	i = 0;
	c = '0';
	is_x = 0;
	if (info->spec == SPEC_P || info->is_hash == 1)
	{
		write(1, (info->spec == 7 ? "0X" : "0x"), 2);
		is_x = 1;
	}
	if (info->acc > digit)
	{
		while (i++ < info->acc - digit)
			write(1, &c, 1);
		write(1, str, digit);
		*n += (is_x ? 2 : 0) + info->acc;
	}
	else
	{
		write(1, str, digit);
		*n += (is_x ? 2 : 0) + digit;
	}
}

void	put_p_sp(int *n, int digit, t_info *info, char *str)
{
	char	c;
	int		i;
	int		j;
	int		ox;

	i = 0;
	if (info->is_min == -1 && info->acc == -1 && info->is_zero == 1)
		c = '0';
	else
		c = ' ';
	ox = (info->spec == 3 || info->is_hash == 1) ? 2 : 0;
	j = info->acc > digit ? info->acc : digit;
	*n += info->field - ox - j;
	if (info->is_min == -1)
	{
		while (i++ < info->field - ox - j)
			write(1, &c, 1);
		put_p_no_sp(n, digit, info, str);
	}
	if (info->is_min == 1)
	{
		put_p_no_sp(n, digit, info, str);
		while (i++ < info->field - ox - j)
			write(1, &c, 1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putters_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhakamay <yhakamay@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:34:54 by yhakamay          #+#    #+#             */
/*   Updated: 2021/01/26 13:34:56 by yhakamay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	put_hex(int *n, va_list *arg, t_info *info)
{
	unsigned int		p;
	char				*str;
	int					ox;
	int					digit;

	ox = (info->is_hash == 1 ? 2 : 0);
	p = va_arg(*arg, unsigned int);
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
	if ((info->field > digit + ox) && (info->field > info->acc + ox))
		put_p_sp(n, digit, info, str);
	else
		put_p_no_sp(n, digit, info, str);
	free(str);
}

void	to_hex(unsigned long long x, char **str, int n, t_info *info)
{
	unsigned long long	i;
	char				*p;

	p = *str;
	while (x)
	{
		i = x % 16;
		if (10 > i)
			**str = i + '0';
		else
			**str = (info->spec == SPEC_X_LARGE ? 'A' : 'a') + i - 10;
		x /= 16;
		(*str)++;
	}
	**str = '\0';
	swap_str(p, n);
	*str = p;
}

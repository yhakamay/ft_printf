/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhakamay <yhakamay@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:32:59 by yhakamay          #+#    #+#             */
/*   Updated: 2021/01/26 13:33:01 by yhakamay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	init_info(t_info *info)
{
	info->is_zero = -1;
	info->is_min = -1;
	info->is_plus = -1;
	info->is_space = -1;
	info->is_hash = -1;
	info->field = -1;
	info->acc = -1;
	info->spec = -1;
	info->null_check = -1;
	info->int_minus = -1;
}

void	check_info(char **s, t_info *info)
{
	if (**s == '0')
		info->is_zero = 1;
	if (**s == '-')
		info->is_min = 1;
	if (**s == '+')
		info->is_plus = 1;
	if (**s == ' ')
		info->is_space = 1;
	if (**s == '#')
		info->is_hash = 1;
	(*s)++;
}

int		check_spec(char **s, t_info *info)
{
	if (ptf_strchr("cspdiuxXn%", **s))
	{
		if (**s == 'c')
			info->spec = SPEC_C;
		if (**s == 's')
			info->spec = SPEC_S;
		if (**s == 'p')
			info->spec = SPEC_P;
		if (**s == 'd' || **s == 'i')
			info->spec = SPEC_D;
		if (**s == 'u')
			info->spec = SPEC_U;
		if (**s == 'x')
			info->spec = SPEC_X;
		if (**s == 'X')
			info->spec = SPEC_X_LARGE;
		if (**s == 'n')
			info->spec = SPEC_N;
		if (**s == '%')
			info->spec = SPEC_PCT;
		(*s)++;
		return (1);
	}
	return (0);
}

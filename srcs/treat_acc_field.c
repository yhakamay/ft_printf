/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_acc_field.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhakamay <yhakamay@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:33:46 by yhakamay          #+#    #+#             */
/*   Updated: 2021/01/26 13:35:48 by yhakamay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	check_acc(char **str, t_info *info, va_list *arg, int *n)
{
	(*str)++;
	if (**str == '*')
		star_acc(str, info, arg, n);
	else
		atoi_acc(str, info, n);
}

void	atoi_field(char **start, t_info *info, int *n)
{
	int	num;

	num = 0;
	while (**start >= '0' && **start <= '9')
	{
		num = num * 10 + (int)**start - '0';
		(*start)++;
	}
	info->field = num;
	if (info->field >= INT_MAX)
		*n = -1;
}

void	atoi_acc(char **start, t_info *info, int *n)
{
	int	num;

	num = 0;
	if (**start >= '0' && **start <= '9')
	{
		while (**start >= '0' && **start <= '9')
		{
			num = num * 10 + (int)**start - '0';
			(*start)++;
		}
		info->acc = num;
	}
	else
		info->acc = num;
	if (info->acc >= INT_MAX || info->acc <= INT_MIN)
		*n = -1;
}

void	star_field(char **s, t_info *info, va_list *arg, int *n)
{
	int	p;

	p = va_arg(*arg, int);
	if (p <= (INT_MIN + 1) || p >= INT_MAX)
	{
		*n = -1;
		(*s)++;
		return ;
	}
	if (p < 0)
	{
		info->is_min = 1;
		p *= -1;
		info->field = p;
	}
	else
		info->field = p;
	(*s)++;
}

void	star_acc(char **s, t_info *info, va_list *arg, int *n)
{
	int	p;

	p = va_arg(*arg, int);
	if (p < 0)
		info->acc = -1;
	else
		info->acc = p;
	if (info->acc >= INT_MAX || info->acc <= INT_MIN)
		*n = -1;
	(*s)++;
}

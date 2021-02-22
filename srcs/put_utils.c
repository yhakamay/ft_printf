/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhakamay <yhakamay@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:33:59 by yhakamay          #+#    #+#             */
/*   Updated: 2021/01/26 13:34:01 by yhakamay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	put_boss(int *n, va_list *arg, t_info *info)
{
	if (*n == -1)
		return ;
	if (info->spec == SPEC_C)
		ptf_putchar(n, arg, info);
	if (info->spec == SPEC_S)
		ptf_putstr(n, arg, info);
	if (info->spec == SPEC_P)
		put_p(n, arg, info);
	if (info->spec == SPEC_D)
		put_int(n, arg, info);
	if (info->spec == SPEC_U)
		put_u(n, arg, info);
	if (info->spec == SPEC_X || info->spec == SPEC_X_LARGE)
		put_hex(n, arg, info);
	if (info->spec == SPEC_N)
		store_words(n, arg);
	if (info->spec == SPEC_PCT)
		put_pct(n, info);
}

void	store_words(int *n, va_list *arg)
{
	int	*p;

	p = va_arg(*arg, int *);
	*p = *n;
}

char	*treat_null_arg(va_list *arg, t_info *info)
{
	char	*str;
	char	null_str[256];

	null_str[0] = '(';
	null_str[1] = 'n';
	null_str[2] = 'u';
	null_str[3] = 'l';
	null_str[4] = 'l';
	null_str[5] = ')';
	null_str[6] = '\0';
	str = va_arg(*arg, char*);
	if (!str)
	{
		info->null_check = 0;
		str = null_str;
		return (str);
	}
	else
		return (str);
}

void	swap_str(char *s, int n)
{
	int		i;
	char	tmp;

	i = 0;
	while (i < n / 2)
	{
		tmp = s[i];
		s[i] = s[n - i - 1];
		s[n - i - 1] = tmp;
		i++;
	}
}

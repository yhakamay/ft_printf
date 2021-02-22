/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhakamay <yhakamay@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:35:05 by yhakamay          #+#    #+#             */
/*   Updated: 2021/01/26 13:35:07 by yhakamay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ptf_putchar(int *n, va_list *arg, t_info *info)
{
	char	c;

	c = va_arg(*arg, int);
	if (info->field <= 1)
		put_str_words(n, &c, 1);
	else
		put_str_sp_zero(n, &c, info, 1);
}

void	ptf_putstr(int *n, va_list *arg, t_info *info)
{
	char		*str;
	int			len;
	long int	str_len;

	str = treat_null_arg(arg, info);
	len = 0;
	str_len = ft_strlen(str);
	if (info->acc == 0)
		put_str_sp_only(n, info);
	else if (info->acc <= str_len)
	{
		len = (info->acc > 0 ? info->acc : str_len);
		if (info->field <= len)
			put_str_words(n, str, len);
		else if (info->field > len)
			put_str_sp_zero(n, str, info, len);
	}
	else if (info->acc > str_len)
	{
		len = ft_strlen(str);
		if (info->field <= len)
			put_str_words(n, str, len);
		else if (info->field > len)
			put_str_sp_zero(n, str, info, len);
	}
}

int		ptf_strchr(char *str, const char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

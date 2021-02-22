/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhakamay <yhakamay@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:32:46 by yhakamay          #+#    #+#             */
/*   Updated: 2021/01/26 13:32:50 by yhakamay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_printf(const char *format, ...)
{
	int		len;
	char	*s;
	va_list	ap;

	len = 0;
	va_start(ap, format);
	s = (char *)format;
	if (s == NULL)
		len = -1;
	while (*s && len >= 0)
	{
		if (*s != '%')
			put_literal(&s, &len);
		else
			put_arg(&s, &len, &ap);
	}
	va_end(ap);
	return (len);
}

void	put_arg(char **format, int *n, va_list *arg)
{
	char		*s;
	t_info		info;

	s = ++(*format);
	init_info(&info);
	while (!(check_spec(&s, &info)) && *s != '\0')
	{
		if (ptf_strchr("0-+ #", *s))
			check_info(&s, &info);
		else if (*s >= '1' && '9' >= *s)
			atoi_field(&s, &info, n);
		else if (*s == '*')
			star_field(&s, &info, arg, n);
		else if (*s == '.')
			check_acc(&s, &info, arg, n);
		else
			s++;
	}
	put_boss(n, arg, &info);
	*format = s;
}

void	put_literal(char **format, int *n)
{
	while (**format && **format != '%')
	{
		write(1, *format, 1);
		(*format)++;
		(*n)++;
	}
}

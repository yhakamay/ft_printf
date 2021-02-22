/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putters_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhakamay <yhakamay@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:34:10 by yhakamay          #+#    #+#             */
/*   Updated: 2021/01/26 13:36:16 by yhakamay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	put_str_sp(int *n, const char *str, t_info *info, int len)
{
	char	blank;
	int		s_len;

	blank = ' ';
	s_len = info->field - len;
	if (info->is_min == 1)
	{
		write(1, str, len);
		while (s_len--)
			write(1, &blank, 1);
	}
	else if (info->is_min == -1)
	{
		while (s_len--)
			write(1, &blank, 1);
		write(1, str, len);
	}
	*n += info->field;
}

void	put_str_sp_only(int *n, t_info *info)
{
	char	c;
	int		len;

	c = (info->is_zero > 0 && info->is_min < 0 ? '0' : ' ');
	len = info->field;
	if (len <= 0)
		return ;
	*n += len;
	while (len--)
		write(1, &c, 1);
}

void	put_str_sp_zero(int *n, const char *str, t_info *info, int len)
{
	char	c;
	int		s_len;

	s_len = info->field - len;
	if (info->is_min == 1)
	{
		write(1, str, len);
		c = ' ';
		while (s_len--)
			write(1, &c, 1);
	}
	else if (info->is_min == -1)
	{
		c = (info->is_zero > 0 ? '0' : ' ');
		while (s_len--)
			write(1, &c, 1);
		write(1, str, len);
	}
	*n += info->field;
}

void	put_str_words(int *n, const char *str, int len)
{
	write(1, str, len);
	*n += len;
}

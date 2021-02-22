/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putters_other.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhakamay <yhakamay@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:36:35 by yhakamay          #+#    #+#             */
/*   Updated: 2021/01/26 13:36:39 by yhakamay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	put_pct(int *n, t_info *info)
{
	char	pct;

	pct = '%';
	if (info->field <= 1)
		put_str_words(n, &pct, 1);
	else
		put_str_sp_zero(n, &pct, info, 1);
}

void	clear_arr(char *str, int digit)
{
	int	i;

	i = 0;
	while (i++ < digit)
	{
		*str = '0';
		str++;
	}
	*str = '\0';
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhakamaya <yhakamaya@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 15:00:37 by yhakamaya         #+#    #+#             */
/*   Updated: 2021/01/26 13:37:44 by yhakamay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

# define SPEC_C 1
# define SPEC_S 2
# define SPEC_P 3
# define SPEC_D 4
# define SPEC_U 5
# define SPEC_X 6
# define SPEC_X_LARGE 7
# define SPEC_N 8
# define SPEC_PCT 9

typedef struct	s_info
{
	int			is_zero;
	int			is_min;
	int			is_space;
	int			is_plus;
	int			is_hash;
	int			field;
	int			acc;
	int			spec;
	int			null_check;
	int			int_minus;
	int			act_num;
	int			act_wid;
}				t_info;

int				ft_printf(const char *format, ...);
void			put_literal(char **format, int *n);
void			put_arg(char **format, int *n, va_list *ap);

int				ptf_strchr(char *str, const char c);
void			ptf_putstr(int *n, va_list *ap, t_info *info);
void			ptf_putchar(int *n, va_list *ap, t_info *info);

void			check_acc(char **str, t_info *info, va_list *ap, int *n);
void			atoi_field(char **start, t_info *info, int *n);
void			atoi_acc(char **start, t_info *info, int *n);
void			star_field(char **s, t_info *info, va_list *ap, int *n);
void			star_acc(char **s, t_info *info, va_list *ap, int *n);

void			init_info(t_info *info);
int				check_spec(char **s, t_info *info);
void			check_info(char **s, t_info *info);

void			put_boss(int *n, va_list *ap, t_info *info);
void			store_words(int *n, va_list *ap);
void			swap_str(char *s, int n);
char			*treat_null_arg(va_list *ap, t_info *info);

int				count_digit(unsigned long long p, t_info *info);
int				count_digit_i(long long p, t_info *info);
int				count_digit_ui(unsigned int p, t_info *info);

void			put_str_sp(int *n, const char *str, t_info *info, int len);
void			put_str_sp_only(int *n, t_info *info);
void			put_str_sp_zero(int *n, const char *str, t_info *info, int len);
void			put_str_words(int *n, const char *str, int len);

void			put_pct(int *n, t_info *info);
void			clear_arr(char *str, int digit);

void			put_arr_u(unsigned int x, char **str, int digit, t_info *info);
void			put_u(int *n, va_list *ap, t_info *info);

void			put_p(int *n, va_list *ap, t_info *info);
void			put_p_sp(int *n, int digit, t_info *info, char *str);
void			put_p_no_sp(int *n, int digit, t_info *info, char *str);

void			to_hex(unsigned long long x, char **str, int n, t_info *info);
void			put_hex(int *n, va_list *ap, t_info *info);

void			set_real_num(int digit, t_info *info);
void			put_int_arr(long long x, char **str, int digit, t_info *info);
void			put_int_str(int digit, t_info *info, char **str);

void			put_int(int *n, va_list *ap, t_info *info);
void			put_int_sp(int digit, t_info *info, char **str);
void			put_int_zero(int digit, t_info *info, char **str);
void			put_int_noflag(int digit, t_info *info, char **str);

#endif

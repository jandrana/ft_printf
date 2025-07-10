/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:46:09 by ana-cast          #+#    #+#             */
/*   Updated: 2024/09/06 12:44:20 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_flag
{
	char	conv;
	int		sharp;
	int		space;
	int		sign;
	int		left;
	int		zero;
	int		width;
	int		prec;
	int		pos;
	int		length;
}	t_flag;

int		ft_printf(char const *str, ...);

void	ft_bpf_putchar(char c, int *result);
void	ft_bpf_putstr(char *s, int *result, int len);
void	ft_bpf_pointer(unsigned long long pointer, int *result, t_flag *fg);
void	ft_bpf_putnbr_base(long long nbr, char *base, int *result, t_flag *fg);

void	add_padding(t_flag *fg, char c, int *result);
void	cs_conversions(t_flag *fg, char *s, char c, int *result);

void	ft_bpf_width(t_flag *fg, int *result, long long nbr);
void	ft_bpf_prec(t_flag *fg, int *result, long long nbr);
int		assign_flags(t_flag *fg, char *str, va_list arg, int *result);

void	diux_conversions(t_flag *fg, long long nbr, char *base, int *result);
void	p_conversion(t_flag *fg, unsigned long long nbr, int *result);

int		ft_strlen(const char *str);
int		ft_isdigit(int c);
char	*ft_strchr(const char *s, int c);
int		ft_atoi(const char *str);
void	reset_flag(t_flag *fg);

#endif /* FT_PRINTF_BONUS_H */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric_flags_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:09:54 by ana-cast          #+#    #+#             */
/*   Updated: 2024/09/06 12:45:46 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_bonus.h>

static int	calc_length(long long nbr, char *base, t_flag *fg)
{
	int	i;

	i = 1;
	if (nbr < 0)
	{
		if (-nbr >= ft_strlen(base) && fg->prec >= 0)
			fg->prec += 1;
		nbr /= ft_strlen(base);
		i += 2;
		if (nbr == 0 && i-- && fg->prec >= 0)
			++fg->prec;
		nbr *= -1;
	}
	while (nbr > ft_strlen(base) - 1)
	{
		i++;
		nbr /= ft_strlen(base);
	}
	fg->prec -= i;
	return (i);
}

static void	adjust_len(t_flag *fg, long long nbr, char *base)
{
	fg->length = calc_length(nbr, base, fg);
	if (fg->sharp && nbr != 0)
		fg->length += 2;
	if (fg->sign && nbr >= 0)
		fg->length++;
	if (fg->space && nbr >= 0)
		fg->length++;
	if (fg->prec >= 0)
		fg->width -= fg->prec;
}

static void	before_putnbr(t_flag *fg, long long nbr, int *result)
{
	fg->width -= fg->length;
	if (fg->width < 0)
		fg->width = 0;
	else if (!fg->left && !fg->zero)
		ft_bpf_width(fg, result, nbr);
	if (fg->sharp && nbr != 0)
	{
		ft_bpf_putchar('0', result);
		ft_bpf_putchar(fg->conv, result);
	}
	if (fg->space && nbr >= 0)
		ft_bpf_putchar(' ', result);
	if (fg->sign && nbr >= 0)
		ft_bpf_putchar('+', result);
	if (nbr >= 0)
		ft_bpf_prec(fg, result, nbr);
	if (fg->zero && nbr >= 0)
	{
		while (fg->width--)
			ft_bpf_putchar('0', result);
	}
}

void	diux_conversions(t_flag *fg, long long nbr, char *base, int *result)
{
	if (fg->prec == 0 && nbr == 0)
	{
		ft_bpf_width(fg, result, nbr);
		return ;
	}
	adjust_len(fg, nbr, base);
	before_putnbr(fg, nbr, result);
	if (!(fg->prec == 0 && nbr == 0))
		ft_bpf_putnbr_base(nbr, base, result, fg);
	if (fg->left)
		ft_bpf_width(fg, result, nbr);
}

void	p_conversion(t_flag *fg, unsigned long long nbr, int *result)
{
	unsigned long long	tmp;

	tmp = nbr;
	if (!nbr)
		fg->length = 5;
	else
	{
		while (++fg->length && tmp > 15)
			tmp /= ft_strlen("0123456789abcdef");
		fg->length += 2;
	}
	if (fg->prec >= 0)
		fg->width -= fg->prec;
	fg->width -= fg->length;
	if (fg->width < 0)
		fg->width = 0;
	if (!fg->left)
		ft_bpf_width(fg, result, nbr);
	ft_bpf_pointer(nbr, result, fg);
	if (fg->left)
		ft_bpf_width(fg, result, nbr);
}

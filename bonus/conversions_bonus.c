/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:32:53 by ana-cast          #+#    #+#             */
/*   Updated: 2024/09/06 12:44:59 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_bonus.h>

void	ft_bpf_putchar(char c, int *result)
{
	if (*result == -1)
		return ;
	if (write(1, &c, 1) == -1)
		*result = -1;
	else
		*result += 1;
}

void	ft_bpf_putstr(char *s, int *result, int len)
{
	int	i;

	i = -1;
	if (!s)
		s = "(null)";
	while (len-- && s[++i])
		ft_bpf_putchar(s[i], result);
}

void	ft_bpf_pointer(unsigned long long pointer, int *result, t_flag *fg)
{
	if (!pointer)
		ft_bpf_putstr("(nil)", result, -1);
	else
	{
		ft_bpf_putstr("0x", result, -1);
		if (pointer >= 16)
		{
			ft_bpf_putnbr_base((pointer / 16), "0123456789abcdef", result, fg);
			ft_bpf_putnbr_base((pointer % 16), "0123456789abcdef", result, fg);
		}
		else
			ft_bpf_putnbr_base(pointer, "0123456789abcdef", result, fg);
	}
}

void	ft_bpf_putnbr_base(long long nbr, char *base, int *result, t_flag *fg)
{
	int	len_base;

	len_base = ft_strlen(base);
	if (*result != -1)
	{
		if (nbr < 0)
		{
			ft_bpf_putchar('-', result);
			if (fg->zero)
			{
				while (fg->width--)
					ft_bpf_putchar('0', result);
			}
			ft_bpf_prec(fg, result, nbr);
			nbr = -nbr;
		}
		if (nbr > ft_strlen(base) - 1)
		{
			ft_bpf_putnbr_base(nbr / len_base, base, result, fg);
			ft_bpf_putnbr_base(nbr % len_base, base, result, fg);
		}
		else
			ft_bpf_putchar(base[nbr], result);
	}
}

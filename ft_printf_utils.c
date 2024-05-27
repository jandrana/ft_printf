/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:32:53 by ana-cast          #+#    #+#             */
/*   Updated: 2024/05/27 19:39:49 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pf_putchar(char c, int *result)
{
	if (*result == -1)
		return ;
	if (write(1, &c, 1) == -1)
		*result = -1;
	else
		*result += 1;
}

void	ft_pf_putstr(char *s, int *result)
{
	int	i;

	i = -1;
	if (!s)
		s = "(null)";
	while (s[++i])
		ft_pf_putchar(s[i], result);
}

void	ft_pf_pointer(unsigned long long pointer, int *result)
{
	if (pointer == 0)
		ft_pf_putstr("(nil)", result);
	else
	{
		ft_pf_putstr("0x", result);
		if (pointer >= 16)
		{
			ft_pf_putnbr_base((pointer / 16), HEXA_LOW, result);
			ft_pf_putnbr_base((pointer % 16), HEXA_LOW, result);
		}
		else
			ft_pf_putnbr_base(pointer, HEXA_LOW, result);
	}
}

void	ft_pf_putnbr_base(long long nbr, char *base, int *result)
{
	int	len_base;

	len_base = ft_strlen(base);
	if (*result != -1)
	{
		if (nbr < 0)
		{
			ft_pf_putchar('-', result);
			nbr = -nbr;
		}
		if (nbr > ft_strlen(base) - 1)
		{
			ft_pf_putnbr_base(nbr / len_base, base, result);
			ft_pf_putnbr_base(nbr % len_base, base, result);
		}
		else
			ft_pf_putchar(base[nbr], result);
	}
}

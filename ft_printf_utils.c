/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:32:53 by ana-cast          #+#    #+#             */
/*   Updated: 2024/01/13 17:33:41 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pf_putchar(char c, int *result)
{
	if (write(1, &c, 1) == -1)
		*result = -1;
	else
		*result += 1;
}

void	ft_pf_putstr(char *s, int *result)
{
	if (s == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			*result = -1;
		else
			*result += 6;
	}
	else
	{
		if (write(1, s, ft_strlen(s)) == -1)
			*result = -1;
		else
			*result += ft_strlen(s);
	}
}

void	ft_pf_pointer(unsigned long long pointer, int	*result)
{
	ft_pf_putstr("0x", result);
	if (pointer >= 16)
	{
		ft_pf_putnbr_base((pointer / 16), "0123456789abcdef", result);
		ft_pf_putnbr_base((pointer % 16), "0123456789abcdef", result);
	}
	else
		ft_pf_putnbr_base(pointer, "0123456789abcdef", result);
}

static int	valid_base(char *base, int len)
{
	int	i;
	int	j;

	i = -1;
	if (len < 2)
		return (0);
	while (base[++i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-'
			|| !(base[i] > 31 && base[i] < 127))
			return (0);
	}
	return (1);
}

void	ft_pf_putnbr_base(long long nbr, char *base, int *result)
{
	int	len_base;

	len_base = ft_strlen(base);
	if (valid_base(base, len_base) != 0 && *result != -1)
	{
		if (nbr < 0)
		{
			ft_pf_putchar('-', result);
			nbr = -nbr;
			ft_pf_putnbr_base(nbr, base, result);
		}
		else if (nbr > ft_strlen(base) - 1)
		{
			ft_pf_putnbr_base(nbr / len_base, base, result);
			ft_pf_putnbr_base(nbr % len_base, base, result);
		}
		else
			ft_pf_putchar(base[nbr], result);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:36:01 by ana-cast          #+#    #+#             */
/*   Updated: 2024/09/06 12:45:05 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

void	ft_pf_putchar(char c, int *result)
{
	if (*result != -1)
	{
		if (write(1, &c, 1) == -1)
			*result = -1;
		else
			*result += 1;
	}
}

void	ft_pf_putstr(char *s, int *result)
{
	if (s == NULL)
		s = "(null)";
	while (*s)
		ft_pf_putchar(*s++, result);
}

void	ft_pf_putnbr_base(long long nbr, char *base, int *result)
{
	int	len_base;

	len_base = ft_strlen(base);
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

void	ft_pf_pointer(unsigned long long pointer, int *result)
{
	if (pointer == 0)
		ft_pf_putstr("(nil)", result);
	else
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
}

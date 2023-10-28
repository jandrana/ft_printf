/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putnbr_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:11:38 by ana-cast          #+#    #+#             */
/*   Updated: 2023/10/19 03:23:33 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:36:01 by ana-cast          #+#    #+#             */
/*   Updated: 2023/10/19 03:33:36 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

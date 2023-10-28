/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_putstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:13:02 by ana-cast          #+#    #+#             */
/*   Updated: 2023/10/19 03:28:22 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

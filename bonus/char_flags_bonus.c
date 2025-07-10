/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_flags_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:32:17 by ana-cast          #+#    #+#             */
/*   Updated: 2024/09/06 12:44:45 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf_bonus.h>

void	add_padding(t_flag *fg, char c, int *result)
{
	while (--fg->width - fg->prec >= 0)
		ft_bpf_putchar(c, result);
}

void	cs_conversions(t_flag *fg, char *s, char c, int *result)
{
	if (!s && fg->conv == 's' && (fg->prec < 0 || fg->prec > 5))
		s = "(null)";
	else if (!s && fg->conv == 's')
		s = "";
	if (fg->conv == 's' && fg->prec < 0)
		fg->prec = ft_strlen(s);
	else if (fg->conv == 'c')
		fg->prec = 1;
	if (fg->conv == 's' && fg->prec > ft_strlen(s))
		fg->width += fg->prec - ft_strlen(s);
	if (!fg->left)
		add_padding(fg, ' ', result);
	if (fg->conv == 's')
		ft_bpf_putstr(s, result, fg->prec);
	else if (fg->conv == 'c')
		ft_bpf_putchar(c, result);
	if (fg->left)
		add_padding(fg, ' ', result);
}

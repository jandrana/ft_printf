/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:46:09 by ana-cast          #+#    #+#             */
/*   Updated: 2023/09/23 17:55:21 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(char const *str, ...);
void	ft_pf_putchar(char c, int *result);
void	ft_pf_putstr(char *s, int *result);
void	ft_pf_putnbr_base(long long nbr, char *base, int *result);
void	ft_pf_pointer(unsigned long long pointer, int	*result);

#endif /* FT_PRINTF_H */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:46:09 by ana-cast          #+#    #+#             */
/*   Updated: 2024/05/27 19:30:18 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define HEXA_LOW "0123456789abcdef"
# define HEXA_CAP "0123456789ABCDEF"
# define DECIMAL "0123456789"

int		ft_printf(char const *str, ...);
/**
 * @param str string
 * @return Int: Returns the length of string str
*/
int		ft_strlen(const char *str);

/**
 * @brief Prints out the char c and increments the int result.
 * @param c Character to print
 * @param result pointer to the int that counts the total bytes printed
 * @return None
*/
void	ft_pf_putchar(char c, int *result);

/**
 * @brief Prints s and increments result depending of bytes printed.
 * @param s String to send
 * @param result pointer to the int that counts the total bytes printed
 * @return None
*/
void	ft_pf_putstr(char *s, int *result);

/**
 * @brief Prints pointer in hexadecimal and increments result depending
   on the number of bytes printed.
 * @param pointer Pointer to print
 * @param result pointer to the int that counts the total bytes printed
 * @return None
*/
void	ft_pf_pointer(unsigned long long pointer, int *result);

/**
 * @brief Prints nbr in *base and increments result depending of bytes printed.
 * @param nbr Number to print
 * @param base Base to which convert nbr before printing it
 * @param result pointer to the int that counts the total bytes printed
 * @return None
*/
void	ft_pf_putnbr_base(long long nbr, char *base, int *result);

#endif /* FT_PRINTF_H */

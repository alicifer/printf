/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:13:01 by alicifer          #+#    #+#             */
/*   Updated: 2023/12/12 10:34:51 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putchar(char c, int *chars_p);
void	ft_putstring(char *str, int *chars_p);
int		ft_toupper(int c);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
char	*ft_unsign_itoa(unsigned int nbr);
void	ft_putnumber(int nbr, int *chars_p);
void	ft_putunsigned(unsigned int nbr, int *chars_p);
void	ft_puthexa(unsigned int hex, int *chars_p, char c);
char	*ft_hexa_to_str(unsigned long hex);
void	ft_pointer(void *pointer, int *chars_p);
int		ft_printf(const char *str, ...);
void	ft_print_format(const char *str, va_list ap, int i, int *chars_p);

#endif
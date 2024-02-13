/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 08:45:38 by alicifer          #+#    #+#             */
/*   Updated: 2023/12/12 10:30:50 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_format(const char *str, va_list ap, int i, int *chars_p)
{
	if (str[i + 1] == 'c')
		ft_putchar(va_arg(ap, int), chars_p);
	else if (str[i + 1] == 's')
		ft_putstring(va_arg(ap, char *), chars_p);
	else if (str[i + 1] == 'p')
		ft_pointer((va_arg(ap, void *)), chars_p);
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		ft_putnumber(va_arg(ap, int), chars_p);
	else if (str[i + 1] == 'u')
		ft_putunsigned(va_arg(ap, unsigned int), chars_p);
	else if (str[i + 1] == 'x' || str[i + 1] == 'X')
		ft_puthexa(va_arg(ap, unsigned int), chars_p, str[i + 1]);
	else if (str[i +1] == '%')
	{
		ft_putchar('%', chars_p);
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		chars_p;
	va_list	ap;

	i = 0;
	chars_p = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (chars_p == -1)
			return (-1);
		else if (str[i] != '%')
		{
			ft_putchar(str[i], &chars_p);
			i++;
		}
		else
		{
			ft_print_format(str, ap, i, &chars_p);
			i += 2;
		}
	}
	va_end(ap);
	return (chars_p);
}

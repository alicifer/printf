/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 08:59:02 by alicifer          #+#    #+#             */
/*   Updated: 2023/12/12 10:33:24 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hexa_to_str(unsigned long hex)
{
	char	*str;
	char	*str_hexa;
	int		i;

	str = (char *)malloc(sizeof(char) * 17);
	if (!str)
		return (NULL);
	str_hexa = "0123456789abcdef";
	i = 0;
	if (hex == 0)
	{
		str[0] = '0';
	}
	while (hex != 0)
	{
		str[i++] = str_hexa[hex % 16];
		hex = hex / 16;
	}
	str[i] = '\0';
	return (str);
}

void	ft_pointer(void *pointer, int *chars_p)
{
	unsigned long	ulong_point;
	char			*str;
	int				i;

	ulong_point = (unsigned long)pointer;
	ft_putstring("0x", chars_p);
	if (ulong_point == 0)
	{
		ft_putchar('0', chars_p);
		return ;
	}
	str = ft_hexa_to_str(ulong_point);
	i = ft_strlen(str);
	while (i--)
		ft_putchar(str[i], chars_p);
	free (str);
}

void	ft_puthexa(unsigned int hex, int *chars_p, char c)
{
	int				i;
	char			*str;

	if (hex == 0)
	{
		ft_putchar('0', chars_p);
		return ;
	}
	str = ft_hexa_to_str((unsigned long)hex);
	i = ft_strlen(str);
	while (i--)
	{
		if (c == 'x')
			ft_putchar(str[i], chars_p);
		else
			ft_putchar(ft_toupper(str[i]), chars_p);
	}
	free (str);
}

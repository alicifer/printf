/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:25:50 by alicifer          #+#    #+#             */
/*   Updated: 2023/12/12 08:31:12 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_sizeint(long n)
{
	int	size;

	size = 1;
	if (n < 0)
	{
		size ++;
		n *= -1;
	}
	while (n > 9)
	{
		n = n / 10;
		size ++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		size;

	nbr = (long)n;
	size = ft_sizeint(nbr);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	str[size] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 9)
	{
		str[--size] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (nbr > 0)
		str[--size] = nbr + '0';
	return (str);
}

char	*ft_unsign_itoa(unsigned int nbr)
{
	char	*str;
	int		size;

	size = ft_sizeint(nbr);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	str[size] = '\0';
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 9)
	{
		str[--size] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (nbr > 0)
		str[--size] = nbr + '0';
	return (str);
}

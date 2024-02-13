/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicifer <alicifer@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:22:03 by alicifer          #+#    #+#             */
/*   Updated: 2023/12/12 10:26:37 by alicifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnumber(int nbr, int *chars_p)
{
	char	*str;

	str = ft_itoa(nbr);
	ft_putstring(str, chars_p);
	free (str);
}

void	ft_putunsigned(unsigned int nbr, int *chars_p)
{
	char	*str;

	str = ft_unsign_itoa(nbr);
	ft_putstring(str, chars_p);
	free (str);
}

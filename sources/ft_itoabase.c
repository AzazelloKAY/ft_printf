/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 18:57:14 by akokoshk          #+#    #+#             */
/*   Updated: 2018/01/22 19:41:45 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_ud_toa_base(unsigned long long val, int base)
{
	char				*bchr;
	char				*res;
	size_t				len;
	unsigned long long 	tmp;

	tmp = val;
	bchr = "0123456789ABCDEF";
	len = 1;
	while ((tmp /= base) != 0)
		len++;
	if (!(res = ft_strnew(len)))
		return (NULL);
	res[0] = (char) '0';
	while (val)
	{
		res[--len] = bchr[val % base];
		val /= base;
	}
	return (res);
}

char	*ft_sd_toa_base(long long val, int base)
{
	char *res;
	char *t;

	res = ft_ud_toa_base((unsigned long long)val, base);
	if (val < 0 && base == 10)
	{
		t = ft_strjoin("-", res);
		ft_memdel((void**)&res);
		res = t;
	}
	return (res);
}

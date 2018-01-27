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

char	*ft_utoa_base(t_print *pf, uint64_t val, int base)
{
	char		*bchr;
	char		*res;
	size_t		len;
	uint64_t	tmp;

	tmp = val;
	bchr = "0123456789ABCDEF";
	len = 1;
	while ((tmp /= base) != 0)
		len++;
	pf->buf_len = len;
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

char	*ft_stoa_base(t_print *pf, int64_t val, int base)
{
	char	*bchr;
	char	*res;
	size_t	len;
	int64_t tmp;

	tmp = val;
	bchr = "0123456789ABCDEF";
	len = 1;
	while ((tmp /= base) != 0)
		len++;
	pf->buf_len = len;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 20:28:55 by akokoshk          #+#    #+#             */
/*   Updated: 2018/02/01 19:37:36 by akokoshk         ###   ########.fr       */
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
	bchr = "0123456789abcdef";
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
	bchr = "0123456789abcdef";
	len = 1;
	while ((tmp /= base) != 0)
		len++;
	pf->buf_len = len;
	if (!(res = ft_strnew(len)))
		return (NULL);
	res[0] = (char) '0';
	while (val)
	{
		res[--len] = bchr[ft_abs(val % base)];
		val /= base;
	}
	return (res);
}

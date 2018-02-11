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

char	*ft_ftoa(t_print *pf, u_doublebfild x)
{
	char	*tchar;

	pf->buf = ft_utoa_base(pf, (uint64_t)x.x, 10);
	x.x -= (uint64_t)x.x;
	pf_fquote(pf);
	pf->buf = ft_joinfree(pf->buf, ".", F_FIRST);
	pf->buf_len++;
	if (x.x == 0)
		return (pf->buf);
	tchar = ft_strnew(1);
	while (x.x != 0)
	{
		x.x *= 10;
		tchar[0] = (uint8_t)x.x + '0';
		pf->buf = ft_joinfree(pf->buf, tchar, F_FIRST);
		x.x -= (uint8_t)x.x;
		pf->buf_flen++;
	}
	pf->buf_len += pf->buf_flen;
	ft_strdel(&tchar);
	return (pf->buf);
}










char	*ft_lftoa(t_print *pf, u_ldoublebfild x)
{
	char	*res;
	char	*tchar;

	res = ft_utoa_base(pf, (uint64_t)x.x, 10);
	x.x -= (uint64_t)x.x;
	pf_fquote(pf);
	if (x.x == 0)
		return (res);
	res = ft_joinfree(res, ".", F_FIRST);
	pf->buf_len++;
	tchar = ft_strnew(1);
	while (x.x != 0)
	{
		x.x *= 10;
		tchar[0] = (uint8_t)x.x + '0';
		res = ft_joinfree(res, tchar, F_FIRST);
		x.x -= (uint8_t)x.x;
		pf->buf_flen++;
	}
	pf->buf_len += pf->buf_flen;
	ft_strdel(&tchar);
	return (res);
}

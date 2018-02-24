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

char				*ft_utoa_base(t_print *pf, uint64_t val, int base)
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
	res[0] = (char)'0';
	while (val)
	{
		res[--len] = bchr[val % base];
		val /= base;
	}
	return (res);
}

char				*ft_stoa_base(t_print *pf, int64_t val, int base)
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
	res[0] = (char)'0';
	while (val)
	{
		res[--len] = bchr[ft_abs(val % base)];
		val /= base;
	}
	return (res);
}

static long double	pf_ldblpow(int i)
{
	long double res;

	res = 1;
	while (i--)
		res *= 10.0;
	return (res);
}

static char			*pf_addfract(t_print *pf, u_ldoublebfild x)
{
	char	*tchar;

	tchar = ft_strnew(1);
	while (x.x != 0)
	{
		x.x *= 10.0;
		tchar[0] = (uint16_t)x.x + '0';
		pf->buf = ft_joinfree(pf->buf, tchar, F_FIRST);
		x.x -= (uint16_t)x.x;
		pf->buf_flen++;
	}
	pf->buf_len += pf->buf_flen;
	ft_strdel(&tchar);
	return (pf->buf);
}

char				*ft_ftoa(t_print *pf, u_ldoublebfild x)
{
	int				i;
	long double		tmp;
	char			*tchar;

	tmp = x.x;
	i = 1;
	while ((tmp /= 10.0) >= 1.0)
		i++;
	tchar = ft_strnew(1);
	while (i--)
	{
		tmp = (uint16_t)(x.x / pf_ldblpow(i));
		tchar[0] = (uint16_t)tmp + (uint16_t)'0';
		pf->buf = ft_joinfree(pf->buf, tchar, F_FIRST);
		x.x -= tmp * pf_ldblpow(i);
		pf->buf_len++;
	}
	pf_fquote(pf);
	pf->buf = ft_joinfree(pf->buf, ".", F_FIRST);
	pf->buf_len++;
	ft_strdel(&tchar);
	if (x.x == 0)
		return (pf->buf);
	return (pf_addfract(pf, x));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 19:42:38 by akokoshk          #+#    #+#             */
/*   Updated: 2018/02/23 19:42:41 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		pf_processprecision(t_print *pf, int tr, int i)
{
	if (tr == 1 && (pf->buf[i] + 1) <= '9')
	{
		pf->buf[i]++;
		tr = 0;
	}
	else if (tr == 1 && (pf->buf[i] + 1) > '9')
		pf->buf[i] = '0';
	else if (pf->buf[i] >= '5')
		tr = 1;
	return (tr);
}

static void		pf_f_precision(t_print *pf)
{
	int i;
	int tr;

	i = pf->precis - pf->buf_flen;
	if (i > 0)
		pf->buf = ft_joinfree(pf->buf, ft_memset(ft_strnew(i), '0', i), F_BOTH);
	else
	{
		i = pf->buf_len - pf->buf_flen;
		i += ((pf->precis + 1) < pf->buf_flen) ? pf->precis + 1 : pf->buf_flen;
		tr = 0;
		while (i-- > 0)
		{
			if ((pf->buf[i] == '.' || pf->buf[i] == ',') && tr == 1)
				continue ;
			if ((tr = pf_processprecision(pf, tr, i)) != 1)
				break ;
		}
		if (tr == 1)
			pf->buf = ft_joinfree("1", pf->buf, F_LAST);
	}
	pf->buf_len = ft_strlen(pf->buf);
	pf->buf_len += -pf->buf_flen
		+ ((pf->fhash == 0 && pf->precis == 0) ? -1 : pf->precis);
	pf->buf[pf->buf_len] = 0;
}

static void		pf_process_double(t_print *pf, u_ldoublebfild x)
{
	char fil;

	pf->sign = (x.f.sign == 1) ? "-" : "+";
	x.f.sign = 0;
	if (x.x != x.x)
		pf->buf = ft_strdup((*pf->tfrm == 'f') ? "nan" : "NAN");
	else if (x.x == (1.0 / 0.0))
		pf->buf = ft_strdup((*pf->tfrm == 'f') ? "inf" : "INF");
	else
	{
		pf->buf = ft_ftoa(pf, x);
		pf_f_precision(pf);
	}
	pf->buf_len = ft_strlen(pf->buf);
	if (x.x == x.x)
		ftps_process_sign(pf);
	fil = (pf->fmnus == 0 && pf->fdot == 0 && pf->fzero == 1) ? '0' : ' ';
	ftpf_process_minlen(pf, pf->buf, pf->buf_len, fil);
}

int				ftpf_f(t_print *pf)
{
	u_ldoublebfild	x;

	pf->precis = (pf->fdot == 0) ? 6 : pf->precis;
	pf->fdot = 1;
	ftpf_skipvarg(pf);
	if (pf->f_ld == 0)
		x.x = va_arg(pf->arg, double);
	else
		x.x = va_arg(pf->arg, long double);
	pf_process_double(pf, x);
	pf->res = ft_concatresbuf(pf);
	pf->res_len += pf->buf_len;
	return (1);
}

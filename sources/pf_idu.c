/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_idu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 21:25:47 by akokoshk          #+#    #+#             */
/*   Updated: 2018/02/01 19:19:07 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void			pf_process_idu(t_print *pf)
{
	char	fil;

	pf_fquote(pf);
	ftpf_process_precis(pf, pf->buf, pf->buf_len);
	if (pf->fplus == 1 || pf->sign[0] == '-'
		|| *pf->tfrm == 'u' || *pf->tfrm == 'U')
		pf->fspace = 0;
	fil = (pf->fmnus == 0 && pf->fdot == 0 && pf->fzero == 1) ? '0' : ' ';
	pf->xiszero = (int8_t)((pf->fzero == 1 && pf->fdot == 0) ? 1 : 0);
	if ((fil == '0' && (pf->fplus == 1 || pf->sign[0] == '-'))
		|| (pf->fspace == 1 && (pf->fmnus == 1 || pf->xiszero == 1)))
		pf->minlen = (pf->minlen < 2) ? 0 : pf->minlen - 1;
	if (fil == '0')
		ftpf_process_minlen(pf, pf->buf, pf->buf_len, fil);
	if (pf->fspace == 1)
	{
		pf->buf = ft_joinfree(" ", pf->buf, F_LAST);
		pf->buf_len++;
	}
	if (*pf->tfrm != 'u' && *pf->tfrm != 'U')
		ftps_process_sign(pf);
	if (fil == ' ')
		ftpf_process_minlen(pf, pf->buf, pf->buf_len, fil);
}

static int64_t		ft_getvarg_s(t_print *pf)
{
	ftpf_skipvarg(pf);
	if (*pf->tfrm == 'D' || pf->f_t > 0 || pf->f_z > 0 || pf->f_j > 0)
		return (va_arg(pf->arg, int64_t));
	else if (pf->f_ll > 0)
		return ((long long)va_arg(pf->arg, void*));
	else if (pf->f_l > 0)
		return ((long)va_arg(pf->arg, void*));
	else if (pf->f_h == 1)
		return ((short)va_arg(pf->arg, void*));
	else if (pf->f_hh == 1)
		return ((char)va_arg(pf->arg, void*));
	else
		return ((int)va_arg(pf->arg, void*));
}

int					ftpf_id(t_print *pf)
{
	int64_t x;

	x = ft_getvarg_s(pf);
	pf->xiszero = (x == 0) ? 1 : 0;
	pf->sign = (x < 0) ? "-" : "+";
	pf->buf = ft_stoa_base(pf, x, 10);
	if (x == 0 && pf->fdot == 1 && pf->precis == 0)
	{
		pf->buf[0] = 0;
		pf->buf_len = 0;
	}
	pf_process_idu(pf);
	pf->res = ft_concatresbuf(pf);
	pf->res_len += pf->buf_len;
	return (1);
}

static uint64_t		ft_getvarg_u(t_print *pf)
{
	ftpf_skipvarg(pf);
	if (*pf->tfrm == 'U' || pf->f_t > 0 || pf->f_z > 0 || pf->f_j > 0)
		return (va_arg(pf->arg, uint64_t));
	else if (pf->f_ll > 0)
		return ((unsigned long long)va_arg(pf->arg, void*));
	else if (pf->f_l > 0)
		return ((unsigned long)va_arg(pf->arg, void*));
	else if (pf->f_h == 1)
		return ((unsigned short)va_arg(pf->arg, void*));
	else if (pf->f_hh == 1)
		return ((unsigned char)va_arg(pf->arg, void*));
	else
		return ((unsigned int)va_arg(pf->arg, void*));
}

int					ftpf_u(t_print *pf)
{
	uint64_t x;

	x = ft_getvarg_u(pf);
	pf->buf = ft_utoa_base(pf, x, 10);
	if (x == 0 && pf->fdot == 1 && pf->precis == 0)
	{
		pf->buf[0] = 0;
		pf->buf_len = 0;
	}
	pf_process_idu(pf);
	pf->res = ft_concatresbuf(pf);
	pf->res_len += pf->buf_len;
	return (1);
}

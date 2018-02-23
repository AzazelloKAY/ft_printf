/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ob.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 19:44:12 by akokoshk          #+#    #+#             */
/*   Updated: 2018/02/23 19:44:14 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static uint64_t		ft_getvarg(t_print *pf)
{
	ftpf_skipvarg(pf);
	if (*pf->tfrm == 'O' || pf->f_z > 0 || pf->f_j > 0)
		return (va_arg(pf->arg, uint64_t));
	else if (pf->f_l > 0 || pf->f_ll > 0 || pf->f_t > 0)
		return (va_arg(pf->arg, uint64_t));
	else if (pf->f_h == 1)
		return ((uint16_t)va_arg(pf->arg, void*));
	else if (pf->f_hh == 1)
		return ((uint8_t)va_arg(pf->arg, void*));
	else
		return (va_arg(pf->arg, uint32_t));
}

static void			pf_process_o(t_print *pf)
{
	char	fil;

	if (pf->fhash == 1 && !pf->xiszero)
	{
		pf->buf = ft_joinfree("0", pf->buf, F_LAST);
		pf->buf_len ++;
	}
	ftpf_process_precis(pf, pf->buf, pf->buf_len);
	fil = (pf->fmnus == 0 && pf->fdot == 0 && pf->fzero == 1) ? '0' : ' ';
	ftpf_process_minlen(pf, pf->buf, pf->buf_len, fil);
//	pf->res_len += pf->buf_len;
}

int					ftpf_o(t_print *pf)
{
	uint64_t x;

	x = ft_getvarg(pf);
	pf->xiszero = (x == 0) ? 1 : 0;
	pf->buf = ft_utoa_base(pf, x, 8);
	if (x == 0 && pf->fdot == 1 && pf->precis == 0 && pf->fhash == 0)
	{
		pf->buf[0] = 0;
		pf->buf_len = 0;
	}
	pf_process_o(pf);
//	pf->res = ft_joinfree(pf->res, pf->buf, F_BOTH);
	pf->res = ft_concatresbuf(pf);
	pf->res_len += pf->buf_len;
	return (1);
}

int				ftpf_b(t_print *pf)
{
	uint64_t x;

	ftpf_skipvarg(pf);
	x = va_arg(pf->arg, uint64_t);
	pf->buf = ft_utoa_base(pf, x, 2);
	pf_process_cs(pf);
//	pf->res = ft_joinfree(pf->res, pf->buf, F_BOTH);
	pf->res = ft_concatresbuf(pf);
	pf->res_len += pf->buf_len;
	return (1);
}

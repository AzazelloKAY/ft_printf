/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 21:20:46 by akokoshk          #+#    #+#             */
/*   Updated: 2018/02/01 19:19:13 by akokoshk         ###   ########.fr       */
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
		return (va_arg(pf->arg, uint16_t));
	else if (pf->f_hh == 1)
		return (va_arg(pf->arg, uint8_t));
	else
		return (va_arg(pf->arg, uint32_t));
}

static void			pf_process_o(t_print *pf)
{
	char	fil;

	if (pf->fhash == 1)
		pf->buf = ft_joinfree("0", pf->buf, F_LAST);
	pf->buf_len += (pf->fhash == 1) ? 1 : 0;
	ftpf_process_precis(pf, pf->buf, pf->buf_len);
	fil = (pf->fmnus == 0 && pf->fdot == 0 && pf->fzero == 1) ? '0' : ' ';
	ftpf_process_minlen(pf, pf->buf, pf->buf_len, fil);
//	pf->res_len += pf->buf_len;
}

int					ftpf_o(t_print *pf)
{
	uint64_t x;

	x = ft_getvarg(pf);
	pf->buf = ft_utoa_base(pf, x, 8);
	((x == 0 && pf->fdot == 1 && pf->precis == 0) ? pf->buf[0] = 0 : 0);
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
	x = va_arg(pf->arg, uint64_t);;
	pf->buf = ft_utoa_base(pf, x, 2);
	pf_process_cs(pf);
//	pf->res = ft_joinfree(pf->res, pf->buf, F_BOTH);
	pf->res = ft_concatresbuf(pf);
	pf->res_len += pf->buf_len;
	return (1);
}

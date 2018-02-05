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

static int64_t		ft_getvarg_s(t_print *pf)
{
	ftpf_skipvarg(pf);
	if (*pf->tfrm == 'D' || pf->f_z > 0 || pf->f_j > 0)
		return (va_arg(pf->arg, int64_t));
	else if (pf->f_l > 0 || pf->f_ll > 0 || pf->f_t > 0)
		return (va_arg(pf->arg, int64_t));
	else if (pf->f_h == 1)
		return (va_arg(pf->arg, int16_t));
	else if (pf->f_hh == 1)
		return (va_arg(pf->arg, int8_t));
	else
		return (va_arg(pf->arg, int32_t));
}

static uint64_t		ft_getvarg_u(t_print *pf)
{
	ftpf_skipvarg(pf);
	if (*pf->tfrm =='U' || pf->f_z > 0 || pf->f_j > 0)
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

static void			pf_process_idu(t_print *pf)
{
	char	fil;

	ftpf_process_precis(pf, pf->buf, pf->buf_len);
	if (*pf->tfrm != 'u' && *pf->tfrm != 'U')
		ftps_process_sign(pf);
	fil = (pf->fmnus == 0 && pf->fdot == 0 && pf->fzero == 1) ? '0' : ' ';
	ftpf_process_minlen(pf, pf->buf, pf->buf_len, fil);
//	pf->res_len += pf->buf_len;
}

int				ftpf_id(t_print *pf)
{
	int64_t x;

	x = ft_getvarg_s(pf);
	pf->sign = (x < 0) ? "-" : "+";
	pf->buf = ft_stoa_base(pf, x, 10);
	((x == 0 && pf->fdot == 1 && pf->precis == 0) ? pf->buf[0] = 0 : 0);
	pf_process_idu(pf);
//	pf->res = ft_joinfree(pf->res, pf->buf, F_BOTH);
	pf->res = ft_concatresbuf(pf);
	pf->res_len += pf->buf_len;
	return (1);
}

int				ftpf_u(t_print *pf)
{
	uint64_t x;

	x = ft_getvarg_u(pf);
	pf->buf = ft_utoa_base(pf, x, 10);
	((x == 0 && pf->fdot == 1 && pf->precis == 0) ? pf->buf[0] = 0 : 0);
	pf_process_idu(pf);
//	pf->res = ft_joinfree(pf->res, pf->buf, F_BOTH);
	pf->res = ft_concatresbuf(pf);
	pf->res_len += pf->buf_len;
	return (1);
}

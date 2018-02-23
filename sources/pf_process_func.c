/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_process_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 22:32:18 by akokoshk          #+#    #+#             */
/*   Updated: 2018/02/01 19:17:42 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long		ft_abs(long x)
{
	return ((x < 0) ? -x : x);
}

int			ftpf_process_minlen(t_print *p, char *buf, int len, char fil)
{
	len = p->minlen - len;
	if (len > 0)
	{
		if (p->fmnus == 0)
			p->buf = ft_joinfree(
					ft_memset(ft_strnew(len), fil, len), buf, F_BOTH);
		else
			p->buf = ft_joinfree(buf, ft_memset(
					ft_strnew(len), fil, len), F_BOTH);
		p->buf_len += len;
	}
	return (p->buf_len);
}

int			ftpf_process_precis(t_print *p, char *buf, int len)
{
	len = p->precis - len;
	if ((p->fdot == 1) && (len > 0))
	{
		p->buf = ft_joinfree(ft_memset(ft_strnew(len), '0', len), buf, F_BOTH);
		p->buf_len += len;
	}
	return (p->buf_len);
}

int			ftps_process_sign(t_print *pf)
{
	if (pf->sign[0] == '-' || pf->fplus == 1)
	{
		pf->buf = ft_joinfree(pf->sign, pf->buf, F_LAST);
		pf->buf_len++;
	}
	return (pf->buf_len);
}

int			ftpf_atoiskip(t_print *pf)
{
	int num;

	if (!ft_isdigit(*pf->tfrm))
		return (0);
	num = ft_atoi(pf->tfrm);
	while (ft_isdigit(*(pf->tfrm + 1)))
		pf->tfrm++;
	return (num);
}

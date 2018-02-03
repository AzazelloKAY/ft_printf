/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 19:31:57 by akokoshk          #+#    #+#             */
/*   Updated: 2018/02/01 19:32:03 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		pf_process_cs(t_print *pf)
{
	char	fil;

	fil = (pf->fmnus == 0 && pf->fzero == 1) ? '0' : ' ';
	ftpf_process_minlen(pf, pf->buf, pf->buf_len, fil);
	pf->res_len += pf->buf_len;
}

int			ftpf_c(t_print *pf)
{
	if (pf->f_l == 1)
		ftpf_uni_c(pf);
	else
	{
		pf->buf = ft_strnew(1);
		pf->buf[0] = (va_arg(pf->arg, int32_t));
		pf->buf_len = 1;
		pf_process_cs(pf);
//		write(1, pf->buf, pf->buf_len);
		pf->res = ft_joinfree(pf->res, pf->buf, F_BOTH);
	}
	return (1);
}

int			ftpf_s(t_print *pf)
{
	char *s;

	if (pf->f_l == 1)
		ftpf_uni_s(pf);
	else
	{
		s = va_arg(pf->arg, char*);
		pf->buf_len = ((pf->fdot == 1) ? pf->precis : (int)ft_strlen(s));
		pf->buf = ft_strsub(s, 0, (size_t)pf->buf_len);
		pf_process_cs(pf);
//		write(1, pf->buf, pf->buf_len);
		pf->res = ft_joinfree(pf->res, pf->buf, F_BOTH);
	}
	return (1);
}

int		ftpf_undefined(t_print *pf)
{
	pf->buf	= ft_strsub(pf->tfrm, 0, 1);
	pf->buf_len = 1;
	pf_process_cs(pf);
//	write(1, pf->buf, pf->buf_len);
	pf->res = ft_joinfree(pf->res, pf->buf, F_BOTH);
	return (1);
}




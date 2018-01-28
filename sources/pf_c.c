/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_cs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:03:02 by akokoshk          #+#    #+#             */
/*   Updated: 2018/01/21 16:04:11 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#include <stdio.h>//******************************

static void		pf_process_cs(t_print *pf)
{
	int		dif;
	char	fil;

	fil = (pf->fmnus == 0 && pf->fzero == 1) ? '0' : ' ';
	dif = pf->minlen - pf->buf_len;
	if (dif > 0 && (pf->fmnus == 0))
		pf->buf = ft_joinfree(
				ft_memset(ft_strnew(dif), fil, dif), pf->buf, F_BOTH);
	if (dif > 0 && (pf->fmnus == 1))
		pf->buf = ft_joinfree(
				pf->buf, ft_memset(ft_strnew(dif), fil, dif), F_BOTH);
	if (dif > 0)
		pf->buf_len += dif;
	pf->res_len += pf->buf_len;
	if (*pf->tfrm == 'x')
		while (dif--)
			pf->buf[dif] = ft_tolower(pf->buf[dif]);
}

int			ftpf_c(t_print *pf)
{
	//если пришел l флаг то работаем как с символом юникода
	if (pf->f_l == 1)
	{
		//ftpf_uni_c(pf);
	}
	else
	{
		pf->buf = ft_strnew(1);
		pf->buf[0] = (va_arg(pf->arg, int32_t));
		pf->buf_len = 1;
		pf_process_cs(pf);
		write(1, pf->buf, pf->buf_len);
	}
	return (1);
}

int			ftpf_s(t_print *pf)
{
	char *s;

	//если пришел l флаг то работаем как с символом юникода
	if (pf->f_l == 1)
	{
		//ftpf_uni_s(pf);
	}
	else
	{
		s = va_arg(pf->arg, char*);
		pf->buf = ft_strsub(s, 0, ((pf->fdot == 1) ? pf->precis : ft_strlen(s)));
		pf->buf_len = (int)ft_strlen(pf->buf);
		pf_process_cs(pf);
		write(1, pf->buf, pf->buf_len);
	}
	return (1);
}

int		ftpf_undefined(t_print *pf)
{
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//также как %c для встреченной нестандартного символа, и продолжаем обычную работу
	ft_putstr(pf->tfrm);
	pf->res_len += ft_strlen(pf->tfrm);
	return (0);
}




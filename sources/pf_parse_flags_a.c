/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_flags_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 20:43:37 by akokoshk          #+#    #+#             */
/*   Updated: 2018/02/01 19:17:53 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ftpf_parsenum(t_print *pf)
{
	int num;

	num = ftpf_atoiskip(pf);
	pf->f_baks = (*(pf->tfrm + 1) == '$') ? 1 : 0;
	if (pf->f_baks == 1)
	{
		pf->argnum = num;
		pf->tfrm++;
	}
	else
		pf->minlen = num;
	return (0);
}

int			ftpf_set_lflag(t_print *pf)
{
	if (*(pf->tfrm + 1) == 'l')
	{
		pf->f_ll = 1;
		pf->tfrm++;
	}
	else
		pf->f_l = 1;
	return (0);
}

int			ftpf_set_hflag(t_print *pf)
{
	if (pf->f_h == 1)
	{
		pf->f_hh = 1;
		pf->f_h	= 0;
	}
	else if (pf->f_hh == 1)
	{
		pf->f_h	= 1;
		pf->f_hh = 0;
	}
	else
		pf->f_h = 1;
	return (0);
}

int 		ftpf_set_starflag(t_print *pf)
{
	pf->minlen = va_arg(pf->arg, int);
	if (pf->minlen < 0)
	{
		pf->minlen = -pf->minlen;
		pf->fmnus = 1;
	}
	return (0);
}

int			ftpf_setdotflag(t_print *pf)
{
	pf->fdot = 1;
	pf->tfrm++;
	pf->precis = (*pf->tfrm != '*') ? ftpf_atoiskip(pf) : va_arg(pf->arg, int);
	((pf->precis < 0) ? pf->fdot = 0 : 0);
	return (0);
}

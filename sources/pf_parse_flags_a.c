/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_flags.c                                   :+:      :+:    :+:   */
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
	pf->f_ml_star = 0;
	pf->minlen = ftpf_atoiskip(pf);
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
	if (*(pf->tfrm + 1) == 'h')
	{
		pf->f_hh = 1;
		pf->tfrm++;
	}
	else
		pf->f_h = 1;
	return (0);
}

int 		ftpf_set_starflag(t_print *pf)
{
	pf->f_ml_star = 1;
	return (0);
}

int			ftpf_setdotflag(t_print *pf)
{
	pf->fdot = 1;
	pf->tfrm++;
	pf->f_ps_star = (*pf->tfrm == '*') ? 1 : 0;
	pf->precis = ftpf_atoiskip(pf);
	return (0);
}

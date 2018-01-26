/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:20:52 by akokoshk          #+#    #+#             */
/*   Updated: 2018/01/24 19:21:17 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int 	ftpf_atoiskip(t_print *pf)
{
	int num;

	if (!ft_isdigit(*pf->tfrm))
		return (0);
	num = ft_atoi(pf->tfrm);
	while (ft_isdigit(pf->tfrm))
		pf->tfrm++;
	return (num);
}

static void	ftpf_setlhflag(t_print *pf)
{
	if (*pf->tfrm == 'l')
	{
		pf->f_l = (pf->f_l > 1) ? pf->f_l : 1;
		pf->f_l = (*(pf->tfrm - 1) == 'l') ? 2 : pf->f_l;
	}
	else if (*pf->tfrm == 'h')
	{
		pf->f_s = (pf->f_s > 1) ? pf->f_s: 1;
		pf->f_s = (*(pf->tfrm - 1) == 'h') ? 2 : pf->f_s;
	}
}

int 		ftpf_setflag(t_print *pf)
{
	if (*pf->tfrm == '-')
		pf->fmnus = 1;//(pf->fmnus == 0) ? 1 : -1/*error?????*/;
	else if (*pf->tfrm == '+')
		pf->fplus = 1;
	else if (*pf->tfrm == '0')
		pf->fzero = 1;
	else if (*pf->tfrm == ' ')
		pf->fspace = 1;
	else if (*pf->tfrm == '#')
		pf->fhash = 1;
	else if (*pf->tfrm == '.')
	{
		pf->fdot = 1;
		pf->tfrm++;
		pf->precision = ftpf_atoiskip(pf);
	}
	else if (*pf->tfrm == 'L')
		pf->f_ld = 1;
	else
		ftpf_setlhflag(pf);
	return (0);
}

int			ftpf_parsenum(t_print *pf)
{
	int tmp;

	tmp = ftpf_atoiskip(pf);
	pf->precision = (tmp > pf->precision) ? tmp : pf->precision;
	return (0);
}

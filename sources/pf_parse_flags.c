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
	while (ft_isdigit(*(pf->tfrm + 1)))
		pf->tfrm++;
	return (num);
}

int			ftpf_parsenum(t_print *pf)
{
	pf->minlen = ftpf_atoiskip(pf);
	return (0);
}

static void	ftpf_setlhflag(t_print *pf)
{
	//позже сплитнуть на идивидуальные для каждого спека
	//**************
	if (*pf->tfrm == 'l')
	{
		if (*(pf->tfrm + 1) == 'l')
		{
			pf->f_ll = 1;
			pf->tfrm++;
		}
		else
			pf->f_l = 1;
	}
	else if (*pf->tfrm == 'h')
	{
		if (*(pf->tfrm + 1) == 'h')
		{
			pf->f_hh = 1;
			pf->tfrm++;
		}
		else
			pf->f_h = 1;
	}
}

int 		ftpf_setflag(t_print *pf)
{
	//позже сплитнуть на идивидуальные для каждого спека
	//**************
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
		pf->precis = ftpf_atoiskip(pf);
	}
	else if (*pf->tfrm == 'L')
		pf->f_ld = 1;
	else
		ftpf_setlhflag(pf);
	return (0);
}



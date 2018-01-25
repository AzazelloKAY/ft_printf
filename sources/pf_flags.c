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
	else if (*pf->tfrm == 'l')
		pf->flong += 1;
	else if (*pf->tfrm == 'L')
		pf->flongd = 1;
	else if (*pf->tfrm == 'h')
		pf->fshort += 1;
	return (0);
}

int			ftpf_parsenum(t_print *pf)
{
	pf->precision = ftpf_atoiskip(pf);
}

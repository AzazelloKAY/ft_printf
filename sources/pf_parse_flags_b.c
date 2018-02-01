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

int 		ftpf_set_minusflag(t_print *pf)
{
	pf->fmnus = 1;
	return (0);
}

int 		ftpf_set_plusflag(t_print *pf)
{
	pf->fplus = 1;
	return (0);
}

int 		ftpf_set_zeroflag(t_print *pf)
{
	pf->fzero = 1;
	return (0);
}

int 		ftpf_set_hashflag(t_print *pf)
{
	pf->fhash = 1;
	return (0);
}

int 		ftpf_set_spaceflag(t_print *pf)
{
	pf->fspace = 1;
	return (0);
}

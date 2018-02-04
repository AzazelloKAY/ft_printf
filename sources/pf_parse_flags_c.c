/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_flags_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 20:43:37 by akokoshk          #+#    #+#             */
/*   Updated: 2018/02/01 19:17:53 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int 		ftpf_set_ldflag(t_print *pf)
{
	pf->f_ld = 1;
	return (0);
}

int 		ftpf_set_jflag(t_print *pf)
{
	pf->f_j = 1;
	return (0);
}

int 		ftpf_set_zflag(t_print *pf)
{
	pf->f_z = 1;
	return (0);
}

int 		ftpf_set_tflag(t_print *pf)
{
	pf->f_t = 1;
	return (0);
}

int		ftpf_skipvarg(t_print *pf)
{
	if (pf->f_baks == 1)
	{
		va_end(pf->arg);
		va_copy(pf->arg, pf->initarg);
		while (pf->argnum-- > 1)
			va_arg(pf->arg, void*);
		return (1);
	}
	return (0);
}
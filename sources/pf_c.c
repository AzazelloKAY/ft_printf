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

//int		ftpf_printer(t_print *pf)
//{
//	char	*line; //replase with variable in *PF??
//	//make all flags
//	//and print the line
//	return ((int)ft_strlen(line));
//}

int		ftpf_c(t_print *pf)
{
	char	*var;

	//process *X by specifik type, and make the korrect line of it;
	return (1);
}

int		ftpf_s(t_print *pf)
{
	char	*line;

	line = va_arg(pf->arg, char*);

	ft_putstr(line);

	return (ft_strlen(line));//ftpf_printer(pf, var));
}

int		ftpf_persent(t_print *pf)
{
	return (1);
}

int		ftpf_undefined(t_print *pf)
{

	//также как %c для встреченной нестандартного символа, и продолжаем обычную работу
	ft_putstr(pf->tfrm);
	pf->res_len += ft_strlen(pf->tfrm);
	return (0);
}



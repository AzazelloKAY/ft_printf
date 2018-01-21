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

int		ftpf_printer(t_print *pf, char *c)
{
	char	*line; //replase with variable in *PF??
	//make all flags
	//and print the line
	return ((int)ft_strlen(line));
}

int		ftpf_c(t_print *pf, void *x)
{
	char	*var;

	//process *X by specifik type, and make the korrect line of it;
	return (ftpf_printer(pf, var));
}

int		ftpf_s(t_print *pf, void* x)
{
	char	*var;
	return (ftpf_printer(pf, var));
}

int		ftpf_persent(t_print *pf, void* x)
{
	return (ftpf_printer(pf, "%"));
}



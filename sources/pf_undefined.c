/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftpf_undefined.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 20:59:04 by akokoshk          #+#    #+#             */
/*   Updated: 2018/01/22 20:59:34 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ftpf_undefined(t_print *pf)
{
	ft_putstr(pf->tfrm);
	pf->res_len += ft_strlen(pf->tfrm);
	return (0);
}
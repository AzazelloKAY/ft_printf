/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <akokoshk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 19:46:09 by akokoshk          #+#    #+#             */
/*   Updated: 2018/01/18 19:46:18 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printbuf(char *c, int len)
{

}

int ft_printf(const char *frmt, ...)
{
	t_print	*pf;

	va_start(pf->arg, frmt);
	while (*frmt)
	{
		if (*frmt == '%')
		{
			write (1, pf->buf, pf->buf_len);
//			ft_select(frmt);
			frmt += pf->tmp;
		}
		else
			frmt++;
	}
	va_end(pf->arg);
	return (pf->res_len);
}

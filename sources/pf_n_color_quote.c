/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_n_color_quote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 19:43:14 by akokoshk          #+#    #+#             */
/*   Updated: 2018/02/23 19:43:14 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ftpf_n(t_print *pf)
{
	void *x;

	ftpf_skipvarg(pf);
	x = va_arg(pf->arg, void*);
	if (pf->f_t > 0 || pf->f_z > 0 || pf->f_j > 0)
		*(int64_t*)x = pf->res_len;
	else if (pf->f_l > 0 || pf->f_ll > 0)
		*(int64_t*)x = pf->res_len;
	else if (pf->f_h == 1)
		*(int16_t*)x = pf->res_len;
	else if (pf->f_hh == 1)
		*(int8_t*)x = pf->res_len;
	else
		*(int32_t*)x = pf->res_len;
	return (1);
}

/*
*** not a standard parser function
*** called directly from printf
*** return *frm shifting
*/

static void		pf_addcolor(t_print *pf, t_colors color)
{
	char *colorcode;

	if (color == pf->f_curcolor)
	{
		pf->res = ft_joinfree(pf->res, "\e[m", F_FIRST);
		pf->f_curcolor = e_def;
		pf->res_len += 3;
	}
	else
	{
		colorcode = ft_joinfree(
				ft_joinfree("\e[", ft_itoa(color), F_LAST), "m", F_FIRST);
		pf->res = ft_strmemcat(pf->res, colorcode, pf->res_len, 5);
		pf->f_curcolor = color;
		pf->res_len += 5;
	}
}

char			*ftpf_color(t_print *pf, char *s)
{
	ft_catbuf(pf, pf->tfrm, s);
	if (ft_strnstr(s, "{black}", 7))
		pf_addcolor(pf, e_black);
	else if (ft_strnstr(s, "{white}", 7))
		pf_addcolor(pf, e_white);
	else if (ft_strnstr(s, "{red}", 5))
		pf_addcolor(pf, e_red);
	else if (ft_strnstr(s, "{green}", 7))
		pf_addcolor(pf, e_green);
	else if (ft_strnstr(s, "{orange}", 8))
		pf_addcolor(pf, e_orange);
	else if (ft_strnstr(s, "{blue}", 6))
		pf_addcolor(pf, e_blue);
	else if (ft_strnstr(s, "{purple}", 8))
		pf_addcolor(pf, e_purple);
	else if (ft_strnstr(s, "{cyan}", 6))
		pf_addcolor(pf, e_cyan);
	else if (ft_strnstr(s, "{gray}", 6))
		pf_addcolor(pf, e_gray);
	else
		return (s);
	while (*s != '}')
		s++;
	return (s + 1);
}

void			pf_fquote(t_print *pf)
{
	char *res;

	if (pf->fquote == 0 || pf->buf_len / 3 == 0)
		return ;
	res = ft_strnew(0);
	while ((pf->buf_len -= 3) > 0)
	{
		res = ft_joinfree(ft_strsub(pf->buf, pf->buf_len, 3), res, F_LAST);
		res = ft_joinfree(",", res, F_LAST);
	}
	res = ft_joinfree(ft_strsub(pf->buf, 0, pf->buf_len + 3), res, F_BOTH);
	ft_strdel(&pf->buf);
	pf->buf = res;
	pf->buf_len = ft_strlen(pf->buf);
}

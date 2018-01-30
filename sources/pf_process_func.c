//
// Created by Ali on 31.01.2018.
//

#include "../includes/ft_printf.h"

int 		pf_process_minlen(t_print *pf, char *buf, int len, char fil)
{
	len = pf->minlen - len;
	if (len > 0)
	{
		if (pf->fmnus == 0)
			buf = ft_joinfree(ft_memset(ft_strnew(len), fil, len), buf, F_BOTH);
		else
			buf = ft_joinfree(buf, ft_memset(ft_strnew(len), fil, len), F_BOTH);
		pf->buf_len += len;
	}
	pf->res_len += pf->buf_len;
	return (pf->buf_len);
}
//*******************************************************************
static void		pf_process_idu(t_print *pf)
{
	int		dif;
	char	fil;

	dif = pf->precis - pf->buf_len;
	if ((pf->fdot == 1) && (dif > 0))
		pf->buf = ft_joinfree(
				ft_memset(ft_strnew(dif), '0', dif), pf->buf, F_BOTH);
	if (*pf->tfrm != 'u' && *pf->tfrm != 'U'
		&& (pf->sign[0] == '-' || pf->fplus == 1))
		pf->buf = ft_joinfree(pf->sign, pf->buf, F_LAST);


	dif = pf->minlen - (int)ft_strlen(pf->buf);
	fil = (pf->fmnus == 0 && pf->fdot == 0 && pf->fzero == 1) ? '0' : ' ';
	if (dif > 0 && (pf->fmnus == 0))
		pf->buf = ft_joinfree(
				ft_memset(ft_strnew(dif), fil, dif), pf->buf, F_BOTH);
	if (dif > 0 && (pf->fmnus == 1))
		pf->buf = ft_joinfree(
				pf->buf, ft_memset(ft_strnew(dif), fil, dif), F_BOTH);

	dif = (int)ft_strlen(pf->buf);
	pf->buf_len = dif;
	pf->res_len += pf->buf_len;
}

static void		pf_process_cs(t_print *pf)
{
	int		dif;
	char	fil;

	dif = pf->minlen - pf->buf_len;
	fil = (pf->fmnus == 0 && pf->fzero == 1) ? '0' : ' ';
	if (dif > 0 && (pf->fmnus == 0))
		pf->buf = ft_joinfree(
				ft_memset(ft_strnew(dif), fil, dif), pf->buf, F_BOTH);
	if (dif > 0 && (pf->fmnus == 1))
		pf->buf = ft_joinfree(
				pf->buf, ft_memset(ft_strnew(dif), fil, dif), F_BOTH);

	if (dif > 0)
		pf->buf_len += dif;
	pf->res_len += pf->buf_len;
	if (*pf->tfrm == 'x')
		while (dif--)
			pf->buf[dif] = ft_tolower(pf->buf[dif]);
}


static void		pf_process_o(t_print *pf)
{
	int		dif;
	char	fil;

	if (pf->fhash == 1)
		pf->buf = ft_joinfree("0", pf->buf, F_LAST);

	dif = pf->precis - (int)ft_strlen(pf->buf);
	if ((pf->fdot == 1) && (dif > 0))
		pf->buf = ft_joinfree(
				ft_memset(ft_strnew(dif), '0', dif), pf->buf, F_BOTH);


	dif = pf->minlen - (int)ft_strlen(pf->buf);
	fil = (pf->fmnus == 0 && pf->fdot == 0 && pf->fzero == 1) ? '0' : ' ';
	if (dif > 0 && (pf->fmnus == 0))
		pf->buf = ft_joinfree(
				ft_memset(ft_strnew(dif), fil, dif), pf->buf, F_BOTH);
	if (dif > 0 && (pf->fmnus == 1))
		pf->buf = ft_joinfree(
				pf->buf, ft_memset(ft_strnew(dif), fil, dif), F_BOTH);


	dif = (int)ft_strlen(pf->buf);
	pf->buf_len = dif;
	pf->res_len += pf->buf_len;

}

static void		pf_process_x(t_print *pf)
{
	int		dif;
	char	fil;

	dif = pf->precis - pf->buf_len;
	if ((pf->fdot == 1) && (dif > 0))
		pf->buf = ft_joinfree(
				ft_memset(ft_strnew(dif), '0', dif), pf->buf, F_BOTH);
	if (pf->fhash == 1 && pf->buf[0] != 0)
		pf->buf = ft_joinfree("0x", pf->buf, F_LAST);


	dif = pf->minlen - (int)ft_strlen(pf->buf);
	fil = (pf->fmnus == 0 && pf->fdot == 0 && pf->fzero == 1) ? '0' : ' ';
	if (dif > 0 && (pf->fmnus == 0))
		pf->buf = ft_joinfree(
				ft_memset(ft_strnew(dif), fil, dif), pf->buf, F_BOTH);
	if (dif > 0 && (pf->fmnus == 1))
		pf->buf = ft_joinfree(
				pf->buf, ft_memset(ft_strnew(dif), fil, dif), F_BOTH);


	dif = (int)ft_strlen(pf->buf);
	pf->buf_len = dif;
	pf->res_len += pf->buf_len;
	if (*pf->tfrm == 'X')
		while (dif--)
			pf->buf[dif] = ft_toupper(pf->buf[dif]);
}


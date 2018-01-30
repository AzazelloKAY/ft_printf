//
// Created by Antonin KOKOSHKO on 1/28/18.
//

#include "../includes/ft_printf.h"

static int		ft_getvarg(t_print *pf, uint64_t *prm)
{
	if (pf->f_l > 0 || pf->f_ll > 0 || pf->f_ld > 0 || pf->f_z > 0 || pf->f_j > 0)
		*prm = va_arg(pf->arg, uint64_t);
	else if (pf->f_h == 1)
		*prm = va_arg(pf->arg, uint16_t);
	else if (pf->f_hh == 1)
		*prm = va_arg(pf->arg, uint8_t);
	else
		*prm = va_arg(pf->arg, uint32_t);
	return (0);
}


//разбить и вынести в отдельные универсальные ф-и пресижт минлен и т,п,
//****************
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
	fil = (pf->fmnus == 0 && pf->fdot == 0 && pf->fzero == 1) ? '0' : ' ';
	dif = pf->minlen - (int)ft_strlen(pf->buf);
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

int				ftpf_x(t_print *pf)
{
	uint64_t x;

	x = 0;
	if (ft_getvarg(pf, &x))
		return (-1); //error status for noargv situation;
	pf->buf = ft_utoa_base(pf, x, 16);
	((x == 0 && pf->fdot == 1 && pf->precis == 0) ? pf->buf[0] = 0 : 0);
	pf_process_x(pf);
	write(1, pf->buf, pf->buf_len);
	return (1);
}

int				ftpf_p(t_print *pf)
{
	uint64_t x;

	pf->fhash = 1;
	x = va_arg(pf->arg, uint64_t);
	pf->buf = ft_utoa_base(pf, x, 16);
	((x == 0 && pf->fdot == 1 && pf->precis == 0) ? pf->buf[0] = 0 : 0); //******** FIX HERE
	pf_process_x(pf);
	write(1, pf->buf, pf->buf_len);
	return (1);
}

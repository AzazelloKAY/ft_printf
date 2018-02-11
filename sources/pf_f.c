//
// Created by Antonin KOKOSHKO on 2/4/18.
//

#include "../includes/ft_printf.h"
#include <stdio.h>//*******************


static void		pf_f_presision(t_print *pf)
{
	int i;
	int tr;

	i = pf->precis - pf->buf_flen;
	if (i > 0)
		pf->buf = ft_joinfree(pf->buf, ft_memset(ft_strnew(i), '0', i), F_BOTH);
	else
	{
		i = pf->buf_len - pf->buf_flen;
		i += ((pf->precis + 1) < pf->buf_flen) ? pf->precis + 1 : pf->buf_flen;
		//printf("DATA buflen=%d  bufFlen=%d  presis=%d", pf->buf_len, pf->buf_flen, );
		tr = 0;
		while (i-- > 0)
		{
			if (pf->buf[i] == '.' || pf->buf[i] == ',')
				continue ;
			if (tr == 1 && (pf->buf[i] + 1) <= '9')
			{
				pf->buf[i]++;
				tr = 0;
			}
			else if (tr == 1 && (pf->buf[i] + 1) > '9')
				pf->buf[i] = '0';
			if (pf->buf[i] >= '5')
				tr = 1;

			//printf("\nshift=%d_chr=%c",i, pf->buf[i]);
		}

	}

//		обработать #
//	if (pf->fhash == 1 && pf->precis == 0)
//		убиваем точку в конце

}

static void		pf_process_double(t_print *pf, u_doublebfild x)
{
	char fil;

	pf->sign = (x.f.sign == 1) ? "-" : "+";
	x.f.sign = 0;
//	pf->buf = ft_utoa_base(pf, (uint64_t)x.x, 10);
	pf->buf = ft_ftoa(pf, x);
	pf_f_presision(pf);



	ftps_process_sign(pf);
	fil = (pf->fmnus == 0 && pf->fdot == 0 && pf->fzero == 1) ? '0' : ' ';
	ftpf_process_minlen(pf, pf->buf, pf->buf_len, fil);
}

//static void		pf_process_ldouble(t_print *pf, u_ldoublebfild x)
//{
//	pf->sign = (x.f.sign == 1) ? "-" : "+";
//	x.f.sign = 0;
//	pf->buf = ft_lftoa(pf, x);
//
//
//
//	ftps_process_sign(pf);
//}
//
//static int		ftpf_lf(t_print *pf)
//{
//	u_ldoublebfild	x;
//
//	ftpf_skipvarg(pf);
//	x.x = va_arg(pf->arg, typeof(x.x));
//
//	pf_process_ldouble(pf, x);
//	pf->res = ft_joinfree(pf->res, pf->buf, F_BOTH);
//	return (1);
//}

int				ftpf_f(t_print *pf)
{
	u_doublebfild	x;

	pf->precis = (pf->fdot == 0) ? 6 : pf->precis;
	pf->fdot = 1;
//	if (pf->f_ld == 1)
//		return (ftpf_lf(pf));
	ftpf_skipvarg(pf);
	x.x = va_arg(pf->arg, typeof(x.x));

	pf_process_double(pf, x);


	pf->res = ft_joinfree(pf->res, pf->buf, F_BOTH);
	pf->res_len += pf->buf_len;
	return (1);
}

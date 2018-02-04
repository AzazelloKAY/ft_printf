//
// Created by Antonin KOKOSHKO on 1/24/18.
//

#include "../includes/ft_printf.h"

void		ft_reset_pf(t_print *pf)
{
	pf->buf_len = 0;
	pf->minlen = 0;
	pf->precis = 0;
	pf->fplus = 0;
	pf->fmnus = 0;
	pf->fhash = 0;
	pf->fzero = 0;
	pf->fspace = 0;
	pf->fdot = 0;
	pf->f_t = 0;
	pf->f_ld = 0;
	pf->f_l = 0;
	pf->f_h = 0;
	pf->f_hh = 0;
	pf->f_ll = 0;
	pf->f_j = 0;
	pf->f_z = 0;
	pf->f_baks = 0;
	pf->argnum = 0;
	pf->sign = "+";
//	ft_strdel(&pf->buf);
	pf->buf == NULL; //????????????????????????? я фришу в конце каждой обработки джоинфри
}

static void		ft_flist_digit(t_print *pf)
{
	pf->flist['-'] = ftpf_set_minusflag;
	pf->flist['+'] = ftpf_set_plusflag;
	pf->flist['#'] = ftpf_set_hashflag;
	pf->flist['0'] = ftpf_set_zeroflag;
	pf->flist[' '] = ftpf_set_spaceflag;
	pf->flist['.'] = ftpf_setdotflag;
	pf->flist['l'] = ftpf_set_lflag;
	pf->flist['L'] = ftpf_set_ldflag;
	pf->flist['h'] = ftpf_set_hflag;
	pf->flist['z'] = ftpf_set_zflag;
	pf->flist['t'] = ftpf_set_tflag;
	pf->flist['j'] = ftpf_set_jflag;
	pf->flist['*'] = ftpf_set_starflag;
	pf->flist['1'] = ftpf_parsenum;
	pf->flist['2'] = ftpf_parsenum;
	pf->flist['3'] = ftpf_parsenum;
	pf->flist['4'] = ftpf_parsenum;
	pf->flist['5'] = ftpf_parsenum;
	pf->flist['6'] = ftpf_parsenum;
	pf->flist['7'] = ftpf_parsenum;
	pf->flist['8'] = ftpf_parsenum;
	pf->flist['9'] = ftpf_parsenum;
}

static void		ft_init_flist(t_print *pf)
{
	pf->flist[0] = &ftpf_undefined;
	pf->flist['c'] = &ftpf_c;
	pf->flist['C'] = &ftpf_uni_c;
	pf->flist['s'] = &ftpf_s;
	pf->flist['S'] = &ftpf_uni_s;
	pf->flist['i'] = &ftpf_id;
	pf->flist['d'] = &ftpf_id;
	pf->flist['D'] = &ftpf_id;
	pf->flist['u'] = &ftpf_u;
	pf->flist['U'] = &ftpf_u;
	pf->flist['p'] = &ftpf_p;
	pf->flist['x'] = &ftpf_x;
	pf->flist['X'] = &ftpf_x;
	pf->flist['o'] = &ftpf_o;
	pf->flist['O'] = &ftpf_o;
	pf->flist['%'] = &ftpf_undefined;
	pf->flist['b'] = &ftpf_b;
	pf->flist['n'] = &ftpf_n;
	pf->flist['f'] = &ftpf_f;
	ft_flist_digit(pf);
}

t_print		*ft_init_pf(const char *frm)
{
	t_print	*pf;

	if (!(pf = ft_memalloc(sizeof(t_print))))
		return (NULL);
	if (!(pf->flist = ft_memalloc(sizeof(func_p) * 128)))
		return (NULL);
	ft_init_flist(pf);
	if (frm == NULL)
		return (NULL);
	pf->tfrm = frm;
	pf->f_curcolor = e_def;
	return (pf);
}


//
// Created by Antonin KOKOSHKO on 1/24/18.
//

#include "../includes/ft_printf.h"

void		ft_reset_pf(t_print *pf)
{
	pf->buf_len = 0;
	pf->buf_flen = 0;
	pf->minlen = 0;
	pf->precis = 0;
	pf->fplus = 0;
	pf->fmnus = 0;
	pf->fhash = 0;
	pf->fzero = 0;
	pf->fspace = 0;
	pf->fdot = 0;
	pf->fquote = 0;
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
	pf->buf = NULL; //????????????????????????? я фришу в конце каждой обработки джоинфри
}

static void		ft_flist_digit(t_print *pf)
{
	pf->flist['-'] = (void*)ftpf_set_minusflag;
	pf->flist['+'] = (void*)ftpf_set_plusflag;
	pf->flist['#'] = (void*)ftpf_set_hashflag;
	pf->flist['0'] = (void*)ftpf_set_zeroflag;
	pf->flist[' '] = (void*)ftpf_set_spaceflag;
	pf->flist['.'] = (void*)ftpf_setdotflag;
	pf->flist['l'] = (void*)ftpf_set_lflag;
	pf->flist['L'] = (void*)ftpf_set_ldflag;
	pf->flist['h'] = (void*)ftpf_set_hflag;
	pf->flist['z'] = (void*)ftpf_set_zflag;
	pf->flist['t'] = (void*)ftpf_set_tflag;
	pf->flist['j'] = (void*)ftpf_set_jflag;
	pf->flist['*'] = (void*)ftpf_set_starflag;
	pf->flist['\''] = (void*)ftpf_set_fquote;
	pf->flist['1'] = (void*)ftpf_parsenum;
	pf->flist['2'] = (void*)ftpf_parsenum;
	pf->flist['3'] = (void*)ftpf_parsenum;
	pf->flist['4'] = (void*)ftpf_parsenum;
	pf->flist['5'] = (void*)ftpf_parsenum;
	pf->flist['6'] = (void*)ftpf_parsenum;
	pf->flist['7'] = (void*)ftpf_parsenum;
	pf->flist['8'] = (void*)ftpf_parsenum;
	pf->flist['9'] = (void*)ftpf_parsenum;
}

static void		ft_init_flist(t_print *pf)
{
	pf->flist[0] = (void*)ftpf_undefined;
	pf->flist['c'] = (void*)ftpf_c;
	pf->flist['C'] = (void*)ftpf_uni_c;
	pf->flist['s'] = (void*)ftpf_s;
	pf->flist['S'] = (void*)ftpf_uni_s;
	pf->flist['i'] = (void*)ftpf_id;
	pf->flist['d'] = (void*)ftpf_id;
	pf->flist['D'] = (void*)ftpf_id;
	pf->flist['u'] = (void*)ftpf_u;
	pf->flist['U'] = (void*)ftpf_u;
	pf->flist['p'] = (void*)ftpf_p;
	pf->flist['x'] = (void*)ftpf_x;
	pf->flist['X'] = (void*)ftpf_x;
	pf->flist['o'] = (void*)ftpf_o;
	pf->flist['O'] = (void*)ftpf_o;
	pf->flist['%'] = (void*)ftpf_undefined;
	pf->flist['b'] = (void*)ftpf_b;
	pf->flist['n'] = (void*)ftpf_n;
	pf->flist['f'] = (void*)ftpf_f;
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
	pf->tfrm = (char*)frm;
	pf->f_curcolor = e_def;
	return (pf);
}


#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
//# include <stdint-gcc.h>
# include "../libft/libft.h"

# define F_NONE -1
# define F_FIRST 0
# define F_LAST 1
# define F_BOTH 2

typedef enum	e_colors {
				e_def = 0,
				e_white = 30,
				e_red = 31,
				e_green = 32,
				e_orange = 33,
				e_blue = 34,
				e_purple = 35,
				e_cyan = 36,
				e_gray = 37,
				e_black = 90,
}				t_colors;

typedef int		(*func_p)(void*); //0 - move forvard; 1 - time to stop ft_parser (spec parse) -1 - error

typedef struct 	s_prnt
{
	int 		buf_len;
	int 		res_len;
	char	 	*tfrm;
	char 		*res;
	char 		*buf;

	//long double	forthefuture;// for presitious float

	//move flags and spec-s to separet struct????
	int 		minlen;
	int			precis;
	int			argnum;
	char 		*sign;
	int8_t		fplus;
	int8_t		fmnus;
	int8_t		fhash;
	int8_t		fzero;
	int8_t		fspace;
	int8_t		fdot;
	int8_t		f_ld;
	int8_t		f_h;
	int8_t		f_l;
	int8_t		f_hh;
	int8_t		f_ll;
	int8_t		f_j;
	int8_t		f_z;
	int8_t		f_t;
	int8_t		f_baks;

	t_colors	f_curcolor;

	va_list		arg;
	va_list		initarg;
	func_p		*flist;
}				t_print;

/*
*** ft_printf
*/

int				ft_printf(const char *format, ...);
char			*ft_catbuf(t_print *pf, const char *start, const char *stop);

/*
*** ft_printf
*/

t_print			*ft_init_pf(const char *frm);
void			ft_reset_pf(t_print *pf);

/*
*** pf_parse_flags_a
*/

int				ftpf_set_starflag(t_print *pf);
int				ftpf_setdotflag(t_print *pf);
int				ftpf_set_hflag(t_print *pf);
int				ftpf_set_lflag(t_print *pf);
int				ftpf_parsenum(t_print *pf);

/*
*** pf_parse_flags_b
*/

int 			ftpf_set_minusflag(t_print *pf);
int 			ftpf_set_plusflag(t_print *pf);
int 			ftpf_set_zeroflag(t_print *pf);
int 			ftpf_set_hashflag(t_print *pf);
int 			ftpf_set_spaceflag(t_print *pf);

/*
*** pf_parse_flags_c
*/

int 			ftpf_set_ldflag(t_print *pf);
int 			ftpf_set_jflag(t_print *pf);
int 			ftpf_set_zflag(t_print *pf);
int				ftpf_set_tflag(t_print *pf);
int				ftpf_skipvarg(t_print *pf);

/*
*** pf_process_func
*/

int 			ftpf_process_minlen(t_print *pf, char *buf, int len, char fil);
int				ftpf_process_precis(t_print *p, char *buf, int len);
int				ftps_process_sign(t_print *pf);
long			ft_abs(long x);
int				ftpf_atoiskip(t_print *pf);

/*
*** pf_cs
*/

void			pf_process_cs(t_print *pf);
int				ftpf_c(t_print *pf);
int				ftpf_s(t_print *pf);
int				ftpf_undefined(t_print *pf);

/*
*** pf_idu
*/

int				ftpf_id(t_print *pf);
int				ftpf_u(t_print *pf);

/*
*** pf_xp
*/

int				ftpf_x(t_print *pf);
int				ftpf_p(t_print *pf);

/*
*** pf_ob
*/

int				ftpf_o(t_print *pf);
int				ftpf_b(t_print *pf);

/*
*** pf_uni
*/

int				ftpf_uni_s(t_print *pf);
int				ftpf_uni_c(t_print *pf);

/*
*** pf_n_color
*/

int				ftpf_n(t_print *pf);
char			*ftpf_color(t_print *pf, char *s);

/*
*** pf_f
*/

int				ftpf_f(t_print *pf);

/*
*** ft_strjoinandfree
*/

char			*ft_joinfree(char const *s1, char const *s2, int flag);
char 			*ft_concatresbuf(t_print *pf);
char 			*ft_strmemcat(char *s1, char *s2, int s1len, int s2len);

/*
*** ft_itoabase
*/

char			*ft_utoa_base(t_print *pf, uint64_t val, int base);
char			*ft_stoa_base(t_print *pf, int64_t val, int base);

#endif

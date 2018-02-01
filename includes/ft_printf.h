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
	char 		*sign;
	int8_t		fplus;
	int8_t		fmnus;
	int8_t		fhash;
	int8_t		fzero;
	int8_t		fspace;
	int8_t		fdot;
	int8_t		f_ml_star;
	int8_t		f_ps_star;
	int8_t		f_ld;
	int8_t		f_h;
	int8_t		f_l;
	int8_t		f_hh;
	int8_t		f_ll;
	int8_t		f_j;
	int8_t		f_z;


	//char		spec;//в моей схеме не нужно т,к, сам символ будет вызывать ф-цию
	va_list		arg;
	va_list		initarg;
	func_p		*flist;
}				t_print;

int				ft_printf(const char *format, ...);

t_print			*ft_init_pf(const char *frm);
int				ftpf_set_starflag(t_print *pf);
int				ftpf_set_lflag(t_print *pf);
int				ftpf_set_hflag(t_print *pf);
int				ftpf_setdotflag(t_print *pf);

int				ftpf_parsenum(t_print *pf);
int 			ftpf_set_minusflag(t_print *pf);
int 			ftpf_set_plusflag(t_print *pf);
int 			ftpf_set_zeroflag(t_print *pf);
int 			ftpf_set_hashflag(t_print *pf);
int 			ftpf_set_spaceflag(t_print *pf);
int 			ftpf_set_ldflag(t_print *pf);
int 			ftpf_set_jflag(t_print *pf);
int 			ftpf_set_zflag(t_print *pf);


int 			ftpf_process_minlen(t_print *pf, char *buf, int len, char fil);
int				ftpf_process_precis(t_print *p, char *buf, int len);
int				ftps_process_sign(t_print *pf);
long			ft_abs(long x);
int				ftpf_atoiskip(t_print *pf);


int				ftpf_c(t_print *pf);
int				ftpf_s(t_print *pf);
void			pf_process_cs(t_print *pf);

int				ftpf_id(t_print *pf);
int				ftpf_u(t_print *pf);

int				ftpf_x(t_print *pf);
int				ftpf_p(t_print *pf);

int				ftpf_o(t_print *pf);

//int				ft_uni_to_chr(char *dst, uint32_t c);
int				ftpf_uni_s(t_print *pf);
int				ftpf_uni_c(t_print *pf);

int				ftpf_undefined(t_print *pf);

void			ft_reset_pf(t_print *pf);

char			*ft_joinfree(char const *s1, char const *s2, int flag);

char			*ft_utoa_base(t_print *pf, uint64_t val, int base);
char			*ft_stoa_base(t_print *pf, int64_t val, int base);

#endif

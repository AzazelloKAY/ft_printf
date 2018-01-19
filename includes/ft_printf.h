#ifndef FT_PRINTF_FT_PRINTF_H
# define FT_PRINTF_FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *format, ...);

typedef void	*(*func_p)(int, int);

typedef struct	s_word
{
	char	*name;
	func_p	func;
}				t_word;

typedef struct 	s_prnt
{
	int 	buf_len;
	int 	res_len;
	int 	tmp;
	int 	minwidth;
	int		precision;
	uint8_t fplus;
	uint8_t fmins;
	uint8_t fhash;
	func_p	func;
	va_list arg;
	char 	*buf;
}				t_print;

#endif

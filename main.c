#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "includes/ft_printf.h"

//	fflush(stdout);



int main()
{
	setlocale(LC_ALL,"");

//	ft_putstr("asdasdgfsdg#$%$^$&$&^*546867sd\n");

uint32_t x = 945;


//	if (MB_CUR_MAX == 1)
//		printf("aaaaaa\n");
//	else if (MB_CUR_MAX == 4)
//		printf("XYIIIII");

	char *c = 0;
	printf(">%5.2caa<\n", c);
	fflush(stdout);
	ft_printf(">%5.2caa<\n", c);


	//***************************************************

//	printf("long dbl size = %lu\n", sizeof(long double));
//	printf("double size = %lu\n", sizeof(double));
//	long double ld= 0;
//	fflush(stdout);
//	double d;
//	d = 1.0;
//	ft_printf("binary = %b\n", d);

//	while (d >0)
//	{
//		d /= 2.0;
//		ft_printf("2binary = %b\n", d);
//	}
//	d /= 2.0;
//	ft_printf("3binary = %b\n", d);
//	d /= 2.0;
//	ft_printf("4binary = %b\n", d);
//	printf("ld = %5.2f\n", d);


//	char *cc = NULL;
//	printf("123\e[m%s\n", ft_strjoin(cc, "asd"));
//	fflush(stdout);
//
//	t_colors n = e_blue;

	//printf("n = %s\n", ft_joinfree("\\e[", ft_itoa(n), F_LAST));
	//ft_printf("a{black}a{red}a{green}a{orange}a{blue}s{purple}s{cyan}s{gay}s{white}sss%dzzz{{white}zzz", 54);



	return (0);
}




#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "includes/ft_printf.h"

//	fflush(stdout);


typedef struct bitfield
{
	unsigned x1:1;
	unsigned x2:30;
	unsigned sign:1;

}				bbfield;

typedef struct s_long_d
{
	unsigned long	man	: 64;
	unsigned long	exp	: 63;
	unsigned 		sign	: 1;

}				t_long_d;

typedef union	u_bfild
{
	long double	x;
	t_long_d	f;
}				t_bfild;


/*
 * 	u_type test;
	test.x = -1;
	test.y.sign = 0;
	printf("==%d\n\n", test.x);
 * */

int main()
{
	setlocale(LC_ALL,"");

//	ft_putstr("asdasdgfsdg#$%$^$&$&^*546867sd\n");
	long double l;
	t_bfild test;
	test.x = -1111111111111111111111111111111111111111111.0L;
	printf(">sign>%d\n", test.f.sign);
	printf(">>%ld\n", test.f.exp);
	printf(">>%Lf\n", test.x);


	int a = 0;
	int b = -1;
	while (a < b)
	{
		printf("\nAAAAq%ld\n", 9223372036854775807);
		a++;
	}
	printf("\nddd");

//u_type test;
//test.x = 2;
//test.y.sign = 0;
//printf("==%d\n\n", test.x);



uint32_t x = 945;


//	if (MB_CUR_MAX == 1)
//		printf("aaaaaa\n");
//	else if (MB_CUR_MAX == 4)
//		printf("XYIIIII");

	char *c = 0;
	printf(">%7.8s<<<\n", c);
	fflush(stdout);
	ft_printf("_%7.8s<<<\n", c);


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




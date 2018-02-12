#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "includes/ft_printf.h"

//	fflush(stdout);



/*
 * 	u_type test;
	test.x = -1;
	test.y.sign = 0;
	printf("==%d\n\n", test.x);
 * */

int main()
{
	setlocale(LC_ALL,"");
	//setlocale(LC_NUMERIC,"");

//	ft_putstr("asdasdgfsdg#$%$^$&$&^*546867sd\n");


//	int ff = 200;
//	ft_printf("%1$d====\n%1$5'd<\n\n", ff);

//	long double l;
//	u_ldoublebfild test;
//	l = -222270.9578;
//	test.x = l;
//	printf(">=>%'Lf<\n", test.x);
//	fflush(stdout);

	u_doublebfild d;
//	d.x = 1.9;
//	printf(">====>%f(S=%d E=%ld M=%ld)<\n", d.x, d.f.sign, d.f.exp, d.f.man);
//	fflush(stdout);
//	ft_printf("sign = %b exp = %b man = %b\n", d.f.sign, d.f.exp, d.f.man);

	d.x = 999.9999;
	printf(">====>%.8f(S=%d E=%ld M=%ld)<\n", d.x, d.f.sign, d.f.exp, d.f.man);
	fflush(stdout);
	ft_printf("sign = %b exp = %b man = %b\n", d.f.sign, d.f.exp, d.f.man);

	ft_printf("##MY## >>>%.8'f<\n", d.x);
//	test.x /= 1;
//	printf(">>%.10Lf<\n", test.x);
//
//	ff = 0;
// //	while (ff < 25)
//	{
//		ft_printf("sign = %b exp = %b man = %b\n", test.f.sign, test.f.exp, test.f.man);
//		fflush(stdout);
//		test.x /= 2;
//		ff++;
//	}

	//ft_printf("sign = %b exp = %d man = %ld\n",test.f.sign, test.f.exp, test.f.man );



//u_type test;
//test.x = 2;
//test.y.sign = 0;
//printf("==%d\n\n", test.x);


//
//uint32_t x = 945;
//
//
//	if (MB_CUR_MAX == 1)
//		printf("aaaaaa\n");
//	else if (MB_CUR_MAX == 4)
//		printf("XYIIIII");
//
//	char *c = 0;
//	printf(">%7.8s<<<\n", c);
//	fflush(stdout);
//	ft_printf("_%7.8s<<<\n", c);


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




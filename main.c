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


//	ft_printf("\n%5b\n", L"жОпА");
//	printf("\n%05b\n", L"жОпА");

	ft_printf("\n==%h+h+h+d\n", 0x1ff);
	printf("\n>>%.*-*+*+d<\n", 2, 4, 5);
	printf("\n\e[36m%lu\n", sizeof(uint64_t));


//char *ff = "жы";
//	write(1, ff, 4);

//	uint32_t	res;
//	uint8_t		*b;
//	uint8_t		bb;
//
//	res = 0;
//
//
//		mask = 0xC080;
//		b[3] = (x & 0x3F) + 0x80;
//		b[2] = ((x & 0x7C0) >> 6) + 0xC0;
//		res = ((x & 0x7C0) << 2) + (x & 0x3F) + 0xC080;
//
//	b = &res;
//	printf("==%hhu\n", b[0]);
//	fflush(stdout);
//
//	write(1, &b[1], 1);
//	write(1, &b[0], 1);
//
//		bb = (((x & 0x7C0) >> 6)  + 0xC0);
//		write(1, &bb, 1);
//		bb = ((x & 0x3F) + 0x80);
//		write(1, &bb, 1);
//
//	char f[3];
//
//	f[0] = ((x & 0x7C0) << 2) + (x & 0x3F) + 0xC080;
//	printf("___%s", f);





//	long i = 7;
//	int8_t xx = 127;
//	int x = printf(">%S_\n", L"ав");
//	printf("num=%d",x);
//	printf("start>");

//	int xx = ft_printf("\n>%s >> ", "<my test string>");//"<words in arg>\n");


//	printf("\npf=%d",printf("\n\n>%в__|%d|__", xx));

	//printf("_%lu\n", sizeof(long double));



//	unsigned a = 429;//.19;
//
//	int c = (unsigned int) a;
//	//ft_bzero(&a, sizeof(long double));
//	//printf("\n<< pf2>=%d\n",printf("=%+9.5u", a));//a & 0x7FFFFFFFFFFFFFFF));
//
//	//printf("===%lu\n", sizeof(long));
//
//	int ca = 10;//'s';
//	printf("=%9..........+30+10c< asdewq>\n", 'g');
//	//printf("=%lld bbbd>\n", 92233720368547759000);
// //	printf("=%6.2s<\n", "ass");
//	fflush(stdout);

//
//	int zz = printf("@main_ftprintf: %####0000 33..1..#00d\n", 256);
//	printf("orig %d\n", zz);
//	fflush(stdout);
//	zz = ft_printf("@main_ftprintf: %####0000 33..1..#00d\n", 256);
//	fflush(stdout);
//	printf("my %d\n", zz);
//	fflush(stdout);
//	char *t = ft_strnew(2);

//	printf("orig=%020.p<\n", 0);
//	ft_printf("my=%20p<\n", 0);

//	printf("or x=%#.0x<\n", 0);
//	ft_printf("my x>%#.0x<\n", 0);
//
//	printf("or o=%#.0o<\n", 0);
//	ft_printf("my o>%#.0o<\n", 0);
//
//	printf("or d=%.0d<\n", 0);
//	ft_printf("my d>%.0d<\n", 0);
//	printf("or u=%.0u<\n", 0);
//	ft_printf("my u>%.0u<\n", 0);
//
//
//	int ss = -42;
//	printf("\nor p=%d<\n", ss);
//	fflush(stdout);
//	ft_printf("my p=%d<\n", ss);
//	fflush(stdout);
//
//	uint16_t da = 0xB1CE0000;
//	uint32_t dd = 0xB1CE;
//	uint8_t a1 = 0xB1;
//	uint8_t a2 = 0xCE;
//	char s[4];
//	s[0] = 0xF0;
//	s[1] = 0x80;
//	s[2] = 0x8E;
//	s[3] = 0xB1;
//	write(1, s, 4);
//	write(1, &a2, 1);
//	write(1, &a1, 1);
//	write(1, &dd, 2);
//	write(1, &da, 2);



	return (0);
}




#include <stdio.h>
#include <locale.h>
#include "includes/ft_printf.h"

//	fflush(stdout);

int main()
{
	setlocale(LC_ALL,"");

//	ft_putstr("asdasdgfsdg#$%$^$&$&^*546867sd\n");

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
//	printf("or p=%10.5s<\n", "asdrew  wer");
//	fflush(stdout);
//	ft_printf("my p=%10.5s<\n", "asdrew  wer");
//	fflush(stdout);

	uint16_t da = 0xB1CE0000;
	uint32_t dd = 0xB1CE;
	uint8_t a1 = 0xB1;
	uint8_t a2 = 0xCE;
	char s[4];
	s[0] = 0xF0;
	s[1] = 0x80;
	s[2] = 0x8E;
	s[3] = 0xB1;
	write(1, s, 4);
//	write(1, &a2, 1);
//	write(1, &a1, 1);
//	write(1, &dd, 2);
//	write(1, &da, 2);



	return (0);
}




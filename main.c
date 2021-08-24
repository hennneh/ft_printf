/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main_batu.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 22:35:59 by bkeskint          #+#    #+#             */
/*   Updated: 2021/08/19 14:00:25 by bkeskint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include "libft/libft.h"
#include <stdio.h>

#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define DEFAULT "\033[0m"

static int counter = 0;
static int counterf = 0;

void	test_compare()
{
	char a = 'a';
	char b = '*';
	int i = +1234;
	int *p = &i;
	int j = -5982;
	int i2 = 9;
	int j2 = -2;
	char *s = "Batuhan Deneme 1";
	char *s2 = "         ";

	counter = printf("printf: %c -- %% -- %c -- %d -- %d -- %i -- %i \n", a, b, i, j, i2, j2);
	printf("counter = %d \n", counter);
	counter = ft_printf("printf: %c -- %% -- %c -- %d -- %d -- %i -- %i \n", a, b, i, j, i2, j2);
	printf("counter = %d \n", counter);
	printf("\n\n");
	counter = printf("printf: %s Start:%s..\n",s, s2);
	printf("counter = %d \n", counter);
	counter = ft_printf("printf: %s Start:%s..\n",s, s2);
	printf("counter = %d \n", counter);
	printf("\n\n");
	counter = printf("printf: %x \n",i);
	printf("counter = %d \n", counter);
	counter = ft_printf("printf: %x \n",i);
	printf("counter = %d \n", counter);
	printf("\n\n");
	counter = printf("printf: %p \n",p);
	printf("counter = %d \n", counter);
	counter = ft_printf("printf: %p \n",p);
	printf("counter = %d \n", counter);
	printf("\n\n");
    printf("The address in Hexadecimal: %p \n", p);
	ft_printf("The address in Hexadecimal: %p", p);
	printf("\n\n");
	printf("\nThe address in Unsigned Integer form: %u", p);
    ft_printf("\nThe address in Unsigned Integer form: %u\n", p);
	counter = 0;
}

void	test_char()
{
	printf(BLUE"\nCHAR TEST\n"); printf(DEFAULT"\n");
	counter +=  printf("1- %c", '0');
	counter +=  printf("2-  %c ", '0');
	counter +=  printf("3- %c", '0' - 256);
	counter +=  printf("4- %c ", '0' + 256);
	counter +=  printf("5-  %c %c %c ", '0', 0, '1');
	counter +=  printf("6-  %c %c %c ", ' ', ' ', ' ');
	counter +=  printf("7-  %c %c %c ", '1', '2', '3');
	counter +=  printf("8-  %c %c %c ", '2', '1', 0);
	counter +=  printf("9-  %c %c %c ", 0, '1', '2');
	printf("\n----------------------------------------------\n");
	counterf +=  ft_printf("1- %c", '0');
	counterf +=  ft_printf("2-  %c ", '0');
	counterf +=  ft_printf("3- %c", '0' - 256);
	counterf +=  ft_printf("4- %c ", '0' + 256);
	counterf +=  ft_printf("5-  %c %c %c ", '0', 0, '1');
	counterf +=  ft_printf("6-  %c %c %c ", ' ', ' ', ' ');
	counterf +=  ft_printf("7-  %c %c %c ", '1', '2', '3');
	counterf +=  ft_printf("8-  %c %c %c ", '2', '1', 0);
	counterf +=  ft_printf("9-  %c %c %c ", 0, '1', '2');
	(counter == counterf) ? (printf(GREEN"\nOK\n")) : (printf(RED"\nKO\n")); printf(YELLOW"orginal - %d | user - %d\n", counter, counterf); printf(DEFAULT"\n");
	counter = 0;
	counterf = 0;
}

void	test_string()
{
	printf(BLUE"\nSTRING TEST\n"); printf(DEFAULT"\n");
	counter +=  printf("1- %s", "");
	counter +=  printf("2-  %s", "");
	counter +=  printf("3- %s ", "");
	counter +=  printf("4-  %s ", "");
	counter +=  printf("5-  %s ", "-");
	counter +=  printf("6-  %s %s ", "", "-");
	counter +=  printf("7-  %s %s ", " - ", "");
	counter +=  printf("8-  %s %s %s %s ", " - ", "", "4", "");
	counter +=  printf("9-  %s %s %s %s %s ", " - ", "", "4", "", "2 ");
	counter +=  printf("10- %s", NULL);
	printf("\n----------------------------------------------\n");
	counterf +=  ft_printf("1- %s", "");
	counterf +=  ft_printf("2-  %s", "");
	counterf +=  ft_printf("3- %s ", "");
	counterf +=  ft_printf("4-  %s ", "");
	counterf +=  ft_printf("5-  %s ", "-");
	counterf +=  ft_printf("6-  %s %s ", "", "-");
	counterf +=  ft_printf("7-  %s %s ", " - ", "");
	counterf +=  ft_printf("8-  %s %s %s %s ", " - ", "", "4", "");
	counterf +=  ft_printf("9-  %s %s %s %s %s ", " - ", "", "4", "", "2 ");
	counterf +=  ft_printf("10- %s", NULL);
	(counter == counterf) ? (printf(GREEN"\nOK\n")) : (printf(RED"\nKO\n")); printf(YELLOW"orginal - %d | user - %d\n", counter, counterf); printf(DEFAULT"\n");
	counter = 0;
	counterf = 0;
}

void test_pointer()
{
	printf(BLUE"\nPOINTER TEST\n"); printf(DEFAULT"\n");
	counter = 0;
	counter +=  printf("1-  %p ", -1);
	counter +=  printf("2-  %p ", 1);
	 counter +=  printf("3-  %p ", 15);
	 counter +=  printf("4-  %p ", 16);
	 counter +=  printf("5-  %p ", 17);
	 counter +=  printf("6-  %p %p ",-9223372036854775808, +9223372036854775807);
	 counter +=  printf("7-  %p %p ", -2147483648, +2147483647);
	 counter +=  printf("8-  %p %p ", 18446744073709551615, -18446744073709551615);
	 counter +=  printf("9-  %p %p ", 0, 0);
	 counter +=  printf("10-  %p ", NULL);
	printf("\n----------------------------------------------\n");
	counterf +=  ft_printf("1-  %p ", -1);
	counterf +=  ft_printf("2-  %p ", 1);
	 counterf +=  ft_printf("3-  %p ", 15);
	 counterf +=  ft_printf("4-  %p ", 16);
	 counterf +=  ft_printf("5-  %p ", 17);
	 counterf +=  ft_printf("6-  %p %p ",-9223372036854775808, +9223372036854775807);
	 counterf +=  ft_printf("7-  %p %p ", -2147483648, +2147483647);
	 counterf +=  ft_printf("8-  %p %p ", 18446744073709551615, -18446744073709551615);
	 counterf +=  ft_printf("9-  %p %p ", 0, 0);
	 counterf +=  ft_printf("10-  %p ", NULL);
	(counter == counterf) ? (printf(GREEN"\nOK\n")) : (printf(RED"\nKO\n")); printf(YELLOW"orginal - %d | user - %d\n", counter, counterf); printf(DEFAULT"\n");
	counter = 0;
	counterf = 0;
}

void	test_d_integer()
{
	printf(BLUE"\nd-INTEGER TEST\n"); printf(DEFAULT"\n");
	counter += printf("1-  %d ", 0);
	counter += printf("2-  %d ", -1);
	counter += printf("3-  %d ", 1);
	counter += printf("4-  %d ", 9);
	counter += printf("5-  %d ", 10);
	counter += printf("6-  %d ", 11);
	counter += printf("7-  %d ", 15);
	counter += printf("8-  %d ", 16);
	counter += printf("9-  %d ", 17);
	counter += printf("10-  %d ", 99);
	counter += printf("11-  %d ", 100);
	counter += printf("12-  %d ", 101);
	counter += printf("13-  %d ", -9);
	counter += printf("14-  %d ", -10);
	counter += printf("15-  %d ", -11);
	counter += printf("16-  %d ", -14);
	counter += printf("17-  %d ", -15);
	counter += printf("18-  %d ", -16);
	counter += printf("19-  %d ", -99);
	counter += printf("20-  %d ", -100);
	counter += printf("21-  %d ", -101);
	counter += printf("22-  %d ", +2147483647);
	counter += printf("23-  %d ", -2147483648);
	counter += printf("24-  %d ", +9223372036854775807);
	counter += printf("25-  %d ", -9223372036854775808);
	counter += printf("26-  %d ", 4294967295);
	counter += printf("27-  %d ", 18446744073709551615);
	counter += printf("28-  %d ", 9223372036854775807LL);
	counter += printf("29-  %d %d %d %d %d %d %d",
				+2147483647, -2147483648, +9223372036854775807, -9223372036854775808, 18446744073709551615	, 0, -42);
	printf("\n----------------------------------------------\n");
	counterf += ft_printf("1-  %d ", 0);
	counterf += ft_printf("2-  %d ", -1);
	counterf += ft_printf("3-  %d ", 1);
	counterf += ft_printf("4-  %d ", 9);
	counterf += ft_printf("5-  %d ", 10);
	counterf += ft_printf("6-  %d ", 11);
	counterf += ft_printf("7-  %d ", 15);
	counterf += ft_printf("8-  %d ", 16);
	counterf += ft_printf("9-  %d ", 17);
	counterf += ft_printf("10-  %d ", 99);
	counterf += ft_printf("11-  %d ", 100);
	counterf += ft_printf("12-  %d ", 101);
	counterf += ft_printf("13-  %d ", -9);
	counterf += ft_printf("14-  %d ", -10);
	counterf += ft_printf("15-  %d ", -11);
	counterf += ft_printf("16-  %d ", -14);
	counterf += ft_printf("17-  %d ", -15);
	counterf += ft_printf("18-  %d ", -16);
	counterf += ft_printf("19-  %d ", -99);
	counterf += ft_printf("20-  %d ", -100);
	counterf += ft_printf("21-  %d ", -101);
	counterf += ft_printf("22-  %d ", +2147483647);
	counterf += ft_printf("23-  %d ", -2147483648);
	counterf += ft_printf("24-  %d ", +9223372036854775807);
	counterf += ft_printf("25-  %d ", -9223372036854775808);
	counterf += ft_printf("26-  %d ", 4294967295);
	counterf += ft_printf("27-  %d ", 18446744073709551615);
	counterf += ft_printf("28-  %d ", 9223372036854775807LL);
	counterf += ft_printf("29-  %d %d %d %d %d %d %d",
				+2147483647, -2147483648, +9223372036854775807, -9223372036854775808, 18446744073709551615	, 0, -42);
	(counter == counterf) ? (printf(GREEN"\nOK\n")) : (printf(RED"\nKO\n")); printf(YELLOW"orginal - %d | user - %d\n", counter, counterf); printf(DEFAULT"\n");
	counter = 0;
	counterf = 0;
}

void	test_i_integer()
{
	printf(BLUE"\ni-INTEGER TEST\n"); printf(DEFAULT"\n");
	counter += printf("1-  %i ", 0);
	counter += printf("2-  %i ", -1);
	counter += printf("3-  %i ", 1);
	counter += printf("4-  %i ", 9);
	counter += printf("5-  %i ", 10);
	counter += printf("6-  %i ", 11);
	counter += printf("7-  %i ", 15);
	counter += printf("8-  %i ", 16);
	counter += printf("9-  %i ", 17);
	counter += printf("10-  %i ", 99);
	counter += printf("11-  %i ", 100);
	counter += printf("12-  %i ", 101);
	counter += printf("13-  %i ", -9);
	counter += printf("14-  %i ", -10);
	counter += printf("15-  %i ", -11);
	counter += printf("16-  %i ", -14);
	counter += printf("17-  %i ", -15);
	counter += printf("18-  %i ", -16);
	counter += printf("19-  %i ", -99);
	counter += printf("20-  %i ", -100);
	counter += printf("21-  %i ", -101);
	counter += printf("22-  %i ", +2147483647);
	counter += printf("23-  %i ", -2147483648);
	counter += printf("24-  %i ", +9223372036854775807);
	counter += printf("25-  %i ", -9223372036854775808);
	counter += printf("26-  %i ", 4294967295);
	counter += printf("27-  %i ", 18446744073709551615);
	counter += printf("28-  %i ", 9223372036854775807LL);
	counter += printf("29-  %i %i %i %i %i %i %i",
				+2147483647, -2147483648, +9223372036854775807, -9223372036854775808, 18446744073709551615	, 0, -42);
	printf("\n----------------------------------------------\n");
	counterf += ft_printf("1-  %i ", 0);
	counterf += ft_printf("2-  %i ", -1);
	counterf += ft_printf("3-  %i ", 1);
	counterf += ft_printf("4-  %i ", 9);
	counterf += ft_printf("5-  %i ", 10);
	counterf += ft_printf("6-  %i ", 11);
	counterf += ft_printf("7-  %i ", 15);
	counterf += ft_printf("8-  %i ", 16);
	counterf += ft_printf("9-  %i ", 17);
	counterf += ft_printf("10-  %i ", 99);
	counterf += ft_printf("11-  %i ", 100);
	counterf += ft_printf("12-  %i ", 101);
	counterf += ft_printf("13-  %i ", -9);
	counterf += ft_printf("14-  %i ", -10);
	counterf += ft_printf("15-  %i ", -11);
	counterf += ft_printf("16-  %i ", -14);
	counterf += ft_printf("17-  %i ", -15);
	counterf += ft_printf("18-  %i ", -16);
	counterf += ft_printf("19-  %i ", -99);
	counterf += ft_printf("20-  %i ", -100);
	counterf += ft_printf("21-  %i ", -101);
	counterf += ft_printf("22-  %i ", +2147483647);
	counterf += ft_printf("23-  %i ", -2147483648);
	counterf += ft_printf("24-  %i ", +9223372036854775807);
	counterf += ft_printf("25-  %i ", -9223372036854775808);
	counterf += ft_printf("26-  %i ", 4294967295);
	counterf += ft_printf("27-  %i ", 18446744073709551615);
	counterf += ft_printf("28-  %i ", 9223372036854775807LL);
	counterf += ft_printf("29-  %i %i %i %i %i %i %i",
				+2147483647, -2147483648, +9223372036854775807, -9223372036854775808, 18446744073709551615	, 0, -42);
	(counter == counterf) ? (printf(GREEN"\nOK\n")) : (printf(RED"\nKO\n")); printf(YELLOW"orginal - %i | user - %i\n", counter, counterf); printf(DEFAULT"\n");
	counter = 0;
	counterf = 0;
}

void	test_unsigned()
{
	printf(BLUE"\nUNSIGNED TEST\n"); printf(DEFAULT"\n");
	counter += printf("1-  %u ", 0);
	counter += printf("2-  %u ", -1);
	counter += printf("3-  %u ", 1);
	counter += printf("4-  %u ", 9);
	counter += printf("5-  %u ", 10);
	counter += printf("6-  %u ", 11);
	counter += printf("7-  %u ", 15);
	counter += printf("8-  %u ", 16);
	counter += printf("9-  %u ", 17);
	counter += printf("10-  %u ", 99);
	counter += printf("11-  %u ", 100);
	counter += printf("12-  %u ", 101);
	counter += printf("13-  %u ", -9);
	counter += printf("14-  %u ", -10);
	counter += printf("15-  %u ", -11);
	counter += printf("16-  %u ", -14);
	counter += printf("17-  %u ", -15);
	counter += printf("18-  %u ", -16);
	counter += printf("19-  %u ", -99);
	counter += printf("20-  %u ", -100);
	counter += printf("21-  %u ", -101);
	counter += printf("22-  %u ", +2147483647);
	counter += printf("23-  %u ", -2147483648);
	counter += printf("24-  %u ", +9223372036854775807);
	counter += printf("25-  %u ", -9223372036854775808);
	counter += printf("26-  %u ", 4294967295);
	counter += printf("27-  %u ", 18446744073709551615);
	counter += printf("28-  %u ", 9223372036854775807LL);
	counter += printf("29-  %u %u %u %u %u %u %d ",
				+2147483647, -2147483648, +9223372036854775807, -9223372036854775808, 18446744073709551615	, 0, -42);
	counter += printf("30-  %u ", NULL);
	printf("\n----------------------------------------------\n");
	counterf += ft_printf("1-  %u ", 0);
	counterf += ft_printf("2-  %u ", -1);
	counterf += ft_printf("3-  %u ", 1);
	counterf += ft_printf("4-  %u ", 9);
	counterf += ft_printf("5-  %u ", 10);
	counterf += ft_printf("6-  %u ", 11);
	counterf += ft_printf("7-  %u ", 15);
	counterf += ft_printf("8-  %u ", 16);
	counterf += ft_printf("9-  %u ", 17);
	counterf += ft_printf("10-  %u ", 99);
	counterf += ft_printf("11-  %u ", 100);
	counterf += ft_printf("12-  %u ", 101);
	counterf += ft_printf("13-  %u ", -9);
	counterf += ft_printf("14-  %u ", -10);
	counterf += ft_printf("15-  %u ", -11);
	counterf += ft_printf("16-  %u ", -14);
	counterf += ft_printf("17-  %u ", -15);
	counterf += ft_printf("18-  %u ", -16);
	counterf += ft_printf("19-  %u ", -99);
	counterf += ft_printf("20-  %u ", -100);
	counterf += ft_printf("21-  %u ", -101);
	counterf += ft_printf("22-  %u ", +2147483647);
	counterf += ft_printf("23-  %u ", -2147483648);
	counterf += ft_printf("24-  %u ", +9223372036854775807);
	counterf += ft_printf("25-  %u ", -9223372036854775808);
	counterf += ft_printf("26-  %u ", 4294967295);
	counterf += ft_printf("27-  %u ", 18446744073709551615);
	counterf += ft_printf("28-  %u ", 9223372036854775807LL);
	counterf += ft_printf("29-  %u %u %u %u %u %u %d ",
				+2147483647, -2147483648, +9223372036854775807, -9223372036854775808, 18446744073709551615	, 0, -42);
	counterf += ft_printf("30-  %u ", NULL);
	(counter == counterf) ? (printf(GREEN"\nOK\n")) : (printf(RED"\nKO\n")); printf(YELLOW"orginal - %i | user - %i\n", counter, counterf); printf(DEFAULT"\n");
	counter = 0;
	counterf = 0;
}

void	test_x_hexadecimal()
{
	printf(BLUE"\nx-HEXADECIMAL TEST\n"); printf(DEFAULT"\n");
	counter += printf("1-  %x ", 0);
	counter += printf("2-  %x ", -1);
	counter += printf("3-  %x ", 1);
	counter += printf("4-  %x ", 9);
	counter += printf("5-  %x ", 10);
	counter += printf("6-  %x ", 11);
	counter += printf("7-  %x ", 15);
	counter += printf("8-  %x ", 16);
	counter += printf("9-  %x ", 17);
	counter += printf("10-  %x ", 99);
	counter += printf("11-  %x ", 100);
	counter += printf("12-  %x ", 101);
	counter += printf("13-  %x ", -9);
	counter += printf("14-  %x ", -10);
	counter += printf("15-  %x ", -11);
	counter += printf("16-  %x ", -14);
	counter += printf("17-  %x ", -15);
	counter += printf("18-  %x ", -16);
	counter += printf("19-  %x ", -99);
	counter += printf("20-  %x ", -100);
	counter += printf("21-  %x ", -101);
	counter += printf("22-  %x ", +2147483647);
	counter += printf("23-  %x ", -2147483648);
	counter += printf("24-  %x ", +9223372036854775807);
	counter += printf("25-  %x ", -9223372036854775808);
	counter += printf("26-  %x ", 4294967295);
	counter += printf("27-  %x ", 18446744073709551615);
	counter += printf("28-  %x ", 9223372036854775807LL);
	counter += printf("29-  %x %x %x %x %x %x %d ",
				+2147483647, -2147483648, +9223372036854775807, -9223372036854775808, 18446744073709551615	, 0, -42);
	counter += printf("30-  %u ", NULL);
	printf("\n----------------------------------------------\n");
	counterf += ft_printf("1-  %x ", 0);
	counterf += ft_printf("2-  %x ", -1);
	counterf += ft_printf("3-  %x ", 1);
	counterf += ft_printf("4-  %x ", 9);
	counterf += ft_printf("5-  %x ", 10);
	counterf += ft_printf("6-  %x ", 11);
	counterf += ft_printf("7-  %x ", 15);
	counterf += ft_printf("8-  %x ", 16);
	counterf += ft_printf("9-  %x ", 17);
	counterf += ft_printf("10-  %x ", 99);
	counterf += ft_printf("11-  %x ", 100);
	counterf += ft_printf("12-  %x ", 101);
	counterf += ft_printf("13-  %x ", -9);
	counterf += ft_printf("14-  %x ", -10);
	counterf += ft_printf("15-  %x ", -11);
	counterf += ft_printf("16-  %x ", -14);
	counterf += ft_printf("17-  %x ", -15);
	counterf += ft_printf("18-  %x ", -16);
	counterf += ft_printf("19-  %x ", -99);
	counterf += ft_printf("20-  %x ", -100);
	counterf += ft_printf("21-  %x ", -101);
	counterf += ft_printf("22-  %x ", +2147483647);
	counterf += ft_printf("23-  %x ", -2147483648);
	counterf += ft_printf("24-  %x ", +9223372036854775807);
	counterf += ft_printf("25-  %x ", -9223372036854775808);
	counterf += ft_printf("26-  %x ", 4294967295);
	counterf += ft_printf("27-  %x ", 18446744073709551615);
	counterf += ft_printf("28-  %x ", 9223372036854775807LL);
	counterf += ft_printf("29-  %x %x %x %x %x %x %d ",
				+2147483647, -2147483648, +9223372036854775807, -9223372036854775808, 18446744073709551615	, 0, -42);
	counterf += ft_printf("30-  %u ", NULL);
	(counter == counterf) ? (printf(GREEN"\nOK\n")) : (printf(RED"\nKO\n")); printf(YELLOW"orginal - %i | user - %i\n", counter, counterf); printf(DEFAULT"\n");
	counter = 0;
	counterf = 0;
}

void	test_X_hexadecimal()
{
	printf(BLUE"\nX-HEXADECIMAL TEST\n"); printf(DEFAULT"\n");
	counter += printf("1-  %X ", 0);
	counter += printf("2-  %X ", -1);
	counter += printf("3-  %X ", 1);
	counter += printf("4-  %X ", 9);
	counter += printf("5-  %X ", 10);
	counter += printf("6-  %X ", 11);
	counter += printf("7-  %X ", 15);
	counter += printf("8-  %X ", 16);
	counter += printf("9-  %X ", 17);
	counter += printf("10-  %X ", 99);
	counter += printf("11-  %X ", 100);
	counter += printf("12-  %X ", 101);
	counter += printf("13-  %X ", -9);
	counter += printf("14-  %X ", -10);
	counter += printf("15-  %X ", -11);
	counter += printf("16-  %X ", -14);
	counter += printf("17-  %X ", -15);
	counter += printf("18-  %X ", -16);
	counter += printf("19-  %X ", -99);
	counter += printf("20-  %X ", -100);
	counter += printf("21-  %X ", -101);
	counter += printf("22-  %X ", +2147483647);
	counter += printf("23-  %X ", -2147483648);
	counter += printf("24-  %X ", +9223372036854775807);
	counter += printf("25-  %X ", -9223372036854775808);
	counter += printf("26-  %X ", 4294967295);
	counter += printf("27-  %X ", 18446744073709551615);
	counter += printf("28-  %X ", 9223372036854775807LL);
	counter += printf("29-  %X %X %X %X %X %X %d",
				+2147483647, -2147483648, +9223372036854775807, -9223372036854775808, 18446744073709551615	, 0, -42);
	printf("\n----------------------------------------------\n");
	counterf += ft_printf("1-  %X ", 0);
	counterf += ft_printf("2-  %X ", -1);
	counterf += ft_printf("3-  %X ", 1);
	counterf += ft_printf("4-  %X ", 9);
	counterf += ft_printf("5-  %X ", 10);
	counterf += ft_printf("6-  %X ", 11);
	counterf += ft_printf("7-  %X ", 15);
	counterf += ft_printf("8-  %X ", 16);
	counterf += ft_printf("9-  %X ", 17);
	counterf += ft_printf("10-  %X ", 99);
	counterf += ft_printf("11-  %X ", 100);
	counterf += ft_printf("12-  %X ", 101);
	counterf += ft_printf("13-  %X ", -9);
	counterf += ft_printf("14-  %X ", -10);
	counterf += ft_printf("15-  %X ", -11);
	counterf += ft_printf("16-  %X ", -14);
	counterf += ft_printf("17-  %X ", -15);
	counterf += ft_printf("18-  %X ", -16);
	counterf += ft_printf("19-  %X ", -99);
	counterf += ft_printf("20-  %X ", -100);
	counterf += ft_printf("21-  %X ", -101);
	counterf += ft_printf("22-  %X ", +2147483647);
	counterf += ft_printf("23-  %X ", -2147483648);
	counterf += ft_printf("24-  %X ", +9223372036854775807);
	counterf += ft_printf("25-  %X ", -9223372036854775808);
	counterf += ft_printf("26-  %X ", 4294967295);
	counterf += ft_printf("27-  %X ", 18446744073709551615);
	counterf += ft_printf("28-  %X ", 9223372036854775807LL);
	counterf += ft_printf("29-  %X %X %X %X %X %X %d",
				+2147483647, -2147483648, +9223372036854775807, -9223372036854775808, 18446744073709551615	, 0, -42);
	(counter == counterf) ? (printf(GREEN"\nOK\n")) : (printf(RED"\nKO\n")); printf(YELLOW"orginal - %i | user - %i\n", counter, counterf); printf(DEFAULT"\n");
	counter = 0;
	counterf = 0;
}

void	test_percent()
{
	printf(BLUE"\nPERCENT TEST\n"); printf(DEFAULT"\n");
	counter += printf("1-  %% ");
	counter += printf("2-  %%%% ");
	counter += printf("3-  %% %% %% ");
	counter += printf("4-  %%  %%  %% ");
	counter += printf("5-  %%   %%   %% ");
	counter += printf("6- %%");
	counter += printf("7- %% %%");
	printf("\n----------------------------------------------\n");
	counterf += ft_printf("1-  %% ");
	counterf += ft_printf("2-  %%%% ");
	counterf += ft_printf("3-  %% %% %% ");
	counterf += ft_printf("4-  %%  %%  %% ");
	counterf += ft_printf("5-  %%   %%   %% ");
	counterf += ft_printf("6- %%");
	counterf += ft_printf("7- %% %%");
	(counter == counterf) ? (printf(GREEN"\nOK\n")) : (printf(RED"\nKO\n")); printf(YELLOW"orginal - %i | user - %i\n", counter, counterf); printf(DEFAULT"\n");
	counter = 0;
	counterf = 0;
}

void	test_mix()
{
		printf(BLUE"\nMIX TEST\n"); printf(DEFAULT"\n");
	counter += printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("\n----------------------------------------------\n");
	counterf += ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	(counter == counterf) ? (printf(GREEN"\nOK\n")) : (printf(RED"\nKO\n")); printf(YELLOW"orginal - %i | user - %i\n", counter, counterf); printf(DEFAULT"\n");
	counter = 0;
	counterf = 0;
}

void	test_bonus()
{
	printf(CYAN"\n-----------------------------------------\n");
	printf("\n----------------BONUS TESTS--------------\n");
	printf("\n-----------------------------------------\n");
	
	printf(DEFAULT"\n");

	printf("\n--------------ORIGINAL_PRINTF-----------\n");
	printf("This is Original Code: \n");
	printf(" %d\n %s\n %li\n %c\n %x\n %X\n %p\n %-4s $\n, %50.2s\n -->|%-16.p|<--\n",
	 24, "Hello World! Here is User", (long)123456789, 'A', 12, 12, "Hello World!", "se", (char *)(NULL), NULL);

	ft_printf("\n--------------FT_PRINTF-----------\n");
	ft_printf("This is User's Code: \n");
	ft_printf(" %d\n %s\n %c\n %x\n %X\n %p\n %-4s\n $\n %50.2s\n -->|%-16.p|<--\n",
	 24, "Hello World! Here is User", 'A', 12, 12, "Hello World!", "se", NULL, NULL);
	 
	printf(CYAN"\n-----------------------------------------\n");
	printf("\n--------------SOME OTHER CASES-----------\n");
	printf("\n-----------------------------------------\n");

	printf(DEFAULT"\n");
	
	ft_printf("%05% \n");
	printf("%05% \n");
	ft_printf("%p \n", NULL);
	printf("%p \n", NULL);
	ft_printf("%.03s\n", NULL);
	printf("%.03s\n", NULL);
	ft_printf("%3.1s\n", NULL);
	printf("%3.1s\n", NULL);
	ft_printf("%9.1s\n", NULL);
	printf("%9.1s\n", NULL);
	ft_printf("%-3.1s\n", NULL);
	printf("%-3.1s\n", NULL);
	ft_printf("%-9.1s\n", NULL);
	printf("%-9.1s\n", NULL);
	ft_printf("%p\n", NULL);
	printf("%p\n", NULL);
	ft_printf("p3 %.4s\n", NULL);
	printf("p3 %.4s\n", NULL);
	ft_printf("%010%\n");
	printf("%010%\n");
	ft_printf("%p\n", NULL);
	printf("%p\n", NULL);
	ft_printf("%15p\n", NULL);
	printf("%15p\n", NULL);
	ft_printf("%-15p\n", NULL);
	printf("%-15p\n", NULL);
	ft_printf("%50.2s", NULL);
	printf("%50.2s", NULL);
	ft_printf("percent 1 %012%\n");
	printf("percent 1 %012%\n");
	ft_printf("percent 2 %12%\n");
	printf("percent 2 %12%\n");
	ft_printf("%-70.193x%-140c%168c%026.51%%0125.119X\n" ,1102840003u,-50,-17,3721437512u);
	printf("%-70.193x%-140c%168c%026.51%%0125.119X\n" ,1102840003u,-50,-17,3721437512u);
	ft_printf("%10c%0036.99%\n" ,9);
	printf("%10c%0036.99%\n" ,9);
	ft_printf("%-132.186x%00129.46%%-191.181X%-75.123d%0033.123u\n" ,2222238685u,3146675666u,251185067,3453417465u);
	printf("%-132.186x%00129.46%%-191.181X%-75.123d%0033.123u\n" ,2222238685u,3146675666u,251185067,3453417465u);
	ft_printf("%--198.101X%0145.12%%172c\n" ,935976394u,-118);
	printf("%--198.101X%0145.12%%172c\n" ,935976394u,-118);
	ft_printf("%--81.*%%019.14%%---27c%-75.150d%00136.74x\n" ,70,-15,-128722927,4090510000u);
	printf("%--81.*%%019.14%%---27c%-75.150d%00136.74x\n" ,70,-15,-128722927,4090510000u);
	ft_printf("%52c%00040.166%%-131c%-12.99s\n" ,-57,123,"k\r/ULCoKi0");
	printf("%52c%00040.166%%-131c%-12.99s\n" ,-57,123,"k\r/ULCoKi0");
	ft_printf("%043.165%%--35.34s%--4.*d%-189.*i\n" ,"TSvqw0m:$c!hhK(,R*",-100,967600936,45,1272776825);
	printf("%043.165%%--35.34s%--4.*d%-189.*i\n" ,"TSvqw0m:$c!hhK(,R*",-100,967600936,45,1272776825);
	ft_printf("%.p\n", NULL);
	printf("%.p\n", NULL);
	ft_printf("%.p\n", NULL);
	printf("%.p\n", NULL);
	ft_printf("%1.p\n", NULL);
	printf("%1.p\n", NULL);
	ft_printf("%1.p\n", NULL);
	printf("%1.p\n", NULL);
	ft_printf("%5.p\n", NULL);
	printf("%5.p\n", NULL);
	ft_printf("%5.p\n", NULL);
	printf("%5.p\n", NULL);
	ft_printf("-->|%-16.p|<-- \n", NULL);
	printf("-->|%-16.p|<-- \n", NULL);
	ft_printf("-->|%-16.p|<-- \n", NULL);
	printf("-->|%-16.p|<-- \n", NULL);

	printf("\n Batuhan \n");
  	ft_printf("-->%5%<--");
  	printf("\n");
  	printf("Original\n");
  	printf("-->%5%<--");
 	printf("\n");
 
 	printf("\n Batuhan \n");
  	ft_printf("-->%-5%<--");
  	printf("\n");
  	printf("Original\n");
  	printf("-->%-5%<--");
	
	printf(CYAN"\n\n\n-----------------------------------------\n");
	printf("\n-----------------END OF FILE-------------\n");
	printf("\n-----------------------------------------\n");
}

void	test_extra()
{
	printf("%013x test 111\n", 4294967295);
    ft_printf("%013x\n\n", 4294967295);
    printf("<%-15x> test 143\n", 9223372036854775807LL);
    ft_printf("<%-15x>\n\n", 9223372036854775807LL);
    printf("%-11x test 139\n", 2147483647);
    ft_printf("%-11x\n\n", 2147483647);
    printf("%-11p %-12p  test 27\n", -2147483648, 2147483647);
    ft_printf("%-11p %-12p\n\n", -2147483648, 2147483647);
}

int main()
{
	 test_compare();
	
	 printf(CYAN"\n\n--------------------------\n--------------------------\nFunction Tests Are Start!!");
	 printf("\n--------------------------\n--------------------------\n");
	 printf(DEFAULT"\n");

	 test_char();
	 test_string();
	test_pointer();
	 test_d_integer();
	 test_i_integer();
	 test_unsigned();
	 test_x_hexadecimal();
	 test_X_hexadecimal();
	 test_percent();
	 test_mix();
	// test_bonus();
	// test_extra();
	return (0);
}

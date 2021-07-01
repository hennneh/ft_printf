#include <stdio.h>
#include <stdarg.h>

void arg_func(int i, ...)
{
	va_list someList;
	va_start(someList, i);
	int j = 0;
	int sum = 0;
	while (j < i)
	{
		 sum += va_arg(someList, int);
	}
	va_end(someList);
	printf("%d\n", sum);
}

int	main(void)
{
	printf("beginngin of program\n");
	arg_func(3, 1, 1, 1);
	printf("function has been called\n");
	return (0);
}

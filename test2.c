#include <stdio.h>

typedef struct
{
	int length;
	int	width;
} rectangle;

int main(void)
{
	rectangle myRectangle = {5, 10};
	printf("length = %d\nwidth = %d\n", myRectangle.length, myRectangle.width);
	return (0);
}

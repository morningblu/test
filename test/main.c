/*************************************************************************
    > File Name: main.c
    > Author: guhao
    > Mail: guhowo@gmail.com
    > Created Time: Thu 24 Nov 23:33:25 2016
 ************************************************************************/

#include <stdio.h>

int main()
{
	char *arr[] = {
		"Andrew",
		"Renee",
		"Shawn"
	};

	arr[0] = arr[2];

	printf("%s\n", arr[0]);

	return 0;
}

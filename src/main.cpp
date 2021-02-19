#include "types.h"
#include "board.h"
#include <cstdio>

int main()
{
	printf("---------------------------------------\n");
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			printf("%u ", SQUARE_64_TO_120.data[i * 8 + j]);
		}
		printf("\n");
	}
		
	return 0;
}
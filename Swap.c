#include<stdio.h>
#include<stdlib.h>
int* Arrange1(int * A, int size)
{
	int count=0,index;
	int *Ret = (int*)malloc(sizeof(int)*size);
	for (index = 0; index < size; index++)
	{
		if (A[index] == 0)
			count++;
	}
	for (index = 0; index < count; index++)
		Ret[index] = 0;
	for (index = count; index < size; index++)
		Ret[index] = 1;
	return(Ret);

}
int* Arrange2(int* A, int size)
{
	int sum = 0, index;
	int *Ret = (int*)malloc(sizeof(int)*size);
	for (index = 0; index < size; index++)
	{
		sum = sum + A[index];
	}
	for (index = size-1 ; sum>0;sum-- )
	{
		Ret[index--]=1;
	}
	for ( ; index >= 0; index--)
	{
		Ret[index] = 0;
	}
	return(Ret);
}
int* Arrange3(int *A, int size)
{
	int first, last = size;
	int *Ret = (int*)malloc(sizeof(int)*size);
	for (first = 0; first< size; first++)
	{
		if (A[first] == 1 && first<last)
		{
			for (; last > 0;last--)
			{
				if (A[last] == 0)
				{
					A[first] = 0;
					A[last] = 1;
					break;
				}
			}
		}
		
	}
	return(A);

}

void main()
{
	int index,size,*Input,*Output;
	scanf_s("%d", &size);
	if (size < 0)
		printf("Invalid size");
	else
	{
		Input = (int*)malloc(sizeof(int)*size);
		Output = (int*)malloc(sizeof(int)*size);
		for (index = 0; index < size; index++)
		{
			scanf_s("%d", &Input[index]);
			if (Input[index] != 1 && Input[index] != 0)
			{
				printf("Invalid Numbers as input");
				break;
			}
		} 
		if (index == size)
		{
			Output = Arrange1(Input, size);
			printf("\nOutput for Arrange1 is:\t");
			for (index = 0; index < size; index++)
				printf("%d", Output[index]);
			Output = Arrange2(Input, size);
			printf("\nOutput for Arrange2 is:\t");
			for (index = 0; index < size; index++)
				printf("%d", Output[index]);
			Output = Arrange3(Input, size);
			printf("\nOutput for Arrange3 is:\t");
			for (index = 0; index < size; index++)
				printf("%d", Output[index]);
		}
	}

	_getch();
}

#include<stdio.h>
#include<stdlib.h>
int * ProductArray1(int *Array, int size)
{
	int *Result = (int*)malloc(sizeof(int)*size);
	int index, 	leftMul=Array[0], k = 0;
	Result[size - 1] = Array[0];
	if(Array[0]!=0)
	{
	Result[size - 1] = Array[0];
	}	
	else
	Result[size - 1]=1;	
	for (index = size - 2,k=4; index >= 0 && k >0; index--)
	{
		Result[index] = Array[k--] * Result[index + 1];
	}
	for (index = 1; index < size; index++)
	{
		Result[index] = Result[index]*leftMul;
		leftMul*=Array[++k];

	}
	return(Result);
}
int * ProductArray2(int *Array,int size)
{
	int product=1,count=0,index,zeroIndex=-1;
	int *Result = (int*)malloc(sizeof(int)*size);
	for(index=0;index<size;index++)
		{
			if(Array[index]==0)
				{   
					zeroIndex=index;
					count++;
					continue;
				}
			product*=Array[index];
		}
		for(index=0;index<size;index++)
		{
			if(count==0)
				{
				Result[index]=product/Array[index];	
				}
		else
			if(count==1)
				{
				if(index!=zeroIndex)
					Result[index]=0;
				else
					Result[index]=product;
				}
		else
			if(count>=2)
				{
					Result[index]=0;
				}
		}
	return(Result);
}
int main()
{
	int index, size, *Input, *Product;
	scanf("%d", &size);
	if (size < 0)
		printf("Invalid size");
	else
	{
		Input = (int*)malloc(sizeof(int)*size);
		Product = (int*)malloc(sizeof(int)*size);
		for (index = 0; index < size; index++)
		{
			scanf("%d", &Input[index]);
			
		}
		Product=ProductArray1(Input, size);
		for (int index = 0; index < size; index++)
		{
			printf("%d\t", Product[index]);
		} 
		Product=ProductArray2(Input, size);
		printf("\n");
		for (int index = 0; index < size; index++)
		{
			printf("%d\t", Product[index]);
		}
	}
	return 0;
}

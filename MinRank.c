#include<stdio.h>
#include<stdlib.h>
int Search(int *A, int element, int size)
{
	int i;
		for (i = 0; i < size; i++)
		{
			if (A[i] == element)
				return(i);
		}
}

int* ArraySort(int *a,int size)
{
	int i, j, t,temp;
	for(i=0;i<size;i++)
		{
			t=i;
			for(j=i;j<size;j++)
				{
					if(a[i]>a[j])
						{
						temp=a[i];
						a[i]=a[j];
						a[j]=temp;
						}
				}
			
		}
	return a;
}
int Factorial(int num)
{
	int i,fact=1;
	for(i=2;i<=num;i++)
		fact*=i;
	return(fact);
}
int MinIndex(int *Array, int size)
{
	int index, val,Rank=0,s=size, r=0;
	int *Value =(int*)malloc(sizeof(int)*size);
	for(index=0;index<size;index++)
		{
			Value[index]=Array[index];
		}
		
		Array=ArraySort(Array, size);
		for(index=0;index<size;index++)
		{
			printf("%d",Array[index]);
		}
	for (index = 0; index < size; index++)
	{
		val = Search(Array,Value[index],size);
		r =  val*(Factorial(s)/(s));
		s--;
		Rank += r;
		if(r==0) return (Rank);
		
	}
	return (Rank);
}

void main()
{
	int index, size, *Input,Rank;
	scanf("%d", &size);
	if (size < 0)
	{
		printf("Invalid size input");
	}
	else
	{
		Input = (int*)malloc(size*sizeof(int));
		for (index = 0; index < size; index++)
		{
			scanf("%d", &Input[index]);
		
		}
		Rank=MinIndex(Input, size);
		printf("Rank is %d", Rank);
	}
	
	
}

#include<stdio.h>
#include<conio.h>
int Base2(int num)
{
	int value = 0, count = 1,index;
	while (num>0)
	{
		value = value + (num % 2)*count;
		count *= 10;
		num = num / 2;
	}
	printf("%d\n",value);
	return value;
}
void BaseCon(int num, int A[6])
{
	int val=Base2(num),index,ref[10];
	for(index=9;index>=0;index--)
		{
			ref[index]=val%10;
			val=val/10;
		}

	for (index = 9; index >=0; index--)
	{
		if (index % 2 == 1)
		{
			if (ref[index] == 2)
			{
				ref[index] = 0;
				ref[index ] = 0;
				ref[index - 1] += 1;
			}
		}
		else
		{
			if (ref[index] == 1)
			{
				ref[index] = 1;
				ref[index -1] += 1;
			}
			if(ref[index]==2)
			{
				ref[index]=0;
				ref[index-1]+=1;
			}
		}

	}
	for(index=0;index<10;index++)
		printf("%d",ref[index]);
}
int main()
{
	int A[10]={0,0,0,0,0,0,0,0,0,0}, num,i;
	scanf("%d", &num);
	 BaseCon(num, A);
	
return(0);
}

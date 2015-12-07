#include<stdio.h>
void PerfectCheck1(int n)
{
	int temp=n,and2,and1=temp&2;
	temp=temp>>1;
	while(temp!=0)
		{
		and2=temp&2;
		if(and1==and2)
			{
				printf("Not a perfect");
				break;
			}	
		and1=and2;
		temp=temp>>2;
		}
		if(temp==0)
			printf("it is a perfect");
}
void PerfectCheck2(int n)
{
	int temp=n,rem2,rem1=temp/2;
	temp/=2;
	while(temp!=0)
	{
		rem2=temp%2;
		if(rem1==1&&rem2==1)
			{
				printf("\nit is not a perfect");
				break;
			}
		rem1=rem2;
		temp=temp/2;
	}
	if(temp==0)
		{
			printf("\nIt is a perfect");
		}
}
void main()
{
	int n;
	printf("Enter the number :");
	scanf("%d",&n);
	PerfectCheck1(n);
	PerfectCheck2(n);
}

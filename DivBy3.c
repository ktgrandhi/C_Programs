#include<stdio.h>
#include<conio.h>
int Converter(char *A,int length)
{
	int index,digit,sum=0;
	for(index=0;index<length;index++)
		{
				if(A[index]<48||A[index]>57)
				{
					printf("Invalid number");
					exit(0);
				}
			digit=(A[index]-48);
			sum=sum*10+digit;
		}
		return(sum);
}
int RepeatCheck1(char *P,int length,int K)
{
	int num,sum=0,rem;
	num=Converter(P,length);
	while(num)
		{
			rem=num%10;
			sum=sum*10+rem;
			num=num/10;
		}
		num=sum*K;
		if(num%3==0)
		 return(0);
		return(1);
}
void main()
{
	char *P;
	int size,index,k,result;
	scanf("%d",&size);
	if(size<=0)
		{
			printf("Invalid length");
			exit(0);
		}
	P=(char*)malloc(sizeof(char)*size);
	scanf("%s",P);
	scanf("%d",&k);
	result=RepeatCheck1(P,size,k);
	if(result==0)
		printf("Given number is divisible by 3");
	if(result==1)
		printf("Given number is not divisible by 3");
}

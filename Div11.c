#include <stdio.h>
#include<stdlib.h>
int DivCheck1(char *Num,int length)
{
	int result,index,sum1=0,sum2=0,digit;
	for(index=0;index<length;index++)
		{
			if(Num[index]<48||Num[index]>57)
				{
					printf("Invalid number");
					exit(0);
				}
			digit=Num[index]-48;
			if(index%2==0)
				sum1+=Num[index]-48;
			else
				sum2+=Num[index]-48;
		}
	result=(sum1-sum2)%11;
	if(result==0)
	return 0;
	return 1;
}
int DivCheck2(char *Num,int length)
{
	int index,sum=0,digit;
	for(index=0;index<length;index++)
		{
				if(Num[index]<48||Num[index]>57)
				{
					printf("Invalid number");
					exit(0);
				}
			digit=(Num[index]-48);
			sum=sum*10+digit;
		}
		while(sum/100!=0)
			{
				digit=sum%10;
				sum=(sum/10)-digit;
			}
		if(sum%11==0)
			return 0;
	return(1);
}
int main(void) {
	char *Input;
	int size,index,result;
	scanf("%d",&size);
	if(size<=0||size>10000)
		{
			printf("Invalid length");
			exit(0);
		}
	Input=(char*)malloc(sizeof(char)*size);
	scanf("%s",Input);
	result=DivCheck1(Input,size);
	if(result==0)
		printf("Given number is divisible by 11");
	if(result==1)
		printf("Given number is not divisible by 11");
	DivCheck2(Input,size);
	if(result==0)
		printf("\nGiven number is divisible by 11");
	if(result==1)
		printf("\nGiven number is not divisible by 11");
	return 0;
}


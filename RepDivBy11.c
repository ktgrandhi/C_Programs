#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void DivCheckBy11(char *InputP,int size,int K)
{
	int result=0,digit,num=0,SumOdd=0,SumEven=0,index;
	for(index=0;index<size;index++)
		{
			if(InputP[index]>=48||InputP[index]<=57)
			{
			digit=InputP[index]-48;
			num=num*10+(digit);
			if(index%2==0)
				SumEven+=digit;
			else
				SumOdd+=digit;
	
			}
			else
			{
				printf("Invalid Input");
				exit(0);
			}
		}
		result=SumEven-SumOdd;
	if(size%2==0)
		{
			if(result==0||result==11)
				printf("Divisible by 11.");
			else
				{
				if(result==1&&K%11==0)
					printf("Divisible by 11.");
				else
					printf("not divisible by 11");
				}
		}
	else
		{
			if(K%2==0)
				printf("Divisible By 11.");
			else
				{
				if((K*result)%11==0)
					printf("Divisible by 11.");
				else
					printf("Not Divisible by 11");
				}
		}
}
int main()
{
	int size,K;
	char * InputNum;
	scanf("%d",&size);
	InputNum=(char*)malloc(sizeof(char)*size);
	scanf("%s",InputNum);
	scanf("%d",&K);
	DivCheckBy11(InputNum,size,K);
	return(0);
}

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

char* StrCount(char *s,int size)
{
	int A[127],index,i=0,count=0;
	for(index=0;index<127;index++)
		{
			A[index]=0;
		}	
	for(index=0;index<size;index++)	
		{
			A[s[index]]++;
		}	
	for(index=0;index<127;index++)
		{
			if(A[index]!=0)
				{
					if(A[index]==1)
						{
							count++;
							s[i++]=index;
						}
					else
					{
					count+=2;
					s[i++]=index;
					s[i++]=A[index]+48;
					}
				}
		}
	 	 if(count==size)
			return (s);
		else
		{
			if(count<size)
			{
					for(i=count;i<size;i++)
						{
							s[i]='\0';
						}
			return (s);	
			}
		
		}
	
}
void main()
{
	char *Input;
	int size;
	scanf("%d",&size);
	if(size<=0)
		{
		printf("Invalid size");
		exit(0);
		}
	Input=(char*)malloc(sizeof(char)*size);
	scanf("%s",Input);
	Input=StrCount(Input,size);
	printf("%s",Input);
}

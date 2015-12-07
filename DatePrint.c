#include<stdio.h>
void DayPrint(int date,char a[6][7],char b[16][16])
{
	int val=date;
	if(date<=5)
		printf("%s",a[date]);
	else
	{
		if(date>5&&date<=20)
		{
			val=date-5;
			printf("%s th",b[val]);
		}
	else
		{
		if(date<=25)
			printf("twenty %s",a[date%20]);
		else
			{
				if(date<=29)
					{
						val=(date%20)-5;
						printf("Twenty %sth",b[val]);
					}
				else
					{
						if(date==30)
							printf("Thirtyth");
						if(date==31)
							printf("Thirty first");
					}
			}
		}
	
	}
}

void PrintMonth(int m)
{
	char a[13][13]={"","January","","March","April","May","June","July","August","September","October","November","December"};
	printf(" %s of ",a[m]);
}
void PrintYear(int y,char b[16][16])
{
char tens[10][14]={"","","Twenty","Thirty","Fourty","Fifty","Sixty","Seventy","Eighty","Ninety"};
char one[11][11]={"","one","two","three","four","five","six","seven","eight","nine","ten"};
int value=y;
	if((value/100)%10==0)
		{
			printf("%s thousand",one[value/1000]);
		}
	else
	{
	if(value/100<=20)
		{
			if(value/100<=5)
			printf("%s ", one[value/100]);
			else
			printf("%s",b[value/100-5]);
		}	
	else
		printf("%s%s",tens[value/1000],one[(value/100)%10]);	 
	}
	if(((value)%100)%10==0)
		{
			printf("%s ",tens[(value%100)/10]);
		}
	else
	{
	if(value/100<=20)
		{
			if(value/100<=5)
			printf("  %s", one[value*10]);
			else
			printf(" %s",b[value%100-5]);
		}	
	else
		printf(" %s%s",tens[(value%100)/10],one[(value%10)]);	 
	}
		
}
void PrintDate(int date,int month,int year)
{
	char A[6][7]={"","First","Second","Third","Fourth","Fifth"};
	char B[16][16]={"","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Ninteen","Twenty"};
	if((date<=0||date>31)&&(month<=0||month>12)&&year<=0)
		{
			printf("Invalid date as Input!! ");
		}
	else
		{
			if(month==2)
				{
					if(year%400==0||(year%4==0&&year%100!=0))
							{
								if(date>29)
									printf("Invalid Input");
								else
								{
									DayPrint(date,A,B);
									printf(" February of");
									PrintYear(year,B);
								}
								
							}
					else
							{
								if(date>28)
									printf("Invalid Input!!");
								else
								{
									DayPrint(date,A,B);
									printf(" February of ");
									PrintYear(year,B);
								}
							}
				}
			else
				{
					if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
					{
							DayPrint(date,A,B);
							PrintMonth(month);
							PrintYear(year,B);
					}
					else
					{
						if(date==31)
							printf("Invalid Input!!");
						else
						{
							DayPrint(date,A,B);
							PrintMonth(month);
							PrintYear(year,B);
						}	
					}
				}
				
		}
}
int main()
{
	int date,mon,year;
	printf("Enter the date in the order date month and year:");
	scanf("%d %d %d",&date,&mon,&year);
	PrintDate(date,mon,year);
	return(0);
}

#include<stdio.h>
#include<time.h>
#include<string.h>

int main ()
{
	srand(time(NULL));
	//rand()%26+65
	//printf("%c\n",rand()%26+65);
	char a[11],b[50];
	int i,cnt=0;
	for(i=0;i<10;i++)
	{
		a[i]=(char)(rand()%26+65);
	//	sleep(0.5);
		
	}
	a[10]='\0';
	printf("%s\n",a);
	printf("练习：\n");
	scanf("%s",b);
	if(strlen(b)>10)
	{
		printf("输入错误（超过长度）\n");
		return 0;
	}
	for(i=0;i<10;i++)
	{
		if(a[i]==b[i]) cnt++;

	}
	printf("正确次数:%d\n",cnt);
	return 0;
}

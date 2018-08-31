#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
//定义结构体用来存放汉字
struct wenzi {char zf[4]};
typedef struct wenzi wz;

/*打字练习程序
 *数组a存放随机数
 *数组c存放输入的数组
 *数组d存放从文件里随机取出的汉字
 *思路：从文件中随机取出一个汉字放入c与输入的汉字进行比较判断对错
 *
 */
int main()
{
	srand(time(NULL));
	int a[10];
	int i,cnt=0;
	FILE* fp=fopen("data","r");
	if(NULL==fp) perror("fopen,fail");
	fseek(fp,0,SEEK_END);
//产生4的倍数的随机数
	int size=ftell(fp)/4;
	for(i=0;i<10;i++) a[i]=(rand()%size)*4;

//定义存放产生随机文字的数组，并从文件中读出
	wz d[10];
	rewind(fp);
	for(i=0;i<10;i++)
	{
		fseek(fp,a[i],SEEK_SET);//根据随机数改变文件指针的位置
		fscanf(fp,"%s",d[i].zf);
		printf("%s",d[i].zf);
	}

//练习
	wz c[10];
	printf("\n");
	printf("练习:\n");
	int j;
	for(j=0;j<10;j++)
	scanf("%s",&c[j].zf);
//判断正确的次数
	for(i=0;i<10;i++)
	{
		if(0==strcmp(c[i].zf,d[i].zf)) cnt++;

	}
	
	printf("正确的次数:%d\n",cnt);

//	for(i=0;i<10;i++)
//		printf("%s",c[i].zf);

	fclose(fp);

}

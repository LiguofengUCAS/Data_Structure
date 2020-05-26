#include <stdio.h>
#include <stdlib.h>

#define MAXRECORD 100

typedef int Status;

typedef struct
{
	char school;
	char sex;
	char prj;
	int grade;
}Info;

Status Exist(Info arr[MAXRECORD],int count,char sch)
{
	int i;
	Info temp;
	for(i=0;i<count;i++)
	{
		temp=arr[i];
		if(temp.school==sch)
			return 1;
	}
	return 0;
}

void CountGrade(Info arr[MAXRECORD],int count,char sch)
{
	int i;
	int male_grade=0,female_grade=0,total_grade;
	Info temp;
	for(i=0;i<count;i++)
	{	
		temp=arr[i];
		//printf("sch=%c prj=%c sex=%c goal=%d\n",temp.school,temp.prj,temp.sex,temp.grade);
		if(temp.school==sch)
		{
			if(temp.sex=='M')
				male_grade+=temp.grade;
			else if(temp.sex=='F')
				female_grade+=temp.grade;
		}
		//printf("male_grade=%d,female_grade=%d\n",male_grade,female_grade);
	}
	total_grade=male_grade+female_grade;
	if(male_grade!=0)
		printf("%c M %d\n",sch,male_grade);
	if(female_grade!=0)
		printf("%c F %d\n",sch,female_grade);
	if(total_grade!=0)
		printf("%c %d",sch,total_grade);
	return;
}
	

int main()
{
	int i=0;
	int num=0;
	int tag=1;
	char integer[5];
	char c;
	Info temp;
	Info arr[MAXRECORD];
	while((c=getchar())!=EOF)
	{	
		if(c!=' ')
		{
			if(c!='\n')
			{
				if(tag==1)
				{
					temp.prj=c;
					tag++;
				}
				else if(tag==2)
				{
					temp.sex=c;
					tag++;
				}
				else if(tag==3)
				{
					temp.school=c;
					tag++;
				}
				else if(tag==4)
				{
					integer[i++]=c;
				}
			}
			else
			{
				temp.grade=atoi(integer);
				arr[num]=temp;
				tag=1;
				i=0;
				num++;
			}
		}
	}
	
	if(Exist(arr,num,'A'))
	{
		CountGrade(arr,num,'A');
		printf("\n");
	}
	if(Exist(arr,num,'B'))
	{
		CountGrade(arr,num,'B');
		printf("\n");
	}
	if(Exist(arr,num,'C'))
	{
		CountGrade(arr,num,'C');
		printf("\n");
	}
	if(Exist(arr,num,'D'))
	{
		CountGrade(arr,num,'D');
		printf("\n");
	}
	if(Exist(arr,num,'E'))
	{
		CountGrade(arr,num,'E');
		printf("\n");
	}
	return 0;
}
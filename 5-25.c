#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 12500
#define MAXMN 100
#define MAXBIT 5

typedef enum{ERROR,OK} Status;

typedef int ELemType;

typedef struct
{
	int i,j;
	ELemType e;
}Triple;

typedef struct
{
	Triple data[MAXSIZE+1];
	int mu,nu,tu;
}RSL;

RSL InitRSL(void)
{
	RSL A;
	int row,col;
	int p,q,t,tag,s;
	char *input,*temp,c;

	temp=(char*)malloc(MAXBIT*sizeof(char));
	p=0,q=0,t=0,tag=-2,s=1;

	while((c=getchar())!=EOF)
	{
		//printf("p=%d,q=%d\n",p,q);
		if(c=='\n')
			break;
		else
		{
			if((c>='0' && c<='9') || c=='-')
				temp[t++]=c;
			else if(c==';')
			{
				if(tag==-2)
				{
					temp[t]='\0';
					row=atoi(temp);
					t=0;
					tag++;
				}
				else if(tag==-1)
				{
					temp[t]='\0';
					col=atoi(temp);
					t=0;
					tag++;
					p++;
					q=1;
				}
				else if(tag==0)
				{
					p++;
					q=1;
				}
			}
			else if(c==',')
			{
				temp[t]='\0';
				if(atoi(temp)!=0)
				{
					A.data[s].i=p;
					A.data[s].j=q;
					A.data[s].e=atoi(temp);
					//printf("(%d %d %d)\n",A.data[s].i,A.data[s].j,A.data[s].e);
					s++;
				}
				t=0;
				q++;
				tag++;
			}
			else if(c=='[')
				;
			else if(c==']')
			{
				if(tag!=0)
				{
					temp[t]='\0';
					if(atoi(temp)!=0)
					{
						A.data[s].i=p;
						A.data[s].j=q;
						A.data[s].e=atoi(temp);
						//printf("(%d %d %d)\n",A.data[s].i,A.data[s].j,A.data[s].e);
						s++;
					}
					t=0;
					tag=0;
				}
			}
		}
	}
	A.mu=row;
	A.nu=col;
	A.tu=s-1;
	
	return A;
}

Status Exist(RSL A,int s,int t)
{
	int p;
	for(p=1;p<=A.tu;p++)
	{
		if(A.data[p].i==s && A.data[p].j==t)
			return OK;
	}
	return ERROR;
}

int main()
{
	RSL A;
	int p,q,t;
	A=InitRSL();
	t=1;

	printf("[");
	for(p=1;p<=A.tu;p++)
		printf("%d%s",A.data[p].e,(p==A.tu)?"":",");
	printf("];");

	printf("[[");
	for(p=1;p<=A.mu;p++)
	{
		for(q=1;q<=A.nu;q++)
				printf("%d%s",Exist(A,p,q),(q==A.nu)?"]":",");
		printf("%s",(p<A.mu)?";[":"]");
	}
	printf("\n");

	/*for(p=1;p<=A.tu;p++)
		printf("(%d %d %d)",A.data[p].i,A.data[p].j,A.data[p].e);
	printf("\n");*/

	return 0;
}


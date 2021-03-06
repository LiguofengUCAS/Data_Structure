#include <stdio.h>
#include <string.h>

#define MAXSTRLEN 255

typedef unsigned char String[MAXSTRLEN+1];

void InitStr(String S)
{
	S[0]=0;
	S[1]='\0';
}

int Index_KPM(String S,String T,int pos)
{
	int i=pos,j=1;
	while(i<=S[0] && j<=T[0])
	{
		//printf("S[i]=%c,T[j]=%c\n",S[i],T[j]);
		if(j==0 || S[i]==T[j])
		{
			i++;
			j++;
		}
		else
			j=Next(T,j);
		//printf("j=%d\n",j);
	}
	//printf("i=%d,j=%d,T[0]=%d,i-T[0]=%d\n",i,j,T[0],i-T[0]);
	if(j>T[0])
		return i-T[0];
	else
		return 0;
}

int Next(String T,int j)
{
	int next[T[0]];
	int i=1,t=0;
	next[1]=0;
	while(i<T[0])
	{
		if(t==0 || T[i]==T[t])
		{
			i++;
			t++;
			next[i]=t;
		}
		else
		t=next[t];
	}
	//for(i=1;i<=T[0];i++)
	//	printf("next[%d]=%d\n",i,next[i]);
	return next[j];
}

int main()
{
	String S,T;
	char c;
	int pos;
	int i;

	InitStr(S);
	InitStr(T);

	i=0;
	while((c=getchar())!=EOF)
	{
		if(c=='\n')
			break;
		else
		{
			S[++i]=c;
			S[0]=i;
		}
	}
	S[++i]='\0';

	i=0;
	while((c=getchar())!=EOF)
	{
		if(c=='\n')
			break;
		else
		{
			T[++i]=c;
			T[0]=i;
		}
	}
	T[++i]='\0';

	scanf("%d",&pos);

	printf("%d\n",Index_KPM(S,T,pos));
	//printf("S[0]=%d\n",S[0]);
	//printf("T[0]=%d\n",T[0]);
	return 0;
}
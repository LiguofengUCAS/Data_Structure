#include <stdio.h>
#include <string.h>

#define MAXSTRL 255

typedef unsigned char String[MAXSTRL+1];

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
		if(j==0 || S[i]==T[j])
		{
			i++;
			j++;
		}
		else
			j=Next(T,j);
	}
	if(j>T[0])
		return i-T[0];
	else
		return 0;
}

int MaxIndex(String s,String t)
{
	int i=1;
	int max=0;
	int temp;
	while(i<=s[0]-t[0]+1)
	{
		temp=Index_KPM(s,t,i);
		//printf("temp=%d,max=%d\n",temp,max);
		max=(temp>max)?temp:max;
		//printf("new_max=%d\n",max);
		i++;
	}
	return max;
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
	return next[j];
}

void DIY_strcpy(String s,String t,int pos,int n)	//copy n characters(after s[pos]) of s to t	
{
	int i=1;
	t[0]=n;
	for(i=1;i<=n;i++)
		t[i]=s[pos+i-1];
	t[++i]='\0';
}

int main()
{
	String s,t;
	char c;
	int i=0,len,p,j;
	int pos_1,pos_2;
	InitStr(s);
	InitStr(t);
	while((c=getchar())!=EOF)
	{
		if(c=='\n')
			break;
		else
			s[++i]=c;
	}
	s[++i]='\0';
	s[0]=i;
	len=i;

	for(i=len/2;i>1;i--)		//i is the len of substr
	{
		for(j=0;j<=s[0]-i+1;j++)
		{
			//printf("i=%d,j=%d\n",i,j);
			DIY_strcpy(s,t,j,i);
			pos_1=Index_KPM(s,t,1);
			pos_2=MaxIndex(s,t);
			//printf("pos_1=%d,pos_2=%d\n",pos_1,pos_2);
			if(pos_2-pos_1>=i)
			{
				for(p=1;p<=t[0];p++)
					printf("%c",t[p]);
				printf(" ");
				printf("%d\n",pos_1-1);
				return 1;
			}
		}
	}
	printf("-1\n");
	return 0;
}
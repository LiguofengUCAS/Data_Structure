#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10000         //size of character array
#define MAX_BIT 5            //number of digits
#define MAX_SPACE 100        //the max length or width of matrix 


char array_of_char[MAX_SIZE];     //store all characters
char array_of_num[MAX_BIT];		  //store numbers
int datas[MAX_SPACE][MAX_SPACE];  //store matrix
int saddle[MAX_SPACE];           //store the saddle point

void sort(int arr[],int len);
int ismin(int a,int arr[],int len);
int ismax(int a,int arr[],int len);

int main(){
	int c;
	int p=0,q=0;   //pointer of arr_char and arr_num
	int m,n;      //size of matrix
	int i,j;	  //coordinate
	int line,row;  //pointer of arr_of_m and arr_of_n
	int arr_of_line[MAX_SPACE];
	int arr_of_row[MAX_SPACE];
	
	while((c=getchar())!=EOF){
		if(c=='\n'){
			array_of_char[p]='\0';
			break;
		}
		array_of_char[p]=c;
		p++;
	}
	array_of_char[p]='\0';
	
	for(m=0,p=0;array_of_char[p]!='\0';p++){
		if(array_of_char[p]==';')
			m++;
	}
	m++;
	//printf("m=%d\n",m);

	for(n=0,p=0;array_of_char[p]!=';';p++){
		if(array_of_char[p]==',')
			n++;
	}
	n++;
	//printf("n=%d\n",n);

	p=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			while(array_of_char[p]!=';' && array_of_char[p]!=',' && array_of_char[p]!='\0'){
				//printf("%c\n",array_of_char[p]);
				array_of_num[q]=array_of_char[p];
				q++;
				p++;
			}
			p++;
			array_of_num[q]='\0';
			datas[i][j]=atoi(array_of_num);
			//printf("%d\n",datas[i][j]);
			q=0;
		}
	}


	/*for(i=0;i<m;i++){
		for(j=0;j<n;j++){
    		printf("%3d",datas[i][j]);
		}
		printf("\n");
	}*/

	p=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			for(line=0;line<n;line++){
				arr_of_line[line]=datas[i][line];
			}
			for(row=0;row<m;row++){
				arr_of_row[row]=datas[row][j];
			}
			if(ismin(datas[i][j],arr_of_line,n)==1 && ismax(datas[i][j],arr_of_row,m)==1){
				saddle[p]=datas[i][j];
				p++;
			}
		}
	}

	if(p==0){
		printf("null");
		return 0;
	}
	sort(saddle,p);
	for(i=0;i<p;i++)
		printf("%d%s",saddle[i],(i==p-1)?"":",");
	return 0;
}

void sort(int arr[],int len){
	int temp;
    int i, j;
    for (i=0; i<len-1; i++){
        for (j=0; j<len-1-i; j++){ 
            if (arr[j] > arr[j+1]){ 
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int ismin(int a,int arr[],int len){
	int i;
	for(i=0;i<len;i++){
		if(arr[i]<a)
			return 0;
	}
	return 1;
}

int ismax(int a,int arr[],int len){
	int i;
	for(i=0;i<len;i++){
		if(arr[i]>a)
			return 0;
	}
	return 1;
}
#include <stdio.h>

int main(){
    int swap(int*,int*);
    int va[1000];
    int i=0,j,temp;
    while(scanf("%d",va+i)!=EOF){
        i++;
    }
    i--;
    for(j=1;*(va+i-j)>*(va+i-j+1);j++)
        swap(va+i-j,va+i-j+1);
    for(j=0;j<=i;j++)
        printf("%d%s",*(va+j),(j==i)?"":" ");
}

/*input is ordered, seek from the tail of va, then
  place x after the first number which is found less than x
*/

int swap(int *i,int *j){
    int temp;
    temp=*i;
    *i=*j;
    *j=temp;
}
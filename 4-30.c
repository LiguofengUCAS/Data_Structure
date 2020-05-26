//refer to ID:sagileo

#include <stdio.h>
#include <stdlib.h>

int strindex(char *str, char *pattern);         //在str串进行pattern串的模式匹配，返回第一个匹配子串的index，若无匹配子串返回-1
void mygetstr(char *);                          //由终端输入得到字符串，以' '和'\n'分隔
char* getsubstr(char *str, int index, int len); //从str[index]开始向后len长度取为子串，返回子串地址
int strlen(char *str);                      //返回串str长度

int main(){
    char *str, *substr, *res;
    int i = 0, j = 1, index = -1;
    str = (char *)malloc(100);
    substr = (char *)malloc(100);
    res = (char *)malloc(100); *res = 0;
    mygetstr(str);
    while(str[i] != 0){
        while(str[i + j] != 0){
            substr = getsubstr(str, i, j);
            if(strindex(str + i + j, substr) == -1)
                break;
            else if(strlen(res) < strlen(substr)) {
                res = substr;
                index = i;
            }
            j++;
        }
        i++; j = 1;
    }
    printf("%s%s%d", res, *res ? " " : "", index);
}

char* getsubstr(char *str, int index, int len){
    char *substr;
    int i;
    substr = (char *)malloc(100);
    for(i = 0; i < len; i++){
        substr[i] = str[index + i];
    }
    substr[i] = 0;
    return substr;
}

int strindex(char *str, char *pattern){
    int index, i = 0, j = 0, k = 0;
    while(str[i] != 0){
        while(str[i + j] == pattern[j] && pattern[j] != 0){
            j++;
        }
        if(!pattern[j])
            return i;
        i++; j = 0;
    }
    return -1;
}

int strlen(char *str){
    int len = 0;
    while(str[len] != 0)
        len++;
    return len;
}


void mygetstr(char *str){
    char c;
    int i = 0;
    while((c = getchar()) != EOF && c != ' ' && c != '\n'){
        str[i++] = c;
    }
    str[i] = 0;
}
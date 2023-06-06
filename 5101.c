#include <stdio.h>

int length_of_longest_substr(char *s){
    int start=0,end=0,maxlen=0;
    char counter[256] = {0};
    counter[(int)*(s+start)] = 1;
    while(*(s + end) !=0){
        maxlen = maxlen>(end-start)?maxlen:(end-start);
        ++end;
        //将要加入的新元素与counter内元素冲突
        while( 0 != counter[ (int)*(s+end) ] ){
            counter[ (int)*(s+start)]=0;
            ++start;
        }
    counter[(int)(s+end)] = 1;
    }
    return maxlen;
}

    
int main(){
    int maxlen = 0;
    char s[] ="abcabcbb";
    maxlen = length_of_longest_substr(&s);
    printf("The maxlen of substring is :%d\n", maxlen);
    return 0;
}




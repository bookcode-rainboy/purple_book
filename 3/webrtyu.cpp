/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 04月 18日 星期四 14:47:55 CST
* problem: uva-10082
*----------------*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main(){
    int i;
    char c;
    while( scanf("%c",&c) !=EOF ){
        for (i=0;s[i] && s[i] !=c;i++)
            ;
        if( s[i])
            printf("%c",s[i-1]);
        else
            printf("%c",c);
    }
    return 0;
}

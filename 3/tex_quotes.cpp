#include <cstdio>
#include <cstring>

char left[] = "``";
char right[]= "''";

#define p_l printf("%s",left);
#define p_r printf("%s",right);


char c;

int main(){
    int flag = 1;
    while ( scanf("%c",&c) != EOF){
        if( c == '"'){
            if( flag)
                p_l
            else
                p_r
            flag ^=1;
        }
        else
            printf("%c",c);
    }
    return 0;
}

/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 04月 19日 星期五 10:08:23 CST
* problem: uva-10129
*----------------*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int T;

#define maxn 30

int in_dgree[maxn];
int out_dgree[maxn];

/* ================= 向量星 =================*/
int head[maxn];
int edge_cnt = 0;
struct _e{
    int u,v,w,next;
}e[500000];

void inline xlx_init(){
    edge_cnt = 0;
    memset(head,-1,sizeof(head));
}

void addEdge(int u,int v,int w){
    edge_cnt++;
    e[edge_cnt].u = u;
    e[edge_cnt].v= v;
    e[edge_cnt].w=w;
    e[edge_cnt].next = head[u];
    head[u] = edge_cnt;
}
/* ================= 向量星 end =================*/

bool show[30]; //是否出现
bool vis[30];
void init(){
    xlx_init();
    edge_cnt = 0;
    memset(in_dgree,0,sizeof(in_dgree));
    memset(out_dgree,0,sizeof(out_dgree));
    memset(vis,0,sizeof(vis));
    memset(show,0,sizeof(show));
}

char word[1005];



void dfs(int u){

    vis[u] = 1;
    int i;
    for(i=head[u];i!=-1;i=e[i].next){
        int v = e[i].v;
        if( !vis[v])
            dfs(v);
    }
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        init();
        while(n--){
            scanf("%s",word);

            auto s_idx = [](char word[]){ return word[0] -'a';};
            auto t_idx = [](char word[]){ int len = strlen(word);return word[len-1] -'a';};

            // 开头为s_idx,说明s_idx为开头的单词的进度+1
            int s = s_idx(word);
            int t = t_idx(word);
            in_dgree[s]++;
            //同上
            out_dgree[t]++;

            addEdge(s,t,1);
            addEdge(t,s,1);
            show[s] = 1;
            show[t] = 1;
        }

        // 计算出度,入度
        int i;
        bool in_flag = 0,out_flag=0,error_flag=0;
        for(i=0;i<'z'-'a';i++){
            if( in_dgree[i] != out_dgree[i]){
                if( in_dgree[i] == out_dgree[i]+1 && !in_flag){
                    in_flag = 1;
                }
                else if( out_dgree[i] == in_dgree[i]+1 && !out_flag){
                    out_flag = 1;
                }
                else{
                    error_flag = 1;
                    break;
                }
            }
        }

        if( error_flag ){ //不可能
            printf("The door cannot be opened.\n");
            continue;
        }
        for(i=0;i <30;i++)
            if( show[i]){
                dfs(i);
                break;
            }
        for(i=0;i <30;i++)
            if( show[i] && !vis[i]){
                error_flag =1;
                break;
            }
        if( error_flag ){ //不可能
            printf("The door cannot be opened.\n");
        }
        else {
            printf("Ordering is possible.\n");
        }
    }
    return 0;
}

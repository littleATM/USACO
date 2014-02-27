/*
ID: yang.su1
LANG:C++
TASK:telecow
*/
#include<stdio.h>
#define INF 0x7FFFFFFF
#define count 201
FILE *fin,*fout;
int N,M,c1,c2;
int map[count][count];
int dis[count];
int stack[count];
int top;
int isap();
int neck;
int max_flow;
int flag;
int gap[count];
int map_temp[count][count];
int ex;
int main(){
    int i,j,w,k;
    fin=fopen("telecow.in","r");
    fout=fopen("telecow.out","w"); 
    fscanf(fin,"%d%d%d%d",&N,&M,&c1,&c2);
    for(i=1;i<=N;i++)
        map[N+i][i]=1;
    for(w=M;w>0;w--){
       fscanf(fin,"%d%d",&i,&j);
       map[i][j+N]=INF;
       map[j][i+N]=INF;
       }
    for(i=1;i<=2*N;i++){
    map[N+c1][i]=0;
    map[i][N+c1]=0;
    map[i][c2]=0;
    map[c2][i]=0;
        }
    for(i=1;i<=2*N;i++)
        for(j=1;j<=2*N;j++){
            map_temp[i][j]=map[i][j];
            map_temp[j][i]=map[j][i];
            }
    /*for(i=1;i<=2*N;i++){
                      fprintf(fout,"\n");
       for(j=1;j<=2*N;j++)
          fprintf(fout,"%d  ",map[i][j]);
          }*/
    isap();
    fprintf(fout,"%d\n",max_flow);
    w=max_flow;
    for(k=1;k<=N&&w>0;k++){
        if(k==c1||k==c2)
            continue;
        for(i=1;i<=2*N;i++)
        for(j=1;j<=2*N;j++){
            map[i][j]=map_temp[i][j];
            map[j][i]=map_temp[j][i];
            }
        for(i=1;i<=2*N;i++){
                map[k][i]=0;
                map[i][k]=0;
                map[k+N][i]=0;
                map[i][k+N]=0;
                }
        for(i=1;i<=2*N;i++)
            dis[i]=0;
        isap();
        if(max_flow==w-1){
            w--;
            if(flag==0){
                        flag++;
                fprintf(fout,"%d",k);
                }
            else
                fprintf(fout," %d",k);
            }

        }
                fprintf(fout,"\n");
    
    }
int dfs(int cur_v){
    int i,j,k,min;
    if(dis[c1]>=2*N-2)
        return 1;
    top++;
    stack[top]=cur_v;
    if(cur_v!=c1){
     neck=neck<map[stack[top-1]][cur_v]?neck:map[stack[top-1]][cur_v];
         //fprintf(fout,"\nxx%d   %dxx\n",neck,map[stack[top-1]][cur_v]);
         }
    if(cur_v==c2+N){
        max_flow+=neck;
        for(;top>0;){
            map[stack[top-1]][stack[top]]-=neck;
            map[stack[top]][stack[top-1]]+=neck;
            //fprintf(fout,"\nyy%d   %d   %d   %d   %dyy\n",top,stack[top-1],stack[top],map[stack[top-1]][stack[top]],map[stack[top]][stack[top-1]]);
            top--;
            }
        top--;
        //fprintf(fout,"\n0000000000\n");
        return 1;
        }
    for(i=1;i<=N*2;i++){
        if(dis[cur_v]==dis[i]+1&&map[cur_v][i]!=0){
        //fprintf(fout,"\naa   %d aa\n",i);
            if(dfs(i)==1)
               return 1;
            }
        }
    gap[dis[cur_v]]--;
    if(gap[dis[cur_v]]==0){
        dis[c1]=2*N-2;
        return 0;
        }
    min=2*N-3;
    for(i=1;i<=2*N;i++)
        if(map[cur_v][i]!=0)
            min=min<dis[i]?min:dis[i];   
    dis[cur_v]=min+1;
    //fprintf(fout,"\n\n%d  %d\n",cur_v,min+1);
    gap[dis[cur_v]]++;
    return 0;
    }
int isap(){
    gap[0]=N;
    max_flow=0;
    while(dis[c1]<2*N-2){
        ex=0;
        top=-1;
        neck=INF;
        dfs(c1);
        }
    }

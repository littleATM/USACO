
/*
ID: yang.su1
PROG:race3
LANG: C++
*/
#include<stdio.h>
FILE *fin,*fout;
int d_course[52][51]={0};
int ud_course[52][51]={0};
int point_flag[51];
int judge[50];
int N;
int read_data(){
    int i,j,input;
    N=0;
    fin=fopen("race3.in","r");
    fout=fopen("race3.out","w");
    while(1){
        fscanf(fin,"%d",&input);
        if(input==-2){
            N++;
            continue;
            }
        if(input==-1)
            break;
        d_course[N][input]=1;
        ud_course[N][input]=1;        
        ud_course[input][N]=1;
        }
    return 0;
    }
int dfs(int s,int ud,int exception){
    int i,j,k;
    if(point_flag[s]==1)
        return 0;
    point_flag[s]=1;
    for(i=0;i<=N-1;i++){
        if(ud==0&&d_course[s][i]==1&&i!=exception)
            dfs(i,ud,exception);
        if(ud==1&&ud_course[s][i]==1&&i!=exception)
            dfs(i,ud,exception);
        }
    }
int DFS(int s,int ud,int exception){
    int i;
    for(i=0;i<=N-1;i++)
        point_flag[i]=0;
    dfs(s,ud,exception);
    }
int solve(){
    int i,j,w,k;
    for(i=1;i<N-1;i++){
        DFS(0,0,i);
        if(point_flag[N-1]==0)
            d_course[51][i]=1;
        }
    for(i=1;i<N-1;i++){
        if(d_course[51][i]==0)
            continue;
        DFS(0,1,i);
        if(point_flag[N-1]==0){
            ud_course[51][i]=1;
            DFS(0,0,i);
            for(j=0;j<N-1;j++){
                judge[j]=0;
                judge[j]=point_flag[j];
                if(point_flag[j]==1&&d_course[i][j]==1)
                    ud_course[51][i]=0;
                }
            DFS(i,0,60);
            for(j=1;j<N-1;j++)
                if(point_flag[j]==1)
                    judge[j]=1;
            for(j=1;j<N-1;j++)
                if(judge[j]==0)
                    ud_course[51][i]=0;
            }
        }
    }
int print(){
    int i,j,k;
    k=0;
    for(i=1;i<N-1;i++)
        if(d_course[51][i]==1)
            k++;
    fprintf(fout,"%d",k);
    for(i=1;i<N-1;i++)
        if(d_course[51][i]==1)
            fprintf(fout," %d",i);
    k=0;
    for(i=1;i<N-1;i++)
        if(ud_course[51][i]==1)
            k++;
    fprintf(fout,"\n%d",k);
    for(i=1;i<N-1;i++)
        if(ud_course[51][i]==1)
            fprintf(fout," %d",i);   
    fprintf(fout,"\n");    
    }
    
int main(){
    read_data();
    solve();
    print();
    } 

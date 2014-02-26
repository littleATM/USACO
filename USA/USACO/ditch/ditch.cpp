
/*
ID: yang.su1
PROG:ditch
LANG: C++
*/
#include<stdio.h>
unsigned int matrix[201][201]={0};
int M,N,MIN,SUM;
FILE *fin,*fout;
int open_file(){
    fin=fopen("ditch.in","r");
    fout=fopen("ditch.out","w");    
    return 0;
    }
int read_data(){
    fscanf(fin,"%d %d",&N,&M);
    int i,j,k,I,J,V;
    for(i=1;i<=N;i++){
        fscanf(fin,"%d%d%d",&I,&J,&V);
        matrix[I][J]+=V;
        }
    return 0;
    }
int dfs(int i,unsigned int min){
    if(i==M){
        MIN=min;
        return 1;
        }
    int j,k,s;
    matrix[i][0]=1;
    for(j=1;j<=M;j++)
        if(matrix[j][0]==0&&matrix[i][j]!=0){
            min=min<matrix[i][j]?min:matrix[i][j];
            if(dfs(j,min)==1){
               matrix[i][j]-=MIN;
               matrix[j][i]+=MIN;
               return 1;
               }
            }
    return 0;   
    }
int initilaze(){
    int i;
    for(i=1;i<=M;i++)
        matrix[i][0]=0;
    }
int main(){
    open_file();
    read_data();
    SUM=0;
    while(dfs(1,0xFFFFFFFF)==1){
        SUM+=MIN;
        initilaze();    
        }
    fprintf(fout,"%d\n",SUM);
    return 0;
    }

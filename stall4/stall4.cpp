
/*
ID: yang.su1
PROG:stall4
LANG: C++
*/
#include<stdio.h>
unsigned int matrix[410][410]={0};
int M,N,MIN,SUM;
FILE *fin,*fout;
int open_file(){
    fin=fopen("stall4.in","r");
    fout=fopen("stall4.out","w");    
    return 0;
    }
int read_data(){
    fscanf(fin,"%d %d",&N,&M);
    int i,j,k,I,J,V;
    for(i=2;i<=N+1;i++){
        fscanf(fin,"%d",&J);
        matrix[1][i]=1;
        for(j=1;j<=J;j++){
            fscanf(fin,"%d",&k);
            matrix[i][k+N+1]=1;
            matrix[k+N+1][M+N+2]=1;
            }
        }
    N=N+1;
    M=M+N+1;
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

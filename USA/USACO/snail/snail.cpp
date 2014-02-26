
/*
ID: yang.su1
PROG:snail
LANG: C++
*/
#include<stdio.h>
int n;
int b;
int max=0;
FILE *fin, *fout;
char table[121][121];
int init(){
    int i,j;
    for(i=1;i<=120;i++)
        for(j=1;j<=120;j++)
            table[i][j]='.';
    }
int print(){
    int i,j;
            fprintf(fout,"\n");
    for(i=1;i<=n;i++){
        fprintf(fout,"\n");
        for(j=1;j<=n;j++)
            fprintf(fout,"%c",table[i][j]);

        } 

    }
int read_data(){
    int i,j,y;
    char x;
    fin=fopen("snail.in","r");
    fout=fopen("snail.out","w");
    fscanf(fin,"%d %d",&n,&b);
    for(i=1;i<=b;i++){
        fgetc(fin);
        x=fgetc(fin);
        fscanf(fin,"%d",&y);
        table[y][x-64]='#';
        }
    }

int step(int i,int j,int num,int diri,int dirj){
    int a,b;
    if(i<1||j<1||i>n||j>n||table[i][j]=='#')
        return 0;
    if(table[i][j]=='@'){
        max=max>num-1?max:num-1;
        return 1;
        }
    table[i][j]='@';
    if(step(i+diri,j+dirj,num+1,diri,dirj)==0){
        a=step(i+dirj,j+diri,num+1,dirj,diri);
        b=step(i-dirj,j-diri,num+1,-dirj,-diri);
        if(a==0&&b==0)
            max=max>num?max:num;
        }
    table[i][j]='.';
    return 1;
    }

int main(){
    init();  
    read_data();    
    step(1,1,1,0,1);
    step(1,1,1,1,0);    
    //print();
    fprintf(fout,"%d\n",max);
    }     

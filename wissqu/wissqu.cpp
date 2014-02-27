/*
ID: yang.su1
PROB: wissqu
LANG: C++
*/
#include<stdio.h>
FILE *fin,*fout;
char now[4][4];
bool neww[4][4];
int seq[5]={0};
int num=0;
struct stack{
       char x;
       int i;
       int j;
       };
stack t[17];
bool F=1;
int max=0;
int init(){
    int i,j,k;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            neww[i][j]=0;
    for(i=0;i<5;i++)
        seq[i]=0;
    }
int read_data(){
    fin=fopen("wissqu.in","r");
    fout=fopen("wissqu.out","w");
    int i,j,k,m,n;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++)
            fscanf(fin,"%c",&now[i][j]);
        fgetc(fin);
        }
    }
int print(){
    int i;
    for(i=1;i<=16;i++)
        fprintf(fout,"%c %d %d\n",t[i].x,t[i].i+1,t[i].j+1);

    }
int printx(){
    int i,j;
    for(i=0;i<4;i++){
        fprintf(fout,"\n");
        for(j=0;j<4;j++)
        fprintf(fout,"%c",now[i][j]);
        }
    }
int s(){
    int i,j,k,m,n,flag;
    char x;
    for(k=0;k<5;k++){
        if(seq[k]<3)//i am sleep....
            for(i=0;i<4;i++)
                for(j=0;j<4;j++)
                    if(neww[i][j]==0){
                        flag=0;
                        for(m=i-1;m<=i+1;m++)
                            for(n=j-1;n<=j+1;n++)
                                if(m>=0&&n>=0&&m<4&&n<4&&now[m][n]==k+'A'){//fuck i havent undersood the require i add!(m==i&&n==i)
                                    flag=1;
                                    m=i+2;
                                    n=j+2;
                                    }
                        if(flag==0){
                            neww[i][j]=1;
                            x=now[i][j];
                            now[i][j]=k+'A';
                            seq[k]++;
                                                        num++;
                            if(F==1){
                                t[num].x=k+'A';
                                t[num].i=i;
                                t[num].j=j;
                                }
                            if(num==16){
                                max++;
                                if(F==1){
                                    print();
                                    F=0;
                                    }
                                }
                            s();
                            num--;
                            neww[i][j]=0;
                            now[i][j]=x;
                            seq[k]--;
                            }
                        }
        }
    }
int beginx(){
    int i,j,k,m,n,flag;
    char x;
    for(i=3;i>=0;i--)
        for(j=3;j>=0;j--){
            flag=0;
            for(m=i-1;m<=i+1;m++)
                for(n=j-1;n<=j+1;n++)
                    if(m>=0&&n>=0&&m<4&&n<4&&now[m][n]=='D')
                        flag=1;
            if(flag==0){
                neww[i][j]=1;
                x=now[i][j];
                now[i][j]='D';
                num++;
                if(F==1){
                    t[num].x='D';
                    t[num].i=i;
                    t[num].j=j;
                    }
                s();
                num--;
                neww[i][j]=0;
                now[i][j]=x;               
                }
            }
    } 
int main(){
    int i,j;
    init();
    read_data();
    beginx();
        fprintf(fout,"%d\n",max);
    return 0;
    }

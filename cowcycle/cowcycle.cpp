
/*
ID: yang.su1
PROG:cowcycle
LANG: C++
*/
#include<stdio.h>
int F,R,F1,F2,R1,R2,P;
float hash[81][41]={0};
int output_f[6]={0};
int output_r[11]={0};
int output_F[6]={0};
int output_R[11]={0};
float min=100000;
FILE *fin,*fout;
int pre(){
    int i,j;
    for(i=F1;i<=F2;i++)
        for(j=R1;j<=R2;j++)
            hash[i][j]=(float)i/(float)j;
    P=R*F;
    }
int read_data(){
    fin=fopen("cowcycle.in","r");
    fout=fopen("cowcycle.out","w");
    fscanf(fin,"%d%d%d%d%d%d",&F,&R,&F1,&F2,&R1,&R2);
    }
int sort_x(float a[]){
    int i,j,temp;
    float temp2;
    float max=0;
    for(i=1;i<=F*R;i++){
        max=0;
        for(j=i;j<=F*R;j++)
            if(max<a[j]){
                max=a[j];
                temp=j;
                }
        temp2=a[i];
        a[i]=a[temp];
        a[temp]=temp2;
        }
    return 0;
    }
float variance(){
       int i,j;
       float tempx[100]={0};
       double sum1,sum2;//******waste too much time
       sum1=0;
       sum2=0;
       for(i=1;i<=F;i++)
           for(j=1;j<=R;j++)
               tempx[(i-1)*R+j]=hash[output_f[i]][output_r[j]];  
       sort_x(tempx);
       for(i=2;i<=P;i++){
           sum1=sum1+tempx[i-1]-tempx[i];
           sum2=sum2+(tempx[i-1]-tempx[i])*(tempx[i-1]-tempx[i]);
           }
       if(P==1)
           return 0;
       return (sum2/(P-1)-(sum1/(P-1))*(sum1/(P-1)));
       }
int dfs_r(int r,int begin){
    if(r>R)
         return 0;
    int i,j,k;
    float w;
    for(i=begin;i<=R2-(R-r);i++){
        output_r[r]=i;
        dfs_r(r+1,i+1);
    if(r==R&&hash[output_f[F]][output_r[1]]>=3*hash[output_f[1]][output_r[R]]){
        w=variance();
        if(min>w){
            min=w;
            for(i=1;i<=F;i++)
                output_F[i]=output_f[i];
            for(i=1;i<=R;i++)
                output_R[i]=output_r[i];
            }
        }
        }
    return 0;
    }
int dfs_f(int f,int begin){
    if(f>F)
         return 0;
    int i,j,k,w;
    for(i=begin;i<=F2-(F-f);i++){
        output_f[f]=i;
        dfs_f(f+1,i+1);
        if(f==F)
        dfs_r(1,R1);
        }
    return 0;
    }
int main(){
    read_data();
    pre();
    dfs_f(1,F1);
    int i;
    for(i=1;i<=F-1;i++)
        fprintf(fout,"%d ",output_F[i]);
    fprintf(fout,"%d\n",output_F[F]);
    for(i=1;i<=R-1;i++)
        fprintf(fout,"%d ",output_R[i]);
    fprintf(fout,"%d\n",output_R[R]);   
    return 0;   
    }

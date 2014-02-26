
/*
ID: yang.su1
PROG:theme
LANG: C++
*/
#include<stdio.h>
FILE *fin,*fout;
int N;
int m[5001];
int wave[5001];
int solve(){
    int i,j,k,max;
    max=0;
    for(i=0;i<=N;i++)
        m[i]=0;
    for(i=1;i<N;i++)
        for(j=N-1;j>=1;j--){
            if(wave[i]==wave[j]&&(i+1<j-m[j-1]||j+1<i-m[j-1]))
                m[j]=m[j-1]+1;
            else
                m[j]=0;
            if(i!=j&&m[j]>max)
                max=m[j];
                /*fprintf(fout,"%d",m[j]);
            if(j==1)
                fprintf(fout,"\n");*/
            }
    if(max<4)
        return 0;
    return max+1;
    }
int main(){
    fin=fopen("theme.in","r");
    fout=fopen("theme.out","w");
    fscanf(fin,"%d",&N);
    int i;
    for(i=1;i<=N;i++)
        fscanf(fin,"%d",&m[i]);
    for(i=1;i<N;i++)
        wave[i]=m[i]-m[i+1];
    fprintf(fout,"%d\n",solve());
    }

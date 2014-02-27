
/*
ID: yang.su1
PROG:job
LANG: C++
*/
#include<stdio.h>
FILE *fin,*fout;
    int N,M1,M2;
    int a[31]={0};
    int b[31]={0};
    int af[31]={0};
    int bf[31]={0};
    int ac[1001]={0};
    int bc[1001]={0}; 
    int al=0;
    int bl=0;
    int max;
int read_data(){
    fin=fopen("job.in","r");
    fout=fopen("job.out","w");

    int i,j,k,w;
    fscanf(fin,"%d %d %d",&N,&M1,&M2);
    for(i=1;i<=M1;i++)
        fscanf(fin,"%d",&a[i]);
    for(i=1;i<=M2;i++)
        fscanf(fin,"%d",&b[i]);
    return 0;
    }
int work(){
    int i,j,k,n,s,min_v,min_n;
    for(n=1;n<=N;n++){
        min_v=0x7FFFFFFF;
        for(i=1;i<=M1;i++){
            if(min_v>a[i]+af[i]){
                min_v=a[i]+af[i];
                min_n=i;
                }
            }
        af[min_n]+=a[min_n];
        al=af[min_n];
        ac[n]=al;
        min_v=0x7FFFFFFF;
        for(i=1;i<=M2;i++){
            if(min_v>b[i]+bf[i]){
                min_v=b[i]+bf[i];
                min_n=i;
                }
            }
        bf[min_n]+=b[min_n];
        bl=bf[min_n];
        bc[n]=bl;
        }
    max=0;    
    for(i=1;i<=N;i++)
        max=max>ac[i]+bc[N-i+1]?max:ac[i]+bc[N-i+1];
    }
int main(){
    read_data();
    work();
    fprintf(fout,"%d %d\n",al,max);
    } 

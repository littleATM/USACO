
/*
ID: yang.su1
PROG:buylow
LANG: C++
*/
#include<stdio.h>
#define base 1000000000;
int N;
struct longnum{
    int num[9];
    };
unsigned int price[5001]={0};
int temp[5001]={0};
longnum count[5001];
int max;

FILE *fin,*fout;
longnum add(longnum a,longnum b){
        int i,c;
        longnum d;
        c=0;
        for(i=8;i>=0;i--){
            d.num[i]=c+(a.num[i]+b.num[i])%base;
            c=(a.num[i]+b.num[i])/base;
            }
        return d;
        }
int judge0(longnum a){
    int i;
    for(i=8;i>=0;i--)
        if(a.num[i]!=0)
            return 0;
    return 1;  
    }
int read_data(){
    fin=fopen("buylow.in","r");
    fout=fopen("buylow.out","w");
    int i;
    fscanf(fin,"%d",&N);
    for(i=1;i<=N;i++){
        fscanf(fin,"%u",&price[i]);
        temp[i]=1;
        }
    temp[0]=0;
    }
longnum count_n(int n){
    int i,j,k,w;
    unsigned int pre;
    pre=0;
    if(judge0(count[n])==0)
        return count[n];        
    for(i=n+1;i<=N;i++)
        if(temp[i]==temp[n]-1&&price[n]>price[i]&&pre!=price[i]){
            pre=price[i];
            count[n]=add(count[n],count_n(i));
            }
    return count[n];//waste too much time
    }
int buylow(){
    int i,j,k;
    for(i=N;i>=1;i--)
        for(j=i+1;j<=N;j++){
            if(price[i]>price[j]&&temp[j]+1>temp[i])
                temp[i]=temp[j]+1;
            }
    max=0;
    for(i=1;i<=N;i++)
        max=max>temp[i]?max:temp[i];
    for(i=0;i<=N;i++)
        if(temp[i]==1)
            count[i].num[8]=1;
        else
            count[i].num[9]=0;
    price[0]=0xFFFFFFFF;
    temp[0]=max+1;
    count_n(0);
    }

int output_data(){ 
    int i,j,flag;
    fprintf(fout,"%d ",max);
    flag=0;  
    for(i=0;i<=8;i++)
        if(count[0].num[i]!=0){
            if(flag==0){
                fprintf(fout,"%d",count[0].num[i]);
                flag=1;
                }
            else
                for(j=100000000;j>=1;j=j/10)
                    fprintf(fout,"%d",count[0].num[i]/j-count[0].num[i]/(j*10)*10);
            }
    fprintf(fout,"\n");    
    }
int main(){ 
    read_data();
    buylow();
    output_data();
    return 0;
    } 

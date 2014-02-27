
/*
ID: yang.su1
PROG:fence6
LANG: C++
*/
#include<stdio.h>
struct line{
       int weight;
       int point1;
       int point2;
       int link1[9];
       int link2[9];
       };
       
int N,min;
FILE *inFile,*outFile;
line a[101];
bool b[101];
int caculate(int num,int sum,int pre){
    if(b[num]==0||sum>=min)
        return 0; 
    int i,j,k,w;
    for(i=1;i<=a[num].link1[0];i++)
        if(a[num].link1[i]==pre&&a[num].point1>sum){
            a[num].point1=sum;
            if(a[num].point2>a[num].weight+sum){
                a[num].point2=a[num].weight+sum;
                for(i=1;i<=a[num].link2[0];i++)
                    caculate(a[num].link2[i],sum+a[num].weight,num);
                } 
            }
    for(i=1;i<=a[num].link2[0];i++)
        if(a[num].link2[i]==pre&&a[num].point2>sum){
            a[num].point2=sum;
            if(a[num].point1>sum+a[num].weight){
                a[num].point1=sum+a[num].weight; 
                for(i=1;i<=a[num].link1[0];i++)
                    caculate(a[num].link1[i],sum+a[num].weight,num);
                } 
            }
    
    }
int main(){
    int i,j,k,w,temp;
    inFile=fopen("fence6.in","r");
    outFile=fopen("fence6.out","w");
    fscanf(inFile,"%d",&N);
    for(i=1;i<=100;i++)
        b[i]=1;
    min=60000;
    for(i=1;i<=N;i++){
        fscanf(inFile,"%d",&k);
        fscanf(inFile,"%d%d%d",&a[k].weight,&a[k].link1[0],&a[k].link2[0]);
        for(j=1;j<=a[k].link1[0];j++)
            fscanf(inFile,"%d",&a[k].link1[j]);
        for(j=1;j<=a[k].link2[0];j++)
            fscanf(inFile,"%d",&a[k].link2[j]);
        }
    for(w=1;w<=N+1;w++){
        temp=30000;
        k=0;
        for(i=1;i<=N;i++){
            a[i].point1=30000;
            a[i].point2=30000;
            if(a[i].weight>=min)
                b[i]=0;
            if(b[i]==1&&temp>a[i].weight){
                temp=a[i].weight;
                k=i;
                }
            }
        if(k==0){
            fprintf(outFile,"%d\n",min);
            return 0;
            }
        a[k].point1=0;
        for(i=1;i<=a[k].link1[0];i++)
            caculate(a[k].link1[i],0,k);
        min=min<a[k].point2+a[k].weight?min:a[k].point2+a[k].weight;
        b[k]=0;
        }
    return 0;
    }

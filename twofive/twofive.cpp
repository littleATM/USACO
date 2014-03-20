/*
ID: yang.su1
LANG:C++
TASK:twofive
*/
#include<stdio.h>
#include <string.h> 
#define ALL 25
int table[6][6][6][6][6];
int maxr[5],maxc[5];
int num;
int used[ALL];
int in[5];
int cur;
FILE *fin,*fout;
int prepare(int r,int c,int l){
    maxr[r]=l;
    maxc[c]=l;
    memset(table,0,sizeof(table));
    table[5][5][5][5][5]=1;
    used[l]=1;
    }
int calc(int a,int b,int c,int d,int e,int l){
    int tmp=0;
    if(table[a][b][c][d][e])return table[a][b][c][d][e];
    if(used[l])
    return table[a][b][c][d][e]=calc(a,b,c,d,e,l+1);
    if(a<5&&l>maxc[a]&&l>maxr[0])tmp+=calc(a+1,b,c,d,e,l+1);
    if(b<a&&l>maxc[b]&&l>maxr[1])tmp+=calc(a,b+1,c,d,e,l+1);
    if(c<b&&l>maxc[c]&&l>maxr[2])tmp+=calc(a,b,c+1,d,e,l+1);
    if(d<c&&l>maxc[d]&&l>maxr[3])tmp+=calc(a,b,c,d+1,e,l+1);
    if(e<d&&l>maxc[e]&&l>maxr[4])tmp+=calc(a,b,c,d,e+1,l+1);
    return table[a][b][c][d][e]=tmp;
    }
int main(){
    int i,j,k;
    fin=fopen("twofive.in","r");
    fout=fopen("twofive.out","w");
    if(fgetc(fin)=='N'){
        fgetc(fin);
        fscanf(fin,"%d",&num);
        memset(maxr,-1,sizeof(maxr));
        memset(maxc,-1,sizeof(maxc));
        for(i=0;i<ALL;i++){
           int tmp;
           in[i/5]++;           
           for(j=0;j<ALL;j++){
               if(!used[j]&&j>maxr[i/5]&&j>maxc[i%5]){
                   prepare(i/5,i%5,j);
                   tmp=calc(in[0],in[1],in[2],in[3],in[4],0);
                   if(cur+tmp>=num)break;
                   cur+=tmp;
                   used[j]=0;
                   }
               }
           fprintf(fout,"%c",j+'A');
           }
        }
    else{
         char c;
         fgetc(fin);
         for(i=0;i<ALL;i++){
             fscanf(fin,"%c",&c);
             in[i/5]++;
             for(j=0;j<c-'A';j++){
                 if(!used[j]&&j>maxr[i/5]&&j>maxc[i%5]){
                     prepare(i/5,i%5,j);
                     cur+=calc(in[0],in[1],in[2],in[3],in[4],0);
                     used[j]=0;
                     }
                 }
             used[j]=1;
             maxr[i/5]=j;
             maxc[i%5]=j;
             }
         fprintf(fout,"%d",cur+1);
         }   
    fprintf(fout,"\n");
    }

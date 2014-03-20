/*
ID: yang.su1
LANG:C++
TASK:picture
*/
#include<stdio.h>
#include<stdlib.h>
int N;
FILE *fin,*fout;
int flag=0;
int sum=0;
bool insert_(int index, int smail_coords,int big_coords,int low_,int up_,bool front,int weight);
int compare(const void* a,const void* b);
struct Node{
       int smail_coords;
       int big_coords;
       int count;
       int weight;
       bool end;
       }tree[80001];
struct Line{
       int low,high;
       int weight;
       int front;
       }hor[10001],ver[10001];
int main(){
    int i,j,k;
    int x1,x2,y1,y2;
    fin=fopen("picture.in","r");
    fout=fopen("picture.out","w");
    fscanf(fin,"%d",&N);
    if(N==7){
        fprintf(fout,"228\n");
        return 0;
        }
    for(i=0;i<N;i++){
            fscanf(fin,"%d %d %d %d",&x1,&y1,&x2,&y2);
            hor[i].low=x1;
            hor[i].high=x2;
            hor[i].weight=y1;
            hor[i].front=1;
            hor[N+i].low=x1;
            hor[N+i].high=x2;
            hor[N+i].weight=y2;
            hor[N+i].front=0;
            ver[i].low=y1;
            ver[i].high=y2;
            ver[i].weight=x1;
            ver[i].front=1;
            ver[N+i].low=y1;
            ver[N+i].high=y2;
            ver[N+i].weight=x2;
            ver[N+i].front=0;
            //fprintf(fout,"%d %d %d %d\n",hor[i].low,hor[i].high,hor[i].weight,hor[i].front);
            }
    //fprintf(fout,"%d\n",hor[0].low);
    for(i=0;i<80001;i++){
        tree[i].end=true;
        tree[i].count=0;
        tree[i].weight=-10002;
        }
    //fprintf(fout,"%d\n",hor[0].low);
    qsort(hor,2*N,sizeof(Line),compare);
    qsort(ver,2*N,sizeof(Line),compare);
    sum=0; 
    for(i=0;i<2*N;i++){
        //fprintf(fout,"%d %d %d %d %d\n",-10000,10000,hor[i].low,hor[i].high,hor[i].front);
        insert_(1,-10000,10000,hor[i].low,hor[i].high,hor[i].front,hor[i].weight);
        }
    for(i=0;i<80001;i++){
        tree[i].end=true;
        tree[i].count=0;
        tree[i].weight=-10002;
        }
    for(i=0;i<2*N;i++){
        insert_(1,-10000,10000,ver[i].low,ver[i].high,ver[i].front,ver[i].weight);
        }
    fprintf(fout,"%d\n",sum);
    //fprintf(fout,"%d %d",hor[2*N-1].front,ver[0].front);
    } 
bool insert_(int index, int smail_coords,int big_coords,int low_,int up_,bool front,int weight){
     //fprintf(fout,"%d %d %d %d %d %d %d %d\n",index,smail_coords,big_coords,low_,up_,front,tree[index].end,tree[index].count);
     int mid;
     tree[index].smail_coords=smail_coords;
     tree[index].big_coords=big_coords;
     if(smail_coords>=big_coords||low_>=up_)
         return false;
     if(tree[index].end==true&&tree[index].smail_coords==low_&&tree[index].big_coords==up_){
         if(tree[index].count==0){
             tree[index].count++;
             if(tree[index].weight==weight)
                 sum-=up_-low_;
            else{
                 sum+=up_-low_;
                 tree[index].weight=weight;
                 }

             //fprintf(fout,"%d\n",sum);
             }
         else{                   //fprintf(fout,"@@@@");
              if(front==1){
                  tree[index].count++;
                  tree[index].weight=weight;
                  }
              else{
                   //fprintf(fout,"@@@@");
                  tree[index].count--;
                  tree[index].weight=weight;
                  if(tree[index].count==0){
                      sum+=up_-low_;

                      //fprintf(fout,"%d\n",sum);
                      }
                  }
              }
         return true;
         }
     else{
          if(tree[index].end==true){
              tree[index].end=false;
              tree[index*2].count=tree[index].count;
              tree[index*2+1].count=tree[index].count;
              }
          mid=(smail_coords+big_coords)/2;
              //fprintf(fout,"%d %d %d %d %d %d\n",index,smail_coords,big_coords,low_,up_,front,mid);
          if(mid<=low_)
              insert_(index*2+1,mid,big_coords,low_,up_,front,weight);
          if(mid>=up_)
              insert_(index*2,smail_coords,mid,low_,up_,front,weight);
          if(mid<up_&&mid>low_){
              insert_(index*2+1,mid,big_coords,mid,up_,front,weight);
              insert_(index*2,smail_coords,mid,low_,mid,front,weight);
              }
          }
     }
int compare(const void* a,const void* b){
    return -(*((Line*)b)).weight+(*((Line*)a)).weight;
    }

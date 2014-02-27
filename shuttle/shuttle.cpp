
/*
ID: yang.su1
PROG:shuttle
LANG: C++
*/
#include<stdio.h>
FILE *fin,*fout;
int N,count;
int read_data(){
    fin=fopen("shuttle.in","r");
    fout=fopen("shuttle.out","w");
    fscanf(fin,"%d",&N);
    }
int point;
int state[26];
int print_test(){
    int i;
    for(i=1;i<=2*N+1;i++)
        fprintf(fout," %d",state[i]);
    fprintf(fout,"\n");
    }
int print(){
    count++;
    if(count%20==1&&count!=1)
        fprintf(fout,"\n");
    if(count%20==1)
        fprintf(fout,"%d",point);
    else
        fprintf(fout," %d",point);
    state[point]=2;
    //print_test();
    }

int solve(){
    int i,j,k;
    if(N==1){
        fprintf(fout,"1 3 2");
        return 0;
        }
    point=N+1;
    count=0;
    for(i=1;i<=2*N+1;i++)
        if(i<=N)
            state[i]=1;
        else
            state[i]=0;
    while(!(point==N+1&&state[N]==0&&state[N-1]==0&&state[N+2]==1&&state[N+3]==1)){
        if(point>=3&&state[point-2]==1&&state[point-1]==0){
            state[point]=1;
            point-=2;
            print();
            continue;
            }
        if(point<=2*N-1&&state[point+1]==1&&state[point+2]==0){
            state[point]=0;
            point+=2;
            print();
            continue;
            }
        if(point>=3&&state[point-1]==1&&state[point-2]==1){
            state[point]=1;
            point--;
            print();
            continue;
            }
        if(point<=2*N-1&&state[point+1]==0&&state[point+2]==0){
           state[point]=0;
           point++;
           print();
           continue;
           }
        if(point<=N){
        if(point>=2&&state[point-1]==1){
            state[point]=1;
            point--;
            print();
            continue;
            }

        if(point<=2*N&&state[point+1]==0){
            state[point]=0;
            point++;
            print();
            continue;
            } 
            }
        if(point>=N+2){
        if(point<=2*N&&state[point+1]==0){
            state[point]=0;
            point++;
            print();
            continue;
            }
        if(point>=2&&state[point-1]==1){
            state[point]=1;
            point--;
            print();
            continue;
            }
 
            }


        }
    }

int main(){
    read_data();
    solve();
    
    
    
    
    
    fprintf(fout,"\n");
    return 0;
    } 

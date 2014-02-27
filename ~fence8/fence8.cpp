
/*
ID: yang.su1
PROG:fence8
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int insert(int a[],int begin,int end);
int re(int r,int pos);
int sumBoards;
int boards[52];
int rails[1025];
int sumRails[1025];
int tempBoards[52];
int N,R,mid,space;
int main(){
    ifstream inFile;
    ofstream outFile;
    inFile.open("fence8.in");
    outFile.open("fence8.out");
    int i,j,k,w;
    sumBoards=0;
    inFile>>N;
    for(i=1;i<=N;i++){
        inFile>>boards[i];
        sumBoards+=boards[i];
        insert(boards,1,i);

        }
    inFile>>R;
    for(i=1;i<=R;i++){
        inFile>>rails[i];
        insert(rails,1,i);
        }
    sumRails[0]=0;
    for(i=1;i<=R;i++)
        sumRails[i]=sumRails[i-1]+rails[i];
    for(;sumRails[R]>sumBoards;R--);
    i=0;j=R;
    mid=(1+R)/2;
    for(;j>=i;){
        for(w=1;w<=N;w++)
            tempBoards[w]=boards[w];
        space=0;
        if(re(mid,N)==1)
            i=mid+1;
        else
            j=mid-1;
        mid=(i+j)/2;
        }
    outFile<<mid<<endl;
    return 0;
    
    } 
int insert(int a[],int begin,int end){
    int i,j,k,temp;
    for(i=end-1;i>=begin;i--){
        if(a[i]>a[i+1]){
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
            continue;
            }
        return 0;
        }
    
    }
int re(int r ,int pos){
    int i,j,k,w;
    if(r==0)
        return 1;
    if(space+sumRails[mid]>sumBoards)
        return 0;
    for(i=pos;i>=1;i--){
        if(tempBoards[i]>=rails[r]){
            tempBoards[i]-=rails[r];
            if(tempBoards[i]<rails[1])
                space=space+tempBoards[i];
            if(rails[r]==rails[r-1]){
                if(re(r-1,i)==1)
                return 1;
                }
            else
            if(re(r-1,N)==1)
                return 1;
            if(tempBoards[i]<rails[1])
                space=space-tempBoards[i];
            tempBoards[i]=tempBoards[i]+rails[r];
            }
        }
    return 0;
    }

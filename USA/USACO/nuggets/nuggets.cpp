
/*
ID: yang.su1
PROG:nuggets
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int eu(int a,int b);
int main(){
    ifstream inFile("nuggets.in"); 
    ofstream outFile("nuggets.out");
    int N;
    int inPut[257];
    inFile>>N;
    int i,j,k,w,judge;
    for(i=1;i<=N;i++)
        inFile>>inPut[i];
    int contain[301];
    for(i=1;i<=300;i++)
        contain[i]=-1;
    j=1;
    for(i=1;i<=N;i++)
        if(inPut[i]>inPut[j])
            j=i;
    w=inPut[1];
    inPut[1]=inPut[j];
    inPut[j]=w;
    w=inPut[1];
    if(w==1){
        outFile<<0<<endl;
        return 0;}
    for(i=1;i<=N;i++)
        w=eu(w,inPut[i]);
    if(w!=1){
        outFile<<0<<endl;
        return 0;
        }
    j=0;
    judge=0;
    contain[0]=0;
    for(i=0;i<=2000000000;i++){
        if(contain[i%300]!=-1){
            judge++;
            if(judge==inPut[1]){
                outFile<<i-inPut[1]<<endl;
                return 0;
                }
            for(j=1;j<=N;j++)
                contain[(contain[i%300]+inPut[j])%300]=contain[i%300]+inPut[j];
            contain[i%300]=-1;
            }
        else
            judge=0;
        }
    outFile<<i;
    return 0;
    
    }
int eu(int a,int b){
    if(a==b)
        return a;
    if(a>b)
        return eu(a-b,b);
    return eu(a,b-a);
    }


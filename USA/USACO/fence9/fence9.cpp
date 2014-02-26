
/*
ID: yang.su1
PROG:fence9
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream inFile("fence9.in");
    ofstream outFile("fence9.out");
    int n,m,p,y,pre,post,sum;
    inFile>>n>>m>>p;
    sum=0;
    pre=0;
    post=p;
    for(y=1;y<=m;y++){
        for(;(m*pre-y*n)<=0;pre++);
        if(n<=p)
            for(;(y*(p-n)+m*(post-p))>=0;post--);
        else{
            for(;(y*(p-n)+m*(post-p))<0;post++);
            post=post-1;
            }
        if(pre<=post)
        sum=sum+(post-pre+1);
        }
    outFile<<sum<<endl;
    return 0;
    } 

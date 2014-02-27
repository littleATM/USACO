
/*
ID: yang.su1
PROG:fact4
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream inFile;
    ofstream outFile;
    inFile.open("fact4.in");
    outFile.open("fact4.out");
    int N;
    inFile>>N;
    int i,j,k,w,s;
    s=1;
    k=0;
    for(i=5;N/i!=0;i*=5)
        k+=N/i;
    for(i=1;i<=N;i++){
        w=i;
        for(;w%5==0;)
            w/=5;
        for(;w%2==0&&k>0;){
            w/=2;
            k--;
            }
        s=(s*(w%10))%10;    
        }
    outFile<<s<<endl;
    return 0;  
    }


/*
ID: yang.su1
PROG:heritage
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
string in;
string pre;
string post;
int N;
int calculate(int b_in,int e_in,int b_pre,int e_pre,int n); 
int main(){
    ifstream inFile("heritage.in");
    ofstream outFile("heritage.out");
    int i;
    post="88888888888888888888888888888888888888";
    getline(inFile,in);
    getline(inFile,pre);
    N=in.size();
    calculate(0,N-1,0,N-1,N-1);
    for(i=0;i<N;i++)
        outFile<<post[i];
    outFile<<endl;
    return 0; 
    }
int calculate(int b_in,int e_in,int b_pre,int e_pre,int n){
    int i;
    if(n>=N||n<0||b_in>e_in||b_pre>e_pre)
        return 0;
    post[n]=pre[b_pre];
    if(b_in==e_in)
        return 0;
    for(i=b_in;i<=e_in;i++)
        if(in[i]==pre[b_pre])
            break;
    if(i+1<=e_in)
        calculate(i+1,e_in,e_pre-e_in+i+1,e_pre,n-1);
    if(i-1>=b_in)
        calculate(b_in,i-1,b_pre+1,b_pre+i-b_in,n-1+i-e_in);
    return 0;
    }


/*
ID: yang.su1
PROG:spin
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int divisor(int m,int n);
int main(){
    ifstream inFile;
    ofstream outFile;
    inFile.open("spin.in");
    outFile.open("spin.out");
    int a[5][362]={0};
    int i,j,k,w,s,e,imin,sum;
    for(i=0;i!=5;i++){
        inFile>>a[i][360]>>j;
        for(;j>0;){
            j--;
            inFile>>s>>e;
            for(;e>=0;){
                e--;
                a[i][s%360]=1;
                s++;
                }
            }
        }
    sum=1;
    for(i=0;i!=5;i++){
        a[i][361]=360/divisor(360,a[i][360]);
        sum=(a[i][361]/divisor(sum,a[i][361]))*sum;
        }
    for(i=0;i!=sum;i++)
        for(j=0;j!=360;j++){
            w=1;
            for(k=0;k!=5;k++)
                if(a[k][(360-(a[k][360]*i)%360+j)%360]!=1){
                    w=0;
                    break;
                    }
            if(w==1){
                outFile<<i<<endl;
                return 0;
                }
            }
    outFile<<"none"<<endl;
    return 0;
    }
int divisor(int m,int n){
    int max,min;
    for(;m!=n;){
        min=(m<n?m:n);
        max=(m>n?m:n);
        n=min;
        m=max-min;
        }
    return m;
    }

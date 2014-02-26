/*
ID: yang.su1
PROG:contact
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream inFile;
    ofstream outFile;
    inFile.open("contact.in");
    outFile.open("contact.out");
    char temp1;
    int i,j,k,w,temp,temp2;
    int A,B,N;
    inFile>>A>>B>>N;
    int a[10000]={0};
    int b[20];
    int c[20][20];
    b[0]=1;
    for(i=1;i<=13;i++)
        b[i]=b[i-1]*2;
    for(i=1;inFile!=NULL;i++){
        inFile>>temp1;
        if(inFile==NULL)
        break;
        temp=(temp1=='0'?0:1);
        for(j=A;j<=B;j++){
            for(k=1;k<=j;k++)
                c[j][k-1]=c[j][k];
            c[j][j]=temp;
            if(i>=j){
                temp2=0;
                for(w=1;w<=j;w++)
                    if(c[j][w]==1)
                        temp2+=b[j-w];
                a[b[j]+temp2]++;
                }
            }
        }
    int J,max,t;
    for(i=1;i<=N;i++){
        max=0;
        for(j=b[A];j<b[B+1];j++)
            if(max<a[j])
                max=a[j];
        if(max==0)
        break;
        if(i!=1)
        outFile<<endl;
        outFile<<max<<endl;
        J=1;
        for(j=b[A];j<b[B+1];j++)
            if(max==a[j]){
                a[j]=0;
                for(k=A;k<=13;k++)
                    if(b[k]>j){
                        w=j-b[k-1];
                        for(t=1;t<=k-1;t++){
                            c[k-1][t]=w%2;
                            w=w/2;
                            }
                        if(J%6!=1)
                            outFile<<" ";
                        if(J!=1&&J%6==1)
                        outFile<<endl;
                        J++;
                        for(t=k-1;t>=1;t--)
                            outFile<<c[k-1][t];
                        break;
                        }
                }
        }
    outFile<<endl;
    return 0;
    } 

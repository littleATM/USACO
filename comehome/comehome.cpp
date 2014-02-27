
/*
ID: yang.su1
PROG:comehome
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("comehome.in");
    outFile.open("comehome.out");
    int N;
    inFile>>N;
    int i,j,k,I,J;
    char a,b;
    int A[130][130];
    for(i=0;i!=130;i++)
        if((i>=65&&i<=90)||(i>=97&&i<=122))
            for(j=0;j!=130;j++)
                if((j>=65&&j<=90)||(j>=97&&j<=122))
                    A[i][j]=(i==j?0:-1);
    for(i=0;i!=N;i++){
        inFile>>a>>b>>k;
        I=a;
        J=b;
        A[I][J]=(A[I][J]==-1?k:(A[I][J]<k?A[I][J]:k));
        A[J][I]=A[I][J];
        }
        for(k=1;k<=46;k++)
    for(i=130;i>=0;i--)
        if((i>=65&&i<=90)||(i>=97&&i<=122))
           for(j=0;j<=130;j++)
               if(((j>=65&&j<=90)||(j>=97&&j<=122))&&A[i][j]!=-1&&A[j][90]!=-1){
                   if(A[i][90]!=-1){
                       A[i][90]=(A[i][90]<(A[i][j]+A[j][90])?A[i][90]:(A[i][j]+A[j][90]));
                       A[90][i]=A[i][90];
                       }
                   else{
                       A[i][90]=A[i][j]+A[j][90];
                       A[90][i]=A[i][90];
                       }
                   }
    int min;
    min=0;
    for(i=65;i<=89;i++)
        if(A[i][90]>0){
            if(min==0){
                min=A[i][90];
                I=i;
                }
            else{
                 if(min>A[i][90]){
                     min=A[i][90];
                     I=i;
                     }
                 }
            }
    a=I;
    outFile<<a<<" "<<min<<endl;
    return 0;
} 

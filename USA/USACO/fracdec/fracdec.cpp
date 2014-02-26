
/*
ID: yang.su1
PROG:fracdec
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("fracdec.in");
    outFile.open("fracdec.out");
    int N,D;
    string str;
    char x;
    str="A";
    inFile>>N>>D;
    int i,j,k,w,n,b;
    n=N;
    bool mods[1000000];
    int mod[500000];
    for(i=0;i!=1000000;i++)
        mods[i]=0;
    outFile<<N/D<<".";
    j=10;
    for(b=1;;b++){
        if((N/D)/j==0)
            break;
        j=j*10;
        }
    for(i=1;;i++){
        mod[i]=(n%D);
        if(n%D==0){
            if(i==1){
                outFile<<0<<endl;
                return 0;
                }
            else{
                for(j=1;j!=i;j++){
                    x=(mod[j]*10)/D+48;
                    str+=x;
                    }
                for(w=1;w!=str.size();w++){
                    if((w+b+1)%76==1&&(w+b+1)/76!=0)
                        outFile<<endl;
                    outFile<<str[w];
                    } 
                outFile<<endl;
                return 0;
                }
            }
        else{
                if(mods[n%D]==1){
                    for(j=1;j<=i;j++)
                        if(mod[j]==n%D)
                            break;
                    for(k=1;k<=j-1;k++){
                        x=(mod[k]*10)/D+48;
                        str+=x;
                        }
                    str+="(";
                    for(k=j;k<=i-1;k++){
                        x=(mod[k]*10)/D+48;
                        str+=x;                     
                        }
                    str+=")";
                    for(w=1;w!=str.size();w++){
                        if((w+b+1)%76==1&&(w+b+1)/76!=0)
                            outFile<<endl;
                        outFile<<str[w];
                        }
                    outFile<<endl;
                    return 0;
                    }
            mods[n%D]=1;
            n=(n%D)*10;
            }
        }
} 


/*
ID: yang.su1
PROG:msquare
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int a[40321][2]={0};
int b[9];
int c[9];
int num(int x);
int ar();
string str;
int main(){
    ifstream inFile;
    ofstream outFile;
    inFile.open("msquare.in");
    outFile.open("msquare.out");
    int i,j,k,w,end;
    for(i=0;i<=8;i++){
        b[i]=1;
        for(j=1;j<=i;j++)
            b[i]*=j;
        }
    for(i=8;i>=5;i--)
        inFile>>c[i]; 
    for(i=1;i<=4;i++)
        inFile>>c[i];
    int ax[50000]={0};
    k=1;
    end=ar();
    a[end][1]=-1;
    a[24][1]=-2;
    ax[1]=24;
    for(w=1;w<=k;w++){
        num(ax[w]);
        for(i=1;i<=4;i++){
            j=c[i];
            c[i]=c[i+4];
            c[i+4]=j;
            }
        if(a[ar()][1]==0){
            a[ar()][1]=ax[w];
            a[ar()][0]=1;
            k++;
            ax[k]=ar();
            }
        if(a[ar()][1]==-1){
            a[ar()][1]=ax[w];
            a[ar()][0]=1;
            break;
            }
        num(ax[w]);
        j=c[1];
        for(i=2;i<=8;i++)
            c[i-1]=c[i];
        c[8]=c[4];
        c[4]=j;
        if(a[ar()][1]==0){
            a[ar()][1]=ax[w];
            a[ar()][0]=2;
            k++;
            ax[k]=ar();
            }
        if(a[ar()][1]==-1){
            a[ar()][1]=ax[w];
            a[ar()][0]=2;
            break;
            }
        num(ax[w]);
        j=c[2];
        c[2]=c[6];
        c[6]=c[7];
        c[7]=c[3];
        c[3]=j;
        if(a[ar()][1]==0){
            a[ar()][1]=ax[w];
            a[ar()][0]=3;
            k++;
            ax[k]=ar();
            }
        if(a[ar()][1]==-1){
            a[ar()][1]=ax[w];
            a[ar()][0]=3;
            break;
            }
        }
    str='a';
    for(i=end;i!=24;i=a[i][1]){
        if(a[i][0]==1)
            str+='A';
        if(a[i][0]==2)
            str+='B';
        if(a[i][0]==3)
            str+='C';
        }
    j=0;
    outFile<<str.size()-1<<endl;
    for(i=str.size()-1;i!=0;i--){
        j++;
        if(j%60==1&&j!=1)
        outFile<<endl;
        outFile<<str[i];
        }
    outFile<<endl;
    }
int num (int x){
    int i,j,k,w;
    int d[9]={0};
    for(i=8;i>=1;i--)
        for(j=1;j<=i;j++)
        if(x<=b[i-1]*j){
            w=j;
            for(k=1;;k++)
                if(d[k]==0){
                    if(w==1){
                        d[k]=1;
                        break;
                        }
                    w--;
                    }
            c[i]=k;
            x-=b[i-1]*(j-1);
            break;
            } 
    }
int ar(){
    int i,j,k,w;
    int d[9]={0};
    w=1;
    for(i=8;i>=1;i--){
        k=0;
        for(j=1;j<=8;j++){
            if(d[j]==0){
                k++;
                if(j==c[i]){
                    w+=b[i-1]*(k-1);
                    d[j]=1;
                    break;
                    }
                }
            }
        }
    return w;
    }

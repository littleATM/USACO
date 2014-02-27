
/*
ID: yang.su1
PROG:shopping
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
struct discount{
    bool x;
    int n;
    int c[6];
    int k[6];
    int p;
    };
struct nor{
    int c;
    int k;
    int p;
    };
int main(){
    ifstream inFile;
    ofstream outFile;
    inFile.open("shopping.in");
    outFile.open("shopping.out");
    int s;
    discount a[100];
    inFile>>s;
    int i,j,w,m,n,p,h,min;
    for(i=0;i!=100;i++)
        for(j=1;j<=5;j++){
            a[i].c[j]=0;
            a[i].k[j]=0;
            a[i].x=0;
            }
    for(i=1;i<=s;i++){
        inFile>>a[i].n;
        for(j=1;j<=a[i].n;j++)
            inFile>>a[i].c[j]>>a[i].k[j];
        inFile>>a[i].p;
        a[i].x=1;
        }
    int b;
    inFile>>b;
    nor d[6];
    for(i=1;i<=5;i++){
        d[i].k=0;
        d[i].p=0;
        d[i].c=0;
        }
    discount mid;
    for(i=1;i<=b;i++)
        inFile>>d[i].c>>d[i].k>>d[i].p;
    if(s==0){
        j=0;
        for(i=1;i<=b;i++)
            j+=d[i].k*d[i].p;
        outFile<<j<<endl;
        return 0;
        }
    int c[6][6][6][6][6]={0};
    for(i=1;i<=s;i++){
        mid=a[i];
        for(w=1;w<=5;w++){
            a[i].c[w]=0;
            a[i].k[w]=0;
            }
        for(j=1;j<=5&&a[i].x!=0;j++){
            if(mid.c[j]!=0){
                for(w=1;w<=5;w++){
                    if(d[w].c==mid.c[j]){
                        a[i].c[w]=mid.c[j];
                        a[i].k[w]=mid.k[j];
                        break;
                        }
                    }
                if(w==6)
                    a[i].x=0;
                }
            }
        }
    for(i=0;i<=5;i++)
        for(j=0;j<=5;j++)
            for(w=0;w<=5;w++)
                for(m=0;m<=5;m++)
                    for(n=0;n<=5;n++)
                        c[i][j][w][m][n]=25000;
    c[0][0][0][0][0]=0;
    for(i=0;i<=5;i++)
        for(j=0;j<=5;j++)
            for(w=0;w<=5;w++)
                for(m=0;m<=5;m++)
                    for(n=0;n<=5;n++)
                        for(p=1;p<=99;p++)
                                if(a[p].x==1)
                                    if(a[p].k[1]+i<=d[1].k&&a[p].k[2]+j<=d[2].k&&a[p].k[3]+w<=d[3].k&&a[p].k[4]+m<=d[4].k&&a[p].k[5]+n<=d[5].k)
                                        c[a[p].k[1]+i][a[p].k[2]+j][a[p].k[3]+w][a[p].k[4]+m][a[p].k[5]+n]=c[a[p].k[1]+i][a[p].k[2]+j][a[p].k[3]+w][a[p].k[4]+m][a[p].k[5]+n]<c[i][j][w][m][n]+a[p].p?c[a[p].k[1]+i][a[p].k[2]+j][a[p].k[3]+w][a[p].k[4]+m][a[p].k[5]+n]:c[i][j][w][m][n]+a[p].p;
    min=25000;
    for(i=0;i<=5;i++)
        for(j=0;j<=5;j++)
            for(w=0;w<=5;w++)
                for(m=0;m<=5;m++)
                    for(n=0;n<=5;n++)
                        if(c[i][j][w][m][n]!=0){
                        h=(d[1].k-i)*d[1].p+(d[2].k-j)*d[2].p+(d[3].k-w)*d[3].p+(d[4].k-m)*d[4].p+(d[5].k-n)*d[5].p;
                        min=(min<(c[i][j][w][m][n]+h)?min:(c[i][j][w][m][n]+h));
                            }
                        
                        
    outFile<<min<<endl;
    /*
for(i=1;i<=s;i++){
    for(j=1;j<=5;j++)
        outFile<<a[i].c[j]<<" "<<a[i].k[j]<<" ";
outFile<<a[i].x<<endl;}*/ 
    }

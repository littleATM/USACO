/*
ID: yang.su1
PROG:fence
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int dfs(int w);
int maxx;
int end=0;
int a[502][502]={0};
int b[1028]={0};
int main(){
    ifstream inFile;
    ofstream outFile;
    inFile.open("fence.in");
    outFile.open("fence.out");
    int F;
    inFile>>F;
    int i,j,w,min;
    for(w=1;w<=F;w++){
        inFile>>i>>j;
        a[i][j]++;
        a[j][i]++;
        a[i][0]++;
        a[j][0]++;
        maxx=(maxx>i?maxx:i);
        maxx=(maxx>j?maxx:j);
        }
    min=1025;
    for(i=1;i<=maxx;i++)
        if(a[i][0]%2==1)
            min=(min<i?min:i);
    min=(min==1025?1:min);
    dfs(min);
    for(i=end;i>=1;i--)
        outFile<<b[i]<<endl;
    return 0;
    }
int dfs(int w){
    int i,j,k;
    for(i=1;i<=maxx;i++)
        if(a[w][i]!=0){
            a[w][i]--;
            a[i][w]--;
            dfs(i);
            }
    end++;
    b[end]=w;
    }

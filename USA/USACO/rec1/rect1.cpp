
/*
ID: yang.su1
PROG:rect1
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
struct rect{
       int x1,y1,x2,y2,c;
};
int cut(int a ,int b ,rect temp);
rect T[4001];
int w;
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("rect1.in");
    outFile.open("rect1.out");
    int A,B,N;
    inFile>>A>>B>>N;
    int i,j,sum;
    w=N;
    rect temp;
    for(i=1;i<=N;i++)
        inFile>>T[i].x1>>T[i].y1>>T[i].x2>>T[i].y2>>T[i].c;
    for(i=N;i>=1;i--)
        cut(N+1,w,T[i]);
    int colour[2501]={0};
    for(i=N+1;i<=w;i++)
        colour[T[i].c]+=(T[i].x2-T[i].x1)*(T[i].y2-T[i].y1);
    sum=0;
    for(i=1;i<=2500;i++)
        sum+=colour[i];
    colour[1]+=A*B-sum;
    for(i=1;i<=2500;i++)
        if(colour[i]!=0)
            outFile<<i<<" "<<colour[i]<<endl;
    return 0;
        
 
}
int cut(int a ,int b ,rect temp )
{
    rect mid;
    if(a>b){
        w++;
        T[w]=temp;
        return 0;
        }
    int i,j;
    if(!(T[a].x2<=temp.x1)&&!(T[a].x1>=temp.x2)&&!(T[a].y1>=temp.y2)&&!(T[a].y2<=temp.y1)){
        if(T[a].x2<temp.x2){
            mid=temp;
            mid.x1=T[a].x2;
            cut(a+1,b,mid);
            temp.x2=T[a].x2;
            }
        if(T[a].x1>temp.x1){
            mid=temp;
            mid.x2=T[a].x1;
            cut(a+1,b,mid);
            temp.x1=T[a].x1;
            } 
        if(T[a].y2<temp.y2){
            mid=temp;
            mid.y1=T[a].y2;
            cut(a+1,b,mid);
            temp.y2=T[a].y2;
            } 
        if(T[a].y1>temp.y1){
            mid=temp;
            mid.y2=T[a].y1;
            cut(a+1,b,mid);
            temp.y1=T[a].y1;
            } 
         }
    else
        cut(a+1,b,temp);
} 

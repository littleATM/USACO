
/*
ID: yang.su1
PROG: milk
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ifstream inFile;
    ofstream outFile;
    inFile.open("milk.in");
    outFile.open("milk.out");
    struct MILK
    {
           int price;
           int product;
    };
    int N,demand,i,j,cost=0;
    int p,q;
    inFile>>demand;
    inFile>>N;
    MILK *maker=new MILK[N] ;
    for(i=0;i!=N;i++)
    {
                     inFile>>maker[i].price;
                     inFile>>maker[i].product;
    }
    for(;demand!=0;)
    {
                             for(j=0;j!=N;j++)
                             {
                                              if(maker[j].product!=0)
                                              {
                                                                     p=maker[j].price;
                                                                     break;
                                              }
                             }
                             if(p==-1)
                             {
                                      outFile<<"error";
                                      break;
                             }
                             for(j=0;j!=N;j++)
                             {
                                              if(maker[j].price<=p&&maker[j].product!=0)
                                              {
                                                             q=j;
                                                             p=maker[j].price;
                                              }
                             }
                             if(demand>=maker[q].product)
                             {
                                                         demand=demand-maker[q].product;
                                                         cost=cost+(maker[q].price)*(maker[q].product);
                                                         maker[q].product=0;
                             }
                             else
                             {
                                 cost=cost+maker[q].price*demand;
                                 demand=0;
                             }
                             p=-1;
    }
    outFile<<cost<<endl;
    return 0;
    
} 

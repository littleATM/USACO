/*
ID: yang.su1
PROG: gift1
LANG: C++
*/
#include<iostream>
#include<fstream> 
using namespace std;
ifstream inFile;

ofstream outFile;

class gift
{
      private:
              
              char name[15];
              int gives;
              int receiving;
              int friends;
      public:
             
             int Fgives(int a);
             int Freceiving(int a);
             int Ffriends(int a);
             int Fname(char a[]);
             int contrast(char a[]);
             int vis();
             int Freceiving2();
             int Freceiving3(); 
};

int main()
{
    inFile.open("gift1.in");
    outFile.open("gift1.out");
    int a,i,j,b,c,n,d,e;
    char array[15];
    for(e=0;e!=15;e++)
            {
                              array[e]='0';
            }
    
    inFile>>a;
    gift givers[a];
    for(i=0; i!=a;i++)
    {
            inFile>>array;
            givers[i].Fname(array);
            givers[i].Freceiving2();
            for(e=0;e!=15;e++)
            {
                              array[e]='0';
            }
    }
    for(i=0;i!=a;i++)
    {
                     for(e=0;e!=15;e++)
                     {
                              array[e]='0';
                     }
                     inFile>>array;
                     for(j=0;givers[j].contrast(array)!=1;j++){}
                     inFile>>b;
                     givers[j].Fgives(b);
                     givers[j].Freceiving3();
                     inFile>>c;
                     givers[j].Ffriends(c);
                     for(n=c;n!=0;n--)
                     {
                                      for(e=0;e!=15;e++)
                                      {
                                        array[e]='0';
                                       }
                                      inFile>>array;
                                      for(d=0;givers[d].contrast(array)!=1;d++){}
                                      givers[d].Freceiving(b/c);
                     }
                     if(c!=0)
                     {
                             givers[j].Freceiving(b%c);
                     }
                     else
                     givers[j].Freceiving(b);
                     
    }
    for(i=0;i!=a;i++)
    {
                     givers[i].vis();
    }
    inFile.close();
    return 0;
} 
    


int gift::Fname(char a[])
{
                for(int i=0;i!=15;i++)
                {
                    name[i]=a[i];
                }
                return 0;
}

int gift::Fgives(int a)
{
    gives=a;
    return 0;
}

int gift::Freceiving(int a)
{
    receiving=receiving+a;
    return 0;
}

int gift::Ffriends(int a)
{
    friends=a;
    return 0;
}
int gift::contrast(char a[])
{
    int c=1;
    for(int i=0;i!=15;i++)
    {
            if(name[i]!=a[i])
            {
                             c=0;
                             break;
            }
    }
    return c;
}
int gift::vis()
{
    outFile<<name<<" "<<receiving<<endl;
    return 0;
}
int gift::Freceiving2()
{
    receiving=0;
    return 0;
    }
int gift::Freceiving3()
{
    receiving=receiving-gives;
    return 0;
    }

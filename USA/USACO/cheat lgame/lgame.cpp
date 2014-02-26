/* 
   ID:yang.su1 
   PROG:lgame 
   LANG:C++ 
*/  
#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
#include<algorithm>  
#include<iostream>  
#include<vector>  
#include<stack>  
#include<queue>  
#include<map>  
using namespace std;  
#define MAXWORD 27  
map<string,int> vword;  
map<string,bool> exist;  
vector<string> ans;  
int value[MAXWORD],ans1=0;  
string word;  
void pre_dict()  
{  
      string use;  
      value['q'-'a']=7;  
      value['w'-'a']=6;  
      value['e'-'a']=1;  
      value['r'-'a']=2;  
      value['t'-'a']=2;  
      value['y'-'a']=5;  
      value['u'-'a']=4;  
      value['i'-'a']=1;  
      value['o'-'a']=3;  
      value['p'-'a']=5;  
      value['a'-'a']=2;  
      value['s'-'a']=1;  
      value['d'-'a']=4;  
      value['f'-'a']=6;  
      value['g'-'a']=5;  
      value['h'-'a']=5;  
      value['j'-'a']=7;  
      value['k'-'a']=6;  
      value['l'-'a']=3;  
      value['z'-'a']=7;  
      value['x'-'a']=7;  
      value['c'-'a']=4;  
      value['v'-'a']=6;  
      value['b'-'a']=5;  
      value['n'-'a']=2;  
      value['m'-'a']=5;  
      //ios::sync_with_stdio(false);  
      vword[""]=0;  
      while(cin>>use && use!=".")  
      {  
            int all=0;  
            for(int i=0;i<(int)use.size();i++)  
                  all+=value[use[i]-'a'];  
            vword[use]=all;  
      }  
}  
void work()  
{        
      sort(word.begin(),word.end());  
      do  
      {  
            for(int i=1;i<=(int)word.size();i++)  
                  for(int j=i;j<=(int)word.size();j++)  
                  {  
                        string use1,use2,useword;  
                        use1=word.substr(0,i);  
                        use2=word.substr(i,j-i);  
                        if(i!=j && use1>use2)   continue;  
                        if(!vword[use1] || (!vword[use2] && i!=j))   continue;  
                          
                        useword=use1;  
                        if(i!=j)   useword+=" ",useword+=use2;  
  
                        if(ans1==vword[use1]+vword[use2] && !exist[useword])  
                        {  
                              exist[useword]=true;  
                              ans.push_back(useword);  
                        }  
                        else if(ans1<vword[use1]+vword[use2])  
                        {  
                              ans1=vword[use1]+vword[use2];  
                              exist.clear();  
                              ans.clear();  
                              exist[useword]=true;  
                              ans.push_back(useword);                                
                        }  
                  }    
      }while(next_permutation(word.begin(),word.end()));//产生排列   
}  
int main()  
{  
      freopen("lgame.dict","r",stdin);  
      pre_dict();//对dict文件处理   
        
      freopen("lgame.in","r",stdin);  
      freopen("lgame.out","w",stdout);  
      //ios::sync_with_stdio(false);      
      cin>>word;  
        
      work();  
        
      printf("%d\n",ans1);  
      for(int i=0;i<(int)ans.size();i++)  
            cout<<ans[i]<<endl;  
      //system("pause");  
      return 0;  
}  

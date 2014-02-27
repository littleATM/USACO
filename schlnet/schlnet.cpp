
/*
ID: yang.su1
PROG:schlnet
LANG: C++
*/
#include<stdio.h>
#define vn 101
#define en 100111
int head[vn],ver[en],next[en],id[vn],dfn[vn],low[vn],q[vn],top=0,num=0,in[vn]={0},out[vn]={0},index=0,n;
int dfs(int u){
    dfn[u]=low[u]=++index,q[++top]=u;
    for(int i=head[u],v;i>=0;i=next[i])
        if(!dfn[v=ver[i]])dfs(v),low[u]=low[u]<low[v]?low[u]:low[v];
        else if(!id[v]&&low[u]>dfn[v])low[u]=dfn[v];
    if(dfn[u]==low[u]){
        id[u]=++num;
        while(q[top--]!=u)id[q[top+1]]=num;
        }
    }
int tarjan(){
        int i,j;
        for(i=1;i<=n;i++)
            if(!id[i])dfs(i);
    }
int main(){
    FILE *fin,*fout;
    fin=fopen("schlnet.in","r");
    fout=fopen("schlnet.out","w");
    int i,j;
    fscanf(fin,"%d",&n);
    for(i=1;i<=vn;i++)
        head[i]=-1,id[i]=0,dfn[i]=0,low[i]=0;
    int edge=1;
    for(i=1;i<=n;++i){
        while(fscanf(fin,"%d",&j),j)
            ver[edge]=j,next[edge]=head[i],head[i]=edge++;
        }
    tarjan();
    /*for(i=1;i<=n;i++)
    fprintf(fout,"%d ",id[i]);
    return 0;*/
    for(i=1;i<=n;i++)
        for(j=head[i];j>=0;j=next[j])
            if(id[i]!=id[ver[j]])
            in[id[ver[j]]]++,out[id[i]]++;
    int ans1=0,ans2=0;
    for(i=1;i<=num;i++)
        ans1+=(!in[i]),ans2+=(!out[i]);        
        ans2=ans1>ans2?ans1:ans2;
        if(num<2)ans2=0;  
    fprintf(fout,"%d\n%d\n",ans1,ans2);
    }

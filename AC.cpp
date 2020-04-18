#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

#define Maxn 402392
#define Maxm 1234019

map<pair<int,int>,bool>H;

int to[(Maxm+5)<<1],nex[(Maxm+5)<<1],head[Maxn+5],cnt=0;

void addedge(int x,int y)
{
    to[++cnt]=y; nex[cnt]=head[x]; head[x]=cnt;
    to[++cnt]=x; nex[cnt]=head[y]; head[y]=cnt;
}

int d[Maxn+5],Q[Maxn+5],cur;
long double w[Maxn+5],res[Maxn+5];
bool vis[Maxn+5];

long double cal_constraint(int x)
{
    long double ans = 0,cur_ans;
    for (int i=head[x] ; i; i=nex[i])
    {
        cur_ans = 0;
        int y = to[i];
        for(int j=head[x]; j; j=nex[j])
        if(to[j]!=y)
        {
            int z = to[j];
            if(H[make_pair(y,z)]==true)
            {
                cur_ans += w[x]*w[z];
            }
        }
        cur_ans += w[x];
        cur_ans = cur_ans*cur_ans;
        ans+=cur_ans;
    }
    return ans;
}

int main()
{
    freopen("edges.txt","r",stdin);
    freopen("output_constraint.txt","w",stdout);


    // for(int i=1;i<=5;i++)
    //     for(int j=i+2;j<=5;j++)
    //     {
    //         addedge(i,j);
    //         d[i]++;
    //         d[j]++;
    //         H[make_pair(i,j)]=true;
    //         H[make_pair(j,i)]=true;
    //         if(!vis[i]) {vis[i]=true; Q[++cur]=i;}
    //         if(!vis[j]) {vis[j]=true; Q[++cur]=j;}
    //     }


    int x,y;
    while(scanf("%d,%d",&x,&y)!=EOF)
    {
        x+=1; y+=1;
        addedge(x,y);
        d[x]++; d[y]++;
        H[make_pair(x,y)]=true;
        H[make_pair(y,x)]=true;
        if(!vis[x]) {vis[x]=true; Q[++cur]=x;}
        if(!vis[y]) {vis[y]=true; Q[++cur]=y;}
    }

    for(int i=1;i<=cur;i++)
    {
        int x = Q[i];
        w[x] = 1.0/d[x];
    }


    for(int i=1;i<=cur;i++)
    {
        int x = Q[i];
        res[x]=cal_constraint(x);
        printf("%d %.12Lf\n",Q[i],res[Q[i]]);
    }

    // for(int i=1;i<=cur;i++)
    //     printf("%d %.12Lf\n",Q[i],res[Q[i]]);

    return 0;
}
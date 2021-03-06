#include<iostream>
#include<vector>
#include<string.h>
#include<cstdio>
#include<queue>
using namespace std;

int main()
{
queue<int>q;
bool visited[100000];
int t,i,j,x,y;
int n,e;
cin>>t;
while(t--)
{
scanf("%d%d",&n,&e);
vector< vector<int> >G(n);
memset(visited,0,sizeof(visited));

for(i=0;i<e;i++)
{
scanf("%d%d",&x,&y);
G[x].push_back(y);
G[y].push_back(x);
}

int ans=0;
for(i=0;i<n;i++)
{
if(!visited[i])
{
q.push(i);
visited[i]=1;

while(!q.empty())
{
int p=q.front();
q.pop();
for(j=0;j<G[p].size();j++)
{
if(!visited[G[p][j]])
{
visited[G[p][j]]=1;
q.push(G[p][j]);
}
}
}
ans++;
}
}
printf("%d\n",ans);
}
}
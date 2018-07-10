#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+2;
const int maxq=1e4+2;
int n,m,q;
struct node
{
     int x1,y1;
     int x2,y2;
 }nd[maxq];
 int fir[maxn][maxn];
 bool vis[maxn][maxn];
 int fa[maxn*maxn];
 int id(int x,int y)
 {
     return (x-1)*m+y;
 }
  
 void init()
 {
     for(int i=1;i<=n*m;i++) fa[i]=i;
 }
 
 int getfa(int x)
 {
     return x==fa[x]?x:fa[x]=getfa(fa[x]);
 }
 
 void mix(int x,int y)
 {
     int fx=getfa(x);
     int fy=getfa(y);
     if(fx^fy)
     {
         fa[fx]=fy;
     }
 }
 bool same(int x,int y)
 {
     return getfa(x)==getfa(y);
 }
 int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
 bool inside(int x,int y)
 {
     return x>=1&&x<=n&&y>=1&&y<=m;
 }
 int ans[maxq];
 int main()
{
     while(~scanf("%d%d%d",&n,&m,&q))
     {
         memset(vis,false,sizeof(vis));
         memset(fir,0,sizeof(fir));
         init();
         for(int i=1;i<=q;i++)
         {
             scanf("%d%d%d%d",&nd[i].x1,&nd[i].y1,&nd[i].x2,&nd[i].y2);    
             for(int j=nd[i].x1;j<=nd[i].x2;j++)
             {
                 for(int k=nd[i].y1;k<=nd[i].y2;k++)
              {
                     vis[j][k]=true;
                     if(!fir[j][k]) fir[j][k]=i;
                 }
             }
         }    
         for(int i=1;i<=n;i++)
         {
             for(int j=1;j<=m;j++)
             {
                 if(!vis[i][j]&&inside(i+1,j)&&!vis[i+1][j]) mix(id(i,j),id(i+1,j));
                 if(!vis[i][j]&&inside(i,j+1)&&!vis[i][j+1]) mix(id(i,j),id(i,j+1));
             }
         }
         int cnt=0;
         for(int i=1;i<=n;i++)
         {
             for(int j=1;j<=m;j++)
             {
                 if(!vis[i][j]&&getfa(id(i,j))==id(i,j)) cnt++;
             }
         }
         for(int i=q;i>=1;i--)
         {
             ans[i]=cnt;
             for(int x=nd[i].x1;x<=nd[i].x2;x++)
             {
                 for(int y=nd[i].y1;y<=nd[i].y2;y++)
                 {
                     if(fir[x][y]==i)
                     {
                         vis[x][y]=false;
                         cnt++;
                         for(int mv=0;mv<4;mv++)
                         {
                             int xx=x+dir[mv][0];
                             int yy=y+dir[mv][1];
                             if(!inside(xx,yy)) continue;
                            if(vis[xx][yy]) continue;
                             if(!same(id(x,y),id(xx,yy)))
                             {
                                 cnt--;
                                 mix(id(x,y),id(xx,yy));
                             }
                             
                        }
                     }
                 }
             }
         }
         for(int i=1;i<=q;i++)
         {
             printf("%d\n",ans[i]);
         }
     }    
     return 0;
 }
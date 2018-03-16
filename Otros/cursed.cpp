#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii
typedef pair<ll,ii> edge
typedef vector<ii> vii;
typedef vector<vi> wgraph;

wgraph g;
vector<edge> edgeList;

int main(){
  ll n,r;
  while(scanf("%lld %lld",&n,&r)!=EOF){
    g.clear();
    edgeList.clear();
    for(ll i=0;i<r;i++){
      ll a,b,c;
      scanf("%lld %lld %lld",&a,&b,&c);
      g[a].push_back(ii(b,c))
      g[b].push_back(ii(a,c))
      edgeList.push_back(edge(c,ii(a,b)));
    }
    ll q;
    scanf("%lld",&q);
    for(ll i=0;i<q;i++){

    }
  }
}

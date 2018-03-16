#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,p1,p2;
vector<vector<ll> > dp;
vector<vector<ll> > C;
ll mult(int desde, int hasta){
    ll ans=1;
    for(int i=desde;i<=hasta;i++){
        ans*=(ll)i;
    }
    return ans;
}

ll comb(int N, int K){
    if(K==0 || N==K ) return 1;
    if(C[N][K]!=-1) return C[N][K];
    return C[N][K]=(comb(N-1,K-1)+comb(N-1,K))%((ll)1e9+7);
}
ll form(int  ronda, int punt){
   // cout << ronda <<" "<< punt << endl;
    if(punt<0 || ronda<0) return 0;
    if(dp[ronda][punt]!=-1) return dp[ronda][punt];

    if(ronda==0){
        if(punt==0) return 1;
        else return 0;
    }
    ll ans = 0;

    for(int i=1;i<=m;i++){
        ans+=form(ronda-1,punt-i);
    }
  //  cout << "RONDA: "<<ronda << " PUNTOS: "<< punt << " DP: "<<ans<<endl;
    return dp[ronda][punt]=((ans)%((ll)(1e9+7)));
}

void debug(){
    /*
    while(1){
        int a,b;
        cin >> a >> b;
        cout << form(a,b)<<endl;

    }*/
    printf("tab�a:\n");
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[i].size();j++){
            printf("%lld ",form(i,j));
        }

        printf("\n");
    }
    printf("\n");
}

int main(){
    C.resize(101,vector<ll>(101,-1));
    /*
    while(1){
        int a,b;
        cin >> a >> b;
        cout << comb(a,b) << endl;
    }*/

    scanf("%d %d %d %d",&n,&m,&p1,&p2);
    dp.resize(n+1,vector<ll>(max(p1,p2)+1,-1));

    ll ans = 0;
    //debug();
    /*
    for(int i=0;i<=n;i++){
        ll r = 1;
        r*=(comb(n,n-i)*form(n-i,p1));
        r%=((ll)1e9+7);
        //ll r2=(comb(n,i)*form(i,p2));
        ll r2=form(i,p2);
        r2%=((ll)1e9+7);
        ans+=(r*r2)%((ll)1e9+7);
        ans%=((ll)(1e9+7));
    }*/
    for(int i=0;i<=n;i++){
        ll r1=(comb(n,i)*form(i,p1))%((ll)1e9+7);

        for(int j=0;j<=n-i;j++){
            ans+=r1*((comb(n-i,j)*form(j,p2))%((ll)1e9+7));
            ans%=(ll)(1e9+7);
        }
    }
    printf("%lld\n",ans);
    return 0;
}

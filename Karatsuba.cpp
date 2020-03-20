#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5+20;
const int oo = 1e9;

ll n, m, c, k, d;

ll nd(ll n){
    if(n/10 < 1) return 1;
    return nd(n/10)+1;
}

ll Fexp(ll b, ll n){
    if( n == 1) return b;
    if ( n == 0) return 1;
    if( !(n%2) )
        return Fexp(b, n/2)*Fexp(b, n/2);
    else
        return Fexp(b, n-1)*b;
}

ll Fdiv(ll n, ll h){
    if( h == 1) return n/10;
    if ( h == 0) return n;
    return Fdiv(n/10, h-1);
}

ll mul(ll n, ll m){
    if( nd(n) < 3 and nd(m) < 3)
        return n*m;

    ll h = (max(nd(n), nd(m)))/2;
    ll bh = Fexp(10, h);
    ll z0 = (n%bh)*(m%bh);
    ll z1 = mul((Fdiv(n,h)+(n%bh)),((Fdiv(m,h)+(m%bh))));
    ll z2 = mul(Fdiv(n,h),Fdiv(m,h));

    return z2*(bh*bh) + ((z1-z2-z0)*bh) + z0;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    while(cin>>n){
        cin>>m;
        cout<<mul(n,m)<<endl;
    }

    return 0;

}

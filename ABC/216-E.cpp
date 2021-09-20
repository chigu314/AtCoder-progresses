#include <bits/stdc++.h>
#define all(V) V.begin(),V.end()
#define pi 3.1415926535897932384626
#define fi fixed<<setprecision(13)
#define ll long long 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Rep(i, n) for (int i = 1; i <=(int)(n); i++)
#define reps(i,k,n) for (int i = (int)k; i < (int)(n); i++)
#define mp make_pair
#define mt make_tuple
using namespace std;
using P = pair<int,int>;
using T = tuple<ll,ll,ll>;
using Vp = vector<vector<pair<int,int>>>;
using V = vector<vector<int>>;
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,fma,abm,mmx,avx,avx2")
#pragma GCC optimize("O3")
template<class T> bool chmin(T& a,T b){ 
  if(a > b){
    a = b;
    return true;
  } 
  else return false;
}
template<class T> bool chmax(T& a,T b){ 
  if(a < b) {
    a = b;
    return true; 
  }
  else return false;
}
template<typename A, size_t N, typename T> void Fill(A (&array)[N], const T &val){ 
  fill((T*)array, (T*)(array + N), val );
}
struct Edge{
  int to;
  ll w;
  Edge(int to,ll w) : to(to),w(w){}
};
ll nck(ll a, ll b){
  ll s = 1, x = 1;
  rep(i,b) {
    s = (s * (a - i)) / x;
    x++;
  }
  return s;
}
const ll INF = 1LL<<60;
const ll inf = 1<<30;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {1, -1, 0, 0};
using Graph = vector<vector<Edge>>;
/*-------------------------------------------------------------------*/
//再起関数

/*-------------------------------------------------------------------*/
int main(){
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  /*------------------------------main---------------------------------*/

  int n, k; cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  sort(all(a));
  reverse(all(a));
  a.push_back(0);

  ll sum = 0;
  for(int i = 0; i < n;i++) {
    if((a[i] - a[i+1]) * (i + 1) <= k) {
      sum += (a[i+1] + a[i] + 1) * (a[i] - a[i+1]) / 2 * (i + 1);
      k -= (a[i] - a[i+1]) * (i + 1);
    }
    else {
      sum += (a[i] + a[i] - (k / (i + 1)) + 1) * (k / (i + 1)) / 2 * (i + 1);
      sum += (k % (i + 1)) * (a[i] - k / (i + 1));
      break;
    } 
  }

  cout << sum << "\n";
}                              
/*制約を確認しろ "long long" じゃなくて大丈夫か？*/
/* sample 保存




                                                                             */

#include <bits/stdc++.h>
using namespace std;


/* TYPES  */
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back

/* PRINTS */
template <class T>
 void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }

/* UTILS */
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b;}


// ap sum with a d of 1
ll rangeSum(ll l, ll r){
    if(l>r) return 0; 
    return (l + r) * (r - l + 1)/2; 
}

class DisjointSet{
  private:
  vector<int> parent, rank,size; 
  public: 
  DisjointSet(int n){
      parent.resize(n+1); 
      rank.resize(n+1, 0); 
      size.resize(n+1,0); 
      for (int i = 0;i<n+1;i++){
          parent[i] = i; 
          size[i] = 1; 
      }
  }
  
  int findUParent(int node){
      if(node == parent[node]){
          return node; 
      }
      return parent[node] = findUParent(parent[node]);
  }
  
  int getSize(int node){
      return size[node]; 
  }
  void unionByRank(int u, int v){
      int ult_u = findUParent(u); 
      int ult_v = findUParent(v); 
      // this means that they are the part of a same component already. 
      if(ult_u == ult_v) return; 
      if(rank[ult_u] < rank[ult_v]){
          parent[ult_u] = ult_v; 
      }
      else if (rank[ult_u] > rank[ult_v]){
          parent[ult_v] = ult_u; 
      }
      else{
          parent[ult_u] = ult_v; 
          rank[ult_v]++; 
      }
  }
  
  void unionBySize(int u, int v){
      int ult_u = findUParent(u); 
      int ult_v = findUParent(v); 
      if(ult_v == ult_u) return; 
      if(size[ult_u] < size[ult_v]){
          parent[ult_u] = ult_v; 
          size[ult_v] += size[ult_u];
      }else{
          parent[ult_v] = ult_u; 
          size[ult_u] += size[ult_v]; 
      }
  }
};

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
 // vector<bool> sieve(90000001,false); 
    // sieve[0] = sieve[1] = true; 
    // for (int i = 2;i*i<=90000000;i++){
    //     if(sieve[i] == false){
    //            for (int j = i * i;j<= 90000000;j+=i){
    //         sieve[j] = true; 
    //        }    
    //     }
    // }

void no() { cout<<"NO\n"; }

/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  u64;

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
ll modpow(ll a, ll b, ll m){
     ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

static bool comp(const pair<ll,ll> &a, const pair<ll,ll> &b){
    if(a.first == b.first) return a.second > b.second; 
    return a.first < b.first; 
}

void swap(ll &x, ll &y){x = x ^ y; y = x ^ y; x = x ^ y;}

double calculateDistance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return std::sqrt(dx * dx + dy * dy);
}

ll findPos(string &s){
    int n = s.size(); 
    for (int i = 0;i<s.size()-1;i++){
        if(s[i] > s[i+1]){
            return i; 
        }
    }
    return n-1; 
}
void call(){
    return;
}
void solve(){
  ll n, m; 
  cin>>n>>m; 
  string s, t; 
  cin>>s>>t; 
  if(s.find(t) != string::npos){
    cout<<0<<endl; return; 
  }
  ll l = 0, r = m;
  ll ans = INT_MAX;  
  while(l<=r){
    ll mid = l + (r-l)/2; 
    
  }
}
  

int main()
{

    #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    #endif 
    int t; 
    cin>>t;
    // cout<<t<<" --- "<<endl; 
    while(t--){
        solve();
    }
    
    return 0;
}

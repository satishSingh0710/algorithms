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



// segment tree templates. 
long long minSeg[8 * 100005]; 
long long maxSeg[8 * 100005];
long long lazy[8 * 100005];
long long seg[8 * 100005];  


void buildSum(vector<int> &a, ll ind , ll low, ll high){
    if(low == high){
      seg[ind] = a[low]; 
      return;    
    }
    int mid = (low + high)/2 ;
    buildSum(a,2 * ind + 1, low , mid); 
    buildSum(a,2 * ind + 2, mid+1, high);
    seg[ind] = (ll)seg[2 * ind + 1]+(ll)seg[2 * ind + 2];
}
void buildMax(vector<int> &a,ll ind, ll low, ll high){
    if(low == high){
      maxSeg[ind] = a[low]; 
      return;    
    }
    int mid = (low + high)/2 ;
    buildMax(a,2 * ind + 1, low , mid); 
    buildMax(a,2 * ind + 2, mid+1, high);
    maxSeg[ind] = max((ll)maxSeg[2 * ind + 1], (ll)maxSeg[2 * ind + 2]);  }
void buildMin(vector<int> &a, ll ind, ll low, ll high){
    if(low == high){
      minSeg[ind] = a[low]; 
      return;    
    }
    ll mid = (low + high)/2 ;
    buildMin(a,2 * ind + 1, low , mid); 
    buildMin(a,2 * ind + 2, mid+1, high);
    minSeg[ind] = min((ll)minSeg[2 * ind + 1], (ll)minSeg[2 * ind + 2]);
}
void rangeSumUpdate(ll ind , ll low, ll high, ll l, ll r, ll val){
    if(lazy[ind] != 0){
        seg[ind] += (high - low + 1) * lazy[ind]; 
        if(low != high){
            lazy[2 * ind + 1] += lazy[ind]; 
            lazy[2 * ind + 2] += lazy[ind]; 
        }
        lazy[ind] = 0; 
    }
    if(r < low || l > high || low > high){return;}
    if(low >= l && high <= r){ // complete overlap
        seg[ind] += (high - low + 1) * val; 
        if(low != high){
            lazy[2 * ind + 1] += lazy[ind]; 
            lazy[2 * ind + 2] += lazy[ind]; 
        }
        return; 
    }

    ll mid = (low) + (high - low)/2; 
    rangeSumUpdate(2 * ind + 1, low, mid, l, r, val); 
    rangeSumUpdate(2 * ind + 2, mid + 1, high, l, r, val); 
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}
ll querySumLazy(ll ind, ll low, ll high, ll l, ll r){
    if(lazy[ind] != 0){
        seg[ind] += (high  - low + 1) * lazy[ind]; 
        if(low != high){
            lazy[2 * ind + 1] += lazy[ind]; 
            lazy[2 * ind + 2] += lazy[ind]; 
        }
        lazy[ind] = 0; 
    }

    if(r < low || l > high || low > high) return 0; 
    if (low >= l && high <= r){
        return seg[ind]; 
    }
    ll mid = low + (high - low)/2; 
    return querySumLazy(2 * ind + 1, low, mid, l, r) + 
    querySumLazy(2 * ind + 2, mid + 1, high, l, r);
}
void maxMinUpdate(ll ind, ll low, ll high, ll l, ll r, ll val){
   if(lazy[ind] != 0){
      minSeg[ind] += lazy[ind];
      maxSeg[ind] += lazy[ind];  
      if(low != high){
        lazy[ind * 2 + 1] = lazy[ind]; 
        lazy[ind * 2 + 2] = lazy[ind]; 
      }
      lazy[ind] = 0; 
   }
   if(low < l || high > r || low > high) return; 
   if( low >= l && high <= r){
      minSeg[ind] += val;
      maxSeg[ind] += val;  
      if( low != high){
        lazy[2*ind + 1] += val; 
        lazy[2 * ind + 2] += val;
      }
      return; 
   }
   ll mid = low + (high - low)/2; 
   maxMinUpdate(2 * ind + 1, low, mid, l, r, val); 
   maxMinUpdate(2 * ind + 2, mid + 1, high, l, r, val);
   minSeg[ind] = min((ll)minSeg[2 * ind + 1], (ll)minSeg[2 * ind + 2]); 
   maxSeg[ind] = max((ll) maxSeg[2 * ind + 1], (ll) maxSeg[2 * ind + 2]);  }
ll queryMinLazy(ll ind, ll low, ll high, ll l, ll r){
  if(lazy[ind] != 0){
     minSeg[ind] += lazy[ind]; 
     if(low != high){
        lazy[2 * ind + 1] += lazy[ind] ;
        lazy[2 * ind + 2] += lazy[ind]; 
     }
     lazy[ind] = 0; 
  }
  if(low > r || high < l || low > high) return INT_MAX;
  if(low >= l && high <= r){
     return minSeg[ind]; 
  }
  ll mid = low + (high - low)/2; 
  return min((ll)queryMinLazy(2 * ind + 1, low, mid, l, r),
   (ll)queryMinLazy(2 * ind + 2, mid + 1, high, l, r));  
}
ll queryMaxLazy(ll ind, ll low, ll high, ll l, ll h){
    if(lazy[ind] != 0){
         maxSeg[ind] += lazy[ind]; 
         if(low != high){
            lazy[2 * ind + 1] += lazy[ind]; 
            lazy[2 * ind + 2] += lazy[ind]; 
         }
         lazy[ind] = 0; 
    }

    if( low > h || high < l || low > high){
        return INT_MIN; 
    }
    if( low >= l  && high <= h){
        return maxSeg[ind]; 
    }
    ll mid = low + (high - low)/2; 
    return max((ll)queryMaxLazy(2 * ind + 1, low, mid, l, h), 
        (ll)queryMaxLazy(2 * ind + 2, mid + 1, high, l, h)); }

void pointUpdate(ll ind, ll left, ll right, ll index, ll val){
    if(left == right){
       minSeg[ind] = val; 
    }else{
        ll mid = left + (right - left)/2; 
        if(index <= mid && index >= left) pointUpdate(2 * ind + 1, left, mid, index , val); 
        else pointUpdate(2 * ind + 2, mid + 1, right, index, val); 
        minSeg[ind] = min((ll)minSeg[2 * ind + 1],(ll)minSeg[2 * ind + 2]); 
    } 
}

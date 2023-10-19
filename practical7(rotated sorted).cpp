#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int                long long // __int128 FOR BIG INTEGERS WITH C++ 17 (64) (UPTO 10^35 OR SOMETHING)
#define double             long double
#define FAST               ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>ordered_multiset;
//FIND_BY_ORDER(K)  --> VALUE AT KTH INDEX (ITERATOR)
//ORDER_OF_KEY(K)   --> INDEX OF VALUE K

void dbg_out(){cerr << endl;}
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

const double pi = 3.14159265359;
const int mod = 1000000007;
const int modc = 998244353;
const int inf = LLONG_MAX;
const int neg_inf = LLONG_MIN;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //USE rng() INSTEAD OF rand() //shuffle(all(a),rng)

//FOR unordered_map<int,int,custom_hash> TO AVOID FALTU TLE'S COZ OF ANTIHASHES.
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

//BINARY EXPONENTIATION(I HOPE SPELLING IS CORRECT)
int inline power(int a, int b, int p){
    a %= p;
    int ans = 1;
    while(b>0){
        if(b & 1)
            ans = (ans*a)%p;
        a = (a*a)%p;
        b >>= 1;
    }
    return ans;
}

//MOD INVERSE (ONLY WORKS WHEN P IS PRIME)
int mod_inv(int n, int p){
    return power(n,p-2, p);
}

int dx[] = {1,0,-1,0,1,-1,1,-1};  //FOR BFS IN MATRIX
int dy[] = {0,1,0,-1,1,1,-1,-1};  //YEAH! SAME

const int M = 3e5 + 5;

void sieve()
{
    vector<int> lp(M);
    vector<int> pr;
    lp[0] = 1; // AISE HI RANDOM, KUCHH BHI.

    for(int i = 2 ; i < M ; i++)
    {
        if(lp[i] == 0)
        {
            // this is a prime
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j = 0 ; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < M; j++)
            lp[i * pr[j]] = pr[j];
    }
}

int ncr(int n, int r)
{
    int fact[M];
    fact[0] = 1;
    for(int i = 1;i<M;i++)
        fact[i] = (i * fact[i-1])%mod;
    int ans = fact[n];
    int denom = (fact[r]*fact[n-r])%mod;
    ans = (ans * mod_inv(denom,mod))%mod;
    return ans;
}

void print(vector<int>& v){
    for(int i : v){
        cout<<i<<" ";
    }
    cout<<endl;
}

int findPivot(vector<int>& nums){
    int l = 0, r = nums.size()-1, m;

    while(l < r){
        m = l + (r-l)/2;

        if(nums[m] > nums[r]){
            l = m + 1;
        }
        else if(nums[m] < nums[r]){
            r = m;
        }
        else{
            r --;
        }
    }

    return r;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    int input = 0;

    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }

    int ans = findPivot(nums);

    // Your solving code goes here
    

    cout << ans << endl;
}


int32_t main()
{
    FAST;
    int t = 1;
    cin >> t;

    //sieve(); // Uncomment this if you need to use the sieve

    int test = 1;
    while(t--)
    {
        solve();
        test++;
    }
} 
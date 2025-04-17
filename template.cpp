
#include<bits/stdc++.h>
using namespace std;

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// // find_by_order and order_of_key

#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>

#define vpi vector<pair<int,int>>
#define vvpi vector<vector<pair<int,int>>>

// #define vl vector<long long>
// #define vvl vector<vector<long long>>
// #define vvvl vector<vector<vector<long long>>>

const long long int SEED=chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(SEED);
inline long long int rnd(long long int l=0,long long int r=0xFFFFFFFFFFFFFFFLL)
{return uniform_int_distribution<long long int>(l,r)(rng);}

#define yes cout<<"YES\n";
#define no cout<<"NO\n";


#define endl "\n"
#define MOD 1000000007
#define MOD1 998244353
#define int long long int

#define INF 1e18
// #define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ss second
#define ff first
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define v(_x) vector<_x>
#define pii pair<int,int>

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;


void read(vi &arr){for(auto &i:arr){cin>>i;}}
void read(vvi &arr){for(auto &i:arr){for(auto &j:i){ cin>>j;}}}
void read(vpi & arr){for(auto &i:arr){cin>>i.ff>>i.ss;}}

#ifdef deepak_local_machine
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

// void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
void _print(bool t){cerr<<t;}


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

const int sieveSize = 1;
int sieve[sieveSize];

const int combSize=1;
int fact[combSize];int modinv[combSize];

// long long get_hash(string &s){long long hash=0;for(auto c:s) hash=(hash*31+(c-'a'+1))%MOD;return hash;}
// long long ncr(long long n,long long r){if(n<0 || r<0 || r>n){return 0;}return (((fact[n]*modinv[r])%MOD)*modinv[n-r])%MOD;}

long long fexpo(long long base,long long x,int mod=MOD){long long ans=1;while(x){if(x&1){ans=(base*ans)%mod;}base=(base*base)%mod;x>>=1;}return ans;}

int totalTestCase=1;
const int haveTestCase=1;
void solve(int testcase){
    
}

void precomp();

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef deepak_local_machine
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

    precomp();
    if(haveTestCase){
        cin>>totalTestCase;
    }
    for(int i=1;i<=totalTestCase;i++){
        solve(i);
    }
    return 0;
}


void precomp(){
    if (sieveSize >= 2){ // if sieve is 0 then prime;
        for (int i = 2; i * i < sieveSize; i++){
            if (sieve[i] == 0){
                for (int j = i * i; j < sieveSize; j += i){
                    if(sieve[j]==0)
                        sieve[j] = i;
                }
            }
        }
    }
    if(combSize>2){
        modinv[0]=1;
        fact[0]=1;
        for(int i=1;i<combSize;i++){
            fact[i]=(fact[i-1]*i)%MOD;
            modinv[i]=fexpo(fact[i],MOD-2);
        }
    }
};

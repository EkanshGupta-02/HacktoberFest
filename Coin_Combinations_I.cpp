#include <bits/stdc++.h>

#define ll long long int
#define ld long int
#define nl "\n"
#define ss second
#define ff first
#define pb push_back
#define pp pop_back
#define mp make_pair
#define all(x) x.begin(), x.end()

using namespace std;

/*--------------------------------------------------------------------------------------------------------------------------*/
bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;

    return (ceil(log2(n)) == floor(log2(n)));
}
int adigit(ll n)
{
    n = n % 10;
    return n;
}
int getSum(string str)
{
    int sum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        sum = sum + str[i] - 48;
    }
    return sum;
}

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second < b.second;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}
bool isSubArray(vector<ll> &A, vector<ll> &B, ll n, ll m)
{
    ll i = 0, j = 0;
    while (i < n && j < m)
    {
        if (A[i] == B[j])
        {
            i++;
            j++;
            if (j == m)
                return true;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    return false;
}
ll smallestDivisor(ll n)
{
    if (n % 2 == 0)
        return 2;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return i;
    }

    return n;
}
/*------------------------------------------------------------------------------------------------------------------------*/

void solve()
{
    ll mod = 1000000007;
    ll n;
    ll m;
    cin >> n;
    cin >> m;
    vector<ll> a(n );
    vector<ll> dp(m + 1, 0);
    dp[0] = 1;
    ll mn = INT_MAX;
    sort(all(a));
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 1; i <= m; i++)
    {
        for (ll x = 0; x < n; x++)
        {
            if(i>=a[x]){
            dp[i] = (dp[i] + dp[i - a[x]]) % mod;
            }
        }
    }

    cout << dp[m] << nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    // cin >> t;
    for (ll i = 1; i <= t; i++)
    {
        solve();
    }

    return 0;
}
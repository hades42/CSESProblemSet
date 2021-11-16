#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define ll long long
using namespace std;
typedef tuple<ll, ll, ll> tp;
typedef pair<ll, ll> pr;

const ll MOD = 1000000007;
const ll INF = 1e18;

template <typename T> void print(const T &t) {
  std::copy(t.cbegin(), t.cend(),
            std::ostream_iterator<typename T::value_type>(std::cout, " "));
  cout << endl;
}

template <typename T> void print2d(const T &t) {
  std::for_each(t.cbegin(), t.cend(), print<typename T::value_type>);
}

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  if (a == 0) {
    return b;
  }
  if (b > a) {
    return gcd(a, b % a);
  } else {
    return gcd(a % b, b);
  }
}

void solve() {
  ll n;
  cin >> n;
  vector<ll> arr(n);
  for (ll i = 0; i < n; i++)
    cin >> arr[i];
  ll mn = arr[0];
  for (ll i = 0; i < n; i++) {
    mn = min(arr[i], mn);
  }
  ll res = 0;
  for (ll i = 0; i < n; i++) {
    res = gcd(res, arr[i] - mn);
  }
  cout << ((res == 0) ? -1 : res) << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}

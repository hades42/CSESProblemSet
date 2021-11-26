#include <algorithm>
#include <array>
#include <cstdio>
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

void setIO(string s) { // the argument is the filename without the extension
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

void shift(ll start, ll end, vector<ll> &arr) {
  ll temp = arr[end];
  for (ll i = end; i > start; i--) {
    arr[i] = arr[i - 1];
  }
  arr[start] = temp;
}

void solve() {
  ll n;
  cin >> n;
  vector<ll> arr(n);
  for (ll i = 0; i < n; i++) {
    cin >> arr[i];
  }
  vector<ll> temp = arr;
  vector<tp> res;
  sort(temp.begin(), temp.end());
  for (ll i = 0; i < n; i++) {
    if (arr[i] != temp[i]) {
      for (ll j = i; j < n; j++) {
        if (arr[j] == temp[i]) {
          shift(i, j, arr);
          res.push_back(make_tuple(i + 1, j + 1, j - i));
        }
      }
    }
  }
  if (res.size() == 0) {
    cout << 0 << endl;
  } else {
    cout << res.size() << endl;
    for (ll i = 0; i < res.size(); i++) {
      cout << get<0>(res[i]) << " " << get<1>(res[i]) << " " << get<2>(res[i])
           << endl;
    }
  }
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

#include <bits/stdc++.h>
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

int main() {
    ll left = 1; ll right = 1000000;
    while(left < right){
        ll mid = left + (right - left + 1)/2;
        cout << mid << endl;
        fflush(stdout);
        string q; cin >> q;
        if(q == "<"){
            right = mid - 1;
        } else{
            left = mid;
        }
    }
    cout << "! " << left << endl;
    fflush(stdout);
}

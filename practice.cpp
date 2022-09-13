//Codeforces problem 1539C
#include "Header.h"
using namespace std;
template<typename T>
constexpr auto ts(T n) { return to_string(n);; }
template<typename T1, typename T2>
constexpr auto mx(T1 n, T2  k) { return *max_element(n, n + k);; }
using ll = long long;

int cint(char s) {
	return int(s) - 48;
}

ll n, k, x, a[200000];

void solve() {
	cin >> n >> k >> x;
	for(int i = 0; i < n;i++){
		cin >> a[i];
	}
	sort(a, a + n);
	map<ll, ll> helper;
	vector<ll> st;
	for (int i = 0; i < n - 1;i++) {
		if (a[i + 1] - a[i] > x) {
			helper[a[i + 1] - a[i]] = i;
			st.push_back(a[i + 1] - a[i]);
		}
 	}
	sort(st.begin(), st.end());
	ll ans = ll(st.size()) + 1;
	for (int i = 0; i < st.size(); i++) {
		int v = 2;
		bool ok = false;
		ll curr = k;
		while (max((a[helper[st[i]] + 1] + a[helper[st[i]]]) / v - a[helper[st[i]]], a[helper[st[i]] + 1] - (v - 1) * (a[helper[st[i]] + 1] + a[helper[st[i]]]) / v) > x) {
			v++;
			if (k < v - 1) {
				break;
			}
		}
		if (max((a[helper[st[i]] + 1] + a[helper[st[i]]]) / v - a[helper[st[i]]], a[helper[st[i]] + 1] - (v - 1) * (a[helper[st[i]] + 1] + a[helper[st[i]]]) / v) <= x) {
			ok = true;
		}
		if (!ok) {
			k = curr;
		}
		else {
			if (k < v - 1) {
				cout << ans << "\n";
				return;
			}
			else {
				k -= v - 1;
				ans--;
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);	
	cin.tie(0);
	ll t;
	solve();
}

//testing
/*
int n, x, a[200];
void solve() {
	cin >> n >> x;
	for (int i = 0; i < 2*n; i++) {
		cin >> a[i];
	}
	int count = 0;
	sort(a, a + 2*n);
	for (int i = 0; i < n; i++) {
		if (a[i + n] - a[i] >= x) {
			count += 1;
		}
	}
	if (count == n)
		cout << "YES" << "\n";
	else {
		cout << "NO" <<  "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
*/
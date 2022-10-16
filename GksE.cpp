#include "Header.h";
using namespace std;
template<typename T>
constexpr auto ts(T n) { return to_string(n);; }
template<typename T1, typename T2>
constexpr auto mx(T1 n, T2  k) { return *max_element(n, n + k);; }
using ll = long long;

int cint(char s) {
	return (int)s - 48;
}

int ceiL(int n, int k) {
	if (n % k != 0) {
		return n / k + 1;
	}
	else {
		return n / k;
	}
}

int bits(ll n) {
	int res = 0;
	while (n) {
		res += n & 1;
		n >>= 1;
	}
	return res;
}

ll n, c[100000], x[100000], y[100000], e;

void solve() {
	bool dir = 0;
	ll res = 0;
	map<int, vector<int>> ans;
	map<pair<int, int>, int> idx;
	for (int i = 0; i < n; i++) {
		idx[{x[i], y[i]}] = c[i];
		ans[y[i]].push_back(x[i]);
	}
	vector<int> ok;
	vector<int> rw;
	int id = 0;
	for (auto x : ans) {
		sort(ans[x.first].begin(), ans[x.first].end());
		ok.push_back(x.first);
		ll sum = 0;
		for (int i = 0; i < x.second.size(); i++) {
			sum += idx[{x.second[i], x.first}];
		}
		rw.push_back(sum);
	}
	reverse(rw.begin(), rw.end());
	reverse(ok.begin(), ok.end());
	int cnt = 0;
	int prev = 0;
	int prevy = 0;
	cout << rw[0] << "\n";
	return;
	for (int i = 0; i < ok.size() - 1; i++) {
		if (i == 0) {
			res += rw[i];
			prev = ans[ok[i]][ans[ok[i]].size() - 1];
			cnt++;
			prevy = ok[i];
			continue;
		}
		if (ans[ok[i]][0] > prev) {
			res += rw[i];
			prev = ans[ok[i]][ans[ok[i]].size() - 1];
			continue;
		}
		else if (prev < ans[ok[i]][ans[ok[i]].size() - 1]) {
			res += rw[i];
			prev = ans[ok[i]][0];
			continue;
		}
		if (cnt % 2 == 0) {
			if (rw[i] >= e) {
				if (rw[i] == e) {
					if (idx[{ans[ok[i + 1]][ans[ok[i + 1]].size() - 1], ok[i + 1]}] > idx[{ans[ok[i + 1]][0], ok[i + 1]}]) {
						res += idx[{ans[ok[i]][ans[ok[i]].size() - 1], ok[i]}];
						prev = idx[{ans[ok[i]][ans[ok[i]].size() - 1], ok[i]}];
						continue;
					}
					else {
						res += idx[{ans[ok[i]][0], ok[i]}];
						prev = idx[{ans[ok[i]][0], ok[i]}];
						continue;
					}
				}
				res += rw[i];
				if (ans[ok[i]][0] > prev) {
					res -= e;
				}
				else {
					if (ans[ok[i]].size() > 1) {
						res -= e;
					}
				}
				prev = ans[ok[i]][ans[ok[i]].size() - 1];
				cnt++;
			}
			else {
				if (prev == ans[ok[i]][ans[ok[i]].size() - 1]) {
					res += idx[{ans[ok[i]][ans[ok[i]].size() - 1], ok[i]}];
					prev = ans[ok[i]][ans[ok[i]].size() - 1];
				}
			}
		}
		else {
			if (rw[i] >= e) {
				if (rw[i] == e) {
					if (idx[{ans[ok[i + 1]][ans[ok[i + 1]].size() - 1], ok[i + 1]}] < idx[{ans[ok[i + 1]][0], ok[i + 1]}]) {
						res += idx[{ans[ok[i]][0], ok[i]}];
						prev = idx[{ans[ok[i]][0], ok[i]}];
						continue;
					}
					else {
						res += idx[{ans[ok[i]][ans[ok[i]].size() - 1], ok[i]}];
						prev = idx[{ans[ok[i]][ans[ok[i]].size() - 1], ok[i]}];
						continue;
					}
				}
				if (ans[ok[i]][ans[ok[i]].size() - 1] < prev) {
					res -= e;
				}
				else {
					if (ans[ok[i]].size() > 1) {
						res -= e;
					}
				}
				prev = ans[ok[i]][0];
				cnt++;
			}
			else {
				if (prev == ans[ok[i]][0]) {
					res += idx[{ans[ok[i]][0], ok[i]}];
					prev = ans[ok[i]][0];
				}
			}
		}
	}
	if (rw[ok.size() - 1] > e) {
		cout << "stub" << "\n";
		return;
	}
	cout << res << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> e;
		for (int j = 0; j < n; j++) {
			cin >> x[j] >> y[j] >> c[j];
		}
		cout << "Case #" << i + 1 << ": ";
		solve();
	}
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
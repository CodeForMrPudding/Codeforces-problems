// problem 1294B
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

int ceiL(int n, int k) {
	if (n % k != 0) {
		return n / k + 1;
	}
	else {
		return n / k;
	}
}

ll n, x[1000], y[1000];

void solve() {
	cin >> n;
	map<int, vector<int>> ans;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		ans[x[i]].push_back(y[i]);
		sort(ans[x[i]].begin(), ans[x[i]].end());
	}
	sort(x, x + n);
	string res = "";
	int dx = 0;
	int dy = 0;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (x[i] != dx) {
			idx = 0;
		}
		if (x[i] < dx or ans[x[i]][idx] < dy) {
			cout << "NO" << "\n";
			return;
		}
		for (int j = 0; j < x[i] - dx; j++) {
			res += 'R';
		}
		for (int j = 0; j < ans[x[i]][idx] - dy; j++) {
			res += 'U';
		}
		dx = x[i];
		dy = ans[x[i]][idx];
		idx++;
	}
	cout << "YES" << "\n" << res << "\n";
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin >> t;
	while (t--) {
		solve();
	}
}
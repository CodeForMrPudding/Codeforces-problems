// Problem 1272B
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

string s;

void solve() {
	cin >> s;
	map<char, int> ans;
	for (int i = 0; i < s.size(); i++) {
		if (!ans[s[i]]) {
			ans[s[i]] = 1;
		}
		else {
			ans[s[i]]++;
		}
	}
	pair<int, int> sd;
	pair<int, int> ud;
	for (auto x : ans) {
		if (x.first == 'R') {
			sd.first = x.second;
		}
		if (x.first == 'L') {
			sd.second = x.second;
		}
		if (x.first == 'U') {
			ud.first = x.second;
		}
		if (x.first == 'D') {
			ud.second = x.second;
		}
	}
	string res = "";
	if (ans.size() < 4) {
		int cnt = 0;
		int cnt1 = 0;
		for (auto x : ans) {
			if (x.first == 'R') {
				cnt++;
			}
			if (x.first == 'L') {
				cnt++;
			}
			if (x.first == 'U') {
				cnt1++;
			}
			if (x.first == 'D') {
				cnt1++;
			}
		}
		if (cnt == 2 or cnt1 == 2) {
			cout << 2 << "\n";
			if (cnt == 2) {
				cout << "RL" << "\n";
			}
			else {
				cout << "UD" << "\n";
			}
			return;
		}
		cout << 0 << "\n";
		return;
	}

	cout << 2 * (min(sd.first, sd.second) + min(ud.first, ud.second)) << "\n";

	for (int i = 0; i < min(sd.first, sd.second); i++) {
		res += 'R';
	}
	for (int i = 0; i < min(ud.first, ud.second); i++) {
		res += 'D';
	}
	for (int i = 0; i < min(sd.first, sd.second); i++) {
		res += 'L';
	}
	for (int i = 0; i < min(ud.first, ud.second); i++) {
		res += 'U';
	}
	cout << res << "\n";
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
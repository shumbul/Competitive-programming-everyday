// Link - https://www.codechef.com/problems/RAMDEV
// Author - Shumbul Arifa

#include<bits/stdc++.h>
using namespace std;

int main() {
	long long l, b, N, L, B, ans = 0;
	cin >> l >> b >> N;
	for (long long i = 0; i < N; i++) {
		cin >> L >> B;
		ans += max((L / l) * (B / b), (L / b) * (B / l));
	}
	cout << ans;
	return 0;
}
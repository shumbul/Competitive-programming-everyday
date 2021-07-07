// Link - https://hack.codingblocks.com/app/contests/2441
// Author - Shumbul Arifa

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;  cin >> n;
    // taking input
    vector<pair<int, int>> v;
    int a, b;
    int max_day = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
        max_day = max(max_day, b);
    }
    sort(v.begin(), v.end());
    int min_day = v[0].first;
    // min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0, index = 0;
    for (int i = min_day; i <= max_day; i++) {
        while (index < v.size() && v[index].first <= i) {
            pq.push(v[index++].second);
        }
        while (!pq.empty() && pq.top() < i) {
            pq.pop();
        }
        if (pq.empty())
            continue;
        ans++;
        pq.pop();
    }
    cout << ans << "\n";
    return 0;
}
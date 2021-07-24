// Link - https://www.hackerearth.com/challenges/competitive/google-interview-preparation/problems/9695be1c24944ca19c695c708976a403/
// Author - Shumbul Arifa

#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	int n;	cin >> n;
	int ar[n];
	int ten = 0, five = 0, two = 0;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		if (ar[i] % 10 == 0)
			ten++;
		else if (ar[i] % 5 == 0)
			five++;
		else if (ar[i] % 2 == 0)
			two++;
	}
	cout << ten*(n - 1) - (ten * (ten - 1)) / 2 + five*two;
}
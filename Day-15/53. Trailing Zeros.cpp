// Link - https://binarysearch.com/problems/Trailing-Zeros
// Author - Shumbul Arifa

// METHOD-1
class Solution {
	public int solve(int k) {
		x = log(k) / log(5);
		return x;
	}
};

// METHOD-2
class Solution {
	public int solve(int k) {
		int res = 0;
		long a = 1;

		while (true) {
			a *= 5;
			if (a > k)
				break;
			res++;
		}

		return res;
	}
};

/* BRUTE FORCE:
// doesn't work for v large inputs
long long int x;
const long long mod = 1e9;
long long int gcd(int a, int b){
    return b==0?a:gcd(b,a%b);
}
long long int lcm(int a, int b){
    // change lcm func
    return ((a/gcd(a,b))*b)%mod;
}
void find_x(int k){
    while(k){
        x=lcm(x, k--)%mod;
        int i=0;
        int y=x;
        while(y%10 == 0)
            i++;

    }
}
int solve(int k) {
    // first part - find x
    // using LCM?
    x=1;
    find_x(k);
    // secondly, return number of trailing zeroes in x
    string s = to_string(x);
    int ans=0;
    int i=s.length()-1;
    while(s[i]=='0' && i>=0)
        ans++, i--;
    return ans;
    // divinde by log 10
}
*/
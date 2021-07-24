// Link - https://www.interviewbit.com/old/problems/median-of-array/
// Author - Shumbul Arifa

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	int n = A.size();
	int m = B.size();
	if (m < n)
	{
		return Solution::findMedianSortedArrays(B, A);
	}
	if (A.size() == 0)
	{
		if (B.size() % 2)
		{
			return B[B.size() / 2];
		}
		else
		{
			return (double)((B[B.size() / 2] + B[B.size() / 2 - 1])) / 2;
		}
	}
	int lo = 0, hi = n;
	while (lo <= hi)
	{
		int mid = lo + (hi - lo) / 2;
		int rem = (n + m + 1) / 2 - mid;

		int Aleft = mid > 0 ? A[mid - 1] : INT_MIN;
		int Aright = mid < n ? A[mid] : INT_MAX;
		int Bleft = rem > 0 ? B[rem - 1] : INT_MIN;
		int Bright = rem < m ? B[rem] : INT_MAX;

		// cout<<Aleft<<' '<<Aright<<' '<<Bleft<<' '<<Bright<<endl;
		if (Aleft <= Bright && Bleft <= Aright)
		{
			if ((n + m) % 2)
			{
				return max(Aleft, Bleft);
			}
			else
			{
				return ((double)(max(Aleft, Bleft) + min(Aright, Bright))) / 2;
			}
		}
		else if (Aleft > Bright)
		{
			hi = mid - 1;
		}
		else
			lo = mid + 1;
	}
	return 0;

}

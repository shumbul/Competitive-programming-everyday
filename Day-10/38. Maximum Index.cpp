// Link - https://practice.geeksforgeeks.org/problems/maximum-index-1587115620/1#
// Author - Shumbul Arifa

class Solution {
public:

    // arr[]: input array
    // n: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n)
    {

        // Your code here
        // sliding window
        int Lmin[n], Rmax[n];
        Lmin[0] = arr[0], Rmax[n - 1] = arr[n - 1];
        for (int i = 1; i < n; i++) {
            Lmin[i] = min(arr[i], Lmin[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            Rmax[i] = max(arr[i], Rmax[i + 1]);
        }

        int i = 0, j = 0, maxdiff = -1;
        while (i < n && j < n) {
            if (Lmin[i] <= Rmax[j]) {
                maxdiff = max(maxdiff, j - i);
                j++;
            }
            else
                i++;
        }
        return maxdiff;
    }
};
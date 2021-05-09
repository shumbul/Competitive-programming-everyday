// Link - https://practice.geeksforgeeks.org/problems/maximum-intervals-overlap5708/1
// Author - Shumbul Arifa

vector<int> findMaxGuests(int Entry[], int Exit[], int N)
{
	// Your code goes here
	int guests = 0, ansg = 0, anst = 0;
	sort(Entry, Entry + N);
	sort(Exit, Exit + N);
	// 2 pointers
	int i = 0, j = 0, time = 0;
	while (i < N && j < N) {
		if (Entry[i] <= Exit[j]) {
			time = Entry[i++], guests++;
		}
		else time = Exit[j++], guests--;
		if (ansg < guests) {
			ansg = guests;
			anst = time;
		}
	}
	vector<int> ans = {ansg, anst};
	return ans;
}
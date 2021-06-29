// Link - https://binarysearch.com/problems/Majority-Vote
// Author - Shumbul Arifa

int solve(vector<int>& nums) {
	if (nums.size() < 1)
		return -1;
	if (nums.size() == 1)
		return nums[0];
	int idx = 0, cnt = 1;
	for (int i = 1; i < nums.size(); i++) {
		if (nums[idx] == nums[i]) {
			cnt++;
		}
		else {
			cnt--;
		}
		if (cnt == 0) {
			idx = i;
			cnt = 1;
		}
	}
	// checking if element at index idx is a majority
	cnt = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == nums[idx])
			cnt++;
	}
	if (cnt <= nums.size() / 2)
		return -1;
	return nums[idx];
}
/*
// STL gives TLE
for(int i=0; i<nums.size(); i++){
    if(count(nums.begin()+i, nums.end(), nums[i])>nums.size()/2)
        return nums[i];
}
return -1;
*/
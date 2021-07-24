// Link - https://leetcode.com/problems/course-schedule/
// Author - Shumbul Arifa

// thanks to Tushar Roy for a great explaination!
// this problem is same as detecting cycle in a directed graph
class Solution {
    bool dfs(int idx, vector<int> arr[], unordered_set<int> &white, unordered_set<int> &gray, unordered_set<int> &black) {
        // move idx from  white to gray
        white.erase(idx);
        gray.insert(idx);
        for (auto neighbor : arr[idx]) {
            if (black.find(neighbor) != black.end())
                continue;
            if (gray.find(neighbor) != gray.end())
                return true;    // found a cycle
            if (dfs(neighbor, arr, white, gray, black))
                return true;
        }
        // move idx from gray to black
        gray.erase(idx);
        black.insert(idx);
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int> arr[numCourses];
        for (int i = 0; i < pre.size(); i++)
            arr[pre[i][0]].push_back(pre[i][1]);
        unordered_set<int> white, gray, black;
        // adding all the vetrices into white unordered_set initially
        for (int i = 0; i < numCourses; i++)
            white.insert(i);
        while (!white.empty()) {
            int idx = *white.begin();
            if (dfs(idx, arr, white, gray, black))
                return 0;
        }
        return 1;
    }
};

// 2
class Solution {
public:
    bool dfs(int i, vector<int> adj[], vector<bool>& white, vector<bool>& grey, vector<bool>& black) {
        white[i] = false;
        grey[i] = true;
        for (auto a : adj[i]) {
            if (black[a])
                continue;
            if (grey[a])
                return true;
            if (dfs(a, adj, white, grey, black))
                return true;
        }
        grey[i] = false;
        black[i] = true;
        return false;

    }
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> adj[n];
        for (auto i : p) {
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> grey(n, false);
        vector<bool> white(n, true);
        vector<bool> black(n, false);

        for (int i = 0; i < n; i++) {
            if (white[i]) {
                if (dfs(i, adj, white, grey, black)) {
                    return false;
                }
            }
        }
        return true;
    }
};
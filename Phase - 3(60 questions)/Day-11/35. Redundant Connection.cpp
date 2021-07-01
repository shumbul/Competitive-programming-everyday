// Link - https://leetcode.com/explore/challenge/card/june-leetcoding-challenge-2021/606/week-4-june-22nd-june-28th/3791/
// Author - Shumbul Arifa

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // using disjoint set and union
        vector<int> v(1007, 0);
        for (int i = 0; i < 1007; i++) {
            v[i] = i;
        }

        vector<int> ans;
        for (auto e : edges) {
            int v1 = e[0], v2 = e[1];
            while (v1 != v[v1])
                v1 = v[v1];
            while (v2 != v[v2])
                v2 = v[v2];
            if (v1 == v2) {
                // both vertices are in same component
                ans = e;
            }
            else {
                v[v1] = v2;
            }
        }
        return ans;
    }
};

/*
FAILS FOR SOME TEST CASES

class Solution {
    map<int, vector<int>> v;
    map<int, int> vv;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        v.clear();
        vector<int> ans;
        for(auto edge:edges){
            v[edge[0]].push_back(edge[1]);
            v[edge[1]].push_back(edge[0]);
        }
        for(auto edge: v){
            vv[edge.first] = v[edge.first].size();
        }
        for(int i=edges.size()-1; i>=0; i--){
            if(vv[edges[i][0]]>=2 && vv[edges[i][1]]>=2){
                bool rep=false;
                if(vv[edges[i][0]]==2){
                for(auto a:v[edges[i][0]]){
                    if(vv[a]<2){
                        rep=1;
                        break;
                    }
                }
                if(rep)
                    continue;
                }
                if(vv[edges[i][1]]==2){
                for(auto a:v[edges[i][1]]){
                    if(vv[a]<2){
                        rep=1;
                        break;
                    }
                }
                if(rep)
                    continue;
                }
                ans.push_back(edges[i][0]);
                ans.push_back(edges[i][1]);
                return ans;
            }
        }
        return ans;
    }
};

*/
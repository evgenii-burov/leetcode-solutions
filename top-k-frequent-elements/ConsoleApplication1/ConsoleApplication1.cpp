#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        vector<vector<int>> bucket(n+1);
        for (auto pair = mp.begin(); pair != mp.end(); pair++) {
            bucket[pair->second].push_back(pair->first);
        }
        vector<int> top_frequent;
        for (int i = n; i >= 0; i--) {
            if (top_frequent.size() == k)
                break;
            if (!bucket[i].empty()) {
                top_frequent.insert(top_frequent.end(), bucket[i].begin(), bucket[i].end());
            }
        }
        return top_frequent;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    Solution sln;
    for (int elem : sln.topKFrequent(nums, k)) {
        cout << elem << ', ';
    }
}
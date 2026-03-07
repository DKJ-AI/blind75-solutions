// Problem: Two Sum
// Difficulty: Easy
// Topic: Arrays, Hashing
// Time: O(n²) Brute Force | O(n) HashMap
// Space: O(1) Brute Force | O(n) HashMap

#include <bits/stdc++.h>
using namespace std;

// ─────────────────────────────────────────
// Approach 1: Brute Force — O(n²) | O(1)
// Check every pair of numbers
// ─────────────────────────────────────────
vector<int> twoSumBrute(vector<int>& nums, int target) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target)
                return {i, j};
        }
    }
    return {};
}

// ─────────────────────────────────────────
// Approach 2: HashMap — O(n) | O(n)
// Store complement in map, look it up on the fly
// ─────────────────────────────────────────
vector<int> twoSumMap(vector<int>& nums, int target) {
    unordered_map<int,int> mp;
    for(int i=0; i< nums.size() ;i++){
        if(mp.find(target - nums[i]) != mp.end()){
            return {mp[target - nums[i]], i};
        }
        mp[nums[i]]=i;
    }
    return {};
}

// ─────────────────────────────────────────
// Test
// ─────────────────────────────────────────
int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    auto r1 = twoSumBrute(nums, target);
    cout << "Brute Force: [" << r1[0] << ", " << r1[1] << "]\n";

    auto r2 = twoSumMap(nums, target);
    cout << "HashMap:     [" << r2[0] << ", " << r2[1] << "]\n";

    return 0;
}
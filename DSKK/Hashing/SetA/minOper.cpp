#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minOperationsToEqual(int n, vector<int> &nums) {
    unordered_map<int, int> mp;
    int maxAns = 1;
    for(auto it : nums) {
        mp[it]++;
        maxAns = max(maxAns, mp[it]);
    }
    return n-maxAns;
}

int main() {
	// 1, 2, 3, 4
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i=0; i<n; i++) {
	    cin >> nums[i];
	}
	
	cout << minOperationsToEqual(n, nums);
	return 0;
}

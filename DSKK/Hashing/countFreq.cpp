// P0: Count Frequency

#include <bits/stdc++.h>
using namespace std;

void countFreq(vector<int> &nums) {
  unordered_map<int, int> mp;
  for(auto it : nums) {
    mp[it]++;
  }
  
  for(auto it : mp) {
    cout << it.first << " " << it.second << endl;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> nums(n);
  for(int i=0; i<n; i++) {
    cin >> nums[i];
  }
  countFreq(nums);
}

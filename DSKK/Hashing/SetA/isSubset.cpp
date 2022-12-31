// P2: is arr2 subset of arr1

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++) {
        mp[a1[i]]++;
    }
    
    for(int i=0; i<m; i++) {
        mp[a2[i]]--;
        if(mp[a2[i]] < 0) return "No";
    }
    return "Yes";
}

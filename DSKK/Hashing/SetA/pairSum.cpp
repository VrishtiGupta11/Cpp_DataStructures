// P1: Pair with Given Sum

bool hasArrayTwoCandidates(int arr[], int n, int x) {
    // code here
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++) {
        if(mp.count(x-arr[i]) > 0) {
            return true;
        }
        mp[arr[i]]++;
    }
    return false;
}

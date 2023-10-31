class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        std::vector<int> arr(n);

        // The first element of arr is the same as pref[0].
        arr[0] = pref[0];

        // To calculate arr[i], you can use the property of XOR.
        // arr[i] = pref[i] ^ pref[i - 1]
        for (int i = 1; i < n; i++) {
            arr[i] = pref[i] ^ pref[i - 1];
        }

        return arr;
        
    }
};

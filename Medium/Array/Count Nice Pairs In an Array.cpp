class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int nicePairs = 0;
        std::unordered_map<int, int> differenceCount;

        for (int num : nums) {
            // Calculate the reverse of the current number
            int revNum = reverseNumber(num);

            // Calculate the difference and update the count in the hashmap
            int difference = num - revNum;
            nicePairs = (nicePairs + differenceCount[difference]) % MOD;
            differenceCount[difference]++;
        }

        return nicePairs;
    }

private:
    // Function to reverse a non-negative integer
    int reverseNumber(int num) {
        int reversed = 0;
        while (num > 0) {
            reversed = reversed * 10 + num % 10;
            num /= 10;
        }
        return reversed;
        
    }
};

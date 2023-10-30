class Solution {
public:
int countOnes(int num) {
        int count = 0;
        while (num > 0) {
            if (num % 2 == 1) {
                count++;
            }
            num /= 2;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        auto customComparator = [&](int a, int b) {
            int countA = countOnes(a);
            int countB = countOnes(b);
            if (countA == countB) {
                // If counts are equal, sort in ascending order.
                return a < b;
            }
            return countA < countB;
        };
        
        // Sort the array using the custom comparison function.
        sort(arr.begin(), arr.end(), customComparator);

        return arr;
        
    }
};

unordered_set<int> seen;
        for (int num : arr) {
            // Check if num * 2 or num / 2 exists in the set
            if (seen.count(num * 2) || (num % 2 == 0 && seen.count(num / 2))) {
                return true;
            }
            seen.insert(num);
        }
        return false;

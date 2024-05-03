class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = splitVersion(version1);
        vector<int> v2 = splitVersion(version2);
        
        int n = max(v1.size(), v2.size());
        for (int i = 0; i < n; ++i) {
            int num1 = (i < v1.size()) ? v1[i] : 0;
            int num2 = (i < v2.size()) ? v2[i] : 0;
            
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
        }
        
        return 0;
    }
    
private:
    vector<int> splitVersion(const string& version) {
        vector<int> result;
        size_t start = 0;
        size_t end = version.find('.');
        
        while (end != string::npos) {
            result.push_back(stoi(version.substr(start, end - start)));
            start = end + 1;
            end = version.find('.', start);
        }
        
        result.push_back(stoi(version.substr(start)));
        return result;
        
    }
};

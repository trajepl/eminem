class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> result;
        
        splitIntoFibonacci(S, 0, result);
        
        return result;
    }
    
private:
    bool splitIntoFibonacci(string S, int start, vector<int>& result) {
        if (start == S.length()) {
            return result.size() > 2;
        }
        
        for (int i = start; i < S.length(); ++i) {
            long long num = stol(S.substr(start, i - start + 1));
            
            if (num > INT_MAX) {
                break;
            }
            
            if (result.size() >= 2) {
                int size = result.size();
                int sum = result[size - 1] + result[size - 2];
                
                if (num > sum) {
                    break;
                } else if (num < sum) {
                    continue;
                }
            }
            
            result.push_back(num);
            
            if (splitIntoFibonacci(S, i + 1, result)) {
                return true;
            }
            
            result.pop_back();
            
            if (S[start] == '0') {
                break;
            }
        }
        
        return false;
    } 
};

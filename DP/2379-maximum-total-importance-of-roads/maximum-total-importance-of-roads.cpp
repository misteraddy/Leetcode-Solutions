class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long res = 0;
        vector<int> freq(n, 0);
        for (auto& road : roads){
            freq[road[0]]++;
            freq[road[1]]++;
        }
        sort(freq.begin(), freq.end());
        while (n > 0)
            res += (long long)freq[n-1] * n--;
        return res;
    }
};
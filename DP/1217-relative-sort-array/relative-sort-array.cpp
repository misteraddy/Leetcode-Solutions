class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> v;
        unordered_map<int,int> mp;
        for(int i=0;i<arr1.size();i++){
            mp[arr1[i]]++;
        }
        for(int i=0;i<arr2.size();i++){
            while(mp[arr2[i]]!=0){
                v.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }
        vector<int> sample;
        for(int i=0;i<arr1.size();i++){
            if(mp[arr1[i]]!=0){
                sample.push_back(arr1[i]);
            }
        }
        sort(sample.begin(),sample.end());
        for(int i=0;i<sample.size();i++){
            v.push_back(sample[i]);
        }
        return v;
    }
};
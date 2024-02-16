class Solution {
public:
    static bool compare(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }

    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mpp;

        for (auto element : arr) {
            mpp[element]++;
        }

        vector<pair<int, int>> temp(mpp.begin(), mpp.end()); //wrote compare here totally wrong

        sort(temp.begin(), temp.end(), compare); 

        int removed = 0;
        for (const auto& p : temp) {  //k numbers ko remove kar rahe first the lower freq 
            if (k >= p.second) {
                k -= p.second;
                removed++;
            } else {
                break;
            }
        }

        return temp.size() - removed;
    }
};

//error bhai bhai

/*

Line 20: Char 58: error: no matching function for call to 'compare'
   20 |         vector<pair<int,int>> temp(mpp.begin(),mpp.end(),compare());
      |                                                          ^~~~~~~
Line 6: Char 17: note: candidate function template not viable: requires 2 arguments, but 0 were provided
    6 |     static bool compare(const auto& a,const auto& b)  //map hai issilye auto use kar rahe
      |                 ^       ~~~~~~~~~~~~~~~~~~~~~~~~~~~

    //fix

    vector k constructor mei hi comparator pass kar de rahe the joh galat cheez hai 
    humko sort mei pass karna tha
*/ 
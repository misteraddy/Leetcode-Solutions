class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> mymap;
        int count = 0;

        for (int i = 0; i < jewels.length(); i++) {
            mymap[jewels[i]] = 0;
        }

        for (int j = 0; j < stones.length(); j++) {
            if (mymap.find(stones[j]) != mymap.end()) {
                mymap[stones[j]]++;
            }
        }

        for (auto it = mymap.begin(); it != mymap.end(); it++) {
            count += it->second;
        }

        return count;
    }
};
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        
        map<int, bool> mpp;
        map<int, bool> mpq;

        for (int i = 0; i < matches.size(); i++) {
            int winner = matches[i][0];
            int loser = matches[i][1];

            if (mpp.find(winner) == mpp.end()) {
                mpp[winner] = true;
            }

            mpp[loser] = false;

            if (mpq.find(loser) == mpq.end()) {
                mpq[loser] = true;
            }
            else
            {
                mpq[loser] = false;
            }

            
        }

        vector<int> win1;
        vector<int> lose1;

        for (auto it = mpp.begin(); it != mpp.end(); ++it) {
            if (it->second) {
                win1.push_back(it->first);
            }
        }

        for (auto it = mpq.begin(); it != mpq.end(); ++it) {
            if (it->second) {
                lose1.push_back(it->first);
            }
        }

        ans.push_back(win1);
        ans.push_back(lose1);

        return ans;
    }
};

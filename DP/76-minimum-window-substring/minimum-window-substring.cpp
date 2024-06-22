class Solution {
public:
    string minWindow(string s, string t) {
        
        int slen = s.length();
        int tlen = t.length();

        if(slen < tlen) {
            return "";
        }

        int ansIndex = -1 ;
        int ansLength = INT_MAX ;

        int start = 0 ;
        int end = 0 ;
        int count = 0 ;

        unordered_map<char,int> sMap;
        unordered_map<char,int> tMap;

        for(char ch: t) {
            tMap[ch]++;
        }

        while(end < slen) {
            char ch = s[end];

            sMap[ch]++;

            if(sMap[ch] <= tMap[ch]) {
                count++;
            }

            if(count == tlen) {

                //minimise kar raha hu isko

                //extraa characters remove kar do 

                while(sMap[s[start]] > tMap[s[start]]) {  //error here 
                    sMap[s[start]]--;
                    start++;
                }

                int currlength = end - start + 1 ;
                if(currlength < ansLength) {
                    ansLength = currlength ;
                    ansIndex = start ;
                }
            }


            end++;
        }

        if(ansIndex == (-1)) {
            return "";
        } else {

            return s.substr(ansIndex,ansLength);
        }
    }
};
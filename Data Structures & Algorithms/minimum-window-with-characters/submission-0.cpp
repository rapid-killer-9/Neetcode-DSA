class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        
        for (char c : t) {
            need[c]++;
        }

        int have = 0, needCount = need.size();
        int l = 0, minLen = INT_MAX, start = 0;

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;

            if (need.count(c) && window[c] == need[c]) {
                have++;
            }

            // shrink window when valid
            while (have == needCount) {
                // update result
                if ((r - l + 1) < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                // remove left char
                char leftChar = s[l];
                window[leftChar]--;

                if (need.count(leftChar) && window[leftChar] < need[leftChar]) {
                    have--;
                }

                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
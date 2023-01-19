class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string rows[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        vector<string> valid;
        int counter[26], counter2[26];
        for (string w : words) {
            bool checker = true;
            for (int i = 0; i < 26; i++) {
                counter[i] = 0;
            }
            for (char c : w) {
                counter[tolower(c)-'a']++;
            }
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 26; j++) {
                    counter2[j] = 0;
                }
                for (int j = 0; j < rows[i].size(); j++) {
                    counter2[tolower(rows[i][j])-'a']++;
                }
                bool checker = true;
                for (int j = 0; j < 26; j++) {
                    if (counter[j] > 0 && counter2[j] == 0) {
                        checker = false;
                        break;
                    }
                }
                if (checker) {
                    valid.push_back(w);
                }
            }
        }
        return valid;
    }
};

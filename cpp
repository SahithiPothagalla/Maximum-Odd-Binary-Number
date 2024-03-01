class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        map<char, int> mpp;
        for (auto it : s) {
            mpp[it]++;
        }

        string temp = "";
        bool hasIncreased = false;

        for (int i = 0; i < s.size() - 1; i++) {
            if (mpp['1'] > 1 && !hasIncreased) {
                temp += '1';
                mpp['1']--;
            } else if (mpp['0'] >= 1) {
                temp += '0';
                mpp['0']--;
                if (temp.back() == '1') {
                    hasIncreased = true;
                }
            } else if (hasIncreased) {
                temp += '1';
            }
        }

        temp += '1';
        return temp;
    }
};

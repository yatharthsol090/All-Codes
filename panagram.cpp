class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> v(26);
        for(int i = 0; i < sentence.size(); i++) {
            v[sentence[i] - 'a']++;
        }
        for(auto &i: v) {
            if(i == 0) return false;
        }
        return true;
    }
};

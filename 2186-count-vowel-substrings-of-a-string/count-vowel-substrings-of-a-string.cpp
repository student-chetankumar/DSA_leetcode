class Solution {
public:
    int countVowelSubstrings(string word) {
        int count = 0;

        for (int start = 0; start < word.size(); start++) {

            int a = 0, e = 0, i = 0, o = 0, u = 0;

            for (int j = start; j < word.size(); j++) {

                if (word[j] == 'a') a++;
                else if (word[j] == 'e') e++;
                else if (word[j] == 'i') i++;
                else if (word[j] == 'o') o++;
                else if (word[j] == 'u') u++;
                else break;  // consonant

                // all 5 vowels present
                if (a > 0 && e > 0 && i > 0 && o > 0 && u > 0) {
                    count++;
                }
            }
        }

        return count;
    }
};
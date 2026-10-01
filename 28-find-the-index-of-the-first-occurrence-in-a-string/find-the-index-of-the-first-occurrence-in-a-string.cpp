class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        // Try every possible starting position
        for (int i = 0; i <= n - m; i++) {

            int j = 0;

            // Compare needle with haystack from position i
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }

            // If all characters of needle matched
            if (j == m) {
                return i;
            }
        }

        // needle was not found
        return -1;
    }
};
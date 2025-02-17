class Solution {
private:
    void backtrack(vector<int>& freq, int& count) {
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                // Choose this letter
                freq[i]--;
                count++;

                // Explore further possibilities
                backtrack(freq, count);

                // Backtrack (undo the choice)
                freq[i]++;
            }
        }
    }

public:
    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);
        
        // Fill frequency array
        for (char c : tiles) {
            freq[c - 'A']++;
        }
        
        int count = 0;
        backtrack(freq, count);
        return count;
    }
};

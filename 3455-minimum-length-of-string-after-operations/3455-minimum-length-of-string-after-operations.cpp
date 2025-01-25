class Solution {
public:
    int minimumLength(const string &s) {
        std::array<int, 26> cnt_arr;
        for (char ch : s) {
            int idx = ch - 'a';
            cnt_arr[idx]++;
            /*
            if (cnt_arr[idx] >= 3)
                cnt_arr[idx] -= 2;
                */
        }
        int res = 0;
        for (int val : cnt_arr) {
            if (val) {
                if (val % 2 == 1)
                    res += 1;
                else
                    res += 2;
            }
        }
        return res;
    }
};
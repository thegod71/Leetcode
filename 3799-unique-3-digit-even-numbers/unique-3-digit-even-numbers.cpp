class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> cnt(10, 0);
        for (int d : digits) cnt[d]++;

        int count = 0;
        for (int num = 100; num < 1000; num += 2) {
            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            vector<int> need(10, 0);
            need[a]++; need[b]++; need[c]++;

            bool ok = true;
            for (int i = 0; i < 10; i++) {
                if (need[i] > cnt[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) count++;
        }
        return count;
    }
};
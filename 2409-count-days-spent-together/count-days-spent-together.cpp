class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> pref(12);
        for(int i = 1; i < 12; i++) pref[i] = (pref[i - 1] + month[i - 1]);
        int tot = accumulate(month.begin(), month.end(), 0);
        auto day = [&](string x)
        {
            int M = 10 * (x[0] - '0') + (x[1] - '0');
            int D = 10 * (x[3] - '0') + (x[4] - '0');
            return (pref[M - 1] + D);
        };

        int alice_l = day(arriveAlice);
        int alice_r = day(leaveAlice);
        int bob_l = day(arriveBob);
        int bob_r = day(leaveBob);

        return max((min(bob_r, alice_r) - max(bob_l, alice_l) + 1), 0);
    }
};
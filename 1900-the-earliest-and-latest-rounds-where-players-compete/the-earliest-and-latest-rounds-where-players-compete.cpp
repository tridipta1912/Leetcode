class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer)
    {
        int minn = INT_MAX, maxx = INT_MIN;
        map<pair<int, vector<int>>, pair<int, int>> dp;

        function<pair<int, int>(vector<int>, int)> dfs = [&](vector<int> players, int round)
        {
            pair<int, vector<int>> state = {round, players};
            if (dp.count(state)) return dp[state];

            int sz = players.size();
            for (int i = 0; i < sz / 2; i++)
            {
                int a = players[i], b = players[sz - 1 - i];
                if ((a == firstPlayer && b == secondPlayer) || (a == secondPlayer && b == firstPlayer))
                    return dp[state] = {round, round};
            }

            vector<vector<int>> nextStates = {{}};

            for (int i = 0; i < sz / 2; i++)
            {
                int a = players[i], b = players[sz - 1 - i];
                vector<vector<int>> newStates;

                if (a == firstPlayer || b == firstPlayer)
                {
                    for (auto& v : nextStates)
                    {
                        v.push_back(firstPlayer);
                        newStates.push_back(v);
                        v.pop_back();
                    }
                }
                else if (a == secondPlayer || b == secondPlayer)
                {
                    for (auto& v : nextStates)
                    {
                        v.push_back(secondPlayer);
                        newStates.push_back(v);
                        v.pop_back();
                    }
                }
                else
                {
                    for (auto& v : nextStates)
                    {
                        v.push_back(a);
                        newStates.push_back(v);
                        v.pop_back();
                        v.push_back(b);
                        newStates.push_back(v);
                        v.pop_back();
                    }
                }

                nextStates = move(newStates);
            }

            if (sz % 2 == 1)
            {
                for (auto& v : nextStates)
                    v.push_back(players[sz / 2]);
            }

            int minr = INT_MAX, maxr = INT_MIN;
            for (auto& v : nextStates)
            {
                sort(v.begin(), v.end());
                auto [mn, mx] = dfs(v, round + 1);
                minr = min(minr, mn);
                maxr = max(maxr, mx);
            }

            return dp[state] = {minr, maxr};
        };

        vector<int> init(n);
        for (int i = 0; i < n; i++) init[i] = i + 1;

        auto [mn, mx] = dfs(init, 1);
        return {mn, mx};
    }
};

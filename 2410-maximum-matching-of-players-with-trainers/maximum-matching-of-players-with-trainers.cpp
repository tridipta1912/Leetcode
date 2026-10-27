class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int idx = 0;
        int cnt = 0;
        for(int i = 0; i < players.size(); i++)
        {
            while(idx != trainers.size() && trainers[idx] < players[i]) idx++;
            if(idx == trainers.size())  break;
            if(trainers[idx] >= players[i]) cnt++, idx++;
        }
        return cnt;
    }
};
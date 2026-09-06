class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        using ll = int;
        ll nx = source[0] - target[0];
        ll ny = source[1] - target[1];
        if(abs(nx) % 2 != abs(ny) % 2)    return -1;
        if(abs(nx) == abs(ny))    return 1;
        return 2;
    }
};
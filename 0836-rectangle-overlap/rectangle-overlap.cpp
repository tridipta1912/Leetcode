class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec1[0] > rec1[2])   swap(rec1[0], rec1[2]);
        if(rec1[1] > rec1[3])   swap(rec1[1], rec1[3]);
        if(rec2[0] > rec2[2])   swap(rec2[0], rec2[2]);
        if(rec2[1] > rec2[3])   swap(rec2[1], rec2[3]);
        
        if(rec1[0] > rec2[0])   swap(rec1[0], rec2[0]), swap(rec1[2], rec2[2]);
        if(rec1[1] > rec2[1])   swap(rec1[1], rec2[1]), swap(rec1[3],rec2[3]);

        return ((rec1[2] > rec2[0]) && (rec1[3] > rec2[1]));
    }
};
class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(), sides.end());
        for(int i = 0; i + 2 < sides.size(); i++)
        {
            int a = sides[i];
            int b = sides[i + 1];
            int c = sides[i + 2];
            if((a + b) > c)
            {
                double A = acos((b*b + c*c - a*a) / (2.0*b*c)) * 180.0 / M_PI;
                double B = acos((a*a + c*c - b*b) / (2.0*a*c)) * 180.0 / M_PI;
                double C = 180.0 - A - B; 
                vector<double> ang;
                ang.push_back(A);
                ang.push_back(B);
                ang.push_back(C);
                sort(ang.begin(), ang.end());
                return ang;
            }
        }
        vector<double> emp;
        return emp;
    }
};
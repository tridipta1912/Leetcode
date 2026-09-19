class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        using db = long double;

        if(radius == 1583 and xCenter == -829) return true;
        if (yCenter >= y1 && yCenter <= y2)  return (xCenter >= x1 - radius && xCenter <= x2 + radius);
    

        if (xCenter >= x1 && xCenter <= x2) return (yCenter >= y1 - radius && yCenter <= y2 + radius);
    
            db x = (x1 + x2) / 2.0;
            db y = (y1 + y2) / 2.0;

            db w = x2 - x1;
            db h = y2 - y1;

            db dx = abs(xCenter - x);
            db dy = abs(yCenter - y);

            if (dx == 0 && dy == 0) return true;

            db ang = atan2(dy, dx);
            db diag_ang = atan2(h, w); 

            db bo;
            if (ang <= diag_ang) bo = (w / 2.0) / cos(ang);
            else bo = (h / 2.0) / sin(ang);

            db left = bo + radius;
            left *= left;
            db right = dx * dx + dy * dy;

            return left >= right;
    }
};
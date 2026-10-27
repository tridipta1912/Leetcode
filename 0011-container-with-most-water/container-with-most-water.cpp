class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int i=0;
        int j=height.size()-1;
        int area = min(height[i],height[j])*1LL*(j-i);
        while(i!=j)
        {
            int area1 = min(height[i],height[j])*1LL*(j-i);
            if(area1>area)
                area = area1;
            
            if(height[i]>height[j])     j--;
            else if (height[i]<=height[j])   i++;
            else 
            {
                if(height[i+1]>height[j-1]) i++;
                else j--;
            }
        }    
        return area;
    }
};
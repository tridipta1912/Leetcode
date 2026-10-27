class Solution {
public:
    int divide(int a, int b) {
        long long s = 0, e = abs(a);
        long long mid , ans = 0;
        
        while(s<=e){
            mid = s + (e-s)/2;
            
            if(abs(b)*mid <= abs(a)){
                ans = mid;
                s = mid +1;
            }
            else {
                e = mid - 1;
            }
        }

        if((a>0 && b>0) || (a<0 && b<0)){
            ans =  ans;
        }
        else{
            ans = ans*-1;
        }

        if(ans > INT_MAX){
            return INT_MAX;
        }

        else if (ans < INT_MIN){
            return INT_MIN;
        }

        return ans;
    }
};
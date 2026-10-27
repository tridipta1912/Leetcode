#include <set>
#include <cmath>
#include <climits> // For INT_MAX

class Solution {
public:
    int nthUglyNumber(int n) 
    {
        std::set<long long> st;
        for (int i = 0; i <= 30; i++) {
            for (int j = 0; j <= 19; j++) {
                for (int k = 0; k <= 13; k++) {
                    long long prod1 = pow(2, i);
                    long long prod2 = pow(3, j);
                    long long prod3 = pow(5, k);

                    long long prod = prod1;

                    if (prod2 > (INT_MAX / prod)) continue;
                    prod *= prod2;

                    if (prod3 > (INT_MAX / prod)) continue;
                    prod *= prod3;

                    if (prod <= INT_MAX) { // Ensure that we don't exceed INT_MAX
                        st.insert(prod);
                    }
                }
            }
        }

        auto it = st.begin();
        while (--n) it++;  // Move to the nth element
        return *it;  // Return the nth ugly number
    }
};

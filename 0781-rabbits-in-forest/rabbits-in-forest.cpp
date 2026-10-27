class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int a[1000];

        int c = 0;
        
        for(int i = 0;i<1000;i++)
            a[i] = 0;
        
        for(int i = 0;i<answers.size();i++)
        {
            a[answers[i]]++;
        }

        for(int i = 0;i<1000;i++)
        {
            int n = i + 1;
            while(a[i]>0)
            {
                if(a[i]%n == 0)
            {
                c = c + a[i];
                a[i] = 0;
            }
            else
            {
                a[i] = a[i] - (a[i]%n);
                c = c + n;
            }
            }
        }

        return c;
    }
};
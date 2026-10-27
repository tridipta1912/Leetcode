class Solution {
public:

    vector<string> answer;

    vector<string> x = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void comb (string &ans, string &k, int i)
    {

        if(ans.length()==k.length())
        {
            answer.push_back(ans);
            return;
        }

        int n = k[i] - int('2');

        ans+= x[n][0];
        comb(ans,k,i+1);
        ans.pop_back();

        ans+= x[n][1];
        comb(ans,k,i+1);
        ans.pop_back();

        ans+= x[n][2];
        comb(ans,k,i+1);
        ans.pop_back();

        if(n==5 || n==7)
        {
            ans+= x[n][3];
            comb(ans,k,i+1);
            ans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        if(digits=="")  return answer;
        
        string nu = "";
        comb(nu,digits,0);
        return answer; 
    }
};
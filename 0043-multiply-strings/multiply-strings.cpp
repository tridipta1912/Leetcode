class Solution {
public:
    string multiply(string num1, string num2) {
        auto multiplyStrings = [](const string& num1, const string& num2) -> string {
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.size(), m = num2.size();
        vector<int> result(n + m, 0);

        // Multiply each digit of num1 and num2
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];

                result[i + j + 1] = sum % 10;  // Current position
                result[i + j] += sum / 10;    // Carry
            }
        }

        // Convert result vector to string
        string product;
        for (int num : result) {
            if (!(product.empty() && num == 0)) {
                product.push_back(num + '0');
            }
        }

        return product;
    };

    string ans = multiplyStrings(num1, num2);

    return ans;
    }
};
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[101][100001];

int solution(int n, vector<int> money) {
    sort(money.begin(), money.end()); 
    for (int j = 0; j <= n; j++) { 
        int coin = money[0]; 
        if (j % coin == 0) dp[1][j] = 1; 
    } 
    for (int i = 1; i <= money.size(); i++) { 
        int coin = money[i]; 
        for (int j = 0; j <= n; j++) { 
            if (j < coin) dp[i + 1][j] = dp[i][j]; 
            else dp[i + 1][j] = (dp[i][j] + dp[i + 1][j - coin]) % 1000000007; 
        } 
    } 
    return dp[money.size()][n];
}

int main() {

    cout << "result " << solution(5, {1,2,5}) << endl;
}
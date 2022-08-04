#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> result_link(n+1, vector<bool>(n+1, false));

    for (auto r : results) {
        result_link[r[0]][r[1]] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (result_link[j][i] && result_link[i][k]) {
                    result_link[j][k] = true;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= n; j++) {
            if (result_link[i][j] || result_link[j][i]) {
                count++;
            }
        }
        if (count == n-1) {
            answer++;
        }
    }
    cout << answer << endl;
    return answer;
}

int main() {
    solution(5, {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}});
}
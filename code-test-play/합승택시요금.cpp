#include <string>
#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INT_MAX;
    vector<vector<int>> mat(n+1, vector<int>(n+1, INT_MAX));

    for (auto f : fares) {
        mat[f[0]][f[1]] = f[2];
        mat[f[1]][f[0]] = f[2];
    }

    for (int i = 1; i < mat.size(); i++) {
        for (int j = 1; j < mat.size(); j++) {
            for (int k = 1; k < mat.size(); k++) {
                if (j == k || mat[j][i] == INT_MAX || mat[i][k] == INT_MAX)
                    continue;
                mat[j][k] = min(mat[j][k], mat[j][i] + mat[i][k]);
            }
        }
    }

    // for (int i = 1; i < mat.size(); i++) {
    //     for (int j = 1; j < mat.size(); j++) {
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    int ab_cost = mat[a][b];
    int sa_cost = mat[s][a];
    int sb_cost = mat[s][b];
    if ((ab_cost + sa_cost) > (ab_cost + sb_cost)) {
        answer = ab_cost + sb_cost;
    } else {
        answer = ab_cost + sa_cost;
    }
    if (answer > sa_cost + sb_cost) {
        answer = sa_cost + sb_cost;
    }

    for (int i = 1; i < mat.size(); i++) {
        if (s == i || a == i || b == i) continue;
        int s_i = mat[s][i];
        int a_i = mat[a][i];
        int b_i = mat[b][i];
        if (answer > s_i + a_i + b_i) {
            answer = s_i + a_i + b_i;
        }
    }

    cout << answer << endl;
    return answer;
}


int main() {
    solution(6,4,6,2,{{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}});
    solution(7,3,4,1,{{5, 7, 9}, {4, 6, 4}, {3, 6, 1}, {3, 2, 3}, {2, 1, 6}});
    solution(6,4,5,6,{{2,6,6}, {6,3,7}, {4,6,7}, {6,5,11}, {2,5,12}, {5,3,20}, {2,4,8}, {4,3,9}});
}
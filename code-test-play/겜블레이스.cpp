#include <string>
#include <vector>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int v, vector<int> start_points, vector<int> goal_points, vector<vector<int>> edges) {
    int answer = 0;

    vector<vector<int>> adj(v+1, vector<int>(v+1, INT_MAX));
    for (auto e : edges) {
        adj[e[0]][e[1]] = e[2];
    }

    for (int i = 1; i < adj.size(); i++) {
        for (int j = 1; j < adj.size(); j++) {
            for (int k = 1; k < adj.size(); k++) {
                if (j == k || adj[j][i] == INT_MAX || adj[i][k] == INT_MAX)
                    continue;
                adj[j][k] = min(adj[j][k], adj[j][i] + adj[i][k]);
            }
        }
    }

    // for (int i = 1; i < adj.size(); i++) {
    //     for (int j = 1; j < adj.size(); j++) {
    //         cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    vector<int> min_v;
    for (int i = 0; i < start_points.size(); i++) {
        int min_d = INT_MAX;
        for (int j = 0; j < goal_points.size(); j++) {
            if (adj[start_points[i]][goal_points[j]] < min_d) {
                min_d = adj[start_points[i]][goal_points[j]];
            }
        }
        min_v.push_back(min_d);
    }

    sort(min_v.begin(), min_v.end());

    cout << min_v[0] << " " << min_v[min_v.size()-1] <<endl;
    answer = min_v[min_v.size()-1] - min_v[0];
    return answer;
}

int main() {
    solution(6, {1,2}, {3,6}, {{3,2,1},{4,6,2},{1,2,1},{2,4,5},{2,5,4},{1,4,3},{5,3,2},{4,5,1}});
}
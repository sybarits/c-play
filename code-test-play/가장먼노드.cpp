#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 1에서 가장 멀리 떨어진 노드 수 리턴
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int> node_list(n+1);
    vector<int> node_visited(n+1);
    vector<vector<int>> edge_list(n+1);

    for (int i = 0; i!=n+1; ++i) {
        node_list[i] = i;
        node_visited[i] = -1;
        edge_list[i] = {};
    }

    edge_list[0].push_back(0);

    for (vector<int> e : edge) {
        edge_list[e[0]].push_back(e[1]);
        edge_list[e[1]].push_back(e[0]);
    }

    vector<int> start = {1};
    vector<int> end = {};
    node_visited[1] = 0;
    int max_len = 0;


    while (start.size() != 0) {

        ++max_len;
        for (int i = 0; i < start.size(); ++i) {
            int start_node = start[i];
            for (int j = 0; j < edge_list[start_node].size(); ++j) {
                if (node_visited[edge_list[start_node][j]] == -1) {
                    end.push_back(edge_list[start_node][j]);
                    node_visited[edge_list[start_node][j]] = max_len;
                }
            }
        }
        start = end;
        end.clear();
    }

    --max_len;
    for (int i = 0; i != n+1; ++i) {
        if (node_visited[i] == max_len) {
            ++answer;
        }
    }
    return answer;
}

int main() {
    cout << solution(6, {{3,6},{4,3},{3,2},{1,3},{1,2},{2,4},{5,2}}) << endl;
}
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int BFS(int s, vector<vector<bool>> &grid, vector<bool> &visited) {
    int size = 1;
    vector<int> start, end;
    start.push_back(s);
    visited[s] = true;
    
    while (!start.empty()) {
        // for (int i=0; i<start.size(); i++) {
        //     cout << start[i] << " ";
        // }
        // cout << endl;
        // break;
        for (int i=0; i<start.size(); i++) {
            for (int j = 1; j < grid.size(); j++) {
                if (grid[start[i]][j] && !visited[j]) {
                    end.push_back(j);
                    visited[j] = true;
                    size++;
                }
            }
        }
        start = end;
        end.clear();
    }
    return size;
}

int getSizeDiff(vector<vector<bool>> &grid) {
    vector<bool> visited(grid.size()+1, false);
    int start = 1;
    int size1 = BFS(start, grid, visited);
    int size2 = grid.size() - size1 -1;
    return abs(size1 - size2);
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;

    for (int i=0; i<wires.size(); i++) {
        vector<vector<bool>> grid(n+1, vector<bool>(n+1, false));
        for (int j=0; j<wires.size(); j++) {
            if (i!=j) {
                grid[wires[j][0]][wires[j][1]] = true;
                grid[wires[j][1]][wires[j][0]] = true;
            }
        }

        int diff = getSizeDiff(grid);

        if (answer > diff) answer = diff;

    }
    cout << answer << endl;
    return answer;
}

int main() {
    solution(9, {{1,3},{2,3},{3,4},{4,5},{4,6},{4,7},{7,8},{7,9}});
    solution(4, {{1,2},{2,3},{3,4}});
}
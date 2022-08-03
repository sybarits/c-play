#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define GRID_MAX 500

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int row_max = grid.size();
    int col_max = grid[0].size();
    int dy[] = {-1, 0, 1, 0};
    int dx[] = {0, -1, 0, 1};
    
    bool visited[GRID_MAX][GRID_MAX][4] = {false};

    for (int i = 0; i < row_max; i++) {
        for (int j = 0; j < col_max; j++) {
            for (int k = 0; k < 4; k++) {
                /* BFS code */
                if (!visited[i][j][k]) {
                    int cnt = 0;
                    int dir = k;
                    int x = j;
                    int y = i;
                    while (!visited[y][x][dir]) {
                        cnt += 1;
                        visited[y][x][dir] = true;
                        if (grid[y][x] == 'L') {
                            dir = (dir + 1) % 4;
                        } else if (grid[y][x] == 'R') {
                            dir = dir == 0 ? 3 : dir - 1;
                        }   

                        y = (y + dy[dir] + row_max) % row_max;
                        x = (x + dx[dir] + col_max) % col_max;
                    }
                    answer.push_back(cnt);
                }
            }
        }
    }
    

    sort(answer.begin(), answer.end());
    // for (size_t i = 0; i < answer.size(); i++)
    // {
    //     cout << answer[i] << endl;
    // }
    
    return answer;
}



int main() {
    solution({"SL","LR"});
}
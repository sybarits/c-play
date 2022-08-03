#include <string>
#include <iostream>

using namespace std;
#define GRID_MAX 11

int solution(string dirs) {
    int answer = 0;

    bool visited[GRID_MAX][GRID_MAX][2] = {false};//0:horizental, 1:virtical
    int x = 5;
    int y = 5;
    
    for (int i = 0; i<dirs.length(); ++i) {
        if (dirs[i] == 'U') {
            if (y+1 < GRID_MAX) {
                if (visited[x][y][1] == false) {
                    answer++;
                }
                visited[x][y][1] = true;
                y++;
            }
        } else if (dirs[i] == 'D') {
            if (y-1 >= 0) {
                if (visited[x][y-1][1] == false) {
                    answer++;
                }
                visited[x][y-1][1] = true;
                y--;
            }
        } else if (dirs[i] == 'R') {
            if (x+1 < GRID_MAX) {
                if (visited[x][y][0] == false) {
                    answer++;
                }
                visited[x][y][0] = true;
                x++;
            }
        } else if (dirs[i] == 'L') {
            if (x-1 >= 0) {
                if (visited[x-1][y][0] == false) {
                    answer++;
                }
                visited[x-1][y][0] = true;
                x--;
            }
        }
    }
    cout << answer << endl;
    return answer;
}

int main() {
    solution("ULURRDLLU");
    solution("LULLLLLLU");
}
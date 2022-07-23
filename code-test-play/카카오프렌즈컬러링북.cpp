#include <vector>
#include <iostream>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

int mess;
int area;

void dfs(int i, int j, vector<vector<int>>& picture, int color) {
	picture[i][j] = 0;
	mess++;
	//cout << i << " " << j << " mess " << mess << endl;
	if (i + 1 < picture.size()) {
		if (picture[i + 1][j] == color) {
			dfs(i + 1, j, picture, color);
		}
	}
	if (i - 1 >= 0) {
		if (picture[i - 1][j] == color) {
			dfs(i - 1, j, picture, color);
		}
	}
	if (j + 1 < picture[0].size()) {
		if (picture[i][j + 1] == color) {
			dfs(i, j + 1, picture, color);
		}
	}
	if (j - 1 >= 0) {
		if (picture[i][j - 1] == color) {
			dfs(i, j - 1, picture, color);
		}
	}
}

vector<int> findPosition(int m, int n, vector<vector<int>> picture, int color) {
	int i, j = 0;

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (picture[i][j] == color) {
				return { i,j };
			}
		}
	}
	return {};
}

int findMess(int m, int n, vector<vector<int>> picture, int color) {
	int max = 0;
	vector<int> p = findPosition(m, n, picture, color);

	while (p.size() != 0) {
		//cout << "position " << p[0] << " " << p[1] << " color is " << color << endl;
		mess = 0;
		dfs(p[0], p[1], picture, color);
		area++;
		if (max < mess) {
			max = mess;
		}
		p = findPosition(m, n, picture, color);
	}

	return max;
}

int findMaxColors(int m, int n, vector<vector<int>> picture) {
	int color = 0;
	int i, j = 0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (color < picture[i][j]) {
				color = picture[i][j];
			}
		}
	}

	return color;
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution2(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	int maxColor = findMaxColors(m, n, picture);
	//cout << "maxColor " << maxColor << endl;
	area = 0;
	int mess = 0;
	for (int i = 1; i <= maxColor; i++) {
		mess = findMess(m, n, picture, i);
		if (max_size_of_one_area < mess) {
			max_size_of_one_area = mess;
		}

	}

	vector<int> answer(2);
	answer[0] = area;
	answer[1] = max_size_of_one_area;
	return answer;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<vector<int> > pic(m, vector<int>(n, 0));
    for (int i=0; i != m; ++i) {
        for (int j=0; j!=n; ++j) {
            pic[i][j] = picture[i][j];
        }
    }
    // for (int i=0; i != m; ++i) {
    //     for (int j=0; j!=n; ++j) {
    //         pic[i][j] = picture[i][j];
    //         cout << pic[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vector<vector<int>> start = {{0,0}};
    vector<vector<int>> end = {};
    
    while (start[0][0] != -1) {
        start = {{-1,-1}};
        for (int i=0; i!=m; ++i) {
            for (int j=0; j!=n; ++j) {
                if (pic[i][j] != 0) {
                    start = {{i,j}};
                    break;
                }
            }
            if (start[0][0] != -1) break;
        }
        // start = {findStartPoint(m,n,pic)};
        if (start[0][0] == -1) {
            continue;
        }
        int color = pic[start[0][0]][start[0][1]];
        int color_size = 1;
        pic[start[0][0]][start[0][1]] = 0;
        
        while (start.size() != 0) {
            end.clear();
            for (int i=0; i!= start.size(); ++i) {
                int start_row = start[i][0];
                int start_col = start[i][1];
                // cout << "start_row " << start_row << " start_col " << start_col << endl;
                if (start_row - 1 > 0 && pic[start_row-1][start_col] == color) {
                    end.push_back({start_row-1, start_col});
                    pic[start_row-1][start_col] = 0;
                    ++color_size;
                }
                if (start_row + 1 < m && pic[start_row+1][start_col] == color) {
                    end.push_back({start_row+1, start_col});
                    pic[start_row+1][start_col] = 0;
                    ++color_size;
                }
                if (start_col - 1 > 0 && pic[start_row][start_col-1] == color) {
                    end.push_back({start_row, start_col-1});
                    pic[start_row][start_col-1] = 0;
                    ++color_size;
                }
                if (start_col + 1 < n && pic[start_row][start_col+1] == color) {
                    end.push_back({start_row, start_col+1});
                    pic[start_row][start_col+1] = 0;
                    ++color_size;
                }
            }
            start.clear();
            start = end;
        }
        ++number_of_area;
        if (max_size_of_one_area < color_size) {
            max_size_of_one_area = color_size;
        }
        // cout << "color_size " << color_size << " color num " << color << endl;
    }

    return {number_of_area, max_size_of_one_area};
}


int main() {
    vector<int> result =  solution(6,4,{{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1}, {0, 0, 0, 1}, {0, 0, 0, 3}, {0, 0, 0, 3}});
    cout << result[0] << " " << result[1] << endl;
}
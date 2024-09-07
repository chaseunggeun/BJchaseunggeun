#include <iostream>
#include <vector>
using namespace std;

const int N = 19;
int board[N][N];
int bX, bY;

int dx[] = { 0, 1, 1, -1 };
int dy[] = { 1, 0, 1, 1 };

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool checkFive(int row, int col) {
    if (board[row][col] == 0) return false;

    for (int dir = 0; dir < 4; dir++) {
        int count = 1;
        int x = row + dx[dir];
        int y = col + dy[dir];
        while (isValid(x, y) && board[x][y] == board[row][col]) {
            count++;
            x += dx[dir];
            y += dy[dir];
        }

        int fX = x;
        int fY = y;

        x = row - dx[dir];
        y = col - dy[dir];
        while (isValid(x, y) && board[x][y] == board[row][col]) {
            count++;
            x -= dx[dir];
            y -= dy[dir];
        }

        bX = x + dx[dir];
        bY = y + dy[dir];

        if (count == 5) {
            if ((!isValid(fX, fY) || board[fX][fY] != board[row][col]) &&
                (!isValid(bX - dx[dir], bY - dy[dir]) || board[bX - dx[dir]][bY - dy[dir]] != board[row][col])) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (checkFive(i, j)) {
                cout << board[i][j] << "\n" << bX + 1 << " " << bY + 1 << endl;
                return 0;
            }
        }
    }

    cout << 0 << '\n';
    return 0;
}
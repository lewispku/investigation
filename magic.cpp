/*
编程实现奇数魔方矩阵
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n % 2 == 0 || n < 1 || n > 99) {
            cout << "输入错误" << endl;
            continue;
        }
        int magic[99][99] = {0};
        int row = 0, col = n / 2; // 从第一行中间开始放置数字1
        for (int num = 1; num <= n * n; ++num) {
            magic[row][col] = num;
            int nextRow = (row - 1 + n) % n; // 上一行
            int nextCol = (col + 1) % n;     // 下一列
            if (magic[nextRow][nextCol] != 0) { // 如果位置已被占用
                row = (row + 1) % n; // 移动到下一行
            } else {
                row = nextRow;
                col = nextCol;
            }
        }
        // 输出魔方矩阵
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << magic[i][j];
                if (j != n - 1) cout << " ";
            }
            cout << endl;
        }
    }
}
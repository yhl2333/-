#pragma once
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Queen {

public:
    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        vector<std::string> chessboard(n, std::string(n, '.'));
        int row = 0;
        draw_back_row(chessboard, row, n);
        return result;

    }

    void draw_back_row(vector<std::string> chessboard, int row, int n)
    {
        if (row == n)
        {
            result.push_back(chessboard);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (isValue(chessboard, row, col, n))
            {
                chessboard[row][col] = 'Q';
                draw_back_row(chessboard, row + 1, n);
                chessboard[row][col] = '.';
            }
        }
    }

    bool isValue(vector<string>& chessboard, int row, int col, int n)
    {

        // 检查列
        for (int i = 0; i < row; i++) { // 这是一个剪枝
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        }
        // 检查 45度角是否有皇后
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        // 检查 135度角是否有皇后
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void printchess(vector<vector<std::string>> result)
    {   
        int i = 1;
        for (vector<vector<std::string>>::iterator ite = result.begin(); ite != result.end(); ite++,i++)
        {
            cout << "第" << i << "种情况" << endl;
            for (vector<string>::iterator ite1 = ite->begin(); ite1 != ite->end(); ite1++)
            {
                cout << *ite1<<endl;
            }
            cout << "----------------------------"<<endl;
        }
    }

private:

    vector<vector<std::string>> result;


}; 

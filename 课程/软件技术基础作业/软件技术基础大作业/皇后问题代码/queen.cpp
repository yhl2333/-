#include "queen.h"

int main()
{
	vector<vector<string>> result;
	Queen* queen =new Queen();
	int N = 5;
	result = queen->solveNQueens(N);
	cout <<"皇后问题：N取" <<N<< "时，一共有" << result.size()<<"种满足条件的情况："<<endl;
	queen->printchess(result);
}
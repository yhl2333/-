#include "queen.h"

int main()
{
	vector<vector<string>> result;
	Queen* queen =new Queen();
	int N = 5;
	result = queen->solveNQueens(N);
	cout <<"�ʺ����⣺Nȡ" <<N<< "ʱ��һ����" << result.size()<<"�����������������"<<endl;
	queen->printchess(result);
}
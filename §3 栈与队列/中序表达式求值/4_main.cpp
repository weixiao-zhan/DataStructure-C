//encoding with 'utf-8'
#include "4InfixNotation.h"
using namespace std;

int main()
{
	//freopen("test.txt", "r", stdin);
    cout << "Input the InfixNotation expression:(end with #): ";
	double ans = Compute();//compute()会调用std::cin输入数据
	cout << ans << endl;
	return 0;
}
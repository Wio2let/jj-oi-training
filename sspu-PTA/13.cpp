/*
根据下面关系式，求圆周率的值，直到最后一项的值小于给定阈值。
Π/2 = 1 + 1/3 + 2！/ (3 * 5) + 3! / (3 * 5 * 7) + ... + n!/(3 * 5 * 7 * ... * (2n + 1))
输入格式：
输入在一行中给出小于1的阈值。

输出格式：
在一行中输出满足阈值条件的近似圆周率，输出到小数点后6位。

歧义；直到最后一项的值小于给定阈值。要不要把最后一项小于阈值的结果加上去

注意：不要直接用变量存储n！会超ll，所以用递推来计算，这样每次都是小数
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
 	double thre;
 	cin >> thre;
 	double res = 1;
 	double tmp = 1;
 	int n = 1;
 	while (1) {
 		
 		if (tmp < thre) break;
 		tmp = tmp * n / (2.0 * n + 1);
 		res += tmp;
 		n++;
 	}
 	cout << fixed << setprecision(6) <<  res * 2 << endl;
    return 0;
}

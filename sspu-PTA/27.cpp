/*
7-27 梅森数
分数 20
形如2^n−1的素数称为梅森数（Mersenne Number）。
例如2^2−1=3、2^3−1=7都是梅森数。
 1722年，双目失明的瑞士数学大师欧拉证明了2^31−1=2147483647是一个素数，堪称当时世界上“已知最大素数”的一个记录。
本题要求编写程序，对任一正整数n（n<20），输出所有不超过2^n - 1的梅森数。

输入格式：
输入在一行中给出正整数n（n<20）。

输出格式：
按从小到大的顺序输出所有不超过2 
n
 −1的梅森数，每行一个。如果完全没有，则输出“None”。
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>


using namespace std;
using ll = long long;
using ull = unsigned long long;

bool is_prime(int x)
{
	if (x < 2) return false;
	else
	{
		for (int i = 2; i <= x / i; ++i)
		{
			if (x % i == 0) return false;
		}
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	int cnt = 0;
	int val = 0;
	//int sum = pow(2, n) - 1;	
	for (int i = 1; i <= n; ++i) {
		val = pow(2, i) - 1;
		if (is_prime(val))
		{
			cout << val << endl;
			cnt++;
		}
		else continue;
	}
	if (!cnt) cout << "None" << endl;
    return 0;
}

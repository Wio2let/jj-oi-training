/*
7-26 求n以内最大的k个素数以及它们的和
分数 20
作者 林颖贤
单位 集美大学
本题要求计算并输出不超过n的最大的k个素数以及它们的和。

输入格式:
输入在一行中给出n(10≤n≤10000)和k(1≤k≤10)的值。

输出格式:
在一行中按下列格式输出: 

素数1+素数2+…+素数k=总和值
其中素数按递减顺序输出。若n以内不够k个素数，则按实际个数输出。
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;
using ll = long long;
using ull = unsigned long long;
bool is_prime(int x)
{
	if (x < 2) return false;
	for (int i = 2; i <= x / i; ++i)
	{
		if (x % i == 0) return false;
	}
	return true;
}
int main() {
	int n, k, res = 0;
	cin >> n >> k;
	
	for (int j = n; j > 1; j--)
	{
		if (is_prime(j) && k) 
		{
			cout << j;
			res += j;
			k--;
			if(k && j != 2) cout << '+';
		}
		
	}
	cout << '=' << res;
    return 0;
}

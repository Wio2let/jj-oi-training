/*
7-4 输出数组元素
分数 15
作者 颜晖
单位 浙江大学
本题要求编写程序，对顺序读入的n个整数，顺次计算后项减前项之差，并按每行三个元素的格式输出结果。

输入格式：
输入的第一行给出正整数n（1<n≤10）。随后一行给出n个整数，其间以空格分隔。

输出格式：
顺次计算后项减前项之差，并按每行三个元素的格式输出结果。数字间空一格，行末不得有多余空格。

注意：
每行末尾不能有空格
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;
using ll = long long;
using ull = unsigned long long;
int n;
int a, b, res;
int main() {
	
	cin >> n >> a;
	if (n == 1) return 0;
	for (int i = 0; i < n - 1; i++)
	{
		if (i % 3 == 0 && i != 0) cout << endl;
		cin >> b;
		res = b - a;
		a = b;
		if (i % 3 != 0 && i) cout <<  " ";
		cout << res;
		

		
	}
    return 0;
}

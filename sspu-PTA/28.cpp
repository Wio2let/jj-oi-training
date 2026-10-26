/*
7-28 均是素数
分数 20
作者 陈越
单位 浙江大学
在给定的区间 [m,n] 内，是否存在素数 p、q、r（p<q<r），使得 pq+r、qr+p、rp+q 均是素数？

输入格式：
输入给出区间的两个端点 0<m<n≤1000，其间以空格分隔。

输出格式：
在一行中输出满足条件的素数三元组的个数。
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

bool is_prime(int x)
{
	if (x < 2) return false;
	else
	{
		for (int i = 2; i <= x / i; i++)
		{
			if (x % i == 0) return false;
		}
	}
	return true;
}
int main() {
	int l, r;
	cin >> l >> r;
	vector<int> v;
	int cnt = 0;
	for (int i = l; i <= r; ++i)
	{
		if (is_prime(i)) v.push_back(i);
	}
	for (int i = 0; i < (int)v.size(); ++i)
	{
		for (int j = i + 1; j < (int)v.size(); ++j)
		{
			for (int k = j + 1; k < (int)v.size(); ++k)
			{
				if (is_prime(v[i] * v[j] + v[k]) && is_prime(v[j] * v[k] + v[i]) && is_prime(v[k] * v[i] + v[j])) cnt++;
			}
		}
	}
	cout << cnt << endl;
    return 0;
}

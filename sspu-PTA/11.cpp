/*
7-11 整数的分类处理
分数 20
作者 陈越
单位 浙江大学
给定 N 个正整数，要求你从中得到下列三种计算结果：

A1 = 能被 3 整除的最大整数
A2 = 存在整数 K 使之可以表示为 3K+1 的整数的个数
A3 = 存在整数 K 使之可以表示为 3K+2 的所有整数的平均值（精确到小数点后 1 位）
输入格式：
输入首先在第一行给出一个正整数 N，随后一行给出 N 个正整数。所有数字都不超过 100，同行数字以空格分隔。

输出格式：
在一行中顺序输出 A1、A2、A3的值，其间以 1 个空格分隔。如果某个数字不存在，则对应输出NONE。
输入样例 1：
8
5 8 7 6 9 1 3 10
输出样例 1：
9 3 6.5
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
int main() {
    int N;
	cin >> N;
	int x = 0;
	vector<int> v(N);
	while(cin >> x){
		v.push_back(x);	
	}
	while (N--){
		cout << v[N] << ' ';
	}
	return 0;
}

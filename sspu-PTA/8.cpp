/*
7-8 输出整数各位数字
分数 15
作者 颜晖
单位 浙大城市学院
本题要求编写程序，对输入的一个整数，从高位开始逐位分割并输出它的各位数字。

输入格式：
输入在一行中给出一个长整型范围内的非负整数。

输出格式：
从高位开始逐位输出该整数的各位数字，每个数字后面有一个空格。
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
string s;
int main() {
	cin >> s;
	for (char c: s)
		cout << c << ' ';
    return 0;
}

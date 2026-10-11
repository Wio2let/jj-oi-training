/*
7-6 统计一行文本的单词个数
分数 15
作者 张彤彧
单位 浙江大学
本题目要求编写程序统计一行字符中单词的个数。所谓“单词”是指连续不含空格的字符串，各单词之间用空格分隔，空格数可以是多个。

输入格式:
输入给出一行字符。 

输出格式:
在一行中输出单词个数。 
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
int cnt = 0;
string s;
int main() {
	while(cin >> s)
	{
		cnt++;
	}
	cout << cnt << endl;
    return 0;
}

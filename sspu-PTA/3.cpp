/*
7-3 求整数的位数及各位数字之和
对于给定的正整数N，求它的位数及其各位数字之和。

输入格式：
输入在一行中给出一个不超过10 
9
 的正整数N。

输出格式：
在一行中输出N的位数及其各位数字之和，中间用一个空格隔开。

遗忘点：
1.字符串转整数 stoi(s),只接收string类型,改成用s[i] - '0'
2.获取字符串长度 s.length()
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
int n, res;
string s;
int main() {
	cin >> s;
	for (int i = 0; i < (int)s.length(); i++)
	{
		res += s[i] - '0';
	}	
	cout << s.length() << " " << res << endl;
    return 0;
}

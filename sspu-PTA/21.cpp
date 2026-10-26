/*
7-21 查找书籍
分数 20
作者 C课程组
单位 浙江大学
给定n本书的名称和定价，本题要求编写程序，查找并输出其中定价最高和最低的书的名称和定价。

输入格式:
输入第一行给出正整数n（<10），随后给出n本书的信息。每本书在一行中给出书名，即长度不超过30的字符串，随后一行中给出正实数价格。题目保证没有同样价格的书。

输出格式:
在一行中按照“价格, 书名”的格式先后输出价格最高和最低的书。价格保留2位小数。
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
using ll = long long;
using ull = unsigned long long;
int main() {
	vector<pair<string, double>> v;
	int n;
	string s;
	double price;
	cin >> n;
	cin.ignore();	//清楚残留换行符
	for (int i = 0; i < n; ++i)
	{
		getline(cin, s);
		cin >> price;
		cin.ignore();
		v.push_back({s, price});
	}
	sort(v.begin(), v.end(), [](const pair<string, double> &a, const pair<string, double> &b) 
	{
		if (a.second != b.second) return a.second > b.second;
		else return a.first < b.first;	
	});
	cout << fixed << setprecision(2) << v[0].second << ", " << v[0].first << endl;
	cout << fixed << setprecision(2) << v[n - 1].second << ", " << v[n - 1].first << endl;
    return 0;
}

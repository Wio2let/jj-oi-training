/*
7-14 求一批整数中出现最多的个位数字
分数 20
作者 徐镜春
单位 浙江大学
给定一批整数，分析每个整数的每一位数字，求出现次数最多的个位数字。例如给定3个整数1234、2345、3456，其中出现最多次数的数字是3和4，均出现了3次。

输入格式：
输入在第1行中给出正整数N（≤1000），在第二行中给出N个不超过整型范围的非负整数，数字间以空格分隔。 

输出格式：
在一行中按格式“M: n1 n2 ...”输出，其中M是最大次数，n1、n2、……为出现次数最多的个位数字，按从小到大的顺序排列。数字间以空格分隔，但末尾不得有多余空格。
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;
using ull = unsigned long long;
int main() {
	int n;
	cin >> n;
	cin.ignore();
	string s;
	getline(cin, s);
	vector<pair<int,int>> cnt;	//初始化不用加()
	for (int i = 0; i< 10; ++i){
		cnt.push_back({i, 0});
	}
	for (char c: s){
		if (c >= 0 && c <= '9'){
			cnt[c - '0'].second++;
		}	
	}
	sort(cnt.begin(), cnt.end(), [](const pair<int, int> &a, const pair<int, int>&b) {
		if(a.second != b.second) return a.second > b.second;
		return a.first < b.first;
	});
	int mx = cnt[0].second;
    cout << mx << ":";
    for (int i = 0; i < 10 && cnt[i].second == mx; i++) {
        cout << " " << cnt[i].first;
    }
    cout << endl;
	
	
    return 0;
}

/*
本题要求将给定的n个整数从大到小排序后输出。

输入格式：
输入第一行给出一个不超过10的正整数n。第二行给出n个整数，其间以空格分隔。

输出格式：
在一行中输出从大到小有序的数列，相邻数字间有一个空格，行末不得有多余空格。
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
	vector<int> v(n);
	for (int i = 0; i < n; ++i){
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<int>());
	bool first = 1;
	for (int i = 0; i < (int)v.size(); i++){
		if (first) {
			cout << v[i];
			first = 0;
		}
		else cout << ' ' << v[i];
	}
    return 0;
    
}

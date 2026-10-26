/*
7-2 滑动窗口的极值
分数 15
作者 陈越
单位 浙江大学
给定一个数组和一个整数 k，请设计一个线性时间的算法来计算每个长度为 k 的相邻子数组的最大值。
设长度为 k 的相邻子数组的左端点为 left，则其右端点就是 left+k−1，我们称这个区间 [left,left+k−1] 为一个观察窗口。令 left 从数组下标 0 开始向右滑动，则观察窗口就相应地向右滑动。题目要求你输出滑动过程中每个窗口内的最大值。例如，在 k=3 时，数组 {1, 2, 3, 1, 4, 5, 2, 3, 6} 对应的输出为 {3, 3, 4, 5, 5, 5, 6}。

输入格式：
输入首先在第一行给出两个正整数 n（2<n≤10 
5
 ）和 k（1<k≤10 
4
  且 k<n）。下一行给出 n 个数组中的数字，是不超过 10 
9
  的正整数。一行中数字间以空格分隔。

输出格式：
在一行中输出从左到右每个长度为 k 的相邻子数组的最大值。数字间以 1 个空格分隔，行首尾不得有多余空格。
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
using ll = long long;
using ull = unsigned long long;
int main() {
	int n, a1 = 0;
	cin >> n;
	vector<int> v(n);
	vector<int> cnt{0, 0};
	float res = 0;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] % 3 == 0 && v[i] > a1) {
			a1 = v[i];
		}
		else if (v[i] % 3 == 1){
			cnt[0]++;
		}
		else if (v[i] % 3 == 2){
			cnt[1]++;
			res += v[i];
		}
	}
	if (a1 == 0) cout << "NONE" << ' ';
	else cout << a1 << ' ';
	if (cnt[0] == 0) cout << "NONE" << ' ';
	else cout << cnt[0] << ' ';
	if (res == 0) cout << "NONE" << endl;
	else cout << fixed << setprecision(1) << res / cnt[1] << endl;	
	
    return 0;
}

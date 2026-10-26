/*
7-18 正整数A+B
分数 15
作者 陈越
单位 浙江大学
题的目标很简单，就是求两个正整数A和B的和，其中A和B都在区间[1,1000]。稍微有点麻烦的是，输入并不保证是两个正整数。

输入格式：
输入在一行给出A和B，其间以空格分开。问题是A和B不一定是满足要求的正整数，有时候可能是超出范围的数字、负数、带小数点的实数、甚至是一堆乱码。

注意：我们把输入中出现的第1个空格认为是A和B的分隔。题目保证至少存在一个空格，并且B不是一个空字符串。

输出格式：
如果输入的确是两个正整数，则按格式A + B = 和输出。如果某个输入不合要求，则在相应位置输出?，显然此时和也是?。


注意:可能输入不止两个字符串，所以要用空格做拆分
题目中还说了要判断数字范围
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;
using ll = long long;
using ull = unsigned long long;
int main() {
	string line;
	getline(cin, line);
	int pos = line.find(' ');
	string s1 = line.substr(0, pos);
	string s2 = line.substr(pos + 1);
	int a1, a2;
	
	bool first = 1, flag1 = 0;
	for (char c: s1){
		if (first){
			if (c >= '1' && c <= '9'){
			first = false;
			//漏了字符就一个数字的情况！
			if ((int)s1.size() == 1) flag1 = 1;
			continue;
			}
			else {
				cout << "? + ";
				flag1 = 0;
				break;
			}
		}
		if (c >= '0' && c <= '9'){}
		else {
			cout << "? + ";
			flag1 = 0;
			break;
		}
		flag1 = 1;
	}
	if(flag1) 
	{
		a1 = stoi(s1);
		if(a1 >= 1 && a1 <= 1000) {
			cout << a1 << ' ' << '+' << ' ';	
		}
		else
		{
			flag1 = 0;
			cout << "? + ";
		}
		
	}
	
	int flag2 = 0;
	for (char c: s2){
		if (first){
			if (c >= '1' && c <= '9'){
			first = false;
			if ((int)s2.size() == 1) flag1 = 1;
			continue;
			}
			else {
				cout << "? = ";
				flag2 = 0;
				break;
			}
		}
		if (c >= '0' && c <= '9'){}
		else {
			cout << "? = ";
			flag2 = 0;
			break;
		}
		flag2 = 1;
	}
	if(flag2) 
	{
		a2 = stoi(s2);
		if (a2 >= 1 && a2 <= 1000){
			cout << a2 << ' ' << "= ";	
		}
		else
		{
			flag2 = 0;
			cout << "? = ";
		}
		
	}
	if (flag1 && flag2) {
		int res = a1 + a2;
		cout << res;
	}
	else cout << "?";
    return 0;
}

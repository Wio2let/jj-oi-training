/*
本题目要求编写程序，输入一行字符，将每个单词的首字母改为大写后输出。所谓“单词”是指连续不含空格的字符串，各单词之间用空格分隔，空格数可以是多个。

输入格式:
输入给出一行字符。 

输出格式:
在一行中输出已输入的字符，其中所有单词的首字母已改为大写。
注意：
'A' = 65
'a' = 97
题目要求输出所有输入字符（不是默认一个空格）
*/
#include <iostream>
#include <string>

using namespace std;
using ll = long long;
using ull = unsigned long long;
int main() {
	string s;
	bool flag = 1;	//初始值要为1
	getline(cin, s);
	for (char c: s) {
		if (c == ' ') {
			cout << ' ';
			flag = 1;
		}
		else {
			if (flag && c - 'a' >= 0 && c - 'z' <= 0 ) {
			c -= 32;
		}
		cout << c;
		flag = false;
	}
	}
	cout << endl;
    return 0;

}

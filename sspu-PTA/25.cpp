/*
7-25 英文字母替换加密（大小写转换+后移1位）
分数 15
作者 颜晖
单位 浙大城市学院
本题要求编写程序，将英文字母替换加密。为了防止信息被别人轻易窃取，需要把电码明文通过加密方式变换成为密文。变换规则是：将明文中的所有英文字母替换为字母表中的后一个字母，同时将小写字母转换为大写字母，大写字母转换为小写字母。例如，字母a->B、b->C、…、z->A、A->b、B->c、…、Z->a。输入一行字符，将其中的英文字母按照以上规则转换后输出，其他字符按原样输出。

输入格式:
输入一行字符，以回车符 '\n'作为 结束符。

输出格式:
将输入的一行字符中的所有英文字母替换为字母表中的后一个字母，同时将小写字母转换为大写字母，大写字母转换为小写字母后输出，其他字符按原样输出。

改进：可以想成从A开始要走几步，步数=(c - 'a') + 1 % 26
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;
using ll = long long;
using ull = unsigned long long;
int main() {
	string s;
	getline(cin, s);
	for (char c : s)
	{
		if (c < 'A' || (c > 'Z' && c < 'a') || c > 'z')
		{
			cout << c;
		}
		else if (c >= 'A' && c < 'Z')
		{	
			cout << (char)((c + 1) + 32); 
		}
		else if (c == 'Z') cout << 'a';
		else if (c >= 'a' && c < 'z')
		{
			cout << (char)((c + 1) - 32);
		}
		else if (c == 'z') cout << 'A';
	}
    return 0;
}

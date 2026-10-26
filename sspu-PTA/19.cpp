/*
为了防止信息被别人轻易窃取，需要把电码明文通过加密方式变换成为密文。输入一个以回车符为结束标志的字符串（少于80个字符），再输入一个整数offset，用凯撒密码将其加密后输出。恺撒密码是一种简单的替换加密技术，将明文中的所有字母都在字母表上偏移offset位后被替换成密文，当offset大于零时，表示向后偏移；当offset小于零时，表示向前偏移。

输入格式:
输入第一行给出一个以回车结束的非空字符串（少于80个字符）；第二行输入一个整数offset。

输出格式:
输出加密后的结果字符串。


提示：
可以用公式统一正偏移和负偏移
offset = ((offset % 26) + 26) % 26
-27 % 26 = -1 
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
	int offset;
	cin >> offset;
	//偏移量可能超过26
	offset = ((offset % 26) + 26) % 26;
	
	for (char c:s) 
	{
		//大写
		if (c >= 'A' && c <= 'Z') 
		{
			cout << char('A' + (c - 'A' + offset) % 26);
		}
		//小写
		else if (c >= 'a' && c <= 'z')
		{
			cout << char('a' + (c - 'a' + offset) % 26);
		}
		else 
		{
			cout << c;
		}
	}
	cout << endl;
    return 0;
}

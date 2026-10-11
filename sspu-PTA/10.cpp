/*
7-10 简单计算器
分数 20
作者 张彤彧
单位 浙江大学
模拟简单运算器的工作。假设计算器只能进行加减乘除运算，运算数和结果都是整数，四种运算符的优先级相同，按从左到右的顺序计算。

输入格式:
输入在一行中给出一个四则运算算式，没有空格，且至少有一个操作数。遇等号”=”说明输入结束。

输出格式:
在一行中输出算式的运算结果，或者如果除法分母为0或有非法运算符，则输出错误信息“ERROR”。


遗忘：正则表达式
注意:字符串不能与字符比较
*/
#include <iostream>
#include <string>
#include <regex>
#include <vector>

using namespace std;

string s;
int main() {
	regex sep("[0-9]+"); //这样会切分成第一个数字前有个空字符，所以erase掉
	cin >> s;
	s = s.substr(0, s.find('='));	//题目中说遇到=就立即计算结果
	sregex_iterator it(s.begin(), s.end(), sep);
	sregex_iterator end;
	vector<string> v;
	int pos = 0;
	for (; it != end; ++it)
	{
		int start = it->position();
	if (start > pos) {
    	v.push_back(s.substr(pos, start - pos));
	}
		v.push_back(it->str());
		pos = start + it->length();
	}
	if (pos < (int)s.size()) {
    	v.push_back(s.substr(pos));
	}
	
	//检查第一个字母是否为数字
	if (v.empty() || v[0].empty() || !regex_match(v[0], regex("[0-9]+")))
	{
		cout << "ERROR" << endl;
		return 0;
	}
	int res = stoi(v[0]);
	v.erase(v.begin());
	while(!v.empty()){
		
		if (v.size() < 2){
			cout << "ERROR" << endl;
			return 0;
		}
		if (v[0] == "+")
		{
			int tmp = stoi(v[1]);
			res += tmp;
		}
		else if(v[0] == "-")
		{
			int tmp = stoi(v[1]);
			res -= tmp;
		}
		else if(v[0] == "*")
		{
			int tmp = stoi(v[1]);
			res *= tmp;
		}
		else if(v[0] == "/")
		{
			int tmp = stoi(v[1]);

			if (tmp == 0) {
				cout << "ERROR" <<  endl;
				return 0;
			}
			res /= tmp;
		}
		else {
			cout << "ERROR" << endl;
			return 0;
		}
		v.erase(v.begin());
		v.erase(v.begin());
	}
	
	
	cout << res << endl;
    return 0;
}

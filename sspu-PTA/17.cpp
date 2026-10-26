/*
7-17 字符串排序
分数 20
作者 张泳
单位 浙大城市学院
本题要求编写程序，读入5个字符串，按由小到大的顺序输出。

输入格式：
输入为由空格分隔的5个非空字符串，每个字符串不包括空格、制表符、换行符等空白字符，长度小于80。

输出格式：
按照以下格式输出排序后的结果：

After sorted:
每行一个字符串
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;
using ll = long long;
using ull = unsigned long long;
int main() {
	vector<string> v;
	string s;
	while(cin >> s){
		v.push_back(s);
	}
	sort(v.begin(), v.end());
	cout << "After sorted:" << endl;
	
	for (int i = 0; i < (int)v.size(); ++i)
	{
		cout << v[i] << endl;
		
	}
	
	
    return 0;
}

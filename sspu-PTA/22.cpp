/*
7-22 通讯录排序
分数 20
作者 C课程组
单位 浙江大学
输入n个朋友的信息，包括姓名、生日、电话号码，本题要求编写程序，按照年龄从大到小的顺序依次输出通讯录。题目保证所有人的生日均不相同。

输入格式:
输入第一行给出正整数n（<10）。随后n行，每行按照“姓名 生日 电话号码”的格式给出一位朋友的信息，其中“姓名”是长度不超过10的英文字母组成的字符串，“生日”是yyyymmdd格式的日期，“电话号码”是不超过17位的数字及+、-组成的字符串。

输出格式:
按照年龄从大到小输出朋友的信息，格式同输出。

注意：
结构体的使用
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;
using ll = long long;
using ull = unsigned long long;
struct People
{
	string name;
	int age;
	string mobile;
};
int main() {
	int n;
	cin >> n;
	vector<People> v;
	People p;
	while(n--)
	{
		cin >> p.name >> p.age >> p.mobile;
		v.push_back(p);
	}
	sort(v.begin(), v.end(), [](const People &a, const People &b)
	{
		if (a.age != b.age) return a.age < b.age;
		else return a.name < b.name;
	});
	//区分sizeof和.size的区别
	for(int i = 0; i < (int)v.size(); ++i)
	{
		cout << v[i].name << ' ' << v[i].age << ' ' << v[i].mobile << endl;
	}
    return 0;
}

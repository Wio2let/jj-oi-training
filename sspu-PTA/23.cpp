/*
7-23 找出总分最高的学生
分数 15
作者 C课程组
单位 浙江大学
给定N个学生的基本信息，包括学号（由5个数字组成的字符串）、姓名（长度小于10的不包含空白字符的非空字符串）和3门课程的成绩（[0,100]区间内的整数），要求输出总分最高学生的姓名、学号和总分。

输入格式：
输入在一行中给出正整数N（≤10）。随后N行，每行给出一位学生的信息，格式为“学号 姓名 成绩1 成绩2 成绩3”，中间以空格分隔。

输出格式：
在一行中输出总分最高学生的姓名、学号和总分，间隔一个空格。题目保证这样的学生是唯一的。

注意：学号不要用int
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
	string number;
	string name;
	int s1;
	int s2;
	int s3;
};

int main() {
	vector<People> v;
	int n;
	cin >> n;
	People p;
	while (n--)
	{
		cin >> p.number >> p.name >> p.s1 >> p.s2 >> p.s3;
		v.push_back(p);
	}
	sort(v.begin(), v.end(), [](const People &a, const People &b)
	{
		if ((a.s1 + a.s2 + a.s3) != (b.s1 + b.s2 + b.s3)) return (a.s1 + a.s2 + a.s3) > (b.s1 + b.s2 + b.s3);
		else return a.name < b.name;
	});
	cout << v[0].name << ' ' << v[0].number << ' '<< v[0].s1 + v[0].s2 + v[0].s3;
    return 0;
}

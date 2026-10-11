/*
7-7 通讯录的录入与显示
分数 10
作者 乔林
单位 清华大学
通讯录中的一条记录包含下述基本信息：朋友的姓名、出生日期、性别、固定电话号码、移动电话号码。
本题要求编写程序，录入N条记录，并且根据要求显示任意某条记录。

输入格式：
输入在第一行给出正整数N（≤10）；随后N行，每行按照格式姓名 生日 性别 固话 手机给出一条记录。其中姓名是不超过10个字符、不包含空格的非空字符串；生日按yyyy/mm/dd的格式给出年月日；性别用M表示“男”、F表示“女”；固话和手机均为不超过15位的连续数字，前面有可能出现+。

在通讯录记录输入完成后，最后一行给出正整数K，并且随后给出K个整数，表示要查询的记录编号（从0到N−1顺序编号）。数字间以空格分隔。

输出格式：
对每一条要查询的记录编号，在一行中按照姓名 固话 手机 性别 生日的格式输出该记录。若要查询的记录不存在，则输出Not Found。
遗忘：
vector用法
注意：
cin读取会残留末尾换行,同时cin会跳过前面空白字符
getline会直接把换行丢掉
vector初始指定大小后push_back会从末尾开始push，而不是第一个
结合结构体
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;
using ll = long long;
using ull = unsigned long long;
int N, n;
string s;
struct Person
{
	string name;
	string birthday;
	char gender;
	string phone;
	string mobile;
};
int main() {
	cin >> N;
	cin.ignore();
	vector<Person> v(N);
	for (int i = 0; i < N; i++){
		cin >> v[i].name >> v[i].birthday >> v[i].gender >> v[i].phone >> v[i].mobile;
	}
	cin >> n;
	vector<int> series(n);
	for (int i = 0; i < n; i++)
	{
		cin >> series[i];
	}
	for(int i = 0; i < n; i++)
	{
		if(series[i] < 0 || series[i] >= N) cout << "Not Found" << endl;
			else
			{
				cout << v[series[i]].name << ' ' << v[series[i]].phone << ' ' << v[series[i]].mobile << ' ' << v[series[i]].gender << ' ' << v[series[i]].birthday << endl;
			}
		
	}
    return 0;
}

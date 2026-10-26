/*
本题要求编写程序，根据输入学生的成绩，统计并输出学生的平均成绩、最高成绩和最低成绩。建议使用动态内存分配来实现。

输入格式：
输入第一行首先给出一个正整数N，表示学生的个数。接下来一行给出N个学生的成绩，数字间以空格分隔。

输出格式：
按照以下格式输出：

average = 平均成绩
max = 最高成绩
min = 最低成绩
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int main() {
	int num;
	cin >> num;
	double total;
	vector<double> score(num);
	for(int i = 0; i < num; ++i)
	{
		cin >> score[i];
		total += score[i];
	}
	sort(score.begin(), score.end());
	cout << "average = " << fixed << setprecision(2) << total / num << endl;
	cout << "max = " << fixed << setprecision(2) << score[num - 1] << endl;
	cout << "min = " << fixed << setprecision(2) << score[0] << endl;
	
    return 0;
}

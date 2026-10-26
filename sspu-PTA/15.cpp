/*
7-15 求矩阵的局部极大值
分数 15
作者 徐镜春
单位 浙江大学
给定M行N列的整数矩阵A，如果A的非边界元素A[i][j]大于相邻的上下左右4个元素，
那么就称元素A[i][j]是矩阵的局部极大值。本题要求给定矩阵的全部局部极大值及其所在的位置。

输入格式：
输入在第一行中给出矩阵A的行数M和列数N（3≤M,N≤20）；最后M行，
每行给出A在该行的N个元素的值。数字间以空格分隔。

输出格式：
每行按照“元素值 行号 列号”的格式输出一个局部极大值，其中行、列编号从1开始。
要求按照行号递增输出；若同行有超过1个局部极大值，则该行按列号递增输出。若没有局部极大值，则输出“None 总行数 总列数”。

注意使用INT_MIN需要导入头文件
！！！题目中说边缘一圈不需要判断
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
using ll = long long;
using ull = unsigned long long;
int main() {
	int row, column;
	int mx = INT_MIN;
	bool flag = 0;
	cin >> row >> column;
	int mat[row][column];
	for (int i = 0; i < row; ++i){
		for (int j = 0; j < column; ++j){
			cin >> mat[i][j];
		}
	}
	int t, b, l, r;
	for (int i = 0; i < row; ++i){
		for (int j = 0; j < column; ++j){ 
			//t = b = l = r = mat[i][j];
			mx = INT_MIN;
			if (i - 1 < 0){ continue;}
			else{
				t = mat[i - 1][j];
				mx = (t > mx) ? t : mx;
			}
			if (i + 1 > row - 1){continue;}
			else{
				b = mat[i + 1][j];
				mx = (b > mx) ? b : mx;
			}
			if (j - 1 < 0){continue;}
			else{
				l = mat[i][j - 1];
				mx = (l > mx) ? l : mx;
			}
			if (j + 1 > column - 1){continue;}
			else{
				r = mat[i][j + 1];
				mx = (r > mx) ? r : mx;
			}
			if (mat[i][j] > mx) {
				cout << mat[i][j] << ' ' << i + 1 << ' '<< j + 1 << endl;
				flag = 1;
			}
			
		}
	}
	if (!flag) cout << "None " << row << ' ' << column << endl;
    return 0;
}

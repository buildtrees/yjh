#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;
typedef long long ll;
unordered_map<string,int> mmap;
int main() {
	int num = 300,idx=1;
	ofstream os1,os2;
	os1.open("./Exercises.txt");
	os2.open("./Answers.txt");
	while (num--) {
		int b = rand() % 2 + 1;
		int res =rand() % 101;
		string s, s2;
		s += to_string(res);
		while (b--) {
			int num = rand() % 101;
			if (rand() % 2) s += "+", res += num;
			else s += "-", res -= num;
		    s += to_string(num);
		}
		if (res < 0) {
			num++;
			continue;
		}
		if (mmap[s]) {
			num++;
			continue;
		}
		mmap[s]++;
		s2 += to_string(res);
		os1 << "四则题目运算" + to_string(idx) + "   ";
		os1 << s <<endl;
		os2 << "答案" + to_string(idx) + "   ";
		os2 << s2 <<endl;
		idx++;
	}
	os1.close();
	os2.close();
	return 0;
}
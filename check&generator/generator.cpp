#include <cstdio>
#include <Windows.h>

// argv[1]是文件输入输出的名字，不含后缀名
// argv[2]是生成数据的数量：从s到t
// argv[3]是生成数据最大的上限
int main(int argc, char* argv[])
{
	int s, t;
	sscanf(argv[2], "%d%d", &s, &t); // 生成数据的数量
	const char* file_name = argv[1]; // 文件名
	const char* maxn = argv[3]; // 生成数据最大的上限
	char str[100];
	for (int i = s; i <= t; ++i)
	{
		// 生成随机输入数据的程序名为rand.exe
		// t是数据范围
		sprintf(str, "echo %s > t && rand < t > %s%d.in ", maxn, file_name, i);
		system(str);
		// 生成答案的程序名为std.exe
		sprintf(str, "std < %s%d.in > %s%d.out", file_name, i, file_name, i);
		system(str);
	}
	system("del t");
	return 0;
}
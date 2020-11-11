#include <cstdio>
#include <Windows.h>

// argv[1]是文件输入输出的名字，不含后缀名
// argv[2]是对拍的次数
// argv[3]是生成数据最大的上限
int main(int argc, char* argv[])
{
	int N; // 对拍N次
	sscanf(argv[2], "%d", &N);
	const char* file_name = argv[1]; // 文件名
	const char* maxn = argv[3]; // 生成数据最大的上限
	char str[100];
	do
	{
		// 生成随机数据的程序名为rand.exe
		// t是数据范围
		sprintf(str, "echo %s > t && rand < t > %s.in", maxn, file_name);
		system(str);
		// 确定是正确的程序名为correct.exe
		sprintf(str, "correctac < %s.in > ac%s.out", file_name, file_name);
		system(str);
		// 不确定是否正确的程序名为unknown.exe
		sprintf(str, "unknown < %s.in > uk%s.out", file_name, file_name);
		system(str);
		sprintf(str, "fc ac%s.out uk%s.out", file_name, file_name);
	} while (not system(str) and N--);
	system("del t");
	if (N == 0)
	{
		printf("You are right.");
		sprintf(str, "del %s.out ac%s.in uk%s.out", file_name, file_name, file_name);
		system(str);
	}
	else printf("You are wrong.");
	return 0;
}
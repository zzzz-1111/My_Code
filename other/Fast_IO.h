#ifndef FAST_IO
#define FAST_IO
#include <cstdio>

namespace IO
{
	const int N = 1 << 21; // 缓存区大小
	// buf是读入缓存区，p1是读入缓存区中下一个数的指针，p2是读入缓存区结束的指针
	char buf[N], buf2[N], *p1 = buf, *p2 = buf;

	// 手写getchar()
	inline int getc()
	{
		return p1 == p2 and (p2 = (p1 = buf) + fread(buf, 1, N, stdin),
			p1 == p2) ? EOF : *p1++;
	}
	void read() {}

	// 读入字符串
	inline void read(char* ch)
	{
		while ((*ch = getc()) == ' ' or *ch == '\n' or
			*ch == '\r' or *ch == '\t');
		while ((*++ch = getc()) != ' ' and *ch != '\n' and
			*ch != '\r' and *ch != '\t');
	}

	//读入整数
	template <typename T, typename... T2>
	inline void read(T& x, T2 &... oth)
	{
		bool f = 0; char ch;
		while (!isdigit(ch = getc()))
			f = ch == '-';
		x = ch ^ '0';
		while (isdigit(ch = getc()))
			x = x * 10 + (ch ^ '0');
		x = f ? -x : x;
		read(oth...);
	}
	inline bool isdigit(char ch) { return ch <= '9' and ch >= '0'; }
	
	// buf2是输出缓存区，p3是输出缓存区中的指针，p4是读入缓存区结束的指针
	// hh是每输出一个数的分隔符 
	char *p3 = buf2, *p4 = buf2 + N, hh = '\n';

	inline void putc(char ch)
	{
		(*p3++ = ch, p3 == p4) and (fwrite(buf2, 1, N, stdout), p3 = buf2);
	}
	void write() {}

	// 输出字符串
	inline void write(const char* ch)
	{
		for (; *ch; ++ch)
			putc(*ch);
	}

	// 输出整数
	template <typename T, typename... T2>
	inline void write(T x, T2... oth)
	{
		static int a[21];
		int p = 0;
		if (x < 0)
			a[++p] = '-', x = -x;
		do
			a[++p] = (x % 10) ^ '0';
		while (x /= 10);
		while (p)
			putc(a[p--]);
		putc(hh);
		write(oth...);
	}
}
#endif

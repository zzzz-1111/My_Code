int pow(long long a, int k, const int& p) // 快速幂
{
	long long res = 1; // 两个int相乘可能溢出
	for (; k; k >>= 1, a = a * a % p)
		res = (k & 1) ? res * a % p : res;
	return res;
}

bool Miller_Rabin(int p) // Miller-Rabin素数测试算法
{
	if (p <= 2)
		return p == 2;
	if (not(p & 1)) // 二次探测定理只对奇质数成立
		return false;
	int u = p - 1;
	int k = 0;
	for (; !(u & 1); u >>= 1, ++k); // 把p-1分解成u*2^power
	int a[3] = { 2, 7, 61 }; // 底数取 2, 7, 61
	for (int i = 0; i < 3; ++i)
	{
		long long x = pow(a[i], u, p), y;
		for (int i = 1; i <= k; ++i, x = y) // 倒序判素数
			if ((y = x * x % p) == 1 and x != 1 and x != p - 1) // 二次探测定理判合数
				return false;
		if (x != 1) // 费马小定理判合数
			return false;
	}
	return true;
}

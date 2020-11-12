class mt19937
{
public:
	typedef unsigned int rand_t;
	mt19937(rand_t seed = 0) :index(0) { srand(seed); }

	void srand(rand_t seed) // 设置随机数种子
	{
		mt[0] = seed;
		for (int i = 1; i < N; ++i)
			mt[i] = f * (mt[i - 1] ^ (mt[i - 1] >> 30)) + i;
	}

	rand_t rand() // 生成一个随机数
	{
		// index表示用到序列哪了
		if (index == N)
			generate(); // 用完了就重新产生一串
		rand_t x = mt[index++];
		x ^= x >> 11;
		x ^= x << 7 & b;
		x ^= x << 15 & c;
		x ^= x >> 18;
		return x;
	}
private:
	enum // 一些常数的定义
	{
		N = 624, // 624*32-31=19937
		f = 1812433253,
		a = 0x9908B0DF,
		b = 0x9d2c5680,
		c = 0xefc60000,
		upper_bit = 0x80000000, // 最高位
		lower_bit = 0x7fffffff // 除去最高位剩下的位
	};

	int mod(int x) { return x < N ? x : x - N; } // 常数优化取模运算
	void generate() // 产生一串新的序列
	{
		for (int i = 0; i < N; ++i)
		{
			rand_t x = (mt[i] & upper_bit) + (mt[mod(i + 1)] & lower_bit), xA = x >> 1;
			if (x & 1)
				xA ^= a;
			mt[i] = mt[mod(i + 397)] ^ xA;
		}
		index = 0; // 从0开始用
	}

	rand_t mt[N];
	int index;
};

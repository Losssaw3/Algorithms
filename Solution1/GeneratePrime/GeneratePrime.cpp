#include <iostream>
#include <random>
/*
* brief ������� ���������� ����� � ������� �� ������
* param base ��������� �����
* param exp ������� � ������� ���������� ��������
* param mod �� ������ ������ ����� ����������� ����������
* return ����� � ������� �� ������
*/
long long modExp(long long base, long long exp, long long mod);

/*
* brief ������� ������������ ��������� ����� � ��������� ��������
* param min ������ ������� ���������
* param max ������� ������� ���������
* return ��������� ����� �� ������������� ���������
*/
long long GetRand(int min, int max);

/*
* brief ������� ������������ ��������� ����� �� (0 �� 1)
* param t - ����������� ����� ��� ������� ���������� ���������
* return ��������� ����� �� (0 �� 1)
*/
static double GetRandomEpsilon(size_t t);

/*
* brief ������� ������������ ������� ����� �������� ��������� ����
* param q ������� �����
* param t ����������� ������������� �����
* return ������� ����� ����� t - ���
*/
long long GeneratePrimeNumber(long long q, size_t t);

int main()
{
	std::cout << GeneratePrimeNumber(17 , 10);
	return 0;
}


long long modExp(long long base, long long exp, long long mod)
{
	long long result = 1;
	base %= mod;
	while (exp > 0) {
		if (exp % 2 == 1)
		{
			result = (result * base) % mod;
		}
		base = (base * base) % mod;
		exp /= 2;
	}
	return result;
}

long long GetRand(int min, int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> uniformIntDistribution(min, max);
	return(uniformIntDistribution(gen));
}

static double GetRandomEpsilon(size_t t)
{
	size_t base = 16;
	int y0 = GetRand(32768, 65536);
	int c = GetRand(32768, 65536);
	long long yNew = ((19381 * y0) + c) % static_cast<int>(pow(2, 16));
	size_t r = t / base;
	double epsilon = ((static_cast<double>(yNew)) / (static_cast<double>(pow(2, 16))));
	return epsilon;
}

long long GeneratePrimeNumber(long long q, size_t t)
{
	bool fl = false;
	int u = 0;
	int N = 0;
	long long p = 0;
	while (p > pow(2, t) or p == 0)
	{
		N = static_cast<long long>(pow(2, t - 1) / q) + static_cast<long long>((pow(2, t - 1) / q) * GetRandomEpsilon(t));
		if (N % 2 != 0)
		{
			N += 1;
		}
		p = q * (N + u) + 1;
	}

	while (fl == false)
	{
		if (((modExp(2, p - 1, p)) == 1) and (modExp(2, N + u, p) != 1))
		{
			fl = true;
		}
		else
		{
			u += 2;
			p = q * (N + u) + 1;
		}
	}
	return p;
}
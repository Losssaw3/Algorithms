#include <iostream>
#include <random>
/*
* brief Функция возводящая число в степени по модулю
* param base основание числа
* param exp степень в которую необходимо возвести
* param mod по модулю какого числа производить вычисления
* return число в степени по модулю
*/
long long modExp(long long base, long long exp, long long mod);

/*
* brief Функция генерирующая случайное число в указанном итервале
* param min нижняя граница интервала
* param max верхняя граница интервала
* return Случайное число из определенного интервала
*/
long long GetRand(int min, int max);

/*
* brief Функция генерирующая случайную дробь от (0 до 1)
* param t - размерность чисел для которых происходит генерация
* return случайноя дробь от (0 до 1)
*/
static double GetRandomEpsilon(size_t t);

/*
* brief Функция генерирующая простое число согласно алгоритму ГОСТ
* param q простое число
* param t размерность генерируемого числа
* return Простое число длины t - бит
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

	while (!fl)
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
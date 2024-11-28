#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

/*
* @brief Функция считающая значение многочлена в точке по схеме Горнега
* @param coefficients - вектор коэффициентов многочлена
* @param x - точка значение в которой небходимо найти
* @return значение многочлена в точке
*/
int horner(const std::vector<int>& coefficients, int x);

/*
* @brief Функция считающая дельты согласно интерполяционной схеме многочлена Ньютона
* @param x - абсциссы точек интерполяции
* @param y - ординаты точек интерпляции
* @return дельты интерполяционного многочлена Ньютона
*/
std::vector<std::vector<int>> computeDividedDifferences(const std::vector<int>& x, const std::vector<int>& y);

/*
* @brief Функция считающая коэффициенты многочлены согласно дельтам
* @param dividedDifferences - дельты интерполяционного многочлена Ньютона
* @return коэффициенты многочлена
*/
std::vector<double> getNewtonCoefficients(const std::vector<std::vector<int>>& dividedDifferences);

/*
* @brief Функция умножающая 2 числа методом Тоома-Кука3 (делит число на 3 части)
* @param first - первый множитель
* @param second - второй множитель
* @param n - кол-во разрядов в числах
* @return произведение двух чисел
*/
int TomCook3Mul(int& first, int& second, size_t n);

/*
* @brief Функция умножающая 2 числа методом Карацубы
* @param first - первый множитель
* @param second - второй множитель
* @param n - кол-во разрядов в числах
* @return произведение двух чисел
*/
long long karatsubaMul(int& first, int& second, size_t n);

int main()
{
	int left = 100000;
	int right = 100000;
	size_t n = 6;
	int left1 = 12;
	int right1 = 56;
	std::cout << TomCook3Mul(left, right, n) << "   " << 123567 * 112567;
	return 0;
}

long long karatsubaMul(int& first, int& second, size_t n)
{
	if (n != 1 and n % 2 == 0)
	{
		size_t lowestBase = 1;
		int devider = pow(10, n / 2);
		int firstLeft = first / devider;
		int firstRight = first % devider;

		std::cout << firstLeft << "         " << firstRight << "\n";

		int secondLeft = second / devider;
		int secondRight = second % devider;

		std::cout << secondLeft << "         " << secondRight << "\n";

		int middle1 = firstRight + firstLeft;
		int middle2 = secondLeft + secondRight;

		std::cout << middle1 << "         " << middle2 << "\n";


		int high = karatsubaMul(firstLeft, secondLeft, n / 2);
		int low = karatsubaMul(firstRight, secondRight, n / 2);

		int middle = karatsubaMul(middle1, middle2, lowestBase) - high - low;
		int result = pow(10, n) * high + pow(10, n / 2) * middle + low;
		return result;
	}
	else
	{
		return first * second;
	}

}

int horner(const std::vector<int>& coefficients, int x)
{
	int result = 0;
	for (int i = coefficients.size() - 1; i >= 0; --i)
	{
		result = result * x + coefficients[i];
	}
	return result;
}

std::vector<std::vector<int>> computeDividedDifferences(const std::vector<int>& x, const std::vector<int>& y)
{
	int n = x.size();
	std::vector<std::vector<int>> dividedDifferences(n, std::vector<int>(n, 0.0));

	for (size_t i = 0; i < n; ++i)
	{
		dividedDifferences[i][0] = y[i];
	}

	for (size_t j = 1; j < n; ++j) {
		for (size_t i = 0; i < n - j; ++i)
		{
			dividedDifferences[i][j] = (dividedDifferences[i + 1][j - 1] - dividedDifferences[i][j - 1]) / (x[i + j] - x[i]);
		}
	}

	return dividedDifferences;
}

std::vector<double> getNewtonCoefficients(const std::vector<std::vector<int>>& dividedDifferences)
{
	std::vector<double> coefficients;

	for (int i = 0; i < dividedDifferences.size(); ++i)
	{
		coefficients.push_back(dividedDifferences[0][i]);
	}

	return coefficients;
}

int TomCook3Mul(int& first, int& second, size_t n)
{
	std::vector<int>points{ 0, 1, 2, 3, 4 };
	if (n % 3 != 0)
	{
		return 0;
	}

	std::vector<int> koefs1;
	std::vector<int> koefs2;
	size_t base = n / 3;
	size_t x = pow(10, base);

	koefs1.push_back(first % static_cast<int>(pow(10, base)));
	koefs2.push_back(second % static_cast<int>(pow(10, base)));


	koefs1.push_back(first % static_cast<int>(pow(10, base * 2)) / static_cast<int>(pow(10, base)));
	koefs2.push_back(second % static_cast<int>(pow(10, base * 2)) / static_cast<int>(pow(10, base)));

	koefs1.push_back(first / static_cast<int>(pow(10, base * 2)));
	koefs2.push_back(second / static_cast<int>(pow(10, base * 2)));


	std::vector<int> values1;
	std::vector<int> values2;
	std::vector<int> values3;

	for (size_t i = 0; i < points.size(); i++)
	{
		values1.push_back(horner(koefs1, points[i]));
		values2.push_back(horner(koefs2, points[i]));
	}
	std::cout << "\n";
	for (size_t i = 0; i < points.size(); i++)
	{
		int newValue = values1[i] * values2[i];
		values3.push_back(newValue);
	}

	std::vector<std::vector<int>>diffs = computeDividedDifferences(points, values3);

	std::vector<double>res = getNewtonCoefficients(diffs);

	std::vector<double>result{ res[0], (-6 * res[4] + 2 * res[3] - res[2] + res[1]) , (11 * res[4] - 3 * res[3] + res[2]) , (-6 * res[4] + res[3]) , res[4] };

	int final = 0;

	for (size_t i = 0; i < result.size(); i++)
	{
		final = final + (result[i] * pow(x, i));
	}
	return final;
}

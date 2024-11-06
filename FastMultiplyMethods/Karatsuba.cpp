#include <iostream>
#include <cmath>
#include "../../SystemOfLinearEquations/SoLE/SoLE.h"
#include "../../SystemOfLinearEquations/SoLE/SoLE.cpp"
#include "../../SystemOfLinearEquations/Matrix/Matrix.h"
#include "../../SystemOfLinearEquations/Matrix/Matrix.cpp"

miit::Matrix getMatrix(int& first, int& second, size_t n)
{
	int base = 100;
	int xHelp = first / pow(10, 2);
	int x2 = first / pow(10, 4);
	int x1 = xHelp % 100;
	int x0 = first % 100;
	std::vector<int> X{x2,x1,x0};

	int yHelp = second / pow(10, 2);
	int y2 = second / pow(10, 4);
	int y1 = yHelp % 100;
	int y0 = second % 100;
	std::vector<int> Y{ y2,y1,y0 };



	std::vector<int> koefs{ 0,1,-1,2,-2 };
	for (size_t i = 0; i < koefs.size(); i++)
	{
		for (size_t j = 0; j < Y.size(); j++)
		{
			X[j] * pow(koefs[i], 2);
		}
	}
	miit::Matrix m{ {1,0,0,0,0},{1,1,1,1,1},{1,-1,1,-1,1},{1,2,4,8,16},{1,-2,4,-8,16}};
	miit::Matrix m1 = m.inverse_default();
	
	return m1;
}	
/*
* @brief Функция умножающая 2 числа методом Карацубы
* @param first - первый множитель
* @param second - второй множитель
* @param n - кол-во разрядов в числах
* @return произведение двух чисел
*/
int karatsubaMul(int& first, int& second, size_t n);

int main()
{
	int left = 1234;
	int right = 5678;
	size_t n = 4;
	size_t n1 = 2;
	int left1 = 12;
	int right1 = 56;
	std::cout << karatsubaMul(left,right,n)  << "   " << 1234 * 5678;
	return 0;
}

int karatsubaMul(int& first, int& second, size_t n)
{
	if (n != 1)
	{
		size_t lowestBase = 1;
		int devider = pow(10, n / 2);
		int firstLeft = first / devider;
		int firstRight = first % devider;

		int secondLeft = second / devider;
		int secondRight = second % devider;

		int middle1 = firstRight + firstLeft;
		int middle2 = secondLeft + secondRight;

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
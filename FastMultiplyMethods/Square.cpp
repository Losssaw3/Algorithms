#include <iostream>
#include <vector>

/*
* brief функция представляющая число в десятичной записи в виде вектора с поразрядными компонентами первоначального числа в указанной системе счисления 
* param n - число в десятичной записи
* param base - основание системы счисления
* return вектор из поразрядных компонентов входного числа в указанной системе счисления
*/
std::vector<int> decimalToVector(int n, int base);
/*
* brief функция переводящая вектор поразрядных компонентов в десятичное число
* param vector - вектор из поразрядных компонентов числа
* return - число в десятичной записи
*/
int vectorToDecimal(const std::vector<int>& vector);

/*
* brief функция для быстрого возведения числа в квадрат
* param number число кооторое нуобходимо возвести
* param base система счисления в которой представлено число
* return квадрат входного числа в указанной системе счисления
*/
int fastSquare(int number, int base);

int main()
{
    int x = 256;
    std::cout << fastSquare(x, 10);
}


std::vector<int> decimalToVector(int n, int base)
{
    std::vector<int> binary;

    if (n == 0)
    {
        binary.push_back(0);
        return binary;
    }

    while (n > 0)
    {
        binary.push_back(n % base);
        n /= base;
    }

    return binary;
}

int vectorToDecimal(const std::vector<int>& vector)
{
    int base = 10;
    int decimal = 0;
    for (int i = 0; i < vector.size(); ++i) {
        decimal += vector[i] * std::pow(base, i);
    }
    return decimal;
}

int fastSquare(int number, int base)
{

    std::vector<int> vector = decimalToVector(number, base);

    int n = vector.size();

    std::vector<int> result(2 * n);
    std::vector<int> uv(3);
    std::vector<int> cuv(3);
    for (size_t i = 0; i <= n - 1; i++)
    {
        // c u v
        // 0 1 2 
        int uvDecimal = result[2 * i] + vector[i] * vector[i];
        uv[2] = (uvDecimal % base);
        uv[1] = (uvDecimal / base);
        result[2 * i] = uv[2];
        for (size_t j = i + 1; j <= n - 1; j++)
        {
            int cuvDecimal = result[i + j] + (2 * vector[i] * vector[j]) + uv[0] * base + uv[1];
            uv[0] = ((cuvDecimal / base) / base);
            uv[1] = ((cuvDecimal / base) % base);
            uv[2] = (cuvDecimal) % base;
            result[i + j] = uv[2];
        }
        if (i == n - 1)
        {
            int addNumber = result[i + n] + uv[0] * base + uv[1];
            result[i + n] = addNumber % base;
        }
        else
        {
            int addNumber = result[i + n + 1] * base + result[i + n] + uv[0] * base + uv[1];
            result[i + n + 1] = addNumber / base;
            result[i + n] = addNumber % base;
        }
    }
    int answer = vectorToDecimal(result);
    return answer;
}
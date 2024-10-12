#include <iostream>
#include <vector>
#include<random>
/**
* @brief ������� ��� ���������� ������� ���������� ����������
* 
* @param min - ����������� �������� ��������
* @param max - ������������ �������� ��������
* @param size - ������ �������
* @return mass - ���������� ������ ����������� ���������� ����������
*/
std::vector<int> random_gen(int min, int max, size_t size)
{
    std::vector<int> mass;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> uniformIntDistribution(min, max);
    for (size_t i = 0; i < size; i++)
    {
        mass.push_back(uniformIntDistribution(gen));
    }
    return mass;
}

/**
* @brief ������� ��������� � ����� ������ �������� �������
* @param vector - ������ �������� �������� ���������� �������� � ������ ������
*/
void printVector(std::vector<int>& vector)
{
    for (size_t i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << '\n';
    }
}

/**
* @brief ������� ��� ���������� ������� ������� �������
*
* @param vector ������ ������� �������� ���������� �������������
* @return vector - ������ ��������������� ������� ��������
*/
std::vector <int> insertionSort(std::vector<int>& vector)
{
    int counter = 0;
    for (size_t i = 1; i < vector.size(); i++)
    {
        int element = vector[i];
        int j = i - 1;
        while (j >= 0 and vector[j] > element)
{
            vector[j + 1] = vector[j];
            counter += 1;
            j--;
        }
        vector[j + 1] = element;
    }
    return vector;
}

/**
* @brief ������� ��� ���������� ������� ������� ������� ����������
* @param vector ������ ������� �������� ���������� ��������������
* @param counter ���-�� �������� ���������
* @return temp1 - ������ ��������������� ������� ������� ����������
*/
std::vector<int> quickSort(std::vector<int>& vector, size_t& counter)
{
    int min_size = 2;
    if (vector.size() < min_size) return vector;
    int current = vector[0];
    std::vector<int> vector1 {};
    std::vector<int> vector2 {};
 
    for (size_t j = 1; j < vector.size(); j++){
        {
            counter++;
            if (vector[j] < current)
                vector1.push_back(vector[j]);
            else
                vector2.push_back(vector[j]);
        }
    }
    std::vector<int> temp1 = quickSort(vector1, counter);
    std::vector<int> temp2 = quickSort(vector2, counter);
    temp1.push_back(current);
    temp1.insert(temp1.end(), temp2.begin(), temp2.end());
    return temp1;
}

/**
* @brief ������� ��� ���������� ������� ������� ��������
* @param vector ������ ������� �������� ���������� �������������
* @return vector - ������ ��������������� ������� ��������
*/
std::vector <int> bubbleSort(std::vector<int>& vector)
{
    int counter = 0;
    for (int i = 0; i < vector.size() - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < vector.size() - i - 1; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                std::swap(vector[j], vector[j + 1]);
                counter += 1;
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
    return vector;
}
int main()
{

    size_t max = 9999;
    size_t min = 0;
    size_t size = 10000;

    std::vector<int> list1 = random_gen(min, max, size);
    std::vector<int> list2 = random_gen(min, max, size);
    std::vector<int> list3 = random_gen(min, max, size);
    std::vector<int> insertionVector = insertionSort(list1);
    std::vector<int> bubbleVector = bubbleSort(list2);
    std::vector<int> quickSorted = quickSort(list3,min);
    printVector(quickSorted);
    return 0;
}

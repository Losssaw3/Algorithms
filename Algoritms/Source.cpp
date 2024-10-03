#include <iostream>
#include <vector>
#include<random>
int random_gen(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> uniformIntDistribution(min, max);
    return uniformIntDistribution(gen);
}

int insertionSort(std::vector<int>& list)
{
    int counter = 0;
    for (unsigned int i = 1; i < list.size(); i++) {
        int elem = list[i];
        int j = i - 1;
        while (j >= 0 and list[j] > elem) {
            list[j + 1] = list[j];
            counter += 1;
            j--;
        }
        list[j + 1] = elem;
    }
    return counter;
}

std::vector<int> quickSort(std::vector<int>& vector, size_t& counter)
{
    if (vector.size() < 2) return vector;
    int current = vector[0];
    std::vector<int> vector_1 {};
    std::vector<int> vector_2 {};
 
    for (size_t j = 1; j < vector.size(); j++){
        {
            counter++;
            if (vector[j] < current)
                vector_1.push_back(vector[j]);
            else
                vector_2.push_back(vector[j]);
        }
    }
    std::vector<int> temp_1 = quickSort(vector_1, counter);
    std::vector<int> temp_2 = quickSort(vector_2, counter);
    temp_1.push_back(current);
    temp_1.insert(temp_1.end(), temp_2.begin(), temp_2.end());
    return temp_1;
}


int bubbleSort(std::vector<int>& vector)
{
    int counter = 0;
    for (int i = 0; i < vector.size() - 1; i++)
    {
        // Track if a swap was made
        bool swapped = false;

        for (int j = 0; j < vector.size() - i - 1; j++)
        {
            if (vector[j] > vector[j + 1])
            {
                // Swap arr[j] and arr[j + 1]
                std::swap(vector[j], vector[j + 1]);
                counter += 1;
                swapped = true;
            }
        }
        // If no two elements were swapped, the array is sorted
        if (!swapped)
        {
            break;
        }
    }
    return counter;
}
int main()
{
    size_t max = 9999;
    size_t min = 0;
    std::vector<int> mass;
    for (size_t i = 0; i < 10000; i++)
    {
        mass.push_back(random_gen(min, max));
    }
    std::vector<int> result = quickSort(mass, min);
    int counter = insertionSort(mass);
    for (size_t i = 0; i < result.size(); i++)
    {
        std::cout << result[i] << '\n';
    }
    std::cout << counter;
    return 0;
}

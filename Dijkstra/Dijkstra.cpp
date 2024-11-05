#include <iostream>
#include <vector>
#include<random>
#include <algorithm>


/*
* @brief Функция генерирующая матрицу путей со случайными значаниями 
* @param node - кол-во узлов в графе
* @param min - минимальное значение элемента в графе
* @param max - максимальное значение элемента в графе
* @return PathMatrix матрицу путей со случайными значаниями 
*/
const std::vector<std::vector<int>> generatePathMatrix(size_t& node, size_t& min, size_t& max);


/*
* @brief Функция выводящая в поток вывода матрицу путей
* @param vector - матрица путей
* @param node - кол-во узлов в графе
*/
void prinPathMatrix(const std::vector<std::vector<int>>& vector, size_t node);

/*
* @brief Функция выводящая в поток вывода вектор с кратчайшими расстояниями
* @param vector - матрица путей
*/
void printSolution(std::vector<size_t>& vector);

/*
* @brief Функция ищущая индекс ненулевого элемента, игнорируя заранее заданные индексы
* @param  vector - вектор в котором необходимо найти индекс
* @param ignoredIndices - вектор индексов, которые необходимо пропускать при поиске
* @return minIndex индекс ненулевого элемента, игнорируя заранее заданные индексы
*/
size_t findMinNonZeroIndex(const std::vector<size_t>& vector, const std::vector<size_t>& ignoredIndices);

/*
* @brief Функция ищущая кратчайшие расстояние до всех узлов от заданного
* @param source - узел от которого надо найти расстояние до всех остальных узлов
* @param PathMatrix - матрица путей
* @return Paths - вектор из кратчайших путей из заданной точки до всех остальных узлов 
*/
std::vector<size_t> getShortestPath(size_t source, const std::vector<std::vector<int>> PathMatrix);

int main()
{
	try
	{
		size_t min = 3;
		size_t max = 20;
		size_t node = 6;
		size_t sourceNode = 7;
		const std::vector<std::vector<int>> m1 = generatePathMatrix(node, min, max);

		prinPathMatrix(m1, node);
		std::vector<size_t> sol = getShortestPath(sourceNode, m1);
		std::cout << "\n" << "---------------------------" << '\n';
		std::cout << "The sortest paths from node " << sourceNode << " (beginning from 0) to all " << '\n';
		printSolution(sol);
		return 0;
	}
	catch (const std::exception&)
	{
		std::exception();
	}
	
}

const std::vector<std::vector<int>> generatePathMatrix(size_t& node, size_t& min, size_t& max)
{

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> uniformIntDistribution(min, max);
	std::vector<std::vector<int>> PathMatrix(node, std::vector<int>(node));
	for (size_t i = 0; i < node; i++)
	{
		PathMatrix[i][i] = 0;
		for (size_t j = i + 1; j < node; j++)
		{
			size_t value = uniformIntDistribution(gen);
			PathMatrix[i][j] = value;
			PathMatrix[j][i] = value;
		}

	}
	return PathMatrix;
}

void prinPathMatrix(const std::vector<std::vector<int>>& vector, size_t node)
{

	for (size_t i = 0; i < node; i++)
	{
		for (size_t j = 0; j < node; j++)
		{
			std::cout << vector[i][j] << '\t';
		}
		std::cout << '\n';
	}
}

void printSolution(std::vector<size_t>& vector)
{
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << "\t";
	}
}

size_t findMinNonZeroIndex(const std::vector<size_t>& vector, const std::vector<size_t>& ignoredIndices)
{
	int minIndex = -1;
	int minValue = std::numeric_limits<int>::max();

	for (int i = 0; i < vector.size(); ++i)
	{
		if (vector[i] != 0 && std::find(ignoredIndices.begin(), ignoredIndices.end(), i) == ignoredIndices.end())
		{
			if (vector[i] < minValue)
			{
				minValue = vector[i];
				minIndex = i;
			}
		}
	}

	return minIndex;
}

std::vector<size_t> getShortestPath(size_t source, const std::vector<std::vector<int>> PathMatrix)
{

	int inf = std::numeric_limits<int>::max();
	size_t matrixSize = PathMatrix[0].size();

	std::vector<size_t>Paths(matrixSize);
	for (size_t i = 0; i < matrixSize; i++)
	{
		Paths[i] = inf;
	}
	Paths[source] = 0;

	std::vector<size_t>wasHere;
	wasHere.push_back(source);

	for (size_t i = 0; i < matrixSize; i++)
	{
		for (size_t j = 0; j < matrixSize; j++)
		{
			if (Paths[j] > PathMatrix[wasHere[i]][j] + Paths[wasHere[i]])
			{
				Paths[j] = PathMatrix[wasHere[i]][j] + Paths[wasHere[i]];
			}
		}
		if (wasHere.size() == matrixSize)
		{
			break;
		}
		else
		{
			size_t min = findMinNonZeroIndex(Paths, wasHere);
			wasHere.push_back(min);
		}

	}
	return Paths;
}
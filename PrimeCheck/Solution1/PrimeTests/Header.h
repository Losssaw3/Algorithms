#pragma once
#include <iostream>
#include <random>
/*
*@brief getRandomNumber - ������� ��� ��������� ���������� ����� � ���������
*@param - max ������������ �������� � ���������
*@param - min ����������� �������� � ���������
*@return ���������� ��������� ����� � �������� ���������
*/
int getRandomNumber(int max, int min);

/*
*@brief modExp - ������� ��� ��������� ������� �� ����� � �������
*@param - base ��������� �������
*@param - exp ������� � ������� ���� �������� ���������
*@param - mod ����� ������� �� �������� ���� �����
*@return ���������� ������� �� ������� base � ������� exp �� mod
*/
long long modExp(long long base, long long exp, long long mod);

/*
*@brief FermaTest - ������� ��� �������� ����� �� �������� ������� �����
*@param - n ����� �� ��������
*@param - t ������� �������
*@return true - ���� ����� ������� false - ���� ����� ���������
*/
bool FermaTest(int n, size_t t);

/*
*@brief JacobiSigh - ������� ����������� ������ ����� ��� ���� ����� a , n
*@param - a ��������� � ����� �����
*@param - n ����������� � ����� �����
*@return ������ �����
*/
int JacobiSign(size_t a, size_t  n);

/*
*@brief SoloveiShtrassen - ������� ��� �������� ����� �� �������� ������� �������-���������
*@param - n ����� �� ��������
*@param - t ������� �������
*@return true - ���� ����� ������� false - ���� ����� ���������
*/
bool SoloveiShtrassen(int n, size_t t);

/*
*@brief MillerRabin - ������� ��� �������� ����� �� �������� ������� ������� - ������
*@param - n ����� �� ��������
*@param - t ������� �������
*@return true - ���� ����� ������� false - ���� ����� ���������
*/
bool MillerRabin(int n, size_t t);
#pragma once
#include <iostream>
#include <random>
/*
*@brief getRandomNumber - функци€ дл€ получени€ случайного числа в диапозоне
*@param - max максимальное значение в диапозоне
*@param - min минимальное значение в диапозоне
*@return возвращает случайное число в заданном диапозоне
*/
int getRandomNumber(int max, int min);

/*
*@brief modExp - функци€ дл€ получени€ остатка от числа в степени
*@param - base основание степени
*@param - exp степень в которую надо возвести основание
*@param - mod число остаток по каторому надо брать
*@return возвращает остаток от делени€ base в степени exp на mod
*/
long long modExp(long long base, long long exp, long long mod);

/*
*@brief FermaTest - функци€ дл€ проверки числа на простоту методом ‘ерма
*@param - n число на проверку
*@param - t степень довери€
*@return true - если число простое false - если число составное
*/
bool FermaTest(int n, size_t t);

/*
*@brief JacobiSigh - функци€ вычисл€юща€ символ якоби дл€ пары чисел a , n
*@param - a числитель в знаке якоби
*@param - n знаменатель в знаке якоби
*@return —имвол якоби
*/
int JacobiSign(size_t a, size_t  n);

/*
*@brief SoloveiShtrassen - функци€ дл€ проверки числа на простоту методом —олове€-Ўтрассена
*@param - n число на проверку
*@param - t степень довери€
*@return true - если число простое false - если число составное
*/
bool SoloveiShtrassen(int n, size_t t);

/*
*@brief MillerRabin - функци€ дл€ проверки числа на простоту методом ћиллера - –абина
*@param - n число на проверку
*@param - t степень довери€
*@return true - если число простое false - если число составное
*/
bool MillerRabin(int n, size_t t);
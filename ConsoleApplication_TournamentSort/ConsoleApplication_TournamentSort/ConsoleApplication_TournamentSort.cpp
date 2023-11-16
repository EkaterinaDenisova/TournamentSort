// ConsoleApplication_TournamentSort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "TournamentSort.h"

//
int main()
{
    setlocale(LC_ALL, "ru");
    int arr[] = { 7, 38, 89, INT_MAX, 165, 56, -2, INT_MIN, -31, 648, 5125, 5126  };
    //int arr[] = { 12, 6 };
    int arrLength = 12;

    cout << "Исходный массив: ";

    // вывод массива
    for (int i = 0; i < arrLength; i++) {
        cout << arr[i] << " ";
    }

    tournamentSort(arr, arrLength);
    cout << endl;
    cout << "Отсортированный массив: ";

    // вывод массива
    for (int i = 0; i < arrLength; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}


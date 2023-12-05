#pragma once
//@author Денисова Екатерина

#include <algorithm>
#include <iostream>
#include "climits"
using namespace std;

// турнирная сортировка массива
// по возрастанию
void tournamentSort(int arr[], int arrLength)
{
    // Определение размера дерева для турнирной сортировки
    // дерево должно быть полным, т.е. количество узлов равно какой-то степени двойки
    int treeSize = 1;
    while (treeSize <= arrLength) {
        treeSize *= 2;
    }
    // вместо цикла использовать логарифм

    // создание динамического массива размерностью, равной количеству узлов в дереве * 2
    int size = (2 * treeSize);
    int* tree = new int[size];

    // каждому узлу присвоить значение максимального для данного типа данных (int)
    for (int i = 0; i < size; i++) {
        tree[i] = INT_MAX;
    }

    // присвоить элементы массива второй половине дерева
    for (int i = 0; i < arrLength; i++) {
        tree[treeSize + i] = arr[i];
    }


    // вывод массива
    /*cout << "\n\n\n\n";
    for (int i = 0; i < size; i++) {
        cout << tree[i] << " ";
    } cout << "\n\n\n\n";*/


    // сортировка путём выбора минимального элемента из каждой пары чисел
    // начинаем с нижнего уровня дерева
    for (int i = treeSize - 1; i >= 1; i--) {
        // родителю присваивается наименьшее из его потомков
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    } //cout << endl;


    // вывод массива
    /*for (int i = 0; i < size; i++) {
        cout << tree[i] << " ";
    } cout << "\n\n\n";*/

    // Достаём элементы из дерева в возрастающем порядке
    int sortIndex = 0;
    // пока не запишем в массив все элементы
    while (sortIndex < arrLength) {

        // Присвоение корня исходному массиву (т.е. минимального элемента)
        arr[sortIndex] = tree[1];

        // увеличиваем счётчик записанных элементов отсортированного массива на 1
        sortIndex++;

        // присвоение корню максимального значения для int
        tree[1] = INT_MAX;

        // индекс первого узла
        int node = 1;
        // в данном цикле из tree удаляются все дубликаты узла, который уже достали из корня в исходный массив
        while (node < treeSize) {
            int leftChild = 2 * node;
            int rightChild = 2 * node + 1;

            // находим индекс наименьшего узла из потомков
            if (tree[leftChild] < tree[rightChild]) {
                node = leftChild;
            }
            else {
                node = rightChild;  
            }

            // этому наименьшему узлу присваиваем максимальное значение для int
            tree[node] = INT_MAX;

            // вывод массива
            /*for (int i = 0; i < size; i++) {
                cout << tree[i] << " ";
            } cout << "\n\n";*/
        }

        // выбор минимального элемента из каждой пары чисел
        for (int i = treeSize - 1; i >= 1; i--) {
            // родителю присваивается наименьшее из его потомков
            tree[i] = min(tree[2 * i], tree[2 * i + 1]);
        }

        // вывод массива
        /*for (int i = 0; i < size; i++) {
            cout << tree[i] << " ";
        } cout << "\n\n\n\n";*/
    }

    delete[] tree;
}
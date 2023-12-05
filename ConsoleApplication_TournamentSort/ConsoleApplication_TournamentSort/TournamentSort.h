#pragma once
//@author �������� ���������

#include <algorithm>
#include <iostream>
#include "climits"
using namespace std;

// ��������� ���������� �������
// �� �����������
void tournamentSort(int arr[], int arrLength)
{
    // ����������� ������� ������ ��� ��������� ����������
    // ������ ������ ���� ������, �.�. ���������� ����� ����� �����-�� ������� ������
    int treeSize = 1;
    while (treeSize <= arrLength) {
        treeSize *= 2;
    }
    // ������ ����� ������������ ��������

    // �������� ������������� ������� ������������, ������ ���������� ����� � ������ * 2
    int size = (2 * treeSize);
    int* tree = new int[size];

    // ������� ���� ��������� �������� ������������� ��� ������� ���� ������ (int)
    for (int i = 0; i < size; i++) {
        tree[i] = INT_MAX;
    }

    // ��������� �������� ������� ������ �������� ������
    for (int i = 0; i < arrLength; i++) {
        tree[treeSize + i] = arr[i];
    }


    // ����� �������
    /*cout << "\n\n\n\n";
    for (int i = 0; i < size; i++) {
        cout << tree[i] << " ";
    } cout << "\n\n\n\n";*/


    // ���������� ���� ������ ������������ �������� �� ������ ���� �����
    // �������� � ������� ������ ������
    for (int i = treeSize - 1; i >= 1; i--) {
        // �������� ������������� ���������� �� ��� ��������
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    } //cout << endl;


    // ����� �������
    /*for (int i = 0; i < size; i++) {
        cout << tree[i] << " ";
    } cout << "\n\n\n";*/

    // ������ �������� �� ������ � ������������ �������
    int sortIndex = 0;
    // ���� �� ������� � ������ ��� ��������
    while (sortIndex < arrLength) {

        // ���������� ����� ��������� ������� (�.�. ������������ ��������)
        arr[sortIndex] = tree[1];

        // ����������� ������� ���������� ��������� ���������������� ������� �� 1
        sortIndex++;

        // ���������� ����� ������������� �������� ��� int
        tree[1] = INT_MAX;

        // ������ ������� ����
        int node = 1;
        // � ������ ����� �� tree ��������� ��� ��������� ����, ������� ��� ������� �� ����� � �������� ������
        while (node < treeSize) {
            int leftChild = 2 * node;
            int rightChild = 2 * node + 1;

            // ������� ������ ����������� ���� �� ��������
            if (tree[leftChild] < tree[rightChild]) {
                node = leftChild;
            }
            else {
                node = rightChild;  
            }

            // ����� ����������� ���� ����������� ������������ �������� ��� int
            tree[node] = INT_MAX;

            // ����� �������
            /*for (int i = 0; i < size; i++) {
                cout << tree[i] << " ";
            } cout << "\n\n";*/
        }

        // ����� ������������ �������� �� ������ ���� �����
        for (int i = treeSize - 1; i >= 1; i--) {
            // �������� ������������� ���������� �� ��� ��������
            tree[i] = min(tree[2 * i], tree[2 * i + 1]);
        }

        // ����� �������
        /*for (int i = 0; i < size; i++) {
            cout << tree[i] << " ";
        } cout << "\n\n\n\n";*/
    }

    delete[] tree;
}
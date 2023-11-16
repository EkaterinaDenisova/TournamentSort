#include "pch.h"
#include "vector"
#include "../ConsoleApplication_TournamentSort/TournamentSort.h"
//@author �������� ���������

// ������������ ������� ��������� ����������
TEST(TestSort, TestTournamentSort) {

	// ������ �� ���� ���������
	int arr[] = { 1, 12 };
	int arrLength = 2;

	tournamentSort(arr,arrLength);
	vector<int> v = { 1, 12 };
	vector<int> v1;
	for (int i = 0; i < arrLength; i++) {
		v1.push_back(arr[i]);
	}

    EXPECT_EQ(v, v1);
	v.clear(); v1.clear();
  

	// ������ �� ������ ��������
	int arr1[] = { -2 };
	arrLength = 1;

	tournamentSort(arr1, arrLength);
	v = { -2 };
	for (int i = 0; i < arrLength; i++) {
		v1.push_back(arr1[i]);
	}

	EXPECT_EQ(v, v1);
	v.clear(); v1.clear();


	// ������ ������
	int* arr2 = nullptr;
	arrLength = 0;

	tournamentSort(arr2, arrLength);
	EXPECT_EQ(arr2,nullptr);
	v = { };
	for (int i = 0; i < arrLength; i++) {
		v1.push_back(arr2[i]);
	}

	EXPECT_EQ(v, v1);
	v.clear(); v1.clear();

	// ������ �� ���������� max_int � min_int
	int arr3[] = {7, 38, 89, INT_MAX, 165, 56, -2, INT_MIN, -31, 648, 5125, 5126};
	arrLength = 12;

	tournamentSort(arr3, arrLength);
	v = { INT_MIN, -31, -2, 7, 38, 56, 89, 165,  648, 5125, 5126, INT_MAX};
	for (int i = 0; i < arrLength; i++) {
		v1.push_back(arr3[i]);
	}

	EXPECT_EQ(v, v1);
	v.clear(); v1.clear();

}
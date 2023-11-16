#include "pch.h"
#include "vector"
#include "../ConsoleApplication_TournamentSort/TournamentSort.h"
//@author Денисова Екатерина

// тестирование функции турнирной сортировки
TEST(TestSort, TestTournamentSort) {

	// массив из двух элементов
	int arr[] = { 1, 12 };
	int arrLength = 2;

	tournamentSort(arr,arrLength);
	vector<int> v = { 1, 12 };
	vector<int> v1;
	for (int i = 0; i < arrLength; i++) {
		v1.push_back(arr[i]);
	}

    EXPECT_EQ(v, v1);
  



}
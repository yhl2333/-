#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
using namespace std;

class Ssort {
public:
	void Insert_sort(vector<int>& v)
	{
		int tmp;

		int j;
		for (int i = 1; i < v.size(); i++)
		{
			tmp = v[i];
			for (j = i - 1; j >= 0 && v[j] > tmp; j--)
			{
				v[j + 1] = v[j];
			}
			v[j + 1] = tmp;
		}
	}

	void Shell_sort(vector<int>& v)
	{
		int n = v.size();

		for (int gap = n / 2; gap > 0; gap /= 2) 
		{
			for (int i = gap; i < n; i++) 
			{
				int temp = v[i];
				int j;

				for (j = i; j >= gap && v[j - gap] > temp; j -= gap) 
				{
					v[j] = v[j - gap];
				}

				v[j] = temp;
			}
		}
	}

	void Bubble_sort(vector<int>& v)
	{
		for (int i = 0; i < v.size(); i++)
		{
			int j;
			for (j = 0; j < v.size() - i-1; j++)
			{
				if (v[j] > v[j + 1])
				{
					int temp = v[j + 1];
					v[j + 1] = v[j];
					v[j] = temp;
				}
			}
		}
	}
	
	void Quick_sort(vector<int>& v)
	{
		int n = v.size();
		quickSort(v,0,n-1);
	}

	void quickSort(vector<int>& v, int low, int high)
	{
		if (low < high)
		{
			int pivotIndex = partition(v, low, high);
			quickSort(v, low, pivotIndex - 1);
			quickSort(v, pivotIndex + 1, high);
		}
	}

	int partition(vector<int>& v, int low, int high) {
		
		int i = low;
		int j = high;
		int pivot = v[i]; // 选择第一个元素作为划分点
		while (i < j)
		{
			while (i < j && v[j] >= pivot)
				j--;
			if (i < j)
			{
				v[i] = v[j];
				i++;
			}
			while (i < j && v[i] < pivot)
				i++;
			if (i < j)
			{
				v[j] = v[i];
				j--;
			}

		}
		v[i] = pivot;
		return i;
	}



	vector<int> generateRandomArray(int size) {
		vector<int> arr(size);
		srand(time(0));
		for (int i = 0; i < size; i++) {
			arr[i] = rand();
		}
		return arr;
	}

	void write_sort(vector<int>& v)
	{
		for (vector<int>::iterator ite = v.begin(); ite != v.end(); ite++)
		{
			cout << *ite;
			cout << endl;
		}
	}
};
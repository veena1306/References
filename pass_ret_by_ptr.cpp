#include <iostream>

void f1(int num)
{
	num = 5; // num is a local variable, destroyed at the end of the function scope!
}

void f1byAddress(int* num)
{
	*num = 5;
}

void findMinMax(int* arr, int size, int* min, int* max)
{
	*min = *max = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (arr[i] < *min)
			*min = arr[i];
		else
			if (arr[i] > *max)
				*max = arr[i];
	}
}
int main()
{
	int n = 3;
	f1(n);
	std::cout << n << std::endl;
	f1byAddress(&n);
	std::cout << n << std::endl;

	int arr[5]{ 3,2,1,5,4 };
	int min = 0, max = 0;
	findMinMax(arr, 5, &min, &max);
	std::cout << min << " " << max << std::endl;
	return 0;
}

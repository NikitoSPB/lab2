#include <iostream>
#include <chrono>

#define countElements 10
#define countSwap 1000
#define minValue -99
#define maxValue 99
#define kComboSort 1.247

using namespace std;
using namespace chrono;

void new_array(int* new_array)
{
	srand((unsigned int)time(NULL));
	int * f_endArray = new_array + countElements - 1;
	for (int* i = new_array; i <= f_endArray; i++)
	{
		*i = rand() % (maxValue - minValue) + minValue;
	}
}

void change(int* arr, int f_i1, int f_i2)
{
	int f_value = *(arr + f_i1);
	*(arr + f_i1) = *(arr + f_i2);
	*(arr + f_i2) = f_value;
}

void print(int* arr)
{
	int* f_endArray = arr + countElements - 1;
	for (int* f_i = arr; f_i <= f_endArray; f_i++)
		cout << "{" << *f_i << "} ";
	cout << "\n\n";
}

void bubbleSort(int* arr)
{
	int * f_endArray = arr + countElements - 1;
	for (int *f_i = arr; f_i < f_endArray; f_i++)
	{
		for (int *f_j = arr; f_j < (f_endArray - (f_i - arr)); f_j++)
		{
			if (*(f_j) > *(f_j + 1))
				change(arr, f_j - arr + 1, f_j - arr);
		}
	}
}

void insertSort(int* arr)
{
	int* f_endArray = arr + countElements;
	for (int *f_i = arr + 1; f_i < f_endArray; f_i++)
	{
		int elem = *f_i, pos = f_i - arr;
		for (int *f_j = f_i - 1; f_j >= arr && *f_j > elem; f_j--)
		{
			*(f_j + 1) = *f_j;
			pos--;
		}
		*(arr + pos) = elem;
	}
}

void shakerSort(int* arr)
{
	int *first = arr, *last = arr + countElements - 1;
	while (first < last)
	{
		for (int *f_i = first; f_i < last; f_i++)
		{
			if (*f_i > *(f_i + 1))
				change(arr, f_i - arr, f_i - arr + 1);
		}
		last--;
		for (int *f_i = last; f_i > first; f_i--)
		{
			if (*(f_i - 1) > *f_i)
				change(arr, f_i - arr, f_i - arr - 1);
		}
		first++;
	}
}

void combSort(int* arr, int temp)
{
	int* f_endArray = arr + countElements - 1;
	while (temp >= 1)
	{
		for (int* f_i = arr; f_i + temp <= f_endArray; f_i++)
		{
			if (*f_i > *(f_i + temp))
				change(arr, f_i - arr, f_i - arr + temp);
		}
		temp /= kComboSort;
	}
}

void quickSort(int* arr, int* begin, int* end)
{
	int* first = begin,* last = end;
	int middle = *(first + ((last - first)/2));
	while (first < last)
	{
		while (*first < middle)
			first++;
		while (*last > middle)
			last--;
		if (first <= last)
		{
			change(arr, first - arr, last - arr);
			first++;
			last--;
		}
	}
	if (begin < last)
		quickSort(arr, begin, last);
	if (first < end)
		quickSort(arr, first, end);
}

void sort(int* sArr)
{
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start1, end1;
	nanoseconds result1;
	int punktSort;
	cout << "Which sort do you want to use? Choose the number\n"
		<< "1 - Bubble\n"
		<< "2 - Shaker\n"
		<< "3 - Comb\n"
		<< "4 - Insert\n"
		<< "5 - Quick\n"
		<< "0 - Exit in menu\n\n";
	cin >> punktSort;
	switch (punktSort)
	{
	case 1:
		start1 = steady_clock::now();
		bubbleSort(sArr);
		end1 = steady_clock::now();
		result1 = duration_cast<nanoseconds>(end1 - start1);
		cout << "Time: ";
		cout << result1.count();
		cout << "ns";
		cout << "\nSort array.\n";
		print(sArr);
		system("Pause");
		break;
	case 2:
		start1 = steady_clock::now();
		shakerSort(sArr);
		end1 = steady_clock::now();
		result1 = duration_cast<nanoseconds>(end1 - start1);
		cout << "Time: ";
		cout << result1.count();
		cout << "ns";
		cout << "\nSort array.\n";
		print(sArr);
		system("Pause");
		break;
	case 3:
		start1 = steady_clock::now();
		combSort(sArr, countElements - 1);
		end1 = steady_clock::now();
		result1 = duration_cast<nanoseconds>(end1 - start1);
		cout << "Time: ";
		cout << result1.count();
		cout << "ns";
		cout << "\nSort array.\n";
		print(sArr);
		system("Pause");
		break;
	case 4:
		start1 = steady_clock::now();
		insertSort(sArr);
		end1 = steady_clock::now();
		result1 = duration_cast<nanoseconds>(end1 - start1);
		cout << "Time: ";
		cout << result1.count();
		cout << "ns";
		cout << "\nSort array.\n";
		print(sArr);
		system("Pause");
		break;
	case 5:
		start1 = steady_clock::now();
		quickSort(sArr, sArr, sArr + countElements - 1);
		end1 = steady_clock::now();
		result1 = duration_cast<nanoseconds>(end1 - start1);
		cout << "Time: ";
		cout << result1.count();
		cout << "ns";
		cout << "\nSort array.\n";
		print(sArr);
		system("Pause");
		break;
	case 0:
		break;
	default:
		cout << "Error! Repeat, please.";
		system("Pause");
		sort(sArr);
		break;
	}
}

int searchMinMax(int* arr)
{
	int min = *arr, max = *arr, * f_endArray = arr + countElements - 1;
	for (int *f_i = arr+1; f_i <= f_endArray; f_i++)
	{
		if (*f_i > max)
			max = *f_i;
		else if (*f_i < min)
			min = *f_i;
	}
	cout << "Min = " << min << " Max = " << max << "\n";
	return (min + max) / 2;
}

void middleValue(int* arr, int middle)
{
	int counter = 0, * f_endArray = arr + countElements - 1;
	cout << "Indexes: ";
	for (int *f_i = arr; f_i <= f_endArray; f_i++)
	{
		if (*f_i == middle)
		{
			cout << "[" << f_i - arr << "] ";
			counter++;
		}
	}
	cout << "\nAmount of elements: " << counter << "\n\n";
}

void searchA(int* arr, int f_a)
{
	int *f_i = arr,* f_endArray = arr + countElements - 1;
	while ((*f_i < f_a) && (f_i <= f_endArray))
		f_i++;
	cout << f_i - arr << " elements low, than a = " << f_a << "\n\n";
}

void searchB(int* arr, int f_b)
{
	int* f_i = arr, * f_endArray = arr + countElements - 1;
	while ((*f_i <= f_b) && (f_i <= f_endArray))
		f_i++;
	cout << f_endArray - f_i << " elements high, than b = " << f_b << "\n\n";
}

int binSearch(int* arr, int f_number, int start, int end)
{
	if (end >= start) {
		int mid = start + (end - start) / 2;

		if (*(arr + mid - 1) == f_number) {
			return mid;
		}
		else if (*(arr + mid - 1) > f_number) {
			return binSearch(arr, f_number, start, mid - 1);
		}
		return binSearch(arr, f_number, mid + 1, end);
	}

	return -1;
}

void uSearch(int* arr, int f_number)
{
	int* f_endArray = arr + countElements - 1;
	for (int* i = arr; i < f_endArray; i++)
	{
		if (*i == f_number)
		{
			cout << "Number is in this array on position " << i-arr+1 << "\n";
			return;
		}
	}
	cout << "Number not in this array" << "\n";
}

void idz(int* arr)
{
	cout << "Sum elements\n";
	int f_number = *arr, * f_endArray = arr + countElements - 1;
	for (int* i = arr; i <= f_endArray - 1; i++)
		*i += *(i + 1);
	*f_endArray += f_number;
	print(arr);
	for (int* i = arr; i < f_endArray; i++)
		change(arr, i - arr, rand() % countElements);
	cout << "Change elements\n";
	print(arr);
	int arr2[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	for (int* i = arr; i <= f_endArray; i++)
	{
		for (int j = 2; j <= 9; j++)
		{
			if ((*i) % j == 0)
				(*(arr2 + j - 2))++;
		}
	}
	cout << countElements << " numbers are divisible by " << 1 << '\n';
	for (int* i = arr2; i <= arr2 + 7; i++)
		cout << *i << " numbers are divisible by " << i - arr2 + 2 << '\n';
}

void menu()
{
	time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
	nanoseconds result;
	system("cls");
	int array[countElements], number, flag_bin, t_counter, itemMenu, mid,* t_arr = NULL;
	cout << "What operation you want to perform? Enter a number from 1 to 9:\n"
		<< "1 - Create a new array\n"
		<< "2 - Sort array\n"
		<< "3 - Search max and min\n"
		<< "4 - Print the average value of max and min in the array, indexes and count of this values.\n"
		<< "5 - Print elements low number ""a"" in sort array\n"
		<< "6 - Print elements high number ""b"" in sort array\n"
		<< "7 - Search number in sort array\n"
		<< "8 - Change elements\n"
		<< "9 - Make IDZ\n"
		<< "0 - Exit\n\n";
	cin >> itemMenu;
	system("cls");
	switch (itemMenu)
	{
	case 1:
		new_array(array);
		print(array);
		system("Pause");
		menu();
		break;
	case 2:
		cout << "A new array has been created.\n";
		new_array(array);
		print(array);
		system("Pause");
		sort(array);
		menu();
		break;
	case 3:
		cout << "A new array has been created.\n";
		new_array(array);
		print(array);
		cout << "Search min and max in not sort array.\n";
		start = steady_clock::now();
		mid = searchMinMax(array);
		end = steady_clock::now();
		result = duration_cast<nanoseconds>(end - start);
		cout << "Time: ";
		cout << result.count();
		cout << " ns\n\n";
		quickSort(array, array, array + countElements - 1);
		cout << "Search min and max in sort array.\n";
		print(array);

		start = steady_clock::now();
		cout << "Min = " << *array << " Max = " << *(array + countElements - 1) << '\n';
		end = steady_clock::now();
		result = duration_cast<nanoseconds>(end - start);
		cout << "Time: ";
		cout << result.count();
		cout << " ns\n\n";
		system("Pause");
		menu();
		break;
	case 4:
		cout << "A new array has been created.\n";
		new_array(array);
		print(array);
		cout << "Search middle value in not sort array.\n";
		mid = searchMinMax(array);
		cout << "Middle value: " << mid << '\n';
		start = steady_clock::now();
		middleValue(array, mid);
		end = steady_clock::now();
		result = duration_cast<nanoseconds>(end - start);
		cout << "Time: ";
		cout << result.count();
		cout << " ns\n\n";
		quickSort(array, array, array + countElements - 1);
		cout << "Search middle value in sort array.\n";
		print(array);
		mid = (*array + *(array + countElements - 1)) / 2;
		cout << "Middle value: " << mid << '\n';
		t_arr = array;
		start = steady_clock::now();
		while (*t_arr < mid)
			t_arr++;
		if (*t_arr != mid)
			cout << "Amount of elements : 0\n";
		else
		{
			t_counter = 0;
			cout << "Indexes: ";
			while (*t_arr == mid)
			{
				cout << '[' << t_arr - array << "] ";
				t_counter++;
				t_arr++;
			}
			cout << "\nAmount of elements :" << t_counter << '\n';
		}
		end = steady_clock::now();
		result = duration_cast<nanoseconds>(end - start);
		cout << "Time: ";
		cout << result.count();
		cout << " ns\n\n";
		system("Pause");
		menu();
		break;
	case 5:
		cout << "A new array has been created.\n";
		new_array(array);
		quickSort(array, array, array + countElements - 1);
		print(array);
		cout << "Input the number.\n";
		int a;
		cin >> a;
		searchA(array, a);
		system("Pause");
		menu();
		break;
	case 6:
		cout << "A new array has been created.\n";
		new_array(array);
		quickSort(array, array, array + countElements - 1);
		print(array);
		cout << "Input the number.\n";
		int b;
		cin >> b;
		searchB(array, b);
		system("Pause");
		menu();
		break;
	case 7:
		cout << "A new array has been created.\n";
		new_array(array);
		quickSort(array, array, array + countElements - 1);
		print(array);
		cout << "Input the number.\n";
		cin >> number;
		cout << "Binary search.\n";
		start = steady_clock::now();
		flag_bin = binSearch(array, number, 0, countElements-1);
		end = steady_clock::now();
		result = duration_cast<nanoseconds>(end - start);
		if (flag_bin == -1)
			cout << "Number not in this array\n";
		else
			cout << "Number is in this array on position " << flag_bin << '\n';
		cout << "Time: ";
		cout << result.count();
		cout << " ns\n\n";
		cout << "Brut search.\n";
		start = steady_clock::now();
		uSearch(array, number);
		end = steady_clock::now();
		result = duration_cast<nanoseconds>(end - start);
		cout << "Time: ";
		cout << result.count();
		cout << " ns\n\n";
		system("Pause");
		menu();
		break;
	case 8:
		cout << "A new array has been created.\n";
		new_array(array);
		print(array);
		cout << "Input the indexes.\n";
		int i1, i2;
		while (true)
		{
			cin >> i1 >> i2;
			if (((i1 < 0) || (i1 > countElements - 1)) || ((i2 < 0) || (i2 > countElements - 1)) || (i1 == i2))
				cout << "Error! Repeat, please.";
			else
				break;
			system("Pause");
		}
		start = steady_clock::now();
		change(array, i1, i2);
		end = steady_clock::now();
		result = duration_cast<nanoseconds>(end - start);
		cout << "Time: ";
		cout << result.count();
		cout << " ns\n\n";
		cout << "\nA new array after changing.\n";
		print(array);
		system("Pause");
		menu();
		break;
	case 9:
		cout << "A new array has been created.\n";
		new_array(array);
		print(array);
		idz(array);
		system("Pause");
		menu();
		break;
	case 0:
		exit(1);
		break;
	default:
		cout << "Error! Repeat, please.";
		system("Pause");
		menu();
		break;
	}
}

int main()
{
	menu();
	return 0;
}
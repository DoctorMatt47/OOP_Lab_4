#include <functional>
#include <numeric>
#include <iostream>
#include <any>
#include <string>


#include "Dice Files/Set.h"
#include "Lists Files/LinkedList.h"
#include "Lists Files/VectorList.h"
#include "Lists Files/ArrayList.h"
#include "Lists Files/ListSorter.h"
#include "Lists Files/Iterators/NodeIterator.h"

using namespace std;

int state;
int func;

void MainMenu();
void CreateList();
int SortMenu();
int ProbMenu();
int MethodSort();

template <class T>
void LinkedListFunctions();

template <class T>
void ArrayListFunctions();

template <class T>
void VectorListFunctions();

template <class T>
bool Predicate(T t1, T t2);
template <>
bool Predicate<int>(int t1, int t2);
template <>
bool Predicate<double>(double t1, double t2);
template <>
bool Predicate<string>(string t1, string t2);
template <>
bool Predicate<vector<int>>(vector<int> t1, vector<int> t2);
template <>
bool Predicate<Dice>(Dice t1, Dice t2);
template <>
bool Predicate<Set>(Set t1, Set t2);
template <class T>
bool PredicateDesc(T t1, T t2);
template <>
bool PredicateDesc<int>(int t1, int t2);
template <>
bool PredicateDesc<double>(double t1, double t2);
template <>
bool PredicateDesc<string>(string t1, string t2);
template <>
bool PredicateDesc<vector<int>>(vector<int> t1, vector<int> t2);
template <>
bool PredicateDesc<Dice>(Dice t1, Dice t2);
template <>
bool PredicateDesc<Set>(Set t1, Set t2);

template <class T>
float FloatField(T t);
template <>
float FloatField(double t);

template <class T>
size_t IntField(T t);
template <>
size_t IntField<int>(int t);

void GetFromConsole(int& t);
void GetFromConsole(double& t);
void GetFromConsole(string& t);
void GetFromConsole(vector<int>& t);
void GetFromConsole(Dice& t);

void Print(IList<int>& list);
void Print(IList<double>& list);
void Print(IList<string>& list);
void Print(IList<vector<int>>& list);
void Print(IList<Dice>& list);

void Random(IList<int>& list);
void Random(IList<double>& list);
void Random(IList<string>& list);
void Random(IList<vector<int>>& list);
void Random(IList<Dice>& list);

void PrintDouble(const double& t)
{
	cout << t << ", ";
}

void PrintString(const string& t)
{
	cout << t << endl;
}

void PrintVector(vector<pair<int, char>> t)
{
	for (auto& value : t)
		cout << value.first << "|" << value.second << ",  ";
	cout << endl;
}

void Start();

int main()
{
	Start();
}

void Start()
{
	MainMenu();
	while (state > 0 && state < 3)
	{
		switch (state)
		{
		case 1:
			{
				CreateList();
				MainMenu();
				break;
			}
		case 2:
			{
				Set s1;
				auto st = 1;
				st = ProbMenu();
				while (st > 0 && st <= 4)
				{
					switch (st)
					{
					case 1:
						s1.InitializeWithConsole();
						st = ProbMenu();
						break;
					case 2:
						s1.RandomInitialize();
						st = ProbMenu();
						break;
					case 3:
						system("cls");
						s1.Print();
						system("pause");
						st = ProbMenu();
						break;
					case 4:
						system("cls");
						s1.FindProbabilityForSums();
						system("pause");
						st = ProbMenu();
						break;
					default:
						break;
					}
				}
				MainMenu();
			}
			break;
		default:
			break;
		}
	}
}

int ProbMenu()
{
	system("cls");
	
	cout <<
		"0.Exit" << endl <<
		"1.Initialize with console" << endl <<
		"2.Random initialize" << endl <<
		"3.Print" << endl <<
		"4.Find probability" << endl;
	int g;
	cin >> g;
	return g;
}

void MainMenu()
{
	system("cls");
	
	cout <<
		"Main menu:" << endl <<
		"0.Exit" << endl <<
		"1.Create list" << endl <<
		"2.Find set probability" << endl;
	cin >> state;
}

void CreateList()
{
	int typeOfList;
	int typeOfData;
	
	system("cls");
	cout <<
		"Choose type of list:" << endl <<
		"0.Exit" << endl <<
		"1.Create linked list" << endl <<
		"2.Create array list" << endl <<
		"3.Create vector list" << endl;
	cin >> typeOfList;

	system("cls");
	cout <<
		"Choose data type:" << endl <<
		"0.Exit" << endl <<
		"1.Int list" << endl <<
		"2.Double list" << endl <<
		"3.String list" << endl <<
		"4.Vector list" << endl <<
		"5.Dice list" << endl <<
		"6.Set list" << endl;
	
	cin >> typeOfData;

	switch (typeOfList)
	{
	case 1:
		switch (typeOfData)
		{
		case 1:
			{
				LinkedListFunctions<int>();
				break;
			}
		case 2:
			{
				LinkedListFunctions<double>();
				break;
			}
		case 3:
			{
				LinkedListFunctions<string>();
				break;
			}
		case 4:
			{
				LinkedListFunctions<vector<int>>();
				break;
			}
		case 5:
			{
				LinkedListFunctions<Dice>();
				break;
			}
		case 6:
			{
				LinkedListFunctions<Set>();
				break;
			}
		default:
			return;
		}
		break;
	case 2:
		switch (typeOfData)
		{
		case 1:
			{
				ArrayListFunctions<int>();
				break;
			}
		case 2:
			{
				ArrayListFunctions<double>();
				break;
			}
		case 3:
			{
				ArrayListFunctions<string>();
				break;
			}
		case 4:
			{
				ArrayListFunctions<vector<int>>();
				break;
			}
		case 5:
			{
				ArrayListFunctions<Dice>();
				break;
			}
		case 6:
			{
				ArrayListFunctions<Set>();
				break;
			}
		default:
			return;
		}
		break;
	case 3:
		switch (typeOfData)
		{
		case 1:
			{
				VectorListFunctions<int>();
				break;
			}
		case 2:
			{
				VectorListFunctions<double>();
				break;
			}
		case 3:
			{
				VectorListFunctions<string>();
				break;
			}
		case 4:
			{
				VectorListFunctions<vector<int>>();
				break;
			}
		case 5:
			{
				VectorListFunctions<Dice>();
				break;
			}
		case 6:
			{
				VectorListFunctions<Set>();
				break;
			}
		default:
			return;
		}
		break;
	default:
		return;
	}

}

void ArrayListFunctionsMenu()
{
	system("cls");
	cout <<
		"Choose function:" << endl <<
		"0.Exit" << endl <<
		"1.Random data" << endl <<
		"2.Push back" << endl <<
		"3.Insert" << endl <<
		"4.Pop back" << endl <<
		"5.Remove" << endl <<
		"6.Clear" << endl <<
		"7.Print" << endl <<
		"8.Sort" << endl;
	cin >> func;
}

void LinkedListFunctionsMenu()
{
	system("cls");
	cout <<
		"Choose function:" << endl <<
		"0.Exit" << endl <<
		"1.Random data" << endl <<
		"2.Push back" << endl <<
		"3.Push front" << endl <<
		"4.Insert" << endl <<
		"5.Pop back" << endl <<
		"6.Pop front" << endl <<
		"7.Remove" << endl <<
		"8.Clear" << endl <<
		"9.Print" << endl <<
		"10.Sort" << endl;
	cin >> func;
}

template <class T>
void ArrayListFunctions()
{
	ArrayList<T> list;
	string str;
	ArrayListFunctionsMenu();
	while (func > 0 && func <= 8)
	{
		switch (func)
		{
		case 1:
			{
				list.Clear();
				Random(list);
				ArrayListFunctionsMenu();
				break;
			}
		case 2:
			{
				T t;
				GetFromConsole(t);
				list.PushBack(t);
				ArrayListFunctionsMenu();
				break;
			}
		case 3:
			{
				int it;
				T t;
				GetFromConsole(t);
				system("cls");
				cout << "Enter number of place:" << endl;
				cin >> it;
				list.Insert(t, it);
				ArrayListFunctionsMenu();
				break;
			}
		case 4:
			{
				list.PopBack();
				ArrayListFunctionsMenu();
				break;
			}
		case 5:
			{
				int it;
				system("cls");
				cout << "Enter number of place:" << endl;
				cin >> it;
				list.Remove(it);
				ArrayListFunctionsMenu();
				break;
			}
		case 6:
			{
				list.Clear();
				ArrayListFunctionsMenu();
				break;
			}
		case 7:
			{
				system("cls");
				Print(list);
				cout << endl;
				std::cin.get();
				std::cin.get();
				ArrayListFunctionsMenu();
				break;
			}
		case 8:
			{
			system("cls");
			auto sort = SortMenu();
			switch (sort)
			{
			case 1:
			{
				auto z = MethodSort();
				if (z == 1)
					ListSorter<T>::InsertionSort(list, Predicate<T>);
				if (z == 2)
					ListSorter<T>::InsertionSort(list, PredicateDesc<T>);
				break;
			}
			case 2:
			{
				auto z = MethodSort();
				if (z == 1)
					ListSorter<T>::SelectionSort(list, Predicate<T>);
				if (z == 2)
					ListSorter<T>::SelectionSort(list, PredicateDesc<T>);
				break;
			}
			case 3:
			{
				auto z = MethodSort();
				if (z == 1)
					ListSorter<T>::BubbleSort(list, Predicate<T>);
				if (z == 2)
					ListSorter<T>::BubbleSort(list, PredicateDesc<T>);
				break;
			}
			case 4:
			{
				auto z = MethodSort();
				if (z == 1)
					ListSorter<T>::GnomeSort(list, Predicate<T>);
				if (z == 2)
					ListSorter<T>::GnomeSort(list, PredicateDesc<T>);
				break;
			}
			case 5:
			{
				auto z = MethodSort();
				if (z == 1)
					ListSorter<T>::MergeSort(list, Predicate<T>);
				if (z == 2)
					ListSorter<T>::MergeSort(list, PredicateDesc<T>);
				break;
			}
			case 6:
			{
				auto z = MethodSort();
				if (z == 1)
					ListSorter<T>::QuickSort(list, Predicate<T>);
				if (z == 2)
					ListSorter<T>::QuickSort(list, PredicateDesc<T>);
				break;
			}
			case 7:
				ListSorter<T>::CountingSort(list, IntField<T>);
				break;
			case 8:
				ListSorter<T>::BucketSort(list, FloatField<T>);
				break;
			default:
				break;
			}
			ArrayListFunctionsMenu();
			}
		default:
			break;
		}
	}
}

template <class T>
void VectorListFunctions()
{
	VectorList<T> list;
	string str;
	ArrayListFunctionsMenu();
	while (func > 0 && func <= 8)
	{
		switch (func)
		{
		case 1:
		{
			list.Clear();
			Random(list);
			ArrayListFunctionsMenu();
			break;
		}
		case 2:
		{
			T t;
			GetFromConsole(t);
			list.PushBack(t);
			ArrayListFunctionsMenu();
			break;
		}
		case 3:
		{
			int it;
			T t;
			GetFromConsole(t);
			system("cls");
			cout << "Enter number of place:" << endl;
			cin >> it;
			list.Insert(t, it);
			ArrayListFunctionsMenu();
			break;
		}
		case 4:
		{
			list.PopBack();
			ArrayListFunctionsMenu();
			break;
		}
		case 5:
		{
			int it;
			system("cls");
			cout << "Enter number of place:" << endl;
			cin >> it;
			list.Remove(it);
			ArrayListFunctionsMenu();
			break;
		}
		case 6:
		{
			list.Clear();
			ArrayListFunctionsMenu();
			break;
		}
		case 7:
		{
			system("cls");
			Print(list);
			cout << endl;
			std::cin.get();
			std::cin.get();
			ArrayListFunctionsMenu();
			break;
		}
		case 8:
			{
			system("cls");
			auto sort = SortMenu();
			switch (sort)
			{
			case 1:
			{
				auto z = MethodSort();
				if (z == 1)
					ListSorter<T>::InsertionSort(list, Predicate<T>);
				if (z == 2)
					ListSorter<T>::InsertionSort(list, PredicateDesc<T>);
				break;
			}
			case 2:
			{
				auto z = MethodSort();
				if (z == 1)
					ListSorter<T>::SelectionSort(list, Predicate<T>);
				if (z == 2)
					ListSorter<T>::SelectionSort(list, PredicateDesc<T>);
				break;
			}
			case 3:
			{
				auto z = MethodSort();
				if (z == 1)
					ListSorter<T>::BubbleSort(list, Predicate<T>);
				if (z == 2)
					ListSorter<T>::BubbleSort(list, PredicateDesc<T>);
				break;
			}
			case 4:
			{
				auto z = MethodSort();
				if (z == 1)
					ListSorter<T>::GnomeSort(list, Predicate<T>);
				if (z == 2)
					ListSorter<T>::GnomeSort(list, PredicateDesc<T>);
				break;
			}
			case 5:
			{
				auto z = MethodSort();
				if (z == 1)
					ListSorter<T>::MergeSort(list, Predicate<T>);
				if (z == 2)
					ListSorter<T>::MergeSort(list, PredicateDesc<T>);
				break;
			}
			case 6:
			{
				auto z = MethodSort();
				if (z == 1)
					ListSorter<T>::QuickSort(list, Predicate<T>);
				if (z == 2)
					ListSorter<T>::QuickSort(list, PredicateDesc<T>);
				break;
			}
			case 7:
				ListSorter<T>::CountingSort(list, IntField<T>);
				break;
			case 8:
				ListSorter<T>::BucketSort(list, FloatField<T>);
				break;
			default:
				break;
			}
			ArrayListFunctionsMenu();
			}
		default:
			break;
		}
	}
}

template <class T>
void LinkedListFunctions()
{
	LinkedList<T> list;
	string str;
	LinkedListFunctionsMenu();
	while (func > 0 && func <= 10)
	{
		switch (func)
		{
		case 1:
			{
				list.Clear();
				Random(list);
				LinkedListFunctionsMenu();
				break;
			}
		case 2:
			{
				T t;
				GetFromConsole(t);
				list.PushBack(t);
				LinkedListFunctionsMenu();
				break;
			}
		case 3:
			{
				T t;
				GetFromConsole(t);
				list.PushFront(t);
				LinkedListFunctionsMenu();
				break;
			}
		case 4:
			{
				int it;
				T t;
				GetFromConsole(t);
				system("cls");
				cout << "Enter number of place:" << endl;
				cin >> it;
				list.Insert(t, it);
				LinkedListFunctionsMenu();
				break;
			}
		case 5:
			{
				list.PopBack();
				LinkedListFunctionsMenu();
				break;
			}
		case 6:
			{
				list.PopFront();
				LinkedListFunctionsMenu();
				break;
			}
		case 7:
			{
				int it;
				system("cls");
				cout << "Enter number of place:" << endl;
				cin >> it;
				list.Remove(it);
				LinkedListFunctionsMenu();
				break;
			}
		case 8:
			{
				list.Clear();
				LinkedListFunctionsMenu();
				break;
			}
		case 9:
			{
				system("cls");
				Print(list);
				cout << endl;
				std::cin.get();
				std::cin.get();
				LinkedListFunctionsMenu();
				break;
			}
		case 10:
			{
				system("cls");
				auto sort = SortMenu();
				switch (sort)
				{
				case 1:
					{
						auto z = MethodSort();
						if (z == 1)
							ListSorter<T>::InsertionSort(list, Predicate<T>);
						if (z == 2)
							ListSorter<T>::InsertionSort(list, PredicateDesc<T>);
						break;
					}
				case 2:
					{
						auto z = MethodSort();
						if (z == 1)
							ListSorter<T>::SelectionSort(list, Predicate<T>);
						if (z == 2)
							ListSorter<T>::SelectionSort(list, PredicateDesc<T>);
						break;
					}
				case 3:
					{
						auto z = MethodSort();
						if (z == 1)
							ListSorter<T>::BubbleSort(list, Predicate<T>);
						if (z == 2)
							ListSorter<T>::BubbleSort(list, PredicateDesc<T>);
						break;
					}
				case 4:
					{
						auto z = MethodSort();
						if (z == 1)
							ListSorter<T>::GnomeSort(list, Predicate<T>);
						if (z == 2)
							ListSorter<T>::GnomeSort(list, PredicateDesc<T>);
						break;
					}
				case 5:
					{
						auto z = MethodSort();
						if (z == 1)
							ListSorter<T>::MergeSort(list, Predicate<T>);
						if (z == 2)
							ListSorter<T>::MergeSort(list, PredicateDesc<T>);
						break;
					}
				case 6:
					{
						auto z = MethodSort();
						if (z == 1)
							ListSorter<T>::QuickSort(list, Predicate<T>);
						if (z == 2)
							ListSorter<T>::QuickSort(list, PredicateDesc<T>);
						break;
					}
				case 7:
					ListSorter<T>::CountingSort(list, IntField<T>);
					break;
				case 8:
					ListSorter<T>::BucketSort(list, FloatField<T>);
					break;
				default:
					break;
				}
				LinkedListFunctionsMenu();
				break;
			}
		default:
			break;
		}
	}
}

int MethodSort()
{
	int z;
	system("cls");
	cout <<
		"Choose method:" << endl <<
		"0.Exit:" << endl <<
		"1.Ascending order:" << endl <<
		"2.Descending order:" << endl;
	cin >> z;
	return z;
}

int SortMenu()
{
	int sort;
	cout << "Choose sorting algorithm:" << endl <<
		"0.Exit" << endl <<
		"1.Insertion sort" << endl <<
		"2.Selection sort" << endl <<
		"3.Bubble sort" << endl <<
		"4.Gnome sort" << endl <<
		"5.Merge sort" << endl <<
		"6.Quick sort" << endl <<
		"7.Counting sort" << endl <<
		"8.Bucket sort" << endl;
	cin >> sort;
	return sort;
}

template <class T>
bool Predicate(T t1, T t2)
{
	return t1 >= t2;
}

template <>
bool Predicate<int>(int t1, int t2)
{
	return t1 >= t2;
}

template <>
bool Predicate<double>(double t1, double t2)
{
	return t1 >= t2;
}

template <>
bool Predicate<string>(string t1, string t2)
{
	return t1.size() >= t2.size();
}

template <>
bool Predicate<vector<int>>(vector<int> t1, vector<int> t2)
{
	return t1.size() >= t2.size();
}

template <>
bool Predicate<Dice>(Dice t1, Dice t2)
{
	return t1.GetAmountOfFaces() >= t2.GetAmountOfFaces();
}

template <>
bool Predicate<Set>(Set t1, Set t2)
{
	return t1.GetSize() >= t2.GetSize();
}

template <class T>
bool PredicateDesc(T t1, T t2)
{
	return t1 <= t2;
}

template <>
bool PredicateDesc<int>(int t1, int t2)
{
	return t1 <= t2;
}

template <>
bool PredicateDesc<double>(double t1, double t2)
{
	return t1 <= t2;
}

template <>
bool PredicateDesc<string>(string t1, string t2)
{
	return t1.size() <= t2.size();
}

template <>
bool PredicateDesc<vector<int>>(vector<int> t1, vector<int> t2)
{
	return t1.size() <= t2.size();
}

template <>
bool PredicateDesc<Dice>(Dice t1, Dice t2)
{
	return t1.GetAmountOfFaces() <= t2.GetAmountOfFaces();
}

template <>
bool PredicateDesc<Set>(Set t1, Set t2)
{
	return t1.GetSize() <= t2.GetSize();
}

template <class T>
float FloatField(T t)
{
	return 0.0;
}

template <>
float FloatField<double>(double t)
{
	return static_cast<float>(t);
}

template <class T>
size_t IntField(T t)
{
	return 0.0;
}

template <>
size_t IntField<int>(int t)
{
	return static_cast<size_t>(t);
}

template <class T>
void GetFromConsole(T& t)
{
	return;
}

void GetFromConsole(int& t)
{
	system("cls");
	cout << "Enter data:";
	cin >> t;
}

void GetFromConsole(double& t)
{
	system("cls");
	cout << "Enter data:";
	cin >> t;
}

void GetFromConsole(string& t)
{
	system("cls");
	cout << "Enter data:" << endl;
	std::getline(std::cin >> std::ws, t);
}

void GetFromConsole(vector<int>& t)
{
	int size;
	system("cls");
	cout << "Enter size of vector:" << endl;
	cin >> size;
	t.resize(size);
	for (auto i = 0; i < size; i++)
	{
		system("cls");
		cout << "Enter " << i << " element:";
		cin >> t[i];
	}
}

void GetFromConsole(Dice& t)
{
	int size;
	system("cls");
	cout << "Enter amount of faces:" << endl;
	cin >> size;
	for (auto i = 0; i < size; i++)
	{
		double prob;
		system("cls");
		cout << "Enter " << i << " element probability:";
		cin >> prob;
		Face face(i, prob);
		t.AddFace(face);
	}
}

template <class T>
void Random(IList<T>& list)
{
	return;
}

void Random(IList<int>& list)
{
	for (auto i = 0; i < rand() % 6 + 4; i++)
		list.PushBack(rand() % 1000);
}

void Random(IList<double>& list)
{
	for (auto i = 0; i < rand() % 6 + 4; i++)
	{
		double temp = rand() % 1000;
		list.PushBack(temp / 1000);
	}
}

void Random(IList<string>& list)
{
	for (auto i = 0; i < rand() % 6 + 4; i++)
	{
		const auto size = rand() % 6 + 4;
		string str;
		str.resize(size);
		for (auto j = 0; j < size; j++)
			str[j] = rand() % 255;
		list.PushBack(str);
	}
}

void Random(IList<vector<int>>& list)
{
	for (auto i = 0; i < rand() % 6 + 4; i++)
	{
		const auto size = rand() % 6 + 4;
		vector<int> vec(size);
		for (auto j = 0; j < size; j++)
			vec[j] = rand() % 100;
		list.PushBack(vec);
	}
}

void Random(IList<Dice>& list)
{
	for (auto k = 0; k < rand() % 8 + 1; k++)
	{
		Dice dice;
		int i;
		auto sum = 1000;
		const auto size = (rand() % 9 + 1) * 2;
		for (i = 0; i < size - 1; i++)
		{
			const auto prob = rand() % sum;
			sum -= prob;
			Face face(1 + i, static_cast<double>(prob) / 1000);
			dice.AddFace(face);
		}
		Face face(1 + i, static_cast<double>(sum) / 1000);
		dice.AddFace(face);
		list.PushBack(dice);
	}
}

void Random(IList<Set>& list)
{
	for (auto k = 0; k < rand() % 5 + 1; k++)
	{
		Set set;
		set.RandomInitialize();
		list.PushBack(set);
	}
}

template <class T>
void Print(IList<T>& list)
{
	return;
}

void Print(IList<int>& list)
{
	list.Print([](const int& t)
	{
		cout << t << " -> ";
	});
}

void Print(IList<double>& list)
{
	list.Print([](const double& t)
	{
		cout << t << " -> ";
	});
}

void Print(IList<string>& list)
{
	list.Print([](const string& t)
	{
		cout << t << endl;
	});
}

void Print(IList<vector<int>>& list)
{
	list.Print([](const vector<int>& t)
	{
		for (auto& value : t)
			cout << value << " -> ";
		cout << endl;
	});
}

void Print(IList<Dice>& list)
{
	list.Print([](Dice t)
	{
		t.Print();
	});
}

void Print(IList<Set>& list)
{
	list.Print([](Set t)
	{
		t.Print();
	});
}

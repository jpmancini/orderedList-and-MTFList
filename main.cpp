#include "MTFList.h"
#include "orderedList.h"
#include <fstream>
#include <chrono>

typedef chrono::high_resolution_clock Clock;


using namespace std;

int main(int argc, char *argv[])
{
	MTFList list2;
	unsigned listLength = 0, querySize = 0;
	int  number = 0, queryNumber = 0;

	string fileName = argv[1];

	ifstream file;
	file.open(fileName.c_str());

	if (file)
	{
		file >> listLength;

		orderedList list1(listLength);

		for (unsigned i = 0; i < listLength; i++)
		{
			file >> number;
			list1.add(i, number);
			list2.add(number);
		}

		//list1.print();
		//list2.print();

		file >> querySize;
 
		int tmpArray[querySize];
		for (unsigned i = 0; i < querySize; i++)
		{
			file >> queryNumber;
			tmpArray[i] = queryNumber;
		}
		chrono::time_point<std::chrono::system_clock> start1, end1;
		start1 = chrono::system_clock::now();

		list1.mergeSort();
		for (unsigned i = 0; i < querySize; i++)
		{
			list1.binarySearch(tmpArray[i]);
		}

		end1 = chrono::system_clock::now();
		chrono::duration<double> timePassed1 = end1 - start1;

		cout << "list1 time: " << timePassed1.count() << endl;

		chrono::time_point<std::chrono::system_clock> start2, end2;
		start2 = chrono::system_clock::now();

		for (unsigned i = 0; i < querySize; i++)
		{
			list2.search(tmpArray[i]);
		}

		end2 = chrono::system_clock::now();
		chrono::duration<double> timePassed2 = end2 - start2;

		cout << "list2 time: " << timePassed2.count() << endl;


		//file.close();
	}

	return 0;
}


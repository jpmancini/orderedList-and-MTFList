#ifndef ORDEREDList_H
#define ORDEREDList_H

using namespace std;

class orderedList
{
public:
	orderedList();
	orderedList(unsigned&);
	void remove(const int&);
	void add(const unsigned&, const int&);
	void mergeSort();
	void mergeSort(int[], int[], int, int);
	void merge(int[], int[], int, int, int);
	unsigned binarySearch(const int);
	void print() const;

private:
	int *array;
	unsigned sz;

	void initialize();

}; //orderedList class

/***************
**CONSTRUCTORS**
***************/

//default constructor
orderedList::orderedList()
{
	initialize();
} //orderedList::orderedList

//explicit constructor
orderedList::orderedList(unsigned& size)
{
	sz = size;
	array = new int[sz];
} //orderedList::oderedList

/*******************
**MEMBER FUNCTIONS**
*******************/

//intializing
void orderedList::initialize()
{
	sz = 0;
	array = new int[sz];
} //orderedList::initialize

//printing
void orderedList::print() const
{
	for (unsigned i = 0; i < sz; i++)
		cout << array[i] << " ";

	//cout << frontPtr->getValue() << endl;
	//cout << backPtr->getValue() << endl;

	cout << endl;
} //orderedList::print

//removing
void orderedList::remove(const int& deletion)
{
	unsigned i = 0;

	while (array[i] != deletion)
		i++;

	while (i < sz)
	{
		array[i] = array[i + 1];
		i++;
	}

} //orderedList::remove

//adding
void orderedList::add(const unsigned& pos, const int& value)
{
	array[pos] = value;
} //orderedList::add

void orderedList::mergeSort()
{
	int tmpArray[sz];

	mergeSort(array, tmpArray, 0, sz - 1);
}

void orderedList::mergeSort(int a[], int tmpArray[], int left, int right)
{
	if (left < right)
	{
		int center = (left + right) / 2;
		mergeSort(a, tmpArray, left, center);
		mergeSort(a, tmpArray, center + 1, right);
		merge(a, tmpArray, left, center + 1, right);
	}
}

void orderedList::merge(int a[], int tmpArray[], int leftPos, int rightPos, int rightEnd)
{

	int leftEnd = rightPos - 1;
	int tmpPos = leftPos;
	int numElements = rightEnd - leftPos + 1;

	while (leftPos <= leftEnd && rightPos <= rightEnd)
	{
		if (a[leftPos] <= a[rightPos])
			tmpArray[tmpPos++] = a[leftPos++];
		else
			tmpArray[tmpPos++] = a[rightPos++];
	}

	while( leftPos <= leftEnd )
		tmpArray[tmpPos++] = a[ leftPos++ ];

	while( rightPos <= rightEnd )
		tmpArray[tmpPos++] = a[rightPos++];

	for( int i = 0; i < numElements; ++i, --rightEnd )
		a[rightEnd] = tmpArray[rightEnd];
}

unsigned orderedList::binarySearch(const int value)
{
	unsigned low = 0, high = sz - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (array[mid] < value)
			low = mid + 1;
		else if (array[mid] > value)
			high = mid - 1;
		else
			return mid; // Found
	}

	return -1;
}

#endif // orderedList_H




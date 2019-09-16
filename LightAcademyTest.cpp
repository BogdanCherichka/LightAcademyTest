#include <iostream>
using namespace std;
#include <cctype>
#include <cstring>

bool checkEvenNumberOfDuplicates(const char* const* const, const int);

int main()
{
	int size = 7;

	char* str1 = new char[15]{ 3 };
	char* str2 = new char[15]{ '3' };
	char* str3 = new char[15]{ 2 };
	char* str4 = new char[15]{ "two" };
	char* str5 = new char[15]{ "aPple" };
	char* str6 = new char[15]{ "apple" };
	char* str7 = new char[15]{ "Appple" };

	char **strAll = new char * [size];

	*strAll = str1;
	*(strAll + 1) = str2;
	*(strAll + 2) = str3;
	*(strAll + 3) = str4;
	*(strAll + 4) = str5;
	*(strAll + 5) = str6;
	*(strAll + 6) = str7;

	cout << "\n";												
	if (checkEvenNumberOfDuplicates(strAll, size)) cout << "Array has even number of duplicates." << endl;		//checking function checkEvenNumberOfDuplicates
	else cout << "Array has odd number of duplicates." << endl;

	for (int i = 0; i < size; i++)
	{
		delete[] *(strAll + i);
	}
	delete[] strAll;

	return 0;
}

bool checkEvenNumberOfDuplicates(const char* const* const arr, const int size)
{
	if (arr)
	{	
		char** arrCopy = nullptr;	//creating a copy of array with all-lower register for saving original data
		arrCopy = new char* [size] {};
		if (arrCopy)	//if dynamic memory for array copy was reserved
		{
			for (int i = 0; i < size; i++)
			{			
				*(arrCopy + i) = nullptr;	//reserving dynamic memory for every line of array copy

				while (*(arrCopy + i) == nullptr)	//if dynamic memory for every line of array copy was reserved
				{
					*(arrCopy + i) = new char[15]{};
				}								
				strcpy_s(*(arrCopy + i), (int)strlen(*(arr + i)) + 1, *(arr + i));	//copying content of original array to array copy
				
				for (int j = 0; j < (int)strlen(*(arrCopy + i)); j++)
				{
					*(*(arrCopy + i) + j) = tolower(*(*(arrCopy + i) + j));		//shifting to lower register every symbol in the line
				}
			}
		}
		
		for (int i = 0; i < size; i++)
		{
			int counter{};	//creating variable that counts number of duplicates

			for (int j = 0; j < size; j++)
			{
				if (!strncmp(*(arrCopy + i), *(arrCopy + j), strlen(*(arrCopy + i)))) counter++; 	//comparing i line with every other lines
			}

			if (counter % 2 == 0)
			{
				for (int i = 0; i < size; i++)		// deleting created array copy before returning true
				{
					delete[] * (arrCopy + i);
				}
				delete[] arrCopy;
				return true;
			}
		}
		
		for (int i = 0; i < size; i++)		// deleting created array copy before returning false
		{
			delete[] * (arrCopy + i);
		}
		delete[] arrCopy;
		return false;
	}
	cout << "Error! Array was not created." << endl;	//error message if dynamic memory was not reserved for array
	return false;
}

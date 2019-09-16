#include <iostream>
using namespace std;
#include <cctype>
#include <cstring>

bool checkEvenNumber(const char* const* const, const int);

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

	for (int i = 0; i < 7; i++)
	{
		cout << *(strAll + i) << endl;
	}

	cout << "\n\n\n";												//checking function checkEvenNumber
	if (checkEvenNumber(strAll, size)) cout << "Returned true." << endl;
	else cout << "Returned false." << endl;


	for (int i = 0; i < size; i++)
	{
		delete[] *(strAll + i);
	}
	delete[] strAll;

	return 0;
}

bool checkEvenNumber(const char* const* const arr, const int size)
{
	if (arr)
	{	
		char** arrCopy = nullptr;										//creating a copy of array with all-lower register for saving original data
		arrCopy = new char* [size] {};
		if (arrCopy)
		{
			for (int i = 0; i < size; i++)
			{			
				*(arrCopy + i) = nullptr;

				while (*(arrCopy + i) == nullptr)
				{
					*(arrCopy + i) = new char[15]{ '\0' };
				}								
				strcpy_s(*(arrCopy + i), (int)strlen(*(arr + i)) + 1, *(arr + i));
				
				for (int j = 0; j < (int)strlen(*(arrCopy + i)); j++)
				{
					*(*(arrCopy + i) + j) = tolower(*(*(arrCopy + i) + j));
				}
			}
		}

		

		for (int i = 0; i < size; i++)
		{
			int counter{};

			for (int j = 0; j < size; j++)
			{
				if (!strncmp(*(arrCopy + i), *(arrCopy + j), strlen(*(arrCopy + i)))) counter++;
			}

			if (counter % 2 == 0)
			{
				for (int i = 0; i < size; i++)					// deleting created copy of array
				{
					delete[] * (arrCopy + i);
				}
				delete[] arrCopy;
				return true;
			}
		}
		
		for (int i = 0; i < size; i++)							// deleting created copy of array
		{
			delete[] * (arrCopy + i);
		}
		delete[] arrCopy;

		return false;
	}
	cout << "Error! Array was not created." << endl;
	return false;

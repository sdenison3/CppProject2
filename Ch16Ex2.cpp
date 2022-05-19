/* Write a program to test the function binarySearch. 
Use either the function bubbleSort or insertionSort to sort the list before the search */

#include<iostream>

using namespace std;

int binarySearch(const int list[], int listLength, int searchItem);
void bubbleSort(int list[], int length);

int main () 
{
	int i;
	int pets;
	int searchItem;
	bool menu = true;
	bool input = true;
	
	cout << "How many pets do you have? : " << endl;
	cin >> pets;
	while(cin.fail() || pets <= 0)
	{
	    cin.clear();
	    cin.ignore(256, '\n');
	    cout << "Invalid # of pets. Please enter a non-negative integer" << endl;
	    cin >> pets;
	}
	cout << "Please enter the age (in years) of all of your pets. After each pet press ENTER" << endl;
	
	int age[pets];
	
	for(i = 0; i < pets; i++)
	{
	    
	        cout << "Pet #" << (i + 1) << ":";
		    cin >> age[i];
		    while(cin.fail() || age[i] < 0)
		    {
		        cin.clear();
		        cin.ignore(256, '\n');
		        cout << "Invalid Input. Please enter a non-negative integer." << endl;
		        cin >> age[i];
		    }
        
	}
	bubbleSort(age, pets);
	
	cout << "Youngest pet is " << age[0] << " years old." << endl;
	cout << "Oldest pet is " << age[pets - 1] << " years old." << endl << endl;
	
	char again;
	
	while(menu)
	{
	    cout << "Please type in age (in years) of pet in question to find position" << endl;
	    cin >> searchItem;
	    if(binarySearch(age, pets, searchItem) == - 1)
	    {
	        cin.clear();
	        cin.ignore(256, '\n');
	        cout << "Invalid Age to check." << endl;
	    }
	    else cout << (binarySearch(age, pets, searchItem) + 1) << " out of " << pets << ": Position of pet aged " << searchItem << " year(s) old" << endl;
	
	    cout << "Would you like to check another age position? (Y/N)" << endl;
	    cin >> again;
	    if(again == 'y' || again == 'Y') menu = true;
	    else if (again == 'n' || again == 'N') 
	    {
	        cout << "Exiting Program.";
	        menu = false;
	    }
	    else 
	    {
	        cout << "Invalid Response. Exiting Program.";
	        return false;
	    }
	}
	return 0;
}

int binarySearch(const int list[], int listLength, int searchItem)
{
	int first = 0;
	int last = listLength - 1;
	int mid;
	
	bool found = false;
	
	while (first <= last && !found)
	{
		mid = (first + last) / 2;
		
		if (list[mid] == searchItem)
			found = true;
		else if (list[mid] > searchItem)
			last = mid - 1;
		else
			first = mid + 1;
	}
	
	if (found)
		return mid;
	else
		return - 1;
}
void bubbleSort(int list[], int length)
{
	int temp;
	
	for(int iteration = 1; iteration < length; iteration++)
	{
		for (int index = 0; index < length - iteration; index++)
			if (list[index] > list[index + 1])
			{
				temp = list[index];
				list[index] = list[index + 1];
				list[index + 1] = temp;
			}
	}
}
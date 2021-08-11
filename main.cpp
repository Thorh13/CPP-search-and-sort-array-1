// Chapter 8, Programming Challenge 4: Charge Account Validation Modification
#include <iostream>
using namespace std;

// Function prototypes
bool search_list(int [], int, int);
void selection_sort(int [], int);

// Constant for the array size
const int SIZE = 18;

int main()
{
  // Array of account numbers
  int accounts[SIZE] = 
    { 5658845, 4520125, 7895122,
      8777541, 8451277, 1302850,
      8080152, 4562555, 5552012,
      5050552, 7825877, 1250255,
      1005231, 6545231, 2852085,
      7576651, 7881200, 4581002 };
  
  int account_number; // To hold an account numbers

  // Sort the list of valid accounts
  selection_sort(accounts, SIZE);

  // Get an account number from the user.
  cout << "\nPlease enter a 7-digit account number: ";
  cin >> account_number;

  // Search the array for the number and indicate
  // wether it is valid or not.
  if (search_list(accounts, SIZE, account_number))
    cout << "The number you entered is valid.\n" << endl;
  else
    cout << "The number you entered is invalid.\n" << endl;

  return 0;
}

//***************************************************
// Function selection_sort.                         *
// This function uses the selection sort algorithm  *
// to sort the array passed as an argument. The     *
// parameter size holds the nmumber of elements.    *
//***************************************************

void selection_sort(int array[], int size)
{
  int start_scan, min_index, min_value;

  for (start_scan = 0; start_scan < (size - 1); start_scan++)
  {
    min_index = start_scan;
    min_value = array[start_scan];
    for (int index = start_scan + 1; index < size; index++)
    {
      if (array[index] < min_value)
      {
        min_value = array[index];
        min_index = index;
      }
    }
    array[min_index] = array[start_scan];
    array[start_scan] = min_value;
  }
}

//***************************************************
// Function search_list.                            *
// This function searches the list array for the    *
// number passed into value. If the number if found *
// the function returns true. Other wise, it returns*
// false.                                           *
//***************************************************

bool search_list(int array[], int num_elems, int value)
{
  bool  found = false;
  int first = 0,
      last = num_elems - 1,
      middle;
  
  while (!found && first <= last)
  {
    middle = (first + last) / 2;
    if (array[middle] == value)
      found = true;
    else if (array[middle] > value)
      last = middle - 1;
    else
      first = middle + 1;
  }
  return found;
}

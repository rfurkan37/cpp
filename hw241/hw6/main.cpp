#include <iostream>
#include <functional>
#include <algorithm>
#include <cstdlib>
#include "PFArray.hpp"
#include "PFArray.cpp"

using namespace std;
using namespace RECPE;

int main()
{
  srand(time(NULL));
  // Create a PFArray and fill it with some integers
  PFArray<int> arr(5);

  for (int i = 0; i < 30; i++)
  {
    arr.push_back(rand() % 100);
  }

  cout << "Randomly generated and pushed back 30 integers" << endl;
  cout << "Size of array: " << arr.size() << endl;

  // print the array
  cout << "Array(used operator[]): " << endl;
  for (int i = 0; i < arr.size(); ++i)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  cout << "Sorting the array using std::sort" << endl;
  sort(arr.begin(), arr.end());
  // Sort the array using std::sort
  cout << "Printing the array after sorting: " << endl;
  for (int i = 0; i < arr.size(); ++i)
  {
    cout << arr[i] << " ";
  }

  cout << endl;


  cout << "Using std::find to find the value 4" << endl;
  // Use std::find to find the value 4
  auto it = find(arr.begin(), arr.end(), 4);

  if (it != arr.end())
    cout << "Found 4 at index " << it - arr.begin() << endl;
  else
    cout << "4 not found" << endl;

  cout << "Using std::for_each to print the elements of the array" << endl;
  // Use std::for_each to print the elements of the array
  for_each(arr.begin(), arr.end(), [](int x)
           { cout << x << " "; });
  cout << endl;

  // try erase function

  cout << "Erase the element at index 1 using erase func" << endl;
  arr.erase(arr.begin() + 1);
  for (int i = 0; i < arr.size(); ++i)
  {
    cout << arr[i] << " ";
  }
  cout << endl;


  arr.erase(arr.begin() + 1, arr.begin() + 3);
  cout << "Erase the elements at index 1 to 3 using erase func" << endl;
  for (int i = 0; i < arr.size(); ++i)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  cout << "Clearing the array" << endl;
  arr.clear();

  cout << "Size of array: " << arr.size() << endl;

  cout << "Array: " << endl;
  for (int i = 0; i < arr.size(); ++i)
  {
    cout << arr[i] << " ";
  }

  cout << endl;

  return 0;
}

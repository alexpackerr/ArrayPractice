#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

int enumerate(const string a[], int n, string target) 
{
	// if other statements don't run, it will return -1
	int it = -1;
	if (n > 0) 
	{
		it = 0;
			// loop that will tally the occurences of an element
		for (size_t i = 0; i < n; i++) 
		{
			if (a[i] == target) 			
				it++;			
		}
	}
		// the empty array returns 0
	else if (n == 0) 
		it = 0;	
	return it;
}

int findMatch(const string a[], int n, string target) 
{
		// looks for matches in the array
	for (size_t i = 0; i < n; i++) 
	{
			// returns first instance of match
		if (a[i] == target) 		
			return i;		
	}
		// returns -1 if no matches
	return -1;
}

bool findRun(const string a[], int n, string target, int& begin, int& end) 
{
	int it = 0;
	int it2 = 0;
		// goes through array
	for (size_t i = 0; i < n; i++) 
	{
			// sets the beginning of run
		if (a[i] == target && it < 1) 
		{
			begin = i;
				// will only run once since it is iterated
				// making it not less than 1
			it++;
			for (size_t j = i + 1; j < n; j++) 
			{
				// iterates until it finds something that's not the target
				if (a[j] != target) 
				{
					end = j - 1;
						// to show that the end isn't the same as the beginning
					it2++; 
					break;
				}
			}
		}
			// a second instance of target won't be found, so it2 would be 0
		if (it2 == 0) 		
			end = begin;		
	}
		// will be true if any target is found
	if (it >= 1) 	
		return true;	
	return false;
}

int findMin(const string a[], int n) 
{
	int j = -1;
	size_t i;
		// initialize min to be first element
	string min = a[0];
		// go through array and compare values to min
	for (i = 1; i < n; i++) 
	{
		if (a[i] < min) 
		{
			min = a[i];
				// keeps track of latest min until end of array
			j = i;
		}
	}
	return j;
}

int moveToEnd(string a[], int n, int pos) 
{
		// temporary string for swapping values
	string temp = "";
		// start at value pos and iterate through
	for (int j = pos; j < n; j++) 
	{
		if (j + 1 < n) 
		{
				// swap values
			temp = a[j + 1];
			a[j + 1] = a[j];
			a[j] = temp;
		}
	}
		// return original position
	return pos;
}

int moveToBeginning(string a[], int n, int pos) 
{
	string temp = "";
		// same idea as moveToEnd but in reverse
	if (pos < n) {
		for (int j = pos; j > 0; j--)
		{
			if (j - 1 >= 0)
			{
				temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
		return pos;
	}
	return -1;
}

int findDifference(const string a1[], int n1, const string a2[], int n2) 
{
	size_t i = 0;
		// finds where a1 and a2 are different
	while (i < n1 && i < n2) 
	{
		if (a1[i] != a2[i]) 
			return i;
		i++;
	}
		// if no difference found, returns 0
	return i;
}

int removeDups(string a[], int n) 
{
	size_t i, j;
	for (i = 0; i < n; i++) 
	{
			// starting at i, looks if next element is a duplicate
			// turns it into an empty string
		for (j = i + 1; j < n; j++) 
		{
			if (a[i] == a[j]) 
				a[j] = "";
				// if run ends, break loop and incriment i
			else 
				break;
		}
	}
		// all consecutive duplicates should be empty strings
	int it = 0;
	for (size_t i = 0; i < n; i++) 
	{
		for (size_t k = 0; k < n; k++) 
		{
				// find empty strings and move them to the end
				// shifting every other value to the left
			if (a[k] == "") 
				moveToEnd(a, n, k);
		}
	}
		// array with no duplicates should be in order with no spaces
		// count the number of elements that aren't empty strings 
	for (size_t i = 0; i < n; i++) 
	{
		if (a[i] != "") 
			it++;
	}
		// return new value of elements
	return it;
}

bool subsequence(const string a1[], int n1, const string a2[], int n2) 
{ 
	int i = 0;
	int j = 0;
		// checking each value of n1 to each value of a2
	while (i < n1) 
	{
		while (j < n2) 
		{
				// if both elements are equal, go to next value in both arrays 
				// aka: element in a2 was found, look for next element
				// keeps subsequence in order
			if (a1[i] == a2[j]) 
			{
				j++;
				i++;
			}
				// if not, only itcrement i and look for same value of a2
			else
				break;
		}
		i++;
	}
		// if all values of a2 were found, j should be equal to n2
	if (j == n2) 
		return true;
	return false;
}

int makeMerger(const string a1[], int n1, const string a2[], int n2, string result[], int max) 
{
		// if there are too many elements, return -1
	if (n1 + n2 > max)	
		return -1;	
		// if a1 and a2 aren't in increasing order, return -1
	for (size_t i = 0; i < n1; i++) 
	{
		if (i + 1 < n1) 
		{
			if (a1[i] > a1[i + 1]) 
				return -1;
		}
	}
	for (size_t i = 0; i < n2; i++)
	{
		if (i + 1 < n2) 
		{
			if (a2[i] > a2[i + 1]) 
				return -1;			
		}
	}	
		// add all elements of a1 to result, then a2
	int j = 0;
	while (j < n1) 
	{
		result[j] = a1[j];
		j++;
	}
	int k = 0;
	while (k < n2) 
	{
		result[k+n1] = a2[k];
		k++;
	}
		// sort values of result to be in increasing order
	int n3 = n1 + n2;
	string temp = "";
	for (size_t i = 0; i < n3; i++) 
	{
		for (size_t j = 0; j < n3; j++)
		{
			if (j + 1 < n3) 
			{
				if (result[j] > result[j + 1])
				{
					temp = result[j];
					result[j] = result[j + 1];
					result[j + 1] = temp;
				}
			}
		}
		if (i + 1 < n3) 
		{
			if (result[i] > result[i + 1]) 
			{
				temp = result[i];
				result[i] = result[i + 1];
				result[i + 1] = temp;
			}
		}
	}
		// return number of values in result
	return n3;
}

int divide(string a[], int n, string divider) 
{
	string temp = "";
	for (size_t i = 0; i < n; i++) 
	{
		for (size_t j = i; j < n; j++)
		{
				// for each value of i, check through whole array
				// see if any elements should be swapped, and swap if so
			if (a[i] >= divider && a[j] < divider) 
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
		// find first place that element is greater than divider
	for (size_t i = 0; i < n; i++) 
	{
		if (a[i] > divider) 
			return i;
	}
		// if no value is greater than divider, return number of elements
	return n;
}


int main() 
{
	string a[5] = { "alpha", "beta", "omega", "gamma", "delta" };
	string b[5] = { "zeta", "alpha", "beta", "epsilon", "pi" };
}
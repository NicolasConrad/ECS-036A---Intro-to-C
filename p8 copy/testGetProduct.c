#include "prog8.c"
#include <assert.h>
#include <stdio.h>

void testGetProduct(void)
{   
	{        
		int arr[] = {5, 8, 3, -1};        
		assert(getProduct(arr, 4) == -120);    
	}    
	{        
		int arr[] = {-7, 14, -2};        
		assert(getProduct(arr, 3) == 196);    
	}    
	{        
		int arr[] = {5, 15, 0, 100, -3};        
		assert(getProduct(arr, 5) == 0);    
	}    
	{        
		int arr[] = {2};        
		assert(getProduct(arr, 1) == 2);    
	}    
	{        
		int arr[] = {27, 15, 3, 14, 0, -5, 2, 0};        
		assert(getProduct(arr, 8) == 0);        
		// Can "lie" about the array size.        
		assert(getProduct(arr, 4) == 27 * 15 * 3 * 14);        
		assert(getProduct(arr, 2) == 27 * 15);        
		assert(getProduct(arr, 1) == 27);        
		// Demonstrating some pointer arithmetic.        
		assert(getProduct(arr + 1, 1) == 15);        
		assert(getProduct(arr + 1, 2) == 45);       
		assert(getProduct(arr + 1, 3) == 45 * 14);        
		assert(getProduct(arr + 5, 2) == -10);    
	}   
	fprintf(stderr, "%s(): All test cases passed!\n", __FUNCTION__);
}

int main()
{    
	testGetProduct();
}

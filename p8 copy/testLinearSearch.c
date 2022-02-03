
#include "prog8.c"
#include <assert.h>
#include <stdio.h>

void testLinearSearch(void)
{    
	{        
		int arr[] = {5, 8, 3, -1};        
		assert(linearSearch(arr, 4, 8));        
		assert(!linearSearch(arr, 4, -7));        
		assert(linearSearch(arr, 4, -1));        
		assert(!linearSearch(arr, 4, 50));    
	}    
	{        
		int arr[] = {-5, -2, 2, -2, 3, 4, 1};        
		assert(linearSearch(arr, 7, -2));        
		assert(linearSearch(arr, 7, -5));        
		assert(!linearSearch(arr, 7, 14));        
		assert(!linearSearch(arr, 7, 20));        
		// Again, we can "lie" about the length.        
		assert(!linearSearch(arr + 1, 6, -5));        
		assert(linearSearch(arr + 1, 6, -2));        
		assert(linearSearch(arr + 1, 6, 2));        
		assert(!linearSearch(arr + 3, 6, 2));    
	}    
	fprintf(stderr, "%s(): All test cases passed!\n", __FUNCTION__);
}

int main()
{    
	testLinearSearch();
}

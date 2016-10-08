// vector::pop_back
#include <iostream>
#include <vector>
#include <algorithm>
int main ()
{
	std::vector<int> myvector;
	int i;
 	for (i = 0 ; i < 100 ; i++)
		myvector.push_back (i);
	int size = 	myvector.size();
	std::cout << "Size of the vector is " << size << std::endl;
	sort(myvector.begin(), myvector.end());
   	 for(i = 0 ; !myvector.empty() ; i++){
      	std::cout << myvector[i] << std::endl;
	  	myvector.pop_back();
	 
    }


return 0;
}

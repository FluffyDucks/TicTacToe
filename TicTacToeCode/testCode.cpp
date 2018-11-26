#include <iostream>
//use this file to test features and interactions in C++ for driver code and helper functions

int main(){
	// int Arr[3][3] = {0, 0, 0,
	// 				1, 2, 3,
	// 			 	4, 5, 6};
	//
	// if((Arr[0][0] == Arr[0][1]) && (Arr[0][1] == Arr[0][2])){
	// 	std::cout << "This works" << '\n';
	// }
	// else{
	// 	std::cout << "This doesn't work" << '\n';
	// }
	int i = 0;
	bool flag1 = false;
	bool flag2 = false;
	while(flag1 == false || flag2 == false){
		std::cout << "i = " << i << '\n';
		std::cout << "flag1 = " << flag1 << '\n';
		if(i % 2 == 0){
			flag1 = true;
		}
		i++;
	}

	return 0;
}

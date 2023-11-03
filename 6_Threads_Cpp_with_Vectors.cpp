/* Thread Example in C++ with Vectors */

#include <iostream>
#include <thread>
#include <vector>
using namespace std;


int main(){

    vector<thread> threads;

	int val = 10;
	cout << "Before +1 Addition in 10 Threads, Value: " << val << endl;


    for(int i = 0; i < 10; ++i){
        threads.push_back(thread{[&](){val++;}});	// Add 10 Threads to Vector
    }

    for(auto &thread : threads){
        thread.join();								// Join 10 Threads from the Vector
    }

	// 10 Becomes 20 After +1 Incrementation in 10 Different Threads
	cout << "After  +1 Addition in 10 Threads, Value: " << val << endl;

return 0;
}

/* Thread Example in C++ */

#include <thread>
#include <iostream>
using namespace std;


void print(string str){

    cout << str;
}


int main(){

    string str = "Thread-";
    thread th1(&print, str+"1\n");
    thread th2(&print, str+"2\n");
	thread th3(&print, str+"3\n");

    th1.join();
    th2.join();
	th3.join();

return 0;
}

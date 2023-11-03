/* Wait Children in Vectors */

#include <iostream>
#include <sys/wait.h>
#include <vector>
using namespace std;


const int process = 20;
vector<pid_t> pids;

int main(){

for (int i = 0; i < process; i++) {
	pids.push_back(fork());
	if (pids[i]==0) {
		for(int j=0; j<100000*(1000/(i+1)+100*i); j++);
		cout << "Child: " << i+1 << endl;
	exit(0);
	}
	waitpid(-1, NULL, 0);
}


cout << "Ended." << endl;

return 0;
}

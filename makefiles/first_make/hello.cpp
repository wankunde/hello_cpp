#include <iostream>
#include <thread>
#include "xdata.h"
using namespace std;

void ThreadMain() {
    cout << "Thread Main" << endl;
}

int main(int argc, char *argv[]) {
    thread th(ThreadMain);
    cout << "Hello C++" <<endl;
    th.join();
    XData xdata;
    return 0;
}


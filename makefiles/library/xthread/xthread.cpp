#include <iostream>
#include "xthread.h"
using namespace std;
void XThread::Start()
{
    cout << "Start thread"<< endl;
    th_ = std::thread(&XThread::Main, this);
}

void XThread::Wait()
{
    cout << "Begin wait thread"<< endl;
    th_.join();
    cout << "End wait thread"<< endl;
}

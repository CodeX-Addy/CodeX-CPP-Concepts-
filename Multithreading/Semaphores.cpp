#include <iostream>
#include <semaphore>
#include <thread>
using namespace std;

// Initialize semaphore with a count of 3 (if it is 1 then said to be binary semaphore)
counting_semaphore<10> semaphore(3);

void worker(int id)
{

    semaphore.acquire();

    cout << "Thread " << id << " acquired the semaphore." << endl;


    semaphore.release();
    cout << "Thread " << id << " released the semaphore." << endl;
}


int main()
{
    thread t1(worker, 1);
    thread t2(worker, 2);
    thread t3(worker, 3);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}

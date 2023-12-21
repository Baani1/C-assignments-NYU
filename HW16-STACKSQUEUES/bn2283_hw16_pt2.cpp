#include <iostream>
#include <vector>
using namespace std;

class QueueUsingVector {
private:
    vector<int> queue;
    int start;

public:
    QueueUsingVector() : start(0) {}

    bool isEmpty() const 
    {
        return start >= queue.size();
    }

    int size() const
    {
        return queue.size() - start;
    }

    void enqueue(int item)
    {
        queue.push_back(item);
    }

    int dequeue() {
        if (isEmpty()) 
        {
            throw std::out_of_range("Queue is empty");
        }
        int item = queue[start];
        start++;

        // Reset the underlying vector if the queue is empty
        if (start > queue.size() / 2) 
        {
            queue.erase(queue.begin(), queue.begin() + start);
            start = 0;
        }
        return item;
    }
};
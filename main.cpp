#include <bits/stdc++.h>


void printDataStructure(bool isStack, bool isQueue, bool isPriorityQueue) {
    if ( isStack && !isQueue && !isPriorityQueue ) { std::cout << "stack" << std::endl; }
    else if ( !isStack && isQueue && !isPriorityQueue ) { std::cout << "queue"  << std::endl; }
    else if ( !isStack && !isQueue && isPriorityQueue ) { std::cout << "priority queue" << std::endl; }
    else if ( isPriorityQueue || isStack || isQueue ) { std::cout << "not sure" << std::endl; }
    else { std::cout << "impossible"  << std::endl; }
}

int main() {
    int input = 0;

    while(std::cin >> input)
    {
        int operation = 0; int value = 0;
        std::stack<int> stack; std::queue<int> queue;
        std::priority_queue<int> priorityQueue;

        bool isStack = true; bool isQueue = true; bool isPriorityQueue = true;
        for (int i = 0; i < input; ++i)
        {
            std::cin >> operation >> value;
            if (operation == 1) {
                stack.push(value);
                queue.push(value);
                priorityQueue.push(value);
            }
            else {
                if (isStack) {
                    if (!stack.empty() && stack.top() == value) { stack.pop(); }
                    else { isStack = false; }
                }
                if (isQueue) {
                    if (!queue.empty() && queue.front() == value) { queue.pop(); }
                    else { isQueue = false; }
                }
                if (isPriorityQueue) {
                    if (!priorityQueue.empty() && priorityQueue.top() == value) { priorityQueue.pop(); }
                    else { isPriorityQueue = false; }
                }
            }
        }
        printDataStructure(isStack, isQueue, isPriorityQueue);
    }
    return 0;
}

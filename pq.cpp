#include "graph.h"

priorityQueue::priorityQueue() {
}

int priorityQueue::getParent(int i){ return (i-1)/2;}

int priorityQueue::getRightChild(int i){ return (2*i)+2; }

int priorityQueue::getLeftChild(int i) {return (2*i)+1; }

void priorityQueue::heapify(int index) {

    int currentMin = index;
    int leftChild = getLeftChild(index);
    int rightChild = getRightChild(index);
    
        if (heap.size() >= leftChild && std::get<2>(heap[leftChild]) < std::get<2>(heap[currentMin])) {
            currentMin = leftChild;
        }

        if (heap.size() >= rightChild && std::get<2>(heap[rightChild]) < std::get<2>(heap[currentMin])) {
            currentMin = rightChild;
        }

    if (currentMin != index) {
        //swaping 2 vertecies
        std::tuple<int, int, int> temp = heap[currentMin]; 
        heap[currentMin] = heap[index];
        heap[index] = temp;
        heapify(currentMin);
    } 

}

//note: the algorithim of this function was inspired by the code in lecture slides
void priorityQueue::heapInsert(std::tuple<int, int, int> value) {
    heap.push_back(value);
    int i = heap.size() - 1;

    
    while (i > 0 && std::get<2>(heap[(i-1)/2]) > std::get<2>(heap[i])) {
        std::tuple<int, int, int> temp = heap[(i-1)/2]; 
        heap[(i-1)/2] = heap[i];
        heap[i] = temp;
        i = (i-1)/2;
    }
    
    //heapify(0);

    heapSize++;
}


std::tuple<int, int, int> priorityQueue::extractMin() {
    std::tuple<int, int, int> min = heap[0];
    
    heap[0] = heap.back();
    heap.pop_back();
    heapSize--;
    
    heapify(0);

    return min;
}


#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <limits>


class illegal_exception{
    public:
        std::string message;

        illegal_exception() {
            message = "illegal argument";
        }
};



class priorityQueue{
    private:
    std::vector<std::tuple<int, int, int>> heap;
    int heapSize{0};

    public:
    priorityQueue();
    void heapify(int index);
    std::tuple<int, int, int> extractMin();
    void heapInsert(std::tuple<int, int, int> edge);
    int getParent(int i);
    int getRightChild(int i);
    int getLeftChild(int i);

};

class Graph{
    private:
        std::vector<std::tuple<int, int>> edgeList[50000];   //a 50000 entries array of vectors of tuples
        int size{0};
        std::vector<int> listOfVerecies;

    public:
        Graph();
        void insert(int vertexA, int vertexB, int weight, bool fromLoad);
        bool validityCheck(int inputVar, std::string type);
        int getSize(){return size;}
        void print(int vertexA);
        void deleteVertex(int vertexA);
        void managesVertices(int vertexToInsert);     //a function that returns a vector of all exisiting vertices
        void MST(bool cost);
};

#endif
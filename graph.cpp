#include "graph.h"

using namespace std;

Graph::Graph() {
    
}


void Graph::insert(int vertexA, int vertexB, int weight, bool fromLoad) {
    //checks that all values are valid 
    if (!validityCheck(vertexA, "vertex") || !validityCheck(vertexB, "vertex") || !validityCheck(weight, "weight") ) {
        throw illegal_exception();
    }
    //subtract 1 from vertices number because array starts at index 0
    vertexA--;
    vertexB--;
    int firstValue{0};

    for(int i{0}; i<edgeList[vertexA].size(); i++) {
        firstValue = get<0>(edgeList[vertexA][i]);
        if (firstValue == vertexB && !fromLoad) {
            cout<<"failure" << endl;
            return;
        }
        else if(firstValue == vertexB && fromLoad) {
            return;
        }
    }


    //used to make connections between vertices
    tuple<int, int> firstConnection(vertexB, weight);
    tuple<int, int> secondConnection(vertexA, weight);

    edgeList[vertexA].push_back(firstConnection);       //inserts a new tuple at entry A with value (b, weight)
    edgeList[vertexB].push_back(secondConnection);      //inserts a new tuple at entry B with value (a, weight)

    if(!fromLoad) {
        cout<<"success" << endl;
    }

    managesVertices(vertexA);
    managesVertices(vertexB);


}

void Graph::print(int vertexA) {
    if(!validityCheck(vertexA, "vertex") ) {
        throw illegal_exception();
    }

    vertexA--;
    int firstvalue{0};
    if(edgeList[vertexA].size() == 0) {
        cout << "failure" << endl;
    } 
    else {
        for(int i{0}; i< edgeList[vertexA].size(); i++) {
            firstvalue = get<0>(edgeList[vertexA][i])+1;

            cout << firstvalue << " ";
        }
        cout<< endl;
    }
}



void Graph::deleteVertex(int vertexA) {
    if(!validityCheck(vertexA, "vertex") ) {
        throw illegal_exception();
    }

    vertexA--;
    int firstValue{0};

    //the vector will store the which indeces of the array to look for instead of traversing through the whole array
    vector<int> connections;       //vector used to to remove the vertex a from the edge set of all vertices adjacent to a.
                            
    if(edgeList[vertexA].size() == 0) {
        cout << "failure" << endl;
    }
    else {
        //for loop used to find the verteces that hava a connection with vertexA
        //stores these verteces inn the connections vector
        for(int i{0}; i< edgeList[vertexA].size(); i++) {
            firstValue = get<0>(edgeList[vertexA][i]);
            connections.push_back(firstValue);
        }
        edgeList[vertexA].clear();      //clear all entries of the vector at index vertexA

        
        for(int i{0}; i<connections.size(); i ++) {
             
            for(int k{0}; k<edgeList[connections[i]].size(); k++ ) {
                firstValue = get<0>(edgeList[connections[i]][k]);
                
                if(firstValue == vertexA) {
                    edgeList[connections[i]].erase(edgeList[connections[i]].begin() + k);
                }
                
            }
                
        }
        cout << "success" << endl;     

        for(int k{0}; k<listOfVerecies.size(); k++) {
            if (listOfVerecies[k] == vertexA) {

                listOfVerecies.at(k) = listOfVerecies.back();
                listOfVerecies.pop_back();
            }
        }   
    }

}

/*
    this function stores all existing vertices in a vector to be used in the priority Queue
*/
void Graph::managesVertices(int vertexToInsert) {

    for(int i{0}; i<listOfVerecies.size(); i++) {
        if(listOfVerecies[i] == vertexToInsert) {
            return;
        }
    }

    listOfVerecies.push_back(vertexToInsert);

}


void Graph::MST(bool cost){
    //vector of tuples storing the vertex, adjecent, cost
    vector<tuple<int, int, int>> mst;
    priorityQueue Q;

    if(listOfVerecies.size() == 0 && !cost) {
        cout << "failure" << endl;
        return;
    }
    else if (listOfVerecies.size() == 0 && cost){
        cout << "cost is 0" << endl;
        return;
    }
    
    //bool array that is used to store whether node was visited before or not
    bool visited[50000]{};

    //start at root vertex
    int root = listOfVerecies[0];

    //in order of: vertex, adjacent, cost
    tuple<int, int, int> firstTuple;
    tuple<int, int, int> min;
    tuple<int, int> tupleVertex; 

    int v;
    int weight;
    int verticesinmst = 0;

    //root has been visited
    visited[root] = true; // vertex 1 is visited i.e. index 0 is true
    verticesinmst++; // we visited 1st vertex
    // edge list is the adjacency list of indices and not the vertex number.

    for(int i{0}; i<edgeList[root].size(); i++) {
        v = get<0>(edgeList[root][i]);        //adjacent vertex
        weight = get<1>(edgeList[root][i]);     //weight between root and v

        firstTuple = make_tuple(root, v, weight);
        Q.heapInsert(firstTuple);
    }
    
    //cout << "ROOT :" << root << " : " << visited[root-1];
    
    while(verticesinmst < listOfVerecies.size()) {
        min = Q.extractMin();
        //Q.heapify();
        if (visited[get<1>(min)] == true)
        {
           // Q.extractMin();
            continue;
        }
        //visited[get<0>(min) - 1] = true;

        //std::cout << "LOOP 3 " << std::endl;
        for(int k{0}; k<edgeList[get<1>(min)].size();k++) {
            
            tupleVertex = edgeList[get<1>(min)][k];

            //std::cout << "IF STATEMENT" << std::endl;
            if(!visited[get<0>(tupleVertex)] && get<1>(tupleVertex) != numeric_limits<int>::max()) {
                tuple<int, int, int> insertTuple (get<1>(min), get<0>(tupleVertex), get<1>(tupleVertex));

                //std::cout << "heap insert" << std::endl;
                Q.heapInsert(insertTuple);
            }

            //cout << "visited: " << visited[get<0>(min)-1];
            
        }
        
        mst.push_back(min);
        if(!visited[get<1>(min)] == true){
            visited[get<1>(min)] = true;
            verticesinmst++;
        }
        if(!visited[get<0>(min)] == true){
            visited[get<0>(min)] = true;
            verticesinmst++;
        }
    }
    
    //cout << mst.size() << endl;
    // only printing mst
    int totalCost{0};
    for(int j{0}; j<mst.size(); j++) {
        if(cost) {
            totalCost = totalCost + get<2>(mst[j]);
        }
        else {
            cout << get<0>(mst[j]) + 1 << " " << get<1>(mst[j]) + 1 << " " << get<2>(mst[j]) << " ";
        }
    }
    
    if(cost) {
        cout << "cost is " << totalCost; 
    }

    cout << endl;

}

//checks validity
bool Graph::validityCheck(int inputVar, string type) {
    if(type == "vertex") {
        if(inputVar <= 0 || inputVar>50000) {
            return false;
        }
    }
    if(type == "weight") {
        if(inputVar <= 0){
            return false;
        }
    }
    return true;
}
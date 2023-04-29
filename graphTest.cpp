#include "graph.h"
#include <iostream>
#include <fstream>


int main() {
    std::string cmd;
    int a;
    int b;
    int w;
    int vertecies;
    Graph * myGraph = new Graph();


    while(std::cin >> cmd) {
        if(cmd == "LOAD") {
            std::string fName;
            std::cin >> fName;
            std::ifstream fin(fName.c_str());
            
            fin>> vertecies;

            while(fin >> a >> b >> w) {
                myGraph->insert(a, b, w, true);
            }
            std::cout<<"success" <<std::endl;
            fin.close();
        }
        else if(cmd == "INSERT") {
            std::cin>>a;
            std::cin>>b;
            std::cin>>w;
            try
            {
                myGraph->insert(a,b,w, false);
            }
            catch(illegal_exception e)
            {
               std::cout << e.message << std::endl;
            }
        }
        else if(cmd == "PRINT") {
            std::cin>>a;
            try
            {
                myGraph->print(a);
            }
            catch(illegal_exception e)
            {
               std::cout << e.message << std::endl;
            }
        }
        else if (cmd == "DELETE") {
            std::cin>>a;
            try
            {
                myGraph->deleteVertex(a);
            }
            catch(illegal_exception e)
            {
               std::cout << e.message << std::endl;
            }
        }
        else if(cmd == "MST") {
            myGraph->MST(false);
        }
        else if(cmd == "COST") {
            myGraph->MST(true);
        }
        else if(cmd == "END") {
            delete myGraph;
            return 0;
        }
    }
}

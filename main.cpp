#include <iostream>
#include <vector>
#include <string> 
#include <unordered_map>
#include <iomanip>
#include <ctime> 

#include "Airport.h"
#include "airport_graph.h"
#include "BFS.h"

using namespace std;


int main() {
    cout << ""<< endl;
    cout << "CS225 Final Project" << endl;
    cout << "Made by: kmajid2, adnann2, ebaadss2, ymohid2" << endl;

    string input = "y"; 
    
    while(input == "y") {
        string airportFile;
        string routesFile;
        string StartingAirport;
        string DestinationAirport;
        
        bool validDataset = false;
        
        validDataset = true;
        airportFile = "airports.dat";
        routesFile = "routes.dat";

        Graph airportGraph(airportFile, routesFile);
        unordered_map<int, Airport> verticesInGraph = airportGraph.getVertices();

        
        cout << "Enter a number to select an operation:" << endl;
        cout << "(0) Using BFS, traverse all of the graph from a given airport " << endl;
        cout << "(1) Using BFS, traverse a given number of moves of the graph from a given airport" << endl;
        cout << "(2) Using BFS, traverse the graph until a destination airport from a given airport" << endl;

        int mode; 
        cin >> mode;
         
        bool validSource = false;

        switch (mode)
        {
            case 0:{
                validSource = false;
                while(validSource == false){
                    cout << "Enter a source airport ID:" << endl;
                    int sourceAP; 
                    cin >> sourceAP;
                    auto it = verticesInGraph.find(sourceAP);
                    if(it != verticesInGraph.end()){
                        validSource = true;
                        BFS myBFS(airportFile, routesFile);
                        vector<string> result_all = myBFS.BFS_all(sourceAP);
                        string sourceAPName = it->second.getAirportName();
                        cout << "Printing out traversal from " << sourceAPName << ": " << endl;
                        for(unsigned i = 0; i < result_all.size(); i++){
                            cout << result_all[i] << " --> ";
                            if(i%4 == 0 && i != 0)
                                cout << "" << endl;
                        }
                        break;
                    }else{
                        cout << "Source airport ID not found in graph." << endl;
                    }
                }
                break;
            }


            case 1:{
                validSource = false;
                while(validSource == false){
                    cout << "Enter a source airport ID:" << endl;
                    int sourceAP; 
                    cin >> sourceAP;
                    auto it = verticesInGraph.find(sourceAP);
                    if(it != verticesInGraph.end()){
                        validSource = true;
                        cout << "Enter moves to traverse:" << endl;
                        int moves;
                        cin >> moves;
                        BFS myBFS(airportFile, routesFile);
                        vector<string> result_moves = myBFS.BFS_moves(sourceAP, moves);
                        string sourceAPName = it->second.getAirportName();
                        cout << "Printing out first " << moves << " moves from " << sourceAPName << ": " << endl;
                        for(unsigned i = 0; i < result_moves.size(); i++){
                            cout << result_moves[i];
                            if(i != result_moves.size()-1)
                                cout << " --> ";
                            if(i%4 == 0 && i != 0)
                                cout << "" <<endl;
                        }
                        break;
                    }else{
                        cout << "Source airport ID not found in graph." << endl;
                    }
                }
                break;
            }


            case 2:{
                bool validAP = false;
                while(validAP == false){
                    cout << "Enter a source airport ID:" << endl;
                    int sourceAP; 
                    cin >> sourceAP;
                    auto it = verticesInGraph.find(sourceAP);
                    if(it != verticesInGraph.end()){
                        string sourceAPName = it->second.getAirportName();
                        cout << "Enter a destination airport ID:" << endl;
                        int destAP; 
                        cin >> destAP;
                        auto it2 = verticesInGraph.find(destAP);
                        if(it2 != verticesInGraph.end()){
                            validAP = true;
                            BFS myBFS(airportFile, routesFile);
                            vector<string> result_dest = myBFS.BFS_dest(sourceAP, destAP);
                            string destAPName = it2->second.getAirportName();
                            cout << "Printing out traversal from " << sourceAPName << " to " << destAPName<< ": " << endl;
                            for(unsigned i = 0; i < result_dest.size(); i++){
                                cout << result_dest[i];
                                if(i != result_dest.size()-1)
                                    cout<< " --> ";
                                if(i%4 == 0 && i != 0)
                                    cout << "" << endl;
                            }
                        }
                    }else{
                        cout << "Invalid airport input" << endl;
                    }
                } 
                break;
            }
        }

        cout << "" << endl;
        cout << "Computation finished. Would you like to run the program again? (y/n) " << endl;

        cin >> input; 
        while(input != "y" && input != "n"){
            cout << "Your input is invalid, make sure that it is lower case and either y or n." << endl; 
            cin >> input; 
        }
    }
    return 0;
}

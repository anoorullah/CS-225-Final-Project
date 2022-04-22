#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>

#include "Airport.h"
#include "PageRank.h"
#include "airport_graph.h"
#include "Djikstras.h"
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
        cout << "(3) Use Djikstra's to calculate the shortest path between two airports" << endl;
        cout << "(4) Use PageRank to find the n most important airports" << endl;

        int mode; 
        cin >> mode;
         
        bool validSource = false;

        switch (mode)
        {
            // "(0) Using BFS, traverse all of the graph from a given airport "
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

            // "(1) Using BFS, traverse a given number of moves of the graph from a given airport"
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

            // "(2) Using BFS, traverse the graph until a destination airport from a given airport"
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

            case 3:{
                string start; 

                cout << "Enter the name of source airport name, \nor enter 'default' to use 'Newark Liberty International Airport' as start and 'Gold Coast Airport' as end:\n";
                
                cin.ignore();
                getline(std::cin, start);

                if(start == "default"){
                    Djikstras shortestpath = Djikstras(airportGraph, "Newark Liberty International Airport", "Gold Coast Airport");
                    vector<string> path = shortestpath.getPathVertices();
                    double distance = shortestpath.getShortestDistance();

                    cout<<"Airports Visited: \n"<<endl;
                    for (unsigned long i = 0; i < path.size(); i++) {
                        cout << path[i];
                        if(i != path.size()-1)
                            cout<< " --> ";
                        if(i%4 == 0 && i != 0)
                            cout << "" << endl;
                    }
                    cout<<""<<endl;
                    cout<<"Total Distance: "<< distance << " KM" << endl;
                } else {
                    cout << "Enter the end location:\n";
                    string end; 
                    getline(std::cin, end);
                    Djikstras shortestpath = Djikstras(airportGraph, start, end);
                    vector<string> path = shortestpath.getPathVertices();
                    double distance = shortestpath.getShortestDistance();
                    if(distance == 0.0){
                        cout<< "One or more airport not found!"<<endl;
                        break;
                    }
                    cout<<"Airports Visited: \n"<<endl;
                    for (unsigned long i = 0; i < path.size(); i++) {
                        cout << path[i];
                        if(i != path.size()-1)
                            cout<< " --> ";
                        if(i%4 == 0 && i != 0)
                            cout << "" << endl;
                    }
                    cout<<""<<endl;
                    cout<<"Total Distance: "<< distance << " KM" << endl;
                }
                break;
            }

            case 4:{
                string airportFile = "airports.dat";
                string routesFile = "routes.dat";
                Graph airportGraph(airportFile, routesFile);
                unordered_map<int, Airport> airportMap = airportGraph.getVertices();
                if(true){
                    PageRank *test = new PageRank();                      //create pagerank obj
                    airportGraph.adjMatrix(test);                         //generate initial adjmatrix from graph
                    test->makeA(test->num, 0.85);                         //finalize adjmatrix
                    vector<double> initial = test->initial_vector();      //generate initial vector 
                    vector<double> re = test->rank(initial, 100, false);           //perform pagerank alg, 100 iteration                        
                    cout << "\nHow many of the most important airports do you want to print? (Enter a number): \n";
                    int top;
                    cin >> top; 
                    vector<int> id_rank = test->top_airport(top);           //pickout the top top important airport        
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

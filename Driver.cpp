#include <iostream>
#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"
#include "DirectedGraph.h"
#include "UndirectedGraph.h"
#include <vector>

using namespace std;

void TestInputDirected();
void DirectedProgram();
void UndirectedProgram();
void TestInputUndirected();

int main()
{   
    //WARNING!!!!
    //Uncomment the functions to see the different implementations
    
    //DirectedProgram();//first
    //UndirectedProgram();//second
    //TestInputDirected();//third
    //TestInputUndirected();//fourth

    return 0;
}

void TestInputDirected() 
{
    DirectedGraph D1;
    cout << "DIRECTED GRAPH" << endl;
    cin >> D1;
    cout << D1;
}

void TestInputUndirected() 
{
    UndirectedGraph D1;
    cout << "UNDIRECTED GRAPH" << endl;
    cin >> D1;
    cout << D1;
}

void DirectedProgram() 
{
    Vertex N1("India", "1");
    Vertex N2("Canada", "2"); 
    Vertex N3("Spain", "3");
    Vertex N4("Nigeria", "4");
    Vertex N5("Peru", "5");
    vector <Vertex> my_nodes{ N1,N2,N3,N4,N5 }; //Create Nodes

    Edges E1(N1, N2);
    Edges E2(N2, N3);
    Edges E3(N3, N4);
    Edges E4(N4, N5);
    Edges E5(N2, N5);
    Edges E6(N4, N2);
    
    vector<Edges> Edge_Graph{ E1,E2,E3,E4,E5}; // couple of edges

    Graph* G1;
    
    DirectedGraph graph1(my_nodes, Edge_Graph);

    G1 = &graph1;

    cout << "--Directed Paths--"<<endl;
    
    G1->printALLpath();

    Graph* G2; // use of polymorphism
    DirectedGraph My_Graph(my_nodes, Edge_Graph);
    G2 = &My_Graph; // assign My_graph adress to the graph pointer
    
    cout << "Searching graph for Edge 1" << endl;
    G2->SearchEdge(E1); 
    
    cout << "Searching graph for Edge 6" << endl;
    G2->SearchEdge(E6); // should not exist
 
    G2->AddEdges("India", "Spain");

    cout << "Adding Edge 6...\n" << endl;
    G2->AddEdges(E6);
    cout << "Searching graph for Edge 6" << endl;
    G2->SearchEdge(E6); //should exist

    cout << "Searching graph for Ukraine (Vertex 6)" << endl;
    G2->FindValue("6");

    cout << "\nAdding Vertex 6..." << endl;
    G2->AddNode("Ukraine", "6"); // adding nodes
    cout << "\nSearching graph for Vertex 6:" << endl;
    G2->FindValue("6"); // 90

    cout << "\nSearching graph for Vertex 1" << endl;
    G2->FindValue(N1);// 1, 100
    cout << "\nDisplaying paths from Vertex 1:"<<endl;
    G2->printpath(N1);
}

void UndirectedProgram() 
{
    Vertex N1("India", "1");
    Vertex N2("Canada", "2");
    Vertex N3("Spain", "3");
    Vertex N4("Nigeria", "4");
    Vertex N5("Peru", "5");
    vector <Vertex> my_nodes{ N1,N2,N3,N4,N5 }; //Create Nodes

    Edges E1(N1, N2);
    Edges E2(N2, N3);
    Edges E3(N3, N4);
    Edges E4(N4, N5);
    Edges E5(N2, N5);
    Edges E6(N4, N2);

    vector<Edges> Edge_Graph{ E1,E2,E3,E4,E5 }; // couple of edges

    Graph* G2;

    UndirectedGraph graph2(my_nodes, Edge_Graph); // undirected graph
   
    G2 = &graph2;

    cout << "--Undirected Paths--" << endl;

    G2->printALLpath();

    Graph* G3; // use of polymorphism
    UndirectedGraph My_Graph(my_nodes, Edge_Graph);
    G3 = &My_Graph; // assign My_graph adress to the graph pointer

    cout << "Searching graph for Edge 1" << endl;
    G3->SearchEdge(E1);

    cout << "Searching graph for Edge 6" << endl;
    G3->SearchEdge(E6); // should not exist

    G3->AddEdges("India", "Spain");

    cout << "Adding Edge 6...\n" << endl;
    G3->AddEdges(E6);
    cout << "Searching graph for Edge 6" << endl;
    G3->SearchEdge(E6); //should exist

    cout << "Searching graph for Ukraine (Vertex 6)" << endl;
    G3->FindValue("6");

    cout << "\nAdding Vertex 6..." << endl;
    G3->AddNode("Ukraine", "6"); // adding nodes
    cout << "\nSearching graph for Vertex 6:" << endl;
    G3->FindValue("6"); // 90

    cout << "\nSearching graph for Vertex 1" << endl;
    G3->FindValue(N1);

    cout << "\nDisplaying paths from Vertex 1:" << endl;
    G3->printpath(N1);

}


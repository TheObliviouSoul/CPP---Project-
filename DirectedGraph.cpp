#include <iostream>
#include <vector>
#include "Edge.h"
#include "DirectedGraph.h"

using namespace std;

DirectedGraph::DirectedGraph() {
    cout << "Empty directed graph created" << endl;
}
DirectedGraph::DirectedGraph(Vertex vertex1, Edges edge1) :Graph(vertex1, edge1) {}

DirectedGraph::DirectedGraph(vector<Vertex> The_vertex, vector<Edges>The_edge) : Graph(The_vertex, The_edge) {}

DirectedGraph::DirectedGraph(const DirectedGraph& My_direct_Graph) {
    All_Edges = My_direct_Graph.All_Edges;
    All_Vertex = My_direct_Graph.All_Vertex;
    AvoidDuplicate();
}

const DirectedGraph& DirectedGraph:: operator=(const DirectedGraph& My_graph) {
    // for self assignment need to overload bool == 
    All_Edges = My_graph.All_Edges;
    All_Vertex = My_graph.All_Vertex;
    AvoidDuplicate();
    return *this;
}

// mutator
void DirectedGraph::setEdges(vector<Edges>& The_Edges) {
    All_Edges = The_Edges;
    Graph::AvoidDuplicate();
}
void DirectedGraph::AddEdges(Edges& The_edge) 
{

    if (checkEdges(The_edge) == true) { return; } // check if the edge already exist if it does than stops the functions
    else {
        All_Edges.push_back(The_edge);
        ConvertEdge(The_edge);
    }

}

void DirectedGraph::AddEdges(string value1, string value2) 
{
    if (checkEdges(value1, value2) == true) { // if this is true then no need to add edges .
        return;
    }
    else {
        Edges Edge1(value1, value2);
        All_Edges.push_back(Edge1);
        ConvertEdge();
    }
}

void DirectedGraph::RemoveEdge(const Edges& The_Edge) {
    string a, b;
    for (int i = 0; i < All_Edges.size(); i++) {

        a = All_Edges.at(i).getfirstVertex();
        b = All_Edges.at(i).getSecondVertex();

        if (a == The_Edge.getfirstVertex() && b == The_Edge.getSecondVertex()) {
            All_Edges.erase(All_Edges.begin() + i); // erase the pair at index i .
            return; // stop loops as edge removed
        }
    }
    cout << "No edge found to remove " << endl;
}

void DirectedGraph::RemoveEdge(string value1, string value2) {
    string a, b;
    for (int i = 0; i < All_Edges.size(); i++) {

        a = All_Edges.at(i).getfirstVertex();
        b = All_Edges.at(i).getSecondVertex();

        if (a == value1 && b == value2) {
            All_Edges.erase(All_Edges.begin() + i); // erase the pair at index i .
            return; // stop loops as edge removed
        }
    }
    cout << "No edge found to remove " << endl;
}

void DirectedGraph::Display() {
    cout << "This is a Directed Graph" << endl;

    cout << "\nVertices :" << endl;
    //cout << All_Vertex.size() ; //for testing purposes

    for (int i = 0; i < All_Vertex.size(); i++) 
    {
        cout << All_Vertex.at(i);
    }
    cout << "\nEdges : " << endl; 
    for (int i = 0; i < All_Edges.size(); i++) 
    {
        cout << All_Edges.at(i);
    }
}

istream& operator>>(istream& Input, DirectedGraph& My_graph) {
    string destination;
    size_t a = 0;
    size_t b = 0;
    Vertex N1;
    Edges E1;
    int magnitude;
    My_graph.All_Vertex.clear();
    My_graph.All_Edges.clear();

    cout << "Enter number of Vertices" << endl;
    Input >> a;

    for (int i = 0; i < a; i++) //Vertex
    { 
        Input >> N1;
        My_graph.All_Vertex.push_back(N1);
    }

    cout << "Enter number of Edges " << endl;
    Input >> b; // instead of resizing we can use this

    for (int i = 0; i < b; i++) // set the edges
    { 
        Input >> E1;
        cout << "Enter magnitude: " << endl;
        Input >> magnitude;
        E1.setMagnitude(magnitude);

        /*int total{};
        for (int i = 0; i < b; i++)
        {
            total += E1.getMagnitude();
            cout << total;
        }*/

        //cout << total;
        My_graph.All_Edges.push_back(E1);
    }
    // we could also check if we already have a graph instead of resetting it completly we could simply add nodes,etc. 

    return  Input;
}

ostream& operator<<(ostream& Output, const DirectedGraph& My_graph)
{
    Output << "This is the output of a Directed Graph" << endl;

    Output << "Vertex :" << endl;
    // cout << All_Vertex.size() ; for testing purposes

    for (int i = 0; i < My_graph.All_Vertex.size(); i++) 
    {
        Output << "ID: " << My_graph.All_Vertex.at(i).getID();
        Output << " Country: " << My_graph.All_Vertex.at(i).getValue() << endl;
    }

    Output << "\nDireted Path:" << endl; // links only the ID not the values as the value is fixed for each nodes we can inquire about them later to
    for (int i = 0; i < My_graph.All_Edges.size(); i++) 
    {
        Output << "(" << My_graph.All_Edges.at(i).getfirstVertex() << " -> ";
        Output << My_graph.All_Edges.at(i).getSecondVertex() << ")" << endl;
        Output << "Magnitude = "<< My_graph.All_Edges.at(i).getMagnitude()<<" km\n\n";
        
    }

    for (int i = 0; i < My_graph.All_Edges.size(); i++) 
    {
        int j = 0;
        Output << "(" << My_graph.All_Vertex.at(i).getValue() << " -> ";
        Output << My_graph.All_Vertex.at(++j).getValue() << ")" << endl;
        Output << "Magnitude = " << My_graph.All_Edges.at(i).getMagnitude() << " km" << endl;
    }

    return Output;
}
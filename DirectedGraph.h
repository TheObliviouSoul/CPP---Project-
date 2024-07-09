#pragma once

#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRPAH_H

#include "Graph.h" 

class DirectedGraph : public Graph {
private:

public:
    DirectedGraph();
    DirectedGraph(Vertex, Edges);
    DirectedGraph(vector<Vertex>, vector<Edges>); //vector nodes
    DirectedGraph(const DirectedGraph&);          //copy constructor

    void setEdges(vector<Edges>&);                // set a vecotr of edges

    void AddEdges(Edges&);
    void AddEdges(string, string);

    void RemoveEdge(const Edges&);                //avoid the object changing with const
    void RemoveEdge(string, string);              //calls the graph remove edge as it is that one or make the graph one an abstract case and use it here .
    void Display();

    //operator overloading
    const DirectedGraph& operator=(const DirectedGraph&);

    //ostream overload
    friend ostream& operator<<(ostream&, const DirectedGraph&);
    friend istream& operator>>(istream&, DirectedGraph&); //input edge

};

#endif 
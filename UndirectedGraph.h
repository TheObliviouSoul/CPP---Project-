#pragma once

#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include "Graph.h"

using std::ostream;

class UndirectedGraph : public Graph 
{
private:
    void ReverseEdges();

public:
    UndirectedGraph();
    UndirectedGraph(vector<Vertex>, vector<Edges>);
    UndirectedGraph(Vertex, Edges);
    UndirectedGraph(const UndirectedGraph&);        //copy constructor ;

    void setEdges(vector<Edges>&);                  //edit protected  data member

    void Display();                              

    void AddEdges(Edges&);
    void AddEdges(string, string);   // need to reverse the edge as well .
    void RemoveEdge(string, string); // need to remove both from 1->2 and 2->1
    void RemoveEdge(const Edges&);

    //operator overloading 
    //assign operator
    const UndirectedGraph& operator=(const UndirectedGraph&);

    //ostream overload
    friend ostream& operator<<(ostream&, const UndirectedGraph&);
    friend istream& operator>>(istream&, UndirectedGraph&);         //input edge

};


#endif
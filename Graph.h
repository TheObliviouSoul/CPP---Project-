#pragma once

#ifndef GRAPHS_H
#define GRAPHS_H

#include <iostream>
#include <vector>
#include <cmath>
#include "Vertex.h"
#include "Edge.h"

using namespace std;


//Everything common to directed and undirected graph is here else its in the respective class.

// declaring my std separatly ;
using std::cout; using std::endl; using std::vector;
using std::pair; using std::ostream;

class Graph {
protected:
    //  vector <Nodes> name ;
    vector<Vertex> All_Vertex; //the type is Nodes
    vector<Edges> All_Edges;   //the type is Edge

public:
    Graph(); //
    Graph(Vertex, Edges);                  //if passing one node and one edges
    Graph(vector<Vertex>, vector<Edges>);  //if we want to initialize a graph with multiple nodes and edges in one go
    Graph(const Graph&);                   //copy constructors ;
    ~Graph();

    void operator=(const Graph&);          //overloading graph ;

    // Mutator and Accessor :
    vector<Vertex> getNodes() const;
    vector<Edges> getEdges() const;

    void setNodes(vector<Vertex>&);            //pass by ref to be a more efficient
    virtual void setEdges(vector<Edges>&) = 0; //different for directed and undirected graph

    // Add and remove nodes .The same for both graph
    void AddNode(Vertex&);                  //adding the object
    void AddNode(string, string);           //adding a node by id and value               

                                            // boolean function to help with the implementation
    bool CheckIdNode(const Vertex&);        //check if the node already exist
    bool CheckIDNode(string);               //check if the node already exist
    bool checkEdges(const Edges&);          //check if the edge already exist to avoid any duplicate .
    bool checkEdges(const string, const string); // check if the edge already exist to avoid duplicate edges.


    //Add or remove an Edge ;
    virtual void AddEdges(Edges&) = 0;
    virtual void AddEdges(string, string) = 0;     //using id1->id2

    virtual void RemoveEdge(const Edges&) = 0;
    virtual void RemoveEdge(string, string) = 0;   //abstarct forces to use polymorphism 
    // Other function
    void ConvertEdge();                            //convert Edges to Nodes if we have nodes that are not declared
    void ConvertEdge(Edges&);
    void AvoidDuplicate();                         //delete any node added twice by id .

    // Print the Path of a graph ;
    void printpath(string);                        //print the path from the nodes. all links from the nodes
    void printpath(const Vertex&);
    void printALLpath();

    void printlink(string);                         //used to print the link to the edge

   //find the value node
    void FindValue(const Vertex&);
    void FindValue(string); // "200"

    void SearchEdge(const Edges&);
    void SearchEdge(string, string);

    // print the graph
    virtual void Display() = 0;                     //need to call directed or directed display function
};

#endif
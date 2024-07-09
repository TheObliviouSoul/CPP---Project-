#pragma once

#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include "Vertex.h"
#include <vector>
#include<string>

using namespace std;

class Edges 
{
private:
    pair <string, string> My_Edges;     //ID for the first link to the second link (x,y)
    int Magnitude;                      //weigth between the path .
    string value1, value2;              //values of the nodes in the edges
                                        //(x,y)

public:
    Edges();
    Edges(string, string, int);         //path + the weight
    Edges(string, string);              // will need to convert this to nodes with values of 0 , if no id exist as nodes now have values
    Edges(Vertex&, Vertex&);            //id + value
    Edges(const Edges&);                //copy constructor
    ~Edges();                           //destuctor

    // Accessing functions :
    void setEdges(string, string, int);
    void setEdges(string, string);

    string getfirstVertex() const;      //return id of the first node (Node1,Node2)
    string getSecondVertex() const;
    int getMagnitude() const;
    void setMagnitude(int);

    string getValue1() const;
    string getValue2() const;

    Vertex getVertex1() const;
    Vertex getVertex2() const;

                                          //Operator overloading
    const Edges& operator=(const Edges&); //Operator overload assign
    //ostream overload

    friend ostream& operator<<(ostream&, const Edges&);
    friend istream& operator>>(istream&, Edges&);       //input edge



};
#endif 
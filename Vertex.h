#pragma once

#ifndef VERTEX_H
#define VERTEX_H

#include<iostream>
#include <vector> 
#include<string>

using namespace std;

class Vertex 
{
private:
    string Id;                      //the location of the Node
    string value;                   //the weight or how much is the node worth
    pair <string, string> My_Vertex;

                                    //contains ID and value .
public:

    Vertex();                       //empty nodes
    Vertex(string, string);         //id , value
    Vertex(string);                 //nodes with only an id no values ;
    Vertex(const Vertex&);          //copy constructor
    ~Vertex();

    void setVertex(string, string); //set nodes with ID and value

                                    
    string getID() const;           //return the ID of the
    string getValue() const;        //return the value of the node

    const Vertex& operator=(const Vertex&);
    const Vertex& operator=(const string&); // only Id no value


    friend std::ostream& operator<<(std::ostream&, const Vertex&);
    friend istream& operator>>(istream&, Vertex&); // input edge

};

#endif

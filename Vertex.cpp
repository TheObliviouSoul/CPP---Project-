#include <iostream>
#include "Vertex.h"

Vertex::Vertex() {}

Vertex::Vertex(string My_Id, string My_value) : Id(My_Id), value(My_value) 
{
  
}
// using member initialization list.

Vertex::Vertex(string value1) : Id(value1), value("0") {};
// using member initialization list

Vertex::Vertex(const Vertex& My_node) 
{
    Id = My_node.Id;
    value = My_node.value;
}
Vertex::~Vertex() {};


// Accesor and mutators

void Vertex::setVertex(string My_Id, string My_value) 
{ // canot use member initialization here because not a constructor
    Id = My_Id;
    value = My_value;
}

string Vertex::getID() const 
{
    return Id;
}
string Vertex::getValue() const 
{
    return value;
}

// operator overloading
const Vertex& Vertex::operator=(const Vertex& My_node) 
{
    if (&My_node == this) { // avoid self assignment
        return *this;
    }
    Id = My_node.Id;
    value = My_node.value;
    return *this;
}

const Vertex& Vertex::operator=(const string& value) 
{
    if (this->Id == value) { return *this; } // check if id is the same if the same then returns as we already have it .
    Id = value;
    this->value = "0"; // set the value to 0 as only the id is given
    return *this;
}

ostream& operator<<(ostream& Output, const Vertex& My_node)
{
    Output << "Country: " << My_node.getID() <<endl<< "ID: " << My_node.getValue() << endl;
    return Output;
}

istream& operator>>(istream& Input, Vertex& My_node)
{
    cout << "Enter ID " << endl;
    Input >> My_node.Id;

    cout << "Enter Destination: " << endl;
    Input >> My_node.value;

    return Input;
}
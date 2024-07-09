#include <iostream>
#include "Vertex.h"
#include "Edge.h"

Edges::Edges() 
{
    Magnitude = 0;
}

Edges::Edges(string first, string second, int Weight) : My_Edges(make_pair(first, second)), Magnitude(Weight), value1("0"), value2("0") {}

Edges::Edges(string first, string second) : My_Edges(make_pair(first, second)), Magnitude(0), value1("0"), value2("0") {}
// using member initialization list

Edges::Edges(Vertex& node1, Vertex& node2) 
{
    string a, b;
    a = node1.getID();
    b = node2.getID();

    value1 = node1.getValue();
    value2 = node2.getValue();

    My_Edges = make_pair(a, b);

}

Edges::Edges(const Edges& Edge2) {
    
    //cout << "Edges copy constructor"  << endl;
    this->My_Edges = make_pair(Edge2.My_Edges.first, Edge2.My_Edges.second);
    this->value1 = Edge2.value1;
    this->value2 = Edge2.value2;

}
//assign operator overload
const Edges& Edges :: operator=(const Edges& Edge2) {
    //cout << "assignment opperator "  << endl;
    My_Edges = make_pair(Edge2.getfirstVertex(), Edge2.getSecondVertex());
    value1 = Edge2.value1;
    value2 = Edge2.value2;
    return *this;
}
Edges :: ~Edges() {};


void Edges::setEdges(string value1, string value2, int value3) 
{
    My_Edges = make_pair(value1, value2);
    Magnitude = value3;
}

void Edges::setEdges(string value1, string value2) 
{
    My_Edges = make_pair(value1, value2);
    Magnitude = 0;
}

string Edges::getfirstVertex() const {                          //returns the first node of the edge
    return My_Edges.first;
}
string Edges::getSecondVertex() const {
    return My_Edges.second;
}


int Edges::getMagnitude() const
{
    return Magnitude;
}
void Edges::setMagnitude(int Magnitude)
{
    this->Magnitude = Magnitude;
}

string Edges::getValue1() const {
    return value1;
}
string Edges::getValue2() const {
    return value2;
}
Vertex Edges::getVertex1() const {

    Vertex N1(My_Edges.first, value1);
    return N1;
}
Vertex Edges::getVertex2() const 
{
    const Vertex N2(My_Edges.second, value2);
    return N2;
}
ostream& operator<<(ostream& Output, const Edges& My_edge) {
    Output << "Edge: (" << My_edge.getfirstVertex() << "," << My_edge.getSecondVertex() << ")" << endl;

    return Output;
}

istream& operator >> (istream& Input, Edges& MY_Edge) 
{

    string a, b, c;
    cout << "enter the first vertex ID " << endl;
    Input >> a;

    cout << "Enter the second vertex ID " << endl;
    Input >> b;

    MY_Edge.My_Edges = make_pair(a, b);

    return Input;
}

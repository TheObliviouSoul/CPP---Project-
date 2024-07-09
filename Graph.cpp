#include "Graph.h"

Graph::Graph() 
{
    cout << "Empty graph created " << endl;
}

Graph::Graph(Vertex firstnode, Edges firstEdge) {
    All_Vertex.push_back(firstnode);
    All_Edges.push_back(firstEdge);
    ConvertEdge(firstEdge);                                 //convert the edge into nodes

    cout << "Graphs with node and edge created " << endl;
}

Graph::Graph(vector<Vertex> MultiNodes, vector<Edges> MultiEdges) :All_Vertex(MultiNodes), All_Edges(MultiEdges) {
    for (int i = 0; i < MultiEdges.size(); i++) {
        ConvertEdge(MultiEdges[i]);
    }                                                       //convert it to keep the values of the edges.
    AvoidDuplicate();                                       //avoid any duplicates while constructing the graph

}

Graph::Graph(const Graph& My_graph) 
{
    All_Edges = My_graph.All_Edges;
    All_Vertex = My_graph.All_Vertex;

    for (int i = 0; i < All_Edges.size(); i++) 
    {
        ConvertEdge(All_Edges[i]);
    } 
    AvoidDuplicate();
}
Graph :: ~Graph() {
    All_Edges.clear();
    All_Vertex.clear();
}

void Graph::operator=(const Graph& My_graph) {
    All_Edges = My_graph.All_Edges;
    All_Vertex = My_graph.All_Vertex;
    for (int i = 0; i < All_Edges.size(); i++) {
        ConvertEdge(All_Edges[i]);
    }
    AvoidDuplicate();
}
                                                    //Accesing functions 
vector<Vertex> Graph::getNodes() const {
    return All_Vertex;
}

vector<Edges> Graph::getEdges() const {
    return All_Edges;
}

void Graph::setNodes(vector<Vertex>& The_Nodes) {
    All_Vertex = The_Nodes;
    AvoidDuplicate();
}


//  bool function to verify if the node or edge was already added
bool Graph::CheckIdNode(const Vertex& TheNode) {
    for (int i = 0; i < All_Vertex.size(); i++) {
        if (All_Vertex.at(i).getID() == TheNode.getID()) {
            return true;
        }
    }
    return false;
}

bool Graph::CheckIDNode(string value) {                             //pass the id to verify if a node already exist before adding
    for (int i = 0; i < All_Vertex.size(); i++) {                   //this is done to try and avoid as many duplicate as possible should avoid all of them but i already have a avoid duplicate function so will add it .
        if (All_Vertex.at(i).getID() == value) {
            return true;
        }
    }
    return false;
}

// check the edges of the graph
bool Graph::checkEdges(const Edges& The_Edge) {
    for (int i = 0; i < All_Edges.size(); i++) {
        if (All_Edges.at(i).getfirstVertex() == The_Edge.getfirstVertex() && All_Edges.at(i).getSecondVertex() == The_Edge.getSecondVertex()) {
            return true;
        }
    }
    return false;
}

bool Graph::checkEdges(const string value1, const string value2) {
    for (int i = 0; i < All_Edges.size(); i++) {
        if (All_Edges.at(i).getfirstVertex() == value1 && All_Edges.at(i).getSecondVertex() == value2) 
        {
            return true;
        }
    }
    return false;
}

// Add and remove Nodes from a graph

void Graph::AddNode(Vertex& My_node) { // pass the actual object
    if (CheckIDNode(My_node.getID()) == false) { // avoid pushing a already exisitng node
        All_Vertex.push_back(My_node);
    }
    else {
        cout << "the id of that node already exists " << endl;
    }
    //AvoidDuplicate() ; // from my proposition i had this not required because of bool
}// If we want to add a node we check if the node already exist and then add it if it doesn't

void Graph::AddNode(string value1, string value2) {
    Vertex N1(value1, value2); // create an object for node
    if (CheckIDNode(value1) == false) { // avoid pushing a already exisiting nodes
        All_Vertex.push_back(N1); // add the object to the vectors of nodes.
    }
    // AvoidDuplicate() ;
}

// convert the edges
void Graph::ConvertEdge() {
    string a, b;
    Vertex NewNode;
    for (int j = 0; j < All_Edges.size(); j++) {
        a = All_Edges.at(j).getfirstVertex();
        b = All_Edges.at(j).getSecondVertex();
        if (CheckIDNode(a) == false) {
            NewNode = a;
            All_Vertex.push_back(NewNode);
        }
        if (CheckIDNode(b) == false) {
            NewNode = b;
            All_Vertex.push_back(b);
        }
    } // copies all the points into one vector Vertices.
}
void Graph::ConvertEdge(Edges& the_edges) {
    string a, b, c, d; // Id of the nodes.

    a = the_edges.getfirstVertex();
    b = the_edges.getValue1();
    c = the_edges.getSecondVertex();
    d = the_edges.getValue2();
    Vertex N1(a, b);
    Vertex N2(c, d);

    if (CheckIDNode(a) == false) {
        // cout << "ajkldfha" <<endl;
        All_Vertex.push_back(N1);
    }
    if (CheckIDNode(c) == false) {
        //cout << N2  << endl ;
        All_Vertex.push_back(N2);
    }


}

// Avoid doubles nodes
void Graph::AvoidDuplicate() {
    int a = 0, b = 0;
    // linear way of removing element .
    for (a = 0; a < All_Vertex.size(); a++) {
        for (b = a + 1; b < All_Vertex.size(); b++) { // loop over the vector until its end starting from the next index of i .
            //     cout << a << " " << b << endl ; for testing
            if (All_Vertex.at(a).getID() == All_Vertex.at(b).getID()) { // check if [1,1,2,3 ] check element at index 1 is the same as index 2 ....
                All_Vertex.erase(All_Vertex.begin() + b);// erase element at index i ; // erase at index b ;
                a = 0; b = 0; // set a and b to beginning of vector to start linear search again .

            }
            else { continue; }
        }
    }
}


void Graph::printlink(string value1) {
    string a, b;

    for (int i = 0; i < All_Edges.size(); i++) 
    {
        a = All_Edges.at(i).getfirstVertex();
        b = All_Edges.at(i).getSecondVertex();

        if (a == value1) 
        {
            cout << "(" << value1 << " -> " << b << ")" << endl;
        }
    }

}

void Graph::printpath(const Vertex& The_Node) { // list the path it leads


    string a, b;
    printlink(The_Node.getID());

    for (size_t i = 0; i < All_Edges.size(); i++) {
        a = All_Edges[i].getfirstVertex();
        b = All_Edges[i].getSecondVertex();

        if (a == The_Node.getID()) {

            Graph::printlink(b);                        //check if any other link to print it as well .
        }
    }

}

void Graph::printpath(string value1) {

    Graph::printlink(value1);                           //call the print link to print it

    string a, b, c, d;                                  //storage for path
    for (int i = 0; i < All_Edges.size(); i++) {
        a = All_Edges[i].getfirstVertex();
        b = All_Edges[i].getSecondVertex();

        if (a == value1) {
            Graph::printlink(b);                        //check if any other link to print it as well . 
        }
    }

}
void Graph::printALLpath() { // I added this function in order to be able to display all node paths
    for (int i = 0; i < All_Vertex.size(); i++) {
        cout << All_Vertex[i] << "Path: " << endl;
        printpath(All_Vertex[i]);
        cout << endl;
    }
}

void Graph::FindValue(const Vertex& My_node) {
    int A = 0;
    for (int i = 0; i < All_Vertex.size(); i++) {
        if (My_node.getValue() == All_Vertex.at(i).getValue()) {
            cout << "Value found at:"<< My_node;
            ++A;
        }
    }
    if (A == 0) { // just to return not found if not found
        cout << "Not found " << endl;
        return;
    }

}

void Graph::FindValue(string value1) {
    int A = 0;
    for (int i = 0; i < All_Vertex.size(); i++) {
        if (value1 == All_Vertex.at(i).getValue()) {
            cout << "Value found at:" << "\n" << All_Vertex.at(i);
            A++;
        }
    }
    if (A == 0) {
        cout << "Not found " << endl;
        return;
    }

}

void Graph::SearchEdge(string value1, string value2) 
{
    if (checkEdges(value1, value2) == true) 
    {
        cout << "The edge: (" << value1 << "," << value2 << ") exist in the graph" << endl;
    }
    else { cout << "The edge does not exist in the graph" << endl; }
}

void Graph::SearchEdge(const Edges& My_edge) 
{
    if (checkEdges(My_edge) == true)
    {
        cout << My_edge << endl;
    }
    else {
        cout << "The Edge does not exist in the graph" << "\n\n";
    }
}
Abstract
A graph is a set of objects, called vertices or nodes, that are connected by an edge. A directed graph is where all the edges are directed from one vertex to another. 
In contrast, a graph where the edges are bidirectional is called an undirected graph. A graph has many useful applications in the real world, such as scheduling tasks, network topology, family tree, data compression, literature citation, social connections, etc. 
This paper summarizes the development of an object-oriented application of a graph, more specifically in the context of travel and connecting flights.

I.	INTRODUCTION
In object-oriented programming, a graph can be a very useful tool in the development of applications. This project places an emphasis on directed and undirected graphs that are both used in the application described in this paper. 
The application’s goal is to be capable of planning a travel route from country to country along with the distance each flight would undergo from one country to the next, and it can be run in two different ways. 
The first implements a directed graph that prompts the user to enter the number of vertices they want (i.e., the number of countries) followed by an ID number and country name for each vertex, and then prompts the user for the number of edges (i.e., the number of flights) followed by the desired path from one vertex ID to another. 
Once the user has entered all the necessary information, the program will output each vertex and their connecting vertices, and then the path from the country of departure to the destination. The second implements an undirected graph with the same functionality, thus displaying a return flight for each leg of the trip. 
Therefore, if the user wished to travel from Canada to India and then to Spain, the resulting flights shown would be Canada to India, as well as India to Canada, followed by India to Spain and then Spain to India.

II.	MEMBER FUNCTIONS
A.	checkEdges()
This member function checks if the new edge is already in the graph and has two different implementations. Both implementations utilize a for loop that loops through the vector of edges. 
Inside the for loop is an if statement that checks if the first and second node of the new edge is equal to a first and second node in the vector of edges. The if statement returns true if this condition is true, which means the new edge is already an edge in the vector. 
If the condition is false for every edge in the vector, it will exit the loop and return false. The difference between the two implementations is that one takes a reference to an edge object as its parameter, while the other takes in two strings representing the first and second nodes of the edge being checked.

B.	addEdges()
This function adds an edge to the graph if the edge doesn’t already exist and has two implementations similar to the checkEdges() function. 
One takes a reference to an edge object as its parameter, while the other takes in two strings representing the first and second nodes of the edge being added. 
Both implementations utilize an if-else statement that calls the checkEdges() function and will “return” if it is equal to true. If the condition is not met, an edge object is instantiated with the parameterized data and stored in the vector of edges using push_back(). 
Once added to the vector of edges, the convertEdge() function is called and loops through the vector of edges checking if each node of the new edge is already in the vector. If either one or both are not, a new vertex object will be instantiated and stored in the vector of vertices using push_back().
 
III.	TECHNIQUES IMPLEMENTED
A.	Inheritance
The application consists of two subclasses, DirectedGraph and UndirectedGraph, both of which are derived from the base class Graph.
 The Graph class contains the searching and adding functions that both subclasses utilize, as well as a pure virtual Display() function.
B.	Polymorphism
	One of the key features of inheritance is that a pointer to a derived class is type-compatible with a pointer to its base class, and polymorphism takes advantage of this versatile feature.  
In function main(), a pointer to Graph is declared, which is then assigned to the address of the DirectedGraph or UndirectedGraph object, which can be done as both are derived from Graph. Additionally, the base class contains a pure virtual Display() function that gets implemented in both derived classes.
C.	Operator Overloading
Operator overloading allows us to define a function name or an operator in the same scope. They’re functions that have the same name except their passing in different arguments. 
In the Vertex.h file there is a constant operator function of type Vertex, one of the functions is taking a constant Vertex reference while the other one s taking a constant string reference. Instead of putting in a value for the ID , the ID could also be a string. 

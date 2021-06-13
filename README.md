# Graphs
A simple basic graph implementation in C++.

## Execution
It is not a lenghty project but gives a basic idea of graphs. Open the file in Visual Studio and Execute the code there.

## What it does?
1. Build a graph class for a simple undirected graph that uses adjacency list representation. Simple means
that between any two vertices in a graph G, there will be only one edge.
2. For each vertex you need to remember the vertex id, name, marker (for visited), list of adjacent nodes.
Make a class for vertex. A vertex will have following attributes:
      * Vertex Id: int
      * Vertex name: char or string (your choice).
      * Marker: a bool, it will keep track of the fact that vertex is visited or not. We added this as most of
      the graph algorithms need to mark the vertex.
      * List of ids of adjacent nodes. Use std linked list.
3. Keep an array of vertices in graph class. Do not keep a linked list of vertices. Because that will increase the
time complexity of graph functions like DFS and BFS .
4. Provide following functions in your undirected graph class
      * Constructor
      * Destructor
      * AddEdge(int vertexId1 , int vertexId2 )


              i. Input two vertex ids and add an edge between them that is it will add vertex with vertexId2 at the end of vertexId1’s adjacency list and vice versa.
              ii.You can assume that the vertex id is an index in the vertex array. That is vertexId=10 will be
                        at index 10 in the vertex array.
                        
      * AddEdge(vertexname1 , vertexname2 )


            i. Input the names of two vertices and add an edge between them
            ii. Note in this case you will have to search the vertices with given name
      e. AddVertex
      
            i. The function input vertex name from the user
            ii. The function assigns next available free vertex id to the vertex
            iii. Set visited to false
            iv. Set Adjacent nodes to Null. (because we will add adjacent nodes information using add edge function
      f. ResetMarker
      
            i. It will reset the boolean marker in each vertex to zero.
      g. Print the graph in Depth First order
      
            i. print the name of the vertices in order they are visited in DFS
            ii. Run the DFS with the
      h. Print the graph in Breadth First order (print the name of the vertices in order they are visited in
      DFS)
      i. Print the DFS Spanning tree (just output the list of edges in the tree).
      j. Print BFS Spanning tree (just output the list of edges in the tree).

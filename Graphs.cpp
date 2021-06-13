#include <iostream>

#include<list>

using namespace std;



class Vertex

{

	friend class Graph;

private:

	int ID;

	char Name;

	bool Marker;

	list<int> AdjacencyList;

public:

	Vertex(int id = 0, char name = ' ', bool marker = false)

	{

		ID = id;

		Name = name;

		Marker = marker;

	}

};



class Graph

{

private:

	int V;

	Vertex * Array;

public:

	int index = 0;



	Graph(int m)

	{

		V = m;

		Array = new Vertex[V];

	}



	~Graph()

	{

		if (Array)
			delete[]Array;

	}



	void addEdge(int Vertexid1, int Vertexid2)

	{

		if (searchID(Vertexid1, Vertexid2) == false)

			Array[Vertexid1].AdjacencyList.push_back(Vertexid2);

		if (searchID(Vertexid2, Vertexid1) == false)

			Array[Vertexid2].AdjacencyList.push_back(Vertexid1);

	}



	void addEdge(char &Vertexname1, char &Vertexname2)

	{

		int id1, id2 = -1;

		for (int i = 0; i < V; i++)

		{

			if (Array[i].Name == Vertexname1)

				id1 = i;

			else if (Array[i].Name == Vertexname2)

				id2 = i;

		}

		if (id1 != -1 && id2 != -1)

			addEdge(id1, id2);

	}



	bool searchID(int Vertexid1, int Vertexid2)

	{

		list<int>::iterator ite;

		for (ite = Array[Vertexid1].AdjacencyList.begin(); ite != Array[Vertexid1].AdjacencyList.end(); ite++)

		{

			Vertex v = *ite;

			if (v.ID == Vertexid2)

				return true;

		}

		return false;

	}



	void AddVertex(char ch)

	{

		Vertex v(index, ch, false);

		Array[index] = v;

		index++;

	}



	void ResetMarker()

	{

		for (int i = 0; i < V; i++)

			Array[i].Marker = false;

	}



	void DFS()

	{

		bool *visited = new bool[V];

		for (int i = 0; i < V; i++)

			visited[i] = false;



		for (int i = 0; i < V; i++)

			if (visited[i] == false)

				DFShelper(Array[i].ID, visited);

	}



	void DFShelper(int &i, bool visited[])

	{

		cout << i << "\t";



		Array[i].Marker = true;

		visited[i] = true;



		list<int>::iterator ite;

		for (ite = Array[i].AdjacencyList.begin(); ite != Array[i].AdjacencyList.end(); ite++)

		{

			if (!visited[*ite])

				DFShelper(*ite, visited);

		}

	}

	void DFSTree()

	{

		bool *visited = new bool[V];

		for (int i = 0; i < V; i++)

			visited[i] = false;



		for (int i = 0; i < V; i++)

			if (visited[i] == false)

				DFSTreehelper(Array[i].ID, visited);

	}



	void DFSTreehelper(int &i, bool visited[])

	{


		Array[i].Marker = true;

		visited[i] = true;



		list<int>::iterator ite;

		for (ite = Array[i].AdjacencyList.begin(); ite != Array[i].AdjacencyList.end(); ite++)

		{

			if (!visited[*ite]) {
				cout << i << "\t" << *ite << endl;
				DFSTreehelper(*ite, visited);
			}

		}

	}


	void BFS(int v)

	{

		ResetMarker();



		bool *visited = new bool[V];

		for (int i = 0; i < V; i++)

			visited[i] = false;



		list<int>queue;

		queue.push_back(v);

		visited[v] = true;



		list<int>::iterator i;



		while (!queue.empty())

		{

			v = queue.front();

			cout << v << "\t";

			queue.pop_front();



			for (i = Array[v].AdjacencyList.begin(); i != Array[v].AdjacencyList.end(); ++i)

			{

				if (!visited[*i])

				{

					visited[*i] = true;

					queue.push_back(*i);

				}

			}

		}

	}

	void BFSTree(int v)

	{

		ResetMarker();



		bool *visited = new bool[V];

		for (int i = 0; i < V; i++)

			visited[i] = false;



		list<int>queue;

		queue.push_back(v);

		visited[v] = true;



		list<int>::iterator i;



		while (!queue.empty())

		{

			v = queue.front();

			queue.pop_front();



			for (i = Array[v].AdjacencyList.begin(); i != Array[v].AdjacencyList.end(); ++i)

			{

				if (!visited[*i])

				{

					visited[*i] = true;
					cout << v << "\t" << *i << endl;
					queue.push_back(*i);

				}

			}

		}

	}

};



int main()

{

	Graph g(8);



	g.AddVertex('a');

	g.AddVertex('b');

	g.AddVertex('c');

	g.AddVertex('d');

	g.AddVertex('w');

	g.AddVertex('x');

	g.AddVertex('y');

	g.AddVertex('z');



	g.addEdge(0, 1);

	g.addEdge(7, 2);

	g.addEdge(0, 2);

	g.addEdge(3, 6);

	g.addEdge(1, 3);

	g.addEdge(5, 3);

	g.addEdge(7, 5);

	g.addEdge(5, 0);

	g.addEdge(7, 4);

	g.addEdge(6, 1);

	g.addEdge(2, 6);

	g.addEdge(6, 6);

	cout << "DFS:\t";

	g.DFS();

	cout << "\nBFS:\t";

	g.BFS(2);


	cout << endl<<"DFS Tree" << endl;
	g.DFSTree();

	cout << endl<<"BFS Tree" << endl;
	g.BFSTree(0);
	return 0;

}
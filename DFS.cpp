/*
 * Implementation of DFS (Depth First Search)
 */

#include <cstdio>
#include <list>>

class Graph
{
    private:
        int _v;
        std::list<int> *_adj;
        std::list<int>::iterator it;

    public:
        Graph(int v);
        void addEdge(int source, int destination);
        void removeEdge(int source, int destination);
        void printAdjacencyMatrix();
        void DFS(int v);
        void ProcessDFS(int v, bool visited []);
};

Graph::Graph(int v)
{
    _v = v;
    _adj = new std::list<int>[v];
}

void Graph::addEdge(int source, int destination)
{
    if(source < _v && source >= 0 && destination >= 0) // both source and destination are valid
    {
        _adj[source].push_back(destination);
    }
}

void Graph::removeEdge(int source, int destination)
{
    if(source < _v && source >= 0 && destination >= 0)
    {
        for(it = _adj[source].begin(); it != _adj[source].end(); ++it)
        {
            if(*it == destination)
            {
                _adj[source].erase(it);
                break;
            }
        }
    }
}

void Graph::printAdjacencyMatrix()
{
    for(int i = 0; i < _v; ++i)
    {
        if(_adj[i].size() == 0){ continue; }

        printf("[%d] => ", i);

        for(it = _adj[i].begin(); it != _adj[i].end(); ++it)
        {
            printf("%d\t", *it);
        }

        printf("\n");
    }
}

void Graph::DFS(int v)
{
    bool *visited = new bool [v];

    for(int i = 0; i < v; ++i){ visited[i] = false; }

    ProcessDFS(v, visited);
}

void Graph::ProcessDFS(int v, bool visited [])
{
    visited[v] = true;
    printf("%d ", v);

    for(it = _adj[v].begin(); it != _adj[v].end(); ++it)
    {
        if(! visited[*it])
        {
            ProcessDFS(*it, visited);
        }
    }
}

int main()
{
    Graph *g = new Graph(5);
    g->addEdge(0, 1);
    g->addEdge(0, 2);
    g->addEdge(1, 2);
    g->addEdge(2, 0);
    g->addEdge(2, 3);
    g->addEdge(3, 3);
    g->printAdjacencyMatrix();
    g->DFS(3);
    return 0;
}
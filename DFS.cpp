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
        _adj[source].push_front(destination);
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

int main()
{
    Graph *g = new Graph(5);
    g->addEdge(0, 1);
    g->addEdge(2, 3);
    g->addEdge(4, 2);
    g->printAdjacencyMatrix();
    return 0;
}
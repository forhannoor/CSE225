// Implementation of DFS(Depth First Search) algorithm.
#include <cstdio>
#include <list>

class Graph
{
    private:
        int _v;
        std::list<int>* _adj;
        std::list<int>::iterator it;

    public:
        Graph(int v);
        void add_edge(int source, int destination);
        void remove_edge(int source, int destination);
        void print_adjacency_matrix();
        void dfs(int v);
        void process_dfs(int v, bool visited []);
};

Graph::Graph(int v)
{
    _v = v;
    _adj = new std::list<int>[v];
}

// Adds an edge/connection from source to destination.
void Graph::add_edge(int source, int destination)
{
    // If both source and destination are valid.
    if(source < _v && source >= 0 && destination >= 0)
        _adj[source].push_back(destination);
}

// Removes the edge/connection from source to destination.
void Graph::remove_edge(int source, int destination)
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

// Prints adjacency matrix.
void Graph::print_adjacency_matrix()
{
    for(int i = 0; i < _v; ++i)
    {
        // If list for current vertex is empty.
        if(_adj[i].size() == 0)
            continue;

        printf("[%d] => ", i);

        for(it = _adj[i].begin(); it != _adj[i].end(); ++it)
            printf("%d\t", *it);

        printf("\n");
    }
}

void Graph::dfs(int v)
{
    bool* visited = new bool [v];

    for(int i = 0; i < v; ++i)
        visited[i] = false;

    process_dfs(v, visited);
}

void Graph::process_dfs(int v, bool visited [])
{
    visited[v] = true;
    printf("%d ", v);

    for(it = _adj[v].begin(); it != _adj[v].end(); ++it)
        if(! visited[*it])
            process_dfs(*it, visited);
}

int main()
{
    Graph* graph = new Graph(5);
    graph->add_edge(0, 1);
    graph->add_edge(0, 2);
    graph->add_edge(1, 2);
    graph->add_edge(2, 0);
    graph->add_edge(2, 3);
    graph->add_edge(3, 3);
    graph->print_adjacency_matrix();
    graph->dfs(3);
    return 0;
}
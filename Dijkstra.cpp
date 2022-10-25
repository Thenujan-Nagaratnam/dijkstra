#include <limits.h>
#include <stdio.h>
using namespace std;
#include <vector>
#include <iostream>

int minDistance(int distance[], bool visited[])
{
    int minimum_cost = 1000, minimum_index;
 
    for (int i = 0; i < 9; i++){
        if (visited[i] == false && distance[i] <= minimum_cost){
            minimum_cost = distance[i];
            minimum_index = i;
        }
    }
    return minimum_index;
}
 
void print(int distance[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d \t\t %d\n", i, distance[i]);
}

void printPath(int prev[], int endNode, int startNode)
{
    vector<int> vec;
    int Node = endNode;
    while(Node != startNode){

        vec.push_back(Node);
        Node = prev[Node];

    }

    vec.push_back(Node);
    cout<<"shortest path from "<<startNode<<" to "<<endNode<<" is := ";
    for (int i = 0; i<vec.size() ;i++){
        cout<<vec[i]<<" ";
    }

}

void dijkstra(int graph[][], int startNode)
{
    int V = 9;
    int distance[V];
    int prev[V];
    bool visited[V];

    for (int i = 0; i < V; i++){
        distance[i] = 1000;
        prev[i] = -1;
        visited[i] = false;
    }
    distance[startNode] = 0;
 
    for (int vertex = 0; vertex < V - 1; vertex++) {

        int u = minDistance(distance, visited);

        visited[u] = true;
 
        for (int v = 0; v < V; v++){
 
            if (!visited[v] && graph[u][v] && distance[u] != 1000 && distance[u] + graph[u][v] < distance[v]){
                distance[v] = distance[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }
    for (int i = 0; i<V;i++){
        printPath(prev, startNode,i);
    }
    print(distance, V);
}


int main()
{
    /* Let us create the example graph discussed above */
    int graph[9][9] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 
    dijkstra(graph, 0);
 
    return 0;
}































#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;
class graph{
    public:
    unordered_map<int,list<int>> adj;

    void addEdges(int u, int v , bool direction){
        //DIRECTION = 0->UNDIRECTED GRAPH
        //DIRECTION = 1->DIRECTED GRAPH

        //CREATE AN EDGE FOR U AND V
        adj[u].push_back(v);
        if(direction == 0){
            adj[v].push_back(u);
        }
    }
    void printAdjList(){
        for(auto i : adj){
            cout << i.first << "->";
            for(auto j : i.second){
                cout << j <<",";
            }
            cout << endl;
        }
    }

};



int main(){

     int n; 
     cout << " ENTER THE NUMBER OF EDGES"<<endl;
     cin >> n;

     int m;
     cout << " ENTER THE NUMBER OF NODES"<<endl;
     cin >> m;
     graph g;


     int direction;
     cout << "FOR DIRECTED GRAPH TYPE '1' OR FOR UNDIRECTED GRAPH TYPE '0'"<<endl;
    cin >> direction;
    cout <<"________________________________"<<endl;


    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        
        //creating an undirected|| directed graph
        //dot operator is used when we want to access some data within a class
        g.addEdges(u,v,direction);
    }

    //printing graph
    g.printAdjList();




}
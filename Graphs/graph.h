//Jack Utzerath
using namespace std;
#include <iostream>
#include <string>
#include <queue>
#include <vector>

class graph
{

public:

    int foo[15][15];
    int prev[15];
    vector<int> pathway;

    graph(int foo2[15][15])
    {
        //for loop to create the 2d array
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                foo[i][j] = foo2[i][j];
            }
        }
    }
    void path(int s, int e)
    {
        //BFS starting at node s 
        BFS(s);

        //Build pathway
        reconstructPath(s,e);
        
    }
  

    void reconstructPath(int s, int e)
    {
        //reconstruct the path backwards starting at the end
        displayPrev();
        
        //loop through path backwards until NULL. i iterates by setting it = parent node
        for (int i = e; i != NULL; i = prev[i])
        {
            pathway.push_back(i);

        }
        //have to add 0 if s is 0
        if (s == 0)
        {
            pathway.push_back(s);
        }
        

        //revserse the vector so it goes from the start to the end
        reverse(pathway.begin(),pathway.end());
        
        //cout stuff
        cout << "The path from " << s << " to " << e << " is the following" << endl;

        for (int i = 0; i < pathway.size(); i++)
        {
            cout << " -> ";
            cout << pathway.at(i);
           
        }
       
       
    }

    void BFS(int s)
    {
        //initalize the queue data structure for the BFS
        queue<int> q;
        //Push the starting node onto the queue;
        q.push(s);

        //Bool array with all false values to keep track of visited placed
        bool visited[15];
        
        //set all to false
        for (int i = 0; i < 15; i++)
        {
            visited[i] = false;
        }
        //Mark start at visited
        visited[s] = true;

        //Make array that keeps track of previous or parent nodes so we can 
        //reconstruct the path later
        

        //Prev to NULL
        //Need to initialize to null so we can stop the at when iteriating through array in path method
        for (int i = 0; i < 15; i++)
        {
            prev[i] = NULL;
        }

        //Loop while the queue is not empty
        while (!q.empty())
        {
            //Pull the parent node
            int par = q.front();
            //pop the parent node
            q.pop();

            //Get the Neighbors of the parent node
            vector<int> n = getNeighbors(par);

            //for loop to go through unvisited neighbors
            for (int i = 0; i < n.size(); i++)
            {
                //check if it is unvisited
                if (!visited[n.at(i)])
                {
                    //push the neighboring node onto the queue and mark it as visited
                    q.push(n.at(i));
                    visited[n.at(i)] = true;

                    //keep track of the parent node of the neighboring node
                    //what I could do to check for if the prev[] already has a value and if it does then I 
                    //attach it onto the lisked list in the array
                    prev[n.at(i)] = par;

                }
            }
        }
    }

     vector<int> getNeighbors(int vertex)
     {
        //create vector 
        vector<int> n;

        //check to see what nodes have weight (are connected)
        for (int i = 0; i < 15; i++)
        {
            if (foo[vertex][i] > 0)
            {
                //push onto the vector
                n.push_back(i);
            }
        }
        //return the vector
        return n;
     }


    int getDistance(int s, int e)
    {
        if (foo[s][e] > 0)
        {
            return foo[s][e];
        }

        else { return NULL; }
    }
   

    void displayPrev()
    {
        cout << endl;
        for (int i = 0; i < 15; i++)
        {
            cout << prev[i] << " ";
        }
        cout << endl;
    }

    void print()
    {
        //print out foo with nested for loop
        for (int i = 0; i < 15; i++)
        {
            for (int j = 0; j < 15; j++)
            {
                if (foo[i][j] / 10 == 0)
                {
                    cout << foo[i][j] << "   ";
                }
                else
                {
                    cout << foo[i][j] << "  ";
                }

            }
            cout << endl;
        }
    }


};
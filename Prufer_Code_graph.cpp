#include<iostream>
 
using namespace std;
 
int main()
{
	int i, j, v, e, min, x;
 
	// Take the input of the number of vertexes of the tree.
	cout<<"Enter the number of vertexes of the tree: ";
	cin>>v;
 
	// Calculate the number of edges in the tree as 'v-1'.
	e = v-1;
	int edge[e][2], deg[v+1] = {0};
 
	cout<<"\nFor "<<v<<" vertexes this connected tree must have exactly "<<e<<" edges.\n";
 
	// Enter the vertex pairs which have an edge between them.
	cout<<"\nEnter "<<e<<" pair of vertexes for the tree.\n";
	for(i = 0; i < e; i++)
	{
		cout<<"Enter the vertex pair for edge "<<i+1<<":";
		cout<<"\nV(1): ";
		cin>>edge[i][0];
		cout<<"V(2): ";
		cin>>edge[i][1];
 
		deg[edge[i][0]]++;
		deg[edge[i][1]]++;
	}
 
	// Print the prufer code of the given tree.
	cout<<"\nThe Prufer code for the given tree is: { ";
	for(i = 0; i < v-2; i++)
	{
		min = 10000;
 
		// Select the vertex which have lowest index and degree as 1.
		for(j = 0; j < e; j++)
		{
			if(deg[edge[j][0]] == 1)
			{
				if(min > edge[j][0])
				{
					min = edge[j][0];
					x = j;
				}
			}
			if(deg[edge[j][1]] == 1)
			{
				if(min > edge[j][1])
				{
					min = edge[j][1];
					x = j;
				}
			}
		}
 
		// Remove the selected vertex by decreasing its degree to 0.
		deg[edge[x][0]]--;
 
		// Decrement the degree of other vertex, since we have removed the edge.
		deg[edge[x][1]]--;
 
		// Print the vertex from which leaf vertex is removed.
		if(deg[edge[x][0]] == 0)
			cout<<edge[x][1]<<" ";
		else
			cout<<edge[x][0]<<" ";	
	}
	cout<<"}";
 
	return 0;
}

/* 
link:https://www.sanfoundry.com/cpp-program-generate-prufer-code/
Case 1:
Enter the number of vertexes of the tree: 4
 
For 4 vertexes this connected tree must have exactly 3 edges.
 
Enter 3 pair of vertexes for the tree.
Enter the vertex pair for edge 1:
V(1): 1
V(2): 2
Enter the vertex pair for edge 2:
V(1): 2
V(2): 3
Enter the vertex pair for edge 3:
V(1): 3
V(2): 4
 
The Prufer code for the given tree is: { 2 3 }
 
Case 2:
Enter the number of vertexes of the tree: 6
 
For 6 vertexes this connected tree must have exactly 5 edges.
 
Enter 5 pair of vertexes for the tree.
Enter the vertex pair for edge 1:
V(1): 1
V(2): 2
Enter the vertex pair for edge 2:
V(1): 1
V(2): 3
Enter the vertex pair for edge 3:
V(1): 1
V(2): 4
Enter the vertex pair for edge 4:
V(1): 1
V(2): 5
Enter the vertex pair for edge 5:
V(1): 5
V(2): 6
 
The Prufer code for the given tree is: { 1 1 1 5 }
*/
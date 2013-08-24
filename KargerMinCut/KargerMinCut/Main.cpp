#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <math.h>
#include <time.h>

using namespace std;

unordered_map<int, vector<int> > verts_edges;
vector<int> keys;

void loadFile();
void saveFile();
int randomVertex();
int randomVertexEdge(int);
void kargerCut(int, int);
void keyRemove(int);

int main(int argc, char * argv[])
{
	loadFile();
	unordered_map<int, vector<int> > *ve_copy = new unordered_map<int, vector<int> >();
	*ve_copy = verts_edges;
	vector<int> *key_copy = new vector<int>();
	*key_copy = keys;
	srand((unsigned int) time(NULL));
	int iterations = 0;
	while (iterations < 100)
	{
		cout << "Iteration " << iterations+1 << " :  " << endl;
		verts_edges = *ve_copy;
		keys = *key_copy;
		while (verts_edges.size() > 2)
		{
			int u = randomVertex();
			int v = randomVertexEdge(u);  // Pick a random vertex edge of the random Node.
			kargerCut(u, v);
		}
		cout << "Cut : " << verts_edges[keys.at(0)].size() << endl;
		++iterations;
	}
	// saveFile();
	delete ve_copy; delete key_copy;
	ve_copy = NULL; key_copy = NULL;
	cout << "Happy Coding!";
	cin.get();
	return 0;
}

void loadFile()
{
	try
	{
		cout << "Loading File..." << endl << endl;
		ifstream load("kargerMinCut.txt");
		string line, temp;
		int node = 1;
		while (getline(load, line))
		{
			// Parse the ints out one by one to strings.
			vector<string> n_e;
			for (unsigned int i = 0; i < line.length(); ++i)
			{
				if ((line[i] == 32 || line[i] == 9) && line.length() > 0)
				{
					n_e.push_back(temp);
					temp = "";
				}
				else if (line[i] != 32 || line[i] != 9)
					temp += line[i];
			}
			// Actually parse the ints using stringstream and store them within vert_edge.
			for (unsigned int i = 0; i < n_e.size(); ++i)
			{
				stringstream ss(n_e[i]);
				int num;
				ss >> num;
				if (i != 0)
					verts_edges[node].push_back(num);
				// Save the extracted Node in the keys vector.
				else
					keys.push_back(num);
			}
			++node;
		}
		load.close();
	}
	catch (...)
	{
		cerr << "Failed to load file." << endl << endl;
	}
}

/* void saveFile()
{
	try
	{
		ofstream save("kargerCut.txt");
		int node;
		for (unsigned int i = 0; i < verts_edges.size(); ++i)
		{
			node = keys[i];
			for (unsigned int j = 0; j < verts_edges[node].size(); ++j)
				save << verts_edges[node][j] << "\t";
			save << endl;
		}
		save.close();
	}
	catch (...)
	{
		cerr << "Failed to save graph." << endl;
	}
} */

void kargerCut(int v1, int v2)
{
	for (unsigned int i = 0; i < verts_edges[v2].size(); ++i)	// Put all of v2's edges into v1's. Ultimately merging the Nodes.
		verts_edges[v1].push_back(verts_edges[v2][i]);

	for (unsigned int i = 0; i < keys.size(); ++i)	// Make sure v2 never shows up again in the verts_edges.
	{
		unsigned int node = (unsigned int) keys[i];
		replace(verts_edges[node].begin(), verts_edges[node].end(), v2, v1);
	}

	verts_edges[v1].erase(remove(verts_edges[v1].begin(), verts_edges[v1].end(), v1), verts_edges[v1].end());	// Remove any self-loops.
	verts_edges.erase(v2);	// erase() the old Node from the graph.
	keyRemove(v2);	// remove() the old Node from the keys.
}

int randomVertex()
{
	int size = keys.size();
	return keys[(rand()%size)];
}

int randomVertexEdge(int node)
{
	vector<int> edges = verts_edges[node];
	int size = edges.size();
	int random = rand() % size;
	return edges[random];
}

void keyRemove(int v1)
{
	vector<int>::iterator itr = keys.begin();
	for (unsigned int i = 0; i < keys.size(); ++i)
	{
		if (keys[i] == v1)
		{
			keys.erase(itr + i);
			break;
		}
	}
}
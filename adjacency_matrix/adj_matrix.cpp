/*
 * Title: adj_matrix.cpp
 * Abstract: This program displays a directed graph in an adjecent matrix.
 * Author: Harald Pederstad
 * ID: 1997
 * Date: 02/06/2018
 */

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
	//Used to store filename
	char filename[50];
	ifstream fileReader;

	cout << "Enter input file name: ";
	cin.getline(filename, 50);
	fileReader.open(filename);

	//stores data about verticies and edges
	int vert;
	int edge;

	int start;
	int end;

	//sets variables equal the 2 first lines of the txt file
	fileReader >> vert;
	fileReader >> edge;

	//prints out info about the graph
	cout << "Number of vertices: " << vert << "\n";
    cout << "Number of edges: " << edge << "\n";
    cout << "Adjecency matrix:" << "\n";

	//Creating a two dimentional array to store info about matrix
	int** matrix = new int*[vert];

	for(int i = 0; i < vert; i++){
		matrix[i] = new int[vert];
	}

	//fills the two dimentional array with zeroes
	for(int a = 0; a < vert; a++){
		for(int b = 0; b < vert; b++){
			matrix[a][b] = 0;
		}
	}

	//puts a 1 where there is an edge
	for(int i = 0; i < edge; i++){
		fileReader >> start >> end;
		matrix[start][end] = 1;
	}

    //closes the file
	fileReader.close();
	
	cout << " " << " ";
	
	//prints out the vertices
	for(int i = 0; i < vert; i++){
	    cout << i << " "; 
	}
	
	cout << "\n";

    //prints out the two dimentional array
	for(int a = 0; a < vert; a++){
	    
	    cout << a << " ";
	    
		for(int b = 0; b < vert; b++){
			cout << matrix[a][b] << " ";
		}
		cout << "\n";
	}

	return 0;
}
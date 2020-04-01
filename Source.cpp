#include <mpi.h> 
#include <iostream>  
#include <cstdlib>  
#include <vector>
#include <ctime>
#include <algorithm>


#define sizeOfArray 50
#define sizeOfMatrix 9

using namespace std;

void workAtArray();
void workAtMatrix();

int main(int argc, char **argv) {
	MPI_Init(&argc, &argv); 
	int rank, size; 
	MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
	MPI_Comm_size(MPI_COMM_WORLD, &size); 
	
	srand(time(NULL));
	
	switch (rank) {
	case 0 :
		cout << "Hello from #"<<rank<<endl;
		workAtArray();
		break;
	case 1:
		cout << "Hello from #" << rank << endl;
		workAtMatrix();
		break;

	default:
		cout << "Rank = " << rank << " empty" << endl;
		break;
	}
	MPI_Finalize();  
	return 0;
}
void workAtArray() {

	vector<int> array(sizeOfArray);
	generate(array.begin(), array.end(), []() { return rand() % 10; });
	cout << "Array:" << endl;
	auto iter = array.begin();
	while (iter != array.end()) {
		cout << *iter << " ";
		++iter;            
	}
	sort(array.begin(),array.end());//sorting array
	cout << "\nSort array: " << endl;
	auto iter1 = array.begin();
	while (iter1 != array.end()) {
		cout << *iter1 << " ";
		++iter1;
	}
}
	
void workAtMatrix() {

	vector<vector<int>> matrix(sizeOfMatrix, vector<int>(sizeOfMatrix));

	for (int i = 0; i < sizeOfMatrix; i++) {
		for (int j = 0; j < sizeOfMatrix; j++) {
			matrix[i][j] = rand() % 100;
		}
		cout << endl;
	}
	cout << "Matrix:" << endl;
	for (int i = 0; i < sizeOfMatrix; i++) {
		for (int j = 0; j < sizeOfMatrix; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	swap(*min_element(matrix.begin(),matrix.end()), *max_element(matrix.begin(), matrix.end()));
	for (size_t i = 0; i < matrix.size(); ++i) {
		for (size_t j = 0; j < matrix.size(); ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}
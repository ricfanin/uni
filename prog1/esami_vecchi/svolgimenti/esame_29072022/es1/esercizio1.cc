#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

// La funzione non va modificata, pena l'annullamento dell'esercizio
void sort_array(int * array, int len_array) {
  for (int i=0; i<len_array; i++) {
    for (int j=i+1; j<len_array; j++) {
      if (array[i] > array[j]) {
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
      }
    }
  }
}

int main(int argc, char * argv []) {

	if(argc < 4)
	{
		cout << "Usage: ./a.out <input file> <num elementi> <int <= num>" << endl;
		return -1;
	}

	ifstream input;
	ofstream output;
	input.open(argv[1]);
	output.open("output.txt");


	int dim = atoi(argv[2]);
	int n = atoi(argv[3]);

	int*  voti_all = new int[dim];
	char voto[2];

	int counter = 0;
	while(input >> voto)
	{
		voti_all[counter] = atoi(voto);
		counter++;
	}
	
	sort_array(voti_all, dim);
	
	for(int i = dim; i > dim - n; i--)
	{
		output << voti_all[i] << endl;
	}
	
	output.close();
	input.close();
	delete voti_all;
	
	return 0;
}

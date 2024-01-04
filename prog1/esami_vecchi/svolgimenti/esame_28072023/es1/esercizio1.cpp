#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;


// è possibile definire funzioni di supporto
void trova_parola(char parola_cercata[], char parola_corrente[]);

int main(int argc, char * argv []) {
  
	// inserire qui il codice

	ifstream input;
	input.open(argv[1]);
	if(input.fail())
	{
		cout << "errore apertura" << endl;
		return -1;
	}

	char parola_cercata[255];
	cin >> parola_cercata;

	char parola_corrente[255];

	while(input >> parola_corrente)
	{	
		trova_parola(parola_cercata, parola_corrente);
	}
	
	input.close();

	return 0;

}

void trova_parola(char parola_cercata[], char parola_corrente[])
{
	char parola_trovata[255] = "";
	for (int i = 0; i < strlen(parola_cercata); i++)
	{
		if(parola_cercata[i] == '*')
		{
			parola_trovata[i] = parola_corrente[i];
		}
		else if(parola_cercata[i] == parola_corrente[i])
		{
			parola_trovata[i] = parola_corrente[i];
		}
	}

	if(strlen(parola_cercata) == strlen(parola_trovata))
	{
		cout << parola_trovata << endl;
	}
}
#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;



int main(int argc, char * argv []) {

  // Controllo che gli argomenti ci siano tutti
  if (argc != 2) {
    cout << "Usage: exercise1.out <input>" << endl;
    exit(1);
  }

  // Apro gli stream di lettura e scrittura
  fstream input;
  input.open(argv[1], ios::in);

  // Controllo che gli stream siano stati aperti correttamente
  if ( input.fail() ) {
    cout << "Errore nell'apertura degli stream!" << endl;
  }

  // Chiedo la stringa da ricercare
  char find[256];
  cout << "Inserire la sequenza di caratteri da ricercare: ";
  cin >> find;

  // Chiedo il valore di shifting
  int shift;
  cout << "Inserire il valore di shifting: ";
  cin >> shift;

  // Trasformo in maiuscolo
  for (int i=0; i<strlen(find); i++) {
    char current = find[i];
    if ( current >='a' && current <= 'z' ) {
      find[i] = current - 'a' + 'A';
    }
  }

  // Applico shifting a dx
  for (int v=0; v<shift; ++v) {
    char tmp = find[strlen(find)-1];
    for (int i=strlen(find)-1; i>0; --i) {
      find[i] = find[i-1];
    }
    find[0] = tmp;
  }

  // Cerco
  int count = 0;
  char buffer[256];
  while(input >> buffer) {
    
    for ( int j=0; j<strlen(buffer); ++j ) {
      bool missmatch = false;
      for ( int i=0; i<strlen(find) && !missmatch; ++i ) {
        if ( buffer[j+i] != find[i] ) {
          // not matching
          missmatch = true;
        }
      }
      if ( ! missmatch ) {
        // found
        count++;
      }
    }
    
  }

  cout << "found " << count << " occurrences of " << find << endl; 

  input.close();

  return 0;

}

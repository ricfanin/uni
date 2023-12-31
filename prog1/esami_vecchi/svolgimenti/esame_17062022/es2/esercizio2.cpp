#include <iostream>
#include <string>

using namespace std;

// Add hereafter the declaration of compute_sum
int compute_sum(int num);
// Add here above the declaration of compute_sum

int main(int argc, char ** argv) {
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " int " << endl;
    exit(1);
  }

  int num;
  try {
    string ss(argv[1]);
    num = stoi(ss);
  } catch (out_of_range) {
    cerr << "Unable to convert the given string to an integer" << endl;
    cerr << "String of the given number = " << argv[1] << endl;
    cerr << "Converted integer = " << num << endl;
    exit(1);
  }
  if (0 > num) {
    cerr << "Expecting an integer greater or equal to 0" << endl;
    exit(1);
  }

  cout << "The initial integer is: " << num << endl;
  cout << "The value of compute_sum(" << num << ") = " << compute_sum(num) << endl;
}


// Add hereafter int compute_sum(int num);
void sum(int num, int somma, int& somma_finale)
{
	if(num > 0)
	{
		int cifra = num%10;
		somma += cifra;
		num = (num - cifra)/10;
		sum(num, somma, somma_finale);
	}
	else
	{
		somma_finale = somma;
		if(somma_finale > 10 && somma_finale%2 == 0)
		{
			sum(somma_finale + 10, 0, somma_finale);
		}
		else if(somma_finale > 10 && somma_finale%2 == 1)
		{
			sum(somma_finale + 1, 0, somma_finale);
		}
	}
	
}

int compute_sum(int num)
{ 
	int somma_finale;
	sum(num, 0, somma_finale);

	return somma_finale;
}
// Add here above the definition of compute_sum

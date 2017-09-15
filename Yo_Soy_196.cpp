/*
Yo_Soy_196.cpp
Sep 1, 2017
Juan Casian
*/

#include <iostream>
#include <string>
#include "BigIntegerLibrary.hh"

using namespace std;

struct BoundaryPair {       /* Struct is the way to compile many variables in one;
                                It is defined:
                                struct NameOfTheStruct {
                                TypeOfVariable NameOfVariable;
                                TypeOfVariable NameOfVariable;
                                ...
                              };

                              It is useful because you can't return more than 1 variable per function.
                              */

  BigInteger LowerBound;
  BigInteger UpperBound;
};

BoundaryPair AskForValue() {
  BoundaryPair FirstPair;             // This is creating a Boundary Pair variable, which is conformed by lower bound and upper bound of BigInteger type
  string a; //This 2 strings are needed because cin does not know what BigInteger is.
  string b;
  cout << "Please enter the Lower Boundary: "; cin >> a;
  FirstPair.LowerBound = stringToBigInteger (a);        // After we use a to get the value you use stringToBigInteger() function to convert it to bigInteger
  cout << "Please enter the upper Boundary: "; cin >> b;
  FirstPair.UpperBound = stringToBigInteger (b);

  if (FirstPair.LowerBound > FirstPair.UpperBound){   //This code test if the value is valid for the program, previously I used to make a diferent function but that can cause erros
    cout << "Your lower boundary can't be bigger than your upper boundary. Please try again!" << endl;
    FirstPair = AskForValue();
  } else {
    return FirstPair;
  }

  // cout << "LowerBound: " << FirstPair.LowerBound << endl;    Test to see that the values are assigned correctly
  // cout << "UpperBound: " << FirstPair.UpperBound << endl;
  return FirstPair;
}

void CheckTheValues (BoundaryPair FirstPair){

   int PalyndromesCounter = 0;

  for (;FirstPair.LowerBound <= FirstPair.UpperBound; FirstPair.LowerBound++){


    string LowerBound = bigIntegerToString(FirstPair.LowerBound);
    string UpperBound = bigIntegerToString(FirstPair.UpperBound);
    string Volteado = string(LowerBound.rbegin(), LowerBound.rend());
    /*
    cout << LowerBound <<endl;          Test to see if the program inverted the string order
    string Volteado = string(LowerBound.rbegin(), LowerBound.rend());     Con esto volteas los strings.
    cout << Volteado << endl;
    */


    if (LowerBound == Volteado){
      PalyndromesCounter = PalyndromesCounter +1;
    }

    if ()



  }

  cout << PalyndromesCounter << endl;

}

int main () {

  BoundaryPair FirstPair;


  cout << "This is a program that will report to you the range of numbers you inputed, number of natural palindromes, # of non-lycherels and number of lycherels candidates. "
  << endl;

    FirstPair = AskForValue();

    cout << "The range of numbers you entered is from " << FirstPair.LowerBound << " to " << FirstPair.UpperBound << "." <<endl;


CheckTheValues(FirstPair);


}

//https://gist.github.com/Adals20/f20fbd8c15d30adcd9c5fede728394c0

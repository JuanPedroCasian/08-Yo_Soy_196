/*
Yo_Soy_196.cpp
Sep 1, 2017
Juan Casian
*/

#include <iostream>
#include <string>
#include "BigIntegerLibrary.hh"
#include <vector>

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

bool CheckPalindrome (BigInteger& CurrentNumber){
  string TestValue = bigIntegerToString(CurrentNumber);     //Using the function bigIntegerToString () to be able to swith it backwards
  string TestValueVolteado = string(TestValue.rbegin(), TestValue.rend()); //This is how you turn backwards a string

  if (TestValue == TestValueVolteado){        // looking for the plindrom
    return true;
  } else {
    return false;
  }
}

bool CheckNonLycherel (BigInteger CurrentNumber){
  BigInteger TestNumber, TestNumberVolteado;
  string TestValue, TestValueVolteado;              /*
                                                      A non lycherel number is a number that is not a palindrome but it is switched and added to the
                                                      normal number will give a palindrome

                                                      This function switches the number checks if they are equal if not, it adds them and checks again
                                                    */

  for (int i=1; i <= 30; i++){
    TestValue = bigIntegerToString(CurrentNumber);
    TestValueVolteado = string(TestValue.rbegin(), TestValue.rend());

    if (TestValue == TestValueVolteado){
      return true;
    } else {
      TestNumber = stringToBigInteger(TestValue);     //Turns the value back to BigInteger so you are able to add them
      TestNumberVolteado = stringToBigInteger(TestValueVolteado);
      CurrentNumber = TestNumber + TestNumberVolteado;
    }
  }
  return false;         // If the process before does not gives a palindrome then it is a lycherel and by returning false you let the CheckTheValues function know
}

void CheckTheValues (BoundaryPair FirstPair){
  BigInteger CurrentNumber = FirstPair.LowerBound;
  int PalinCounter = 0, NonLycheCounter = 0, LycheCounter = 0;
  vector <BigInteger> Palindromes;
  int IDVector = 0;

  for (;CurrentNumber <= FirstPair.UpperBound; CurrentNumber ++){
    if (CheckPalindrome(CurrentNumber) == true){    //simple counter
      PalinCounter +=1;
    } else if (CheckNonLycherel(CurrentNumber) == true){
      NonLycheCounter +=1;
    } else if (CheckNonLycherel(CurrentNumber) == false){
      LycheCounter +=1;
      Palindromes.push_back(CurrentNumber);     // When a number is a palindrome it stores it in a Vector
      IDVector +=1;   //IDVector works to know how many values do you have so you can print them later
    }
  }

  cout << "Number of Palindromes: " << PalinCounter << endl;
  cout << "Number of NonLycherels candidates: " << NonLycheCounter << endl;
  cout << "Number of Lycherel candidates: " << LycheCounter << endl;

  cout << "The Lycherel candidates found are: " << endl;
  for (int i = 0; i < IDVector; i++){     //Here is where IDVector comes in Handy
    cout << Palindromes[i] << endl;
  }

}

int main () {

  BoundaryPair FirstPair;


  cout << "This is a program that will report to you the range of numbers you inputed, number of natural palindromes, # of non-lycherels and number of lycherels candidates. "
  << endl;

    FirstPair = AskForValue();

    cout << "The range of numbers you entered is from " << FirstPair.LowerBound << " to " << FirstPair.UpperBound << "." <<endl;


CheckTheValues(FirstPair);

cout << "FINALLY WE MADE IT!!!!!" << endl;

}

//https://gist.github.com/Adals20/f20fbd8c15d30adcd9c5fede728394c0

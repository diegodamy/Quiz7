#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int CheckIfFirstOpen(string list1){
  ifstream ListOne;
  ListOne.open(list1.c_str());

  if (ListOne.is_open()){
    return 1;
  } else {
    return 0;
  }
}

int CheckIfSecondOpen(string list2){
  ifstream ListTwo;
  ListTwo.open(list2.c_str());

  if (ListTwo.is_open()){
    return 1;
  } else {
    return 0;
  }
}

vector<int>ReadList1(string list1){
  vector<int>List1(4);
  ifstream ListOne;
  ListOne.open(list1.c_str());

  for (int i = 0; i < List1.size(); i++) {
      ListOne >> List1[i];
    }
  return List1;
  ListOne.close();
}


vector<int>ReadList2(string list2){
  vector<int>List2(4);
  ifstream ListTwo;
  ListTwo.open(list2.c_str());

  for (int i = 0; i < List2.size(); i++){
    ListTwo >> List2[i];
  }
  return List2;
  ListTwo.close();
}



int DotProduct (vector<int>List1, vector<int>List2){
  int size = 4;
  int sum;

  for (int i = 0; i < size; i++){
    sum += List1[i] * List2[i];
  }
  cout << "Dot product is " << sum;
}

int main(){
  string list1;
  string list2;

  cout << "Please enter the name of the first list:" << endl;
  cin >> list1;
  cout << "Please enter the name of the second list:" << endl;
  cin >> list2;

  while (CheckIfFirstOpen(list1) == 0) {
    cout << "Unable to open first file." << endl;
    cout <<"Please enter the name of the first text:" << endl;
    cin >> list1;
  }
  cout << endl;

  while (CheckIfSecondOpen(list2) == 0) {
    cout << "Unable to open second file." << endl;
    cout <<"Please enter the name of the second text:" << endl;
    cin >> list2;
  }
  cout << endl;

  vector<int>List1 = ReadList1(list1);
  vector<int>List2 = ReadList2(list2);
  DotProduct(List1,List2);

}

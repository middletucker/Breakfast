// This is a modified exercise from the Malik text in Chapter 9
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// global vars
string StoreName = "24/7 Breakfast Feast";

const int NO_OF_ITEMS = 8; // corresponds to items in BreakfastMenu.txt

// globaly decare struct type the groups menu item with the price

// function prototypes

int main() {

  // variables needed here

  ifstream inFile;

  cout << fixed << showpoint << setprecision(2);

  inFile.open("BreakfastMenu.txt");

  if (!inFile) {
    cout << "Cannot open menu. Program Ending..." << endl;
    return 1;
  }

  getData(inFile, menuList, NO_OF_ITEMS);
  showMenu(menuList, NO_OF_ITEMS);
  makeSelection(NO_OF_ITEMS, choiceList, choiceListLength);
  printCheck(menuList, NO_OF_ITEMS, choiceList, choiceListLength);

  return 0;
}

void getData(ifstream &inFile, menuItemType mList[], int listSize) {
  char ch;
  for (int i = 0; i < listSize; i++) {
    getline(inFile, mList[i].menuItem);
    inFile >> mList[i].menuPrice;
    inFile.get(ch);
  }
}

void showMenu(menuItemType mList[], int listSize) {
  //<ToDo> Finish this!
}

void printCheck(menuItemType mList[], int listSize, int cList[],
                int cListLength) {
  //<ToDo> Finish this!
}

void makeSelection(int listSize, int cList[], int &cListLength) {
  int itemNo;

  char response;

  cListLength = 0;

  cout << "You can make up to " << listSize << " single order selections"
       << endl;

  cout << "Do you want to make selection Y/y (Yes), N/n (No): ";
  cin >> response;
  cout << endl;

  while ((response == 'Y' || response == 'y') && cListLength < 8) {
    cout << "Enter item number: ";
    cin >> itemNo;
    cout << endl;

    if (!isItemSelected(cList, cListLength, itemNo))
      cList[cListLength++] = itemNo - 1;
    else
      cout << "Item already selected" << endl;

    cout << "Select another item Y/y (Yes), N/n (No): ";
    cin >> response;
    cout << endl;
  }
}

bool isItemSelected(int cList[], int cListLength, int itemNo) {
  bool found = false;

  for (int i = 0; i < cListLength; i++)
    if (cList[i] == itemNo) {
      found = true;
      break;
    }

  return found;
}

Line 10 : Col 36

History


Enable "Accessible Terminal" in Workspace Settings to use a screen reader with the console.
Booting ReplReady

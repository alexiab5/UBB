#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"
#include <cassert>

using namespace std;

bool r(TComp r1, TComp r2) {
    return r1 >= r2;
}

void printBag(SortedBag sb){
    SortedBagIterator it = sb.iterator();
    while(it.valid()){
        cout << it.getCurrent() << " ";
        it.next();
    }
    cout << "\n";
}

int main() {
	testAll();
	testAllExtended();
	cout << "Test over" << endl;
	system("pause");
}

#include <iostream>
#include "hashMap.h"
using namespace std;

int main()
{
    cout << "========== Default Constructor ==========\n";
    HashMap<int, int> map;

    cout << "Size : " << map.getSize() << endl;
    cout << "Load Factor : " << map.getLoadFactor() << endl;

    cout << "\n========== Insertion ==========\n";
    map.set(1, 100);
    map.set(2, 200);
    map.set(3, 300);
    map.set(4, 400);
    map.set(5, 500);

    cout << "Size : " << map.getSize() << endl;

    cout << "\n========== Get ==========\n";
    cout << "Key 1 : " << map.get(1) << endl;
    cout << "Key 2 : " << map.get(2) << endl;
    cout << "Key 3 : " << map.get(3) << endl;
    cout << "Key 4 : " << map.get(4) << endl;
    cout << "Key 5 : " << map.get(5) << endl;

    cout << "\n========== Update Existing Key ==========\n";
    map.set(3, 999);

    cout << "Key 3 : " << map.get(3) << endl;

    cout << "\n========== Exists ==========\n";
    cout << "Exists(3) : " << map.exists(3) << endl;
    cout << "Exists(10): " << map.exists(10) << endl;

    cout << "\n========== Remove ==========\n";
    map.remove(2);

    cout << "Exists(2): " << map.exists(2) << endl;
    cout << "Size : " << map.getSize() << endl;

    cout << "\n========== Copy Constructor ==========\n";
    HashMap<int, int> copyMap(map);

    cout << "Copy Size : " << copyMap.getSize() << endl;
    cout << "Key 1 : " << copyMap.get(1) << endl;
    cout << "Key 3 : " << copyMap.get(3) << endl;

    cout << "\n========== Assignment Operator ==========\n";
    HashMap<int, int> assignMap;

    assignMap = map;

    cout << "Assign Size : " << assignMap.getSize() << endl;
    cout << "Key 1 : " << assignMap.get(1) << endl;
    cout << "Key 5 : " << assignMap.get(5) << endl;

    cout << "\n========== Deep Copy Check ==========\n";

    map.set(1, 1111);

    cout << "Original : " << map.get(1) << endl;
    cout << "Copy     : " << copyMap.get(1) << endl;
    cout << "Assigned : " << assignMap.get(1) << endl;

    cout << "\n========== Exception Test ==========\n";

    try
    {
        cout << map.get(100) << endl;
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }

    cout << "\n========== Rehash Test ==========\n";

    for (int i = 6; i <= 50; i++)
    {
        map.set(i, i * 10);
    }

    cout << "Size : " << map.getSize() << endl;
    cout << "Load Factor : " << map.getLoadFactor() << endl;

    cout << "Key 50 : " << map.get(50) << endl;
    cout << "Key 35 : " << map.get(35) << endl;
    cout << "Key 20 : " << map.get(20) << endl;

    cout << "\nAll Tests Passed Successfully.\n";

    return 0;
}
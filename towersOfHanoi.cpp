/*
 * towersOfHanoi.cpp
 *
 *  Created on: Sep 20, 2017
 *      Author: Daniel Peterson
 */

#include <iostream>
#include <stack>

using namespace std;

struct tower {
	int towerIndex;
	stack<int> towerRings;
};

void ringMover(tower & fromTower, tower & toTower)
{
	int ring = fromTower.towerRings.top();
	cout << "Moving " << ring << " from tower " << fromTower.towerIndex << " to tower " << toTower.towerIndex << endl;
	fromTower.towerRings.pop();
	toTower.towerRings.push(ring);
}

void towerOfHanoi(int n, tower & fromTower, tower & toTower, tower & tempTower)
{
	if (n == 0) return;
	towerOfHanoi(n-1, fromTower, tempTower, toTower);
	ringMover(fromTower,  toTower);
	towerOfHanoi(n-1, tempTower, toTower, fromTower);
}

int main()
{
	unsigned int n = 0;
	// initialize the towers
	tower tower1, tower2, tower3;

	// set the tower indices
	tower1.towerIndex = 1;
	tower2.towerIndex = 2;
	tower3.towerIndex = 3;

	cout << "Welcome to the towers of Hanoi.\nHow many rings would you like to move? ";
	cin >> n;

	// populate the first tower
	for (unsigned int i = 0; i < n; i++) {
		tower1.towerRings.push(n - i);
	}

	towerOfHanoi(n, tower1, tower3, tower2);

	cout << "Your rings have been moved.\nHave a nice day!\n";

	return 0;
}

#include "Camera.h"
#include "Track.h"
#include "Kart.h"
#include <iostream>
#include <GL/glut.h>
#include <vector>

using namespace std;

int main(){
	int players;
	cout << "Enter the number of players (1-4): ";
	cin >> players;
	vector <Kart> playerkarts;
	for (int i=1; i<=players; i++){
		int j;
		cout << "Player " << i << " choose your kart(1-4): "
		cin << j;
		playerkarts.push_back(Kart(j));	
	}
	// This could be the beginning of the driver program.
}

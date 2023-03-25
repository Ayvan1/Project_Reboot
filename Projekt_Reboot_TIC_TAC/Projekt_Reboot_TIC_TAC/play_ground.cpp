#include "play_ground.h"

void play_ground::tableau(list<postion> &busy_pos)
{
	for (int n = 0; n < 4; n++) {
		for (int i = 0; i < 25; i++) {
			cout << "*";
		}
		cout << endl;
		if (n == 3) {
			break;
		}
		
		for (int i = 0; i < 4; i++) {
			cout << "*\t";
			for (auto pos : busy_pos) {
				if (pos.get_x() == i + 1 && pos.get_y() == n + 1 ) {
					pos.get_player() == 1 ? cout << "X" : cout << "O";
					break;
				}
			}
		
		}
		cout << endl;	
		
	}
	
}

void play_ground::ground_mark(int player,list<postion> &busy_pos)
{
	
	bool true_False = true;
	int x, y;
	
	while (true_False) {
		cout << "---> the value of X : ";
		cin >> x;
		cout << "---> the value of Y : ";
		cin >> y;
		postion position(x, y, player);
		bool verif = true;
		if (x < 0 || x > 3) {
			cout << "---> wrong position" << endl;
			continue;
		}
		if (y < 0 || y > 3) {
			cout << "---> wrong position" << endl;
			continue;
		}
		for (auto element : busy_pos)
			if (element == position) {
				verif = false;
				break;
			}
		if (!verif) {
			busy_pos.push_back(position);
			true_False = false;
		}
	}
}

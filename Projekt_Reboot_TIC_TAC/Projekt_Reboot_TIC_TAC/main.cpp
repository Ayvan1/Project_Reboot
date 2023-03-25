#include "play_ground.h"
#include "postion.h"

void menu();
bool check_horizontal(list<postion> play_ground);
bool check_vertical(list<postion> play_ground);
bool check_diagoonal(list<postion> play_ground);

int main() {
	list <postion> my_l;
	play_ground my_p;
	my_l.push_back(postion(2, 1, 2));
	my_l.push_back(postion(1, 2, 1));
	my_l.push_back(postion(2, 2, 2));
	my_l.push_back(postion(2, 3, 1));

	my_p.tableau(my_l);
	return 0;
}
void menu() {
	cout << "--------- Menu ---------" << endl;
	cout << "---> new play \n---> table score\n---> exit";
}

bool check_horizontal(list<postion> play_ground) {
	int arry[2] = {};
	for (int n = 0; n < 4; n++) {
		for (int i = 0; i < 4; i++) {
			for (auto& element : play_ground) {
				if (element.get_x() == i + 1) {
					element.get_player() == 1 ? arry[0]++ : arry[1]++;
					break;
				}
			}
		}
		if (arry[0] == 3) {
			cout << "---> the winner is Player 1" << endl;
			return true;
		}
		else if (arry[1] == 3) {
			cout << "---> the winner is Player 2" << endl;
			return true;
		}
		arry[0] = 0, arry[1] = 0;
	}
	return false;
}

bool check_vertical(list<postion> play_ground) {
	int arry[2] = {};
	for (int n = 0; n < 4; n++) {
		for (int i = 0; i < 4; i++) {
			for (auto& element : play_ground) {
				if (element.get_y() == i + 1) {
					element.get_player() == 1 ? arry[0]++ : arry[1]++;
					break;
				}
			}
		}
		if (arry[0] == 3) {
			cout << "---> the winner is Player 1" << endl;
			return true;
		}
		else if (arry[1] == 3) {
			cout << "---> the winner is Player 2" << endl;
			return true;
		}
		arry[0] = 0, arry[1] = 0;
	}
	return false;
}

bool check_diagoonal(list<postion> play_ground) {
	int axe_x = 1, axe_y = 1;
	int arry[2] = {}; 
	
	while (axe_x < 4 && axe_y < 4) {
		for (auto& element : play_ground) {
			if (element.get_x() == axe_x && element.get_y() == axe_y) {
				element.get_player() == 1 ? arry[0]++ : arry[1]++;
				break;
			}
		}
		axe_x++, axe_y++;
	}
	if (arry[0] == 3) {
		cout << "---> the winner is Player 1" << endl;
		return true;
	}
	else if (arry[1] == 3) {
		cout << "---> the winner is Player 2" << endl;
		return true;
	}
	arry[0] = 0, arry[1] = 0;
	while (axe_x > 0 && axe_y > 0) {
		for (auto& element : play_ground) {
			if (element.get_x() == axe_x && element.get_y() == axe_y) {
				element.get_player() == 1 ? arry[0]++ : arry[1]++;
				break;
			}
		}
		axe_x--, axe_y--;
	}
	if (arry[0] == 3) {
		cout << "---> the winner is Player 1" << endl;
		return true;
	}
	else if (arry[1] == 3) {
		cout << "---> the winner is Player 2" << endl;
		return true;
	}
	return  false;
}
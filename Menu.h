#ifndef MENU_H
#define MENU_H

class Menu {
private:
	int menuPosition;
	int maxMenuPosition;
	char **menuStrings;
	char *nameOfTheMenu;

	enum { UpArrow = 72, DownArrow = 80, ENTER = 13, ESC = 27 };
public:
	Menu(char *name, char **strings, int maxmp);
	~Menu();
	int menu();
	bool choice();
};

#endif
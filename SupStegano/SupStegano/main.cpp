#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void Menu(char *argv[]);

void ArgsControl(char *argv[]);

void CheckArgs(char *argv[]);
void AddArgs(char *argv[]);
void ReadArgs(char *argv[]);

void MenuCheck();
void MenuAddText();
void MenuReadText();

const char image[] = "picture.jpg";
const string specLine = "###### specific line ######";
vector <string> lines;


int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		Menu(argv);
	}
	else if(argc > 2)
	{
		ArgsControl(argv);
	}

	getchar();
	return 0;
}

void Menu(char *argv[])
{

	while (true)
	{
		int choice = 0;

		cout << "1. Check" << endl << endl;
		cout << "2. Add text" << endl << endl;
		cout << "3. Read text" << endl << endl;

		cout << "your choice: " << endl << endl;

		cin >> choice;

		switch (choice)
		{
		case 1:
			MenuCheck();
			break;
		case 2:
			MenuAddText();
			break;
		case 3:
			MenuReadText();
			break;
		default:
			cout << "Choose 1, 2 or 3." << endl << endl;
			Menu(argv);
			break;
		}
	}

}

void MenuCheck()
{
	int check = 0;  // 0 = false | 1 = true
	string line;
	string HiddenText; //Get the hidden text
	ifstream picture(image);

	lines.clear();

	if (picture.is_open())
	{
		while (getline(picture, line))
		{
			lines.push_back(line);
		}
		picture.close();
	}

	else cout << "Can't read file";

	for (int i = 0; i < lines.size(); i++)
	{
		if (lines[i] == specLine)
		{
			check = 1;
		}
	}

	if (check == 1)
	{
		cout << "\nHidden text found" << endl << endl;
	}
	else if(check == 0)
	{
		cout << "\nNo hidden text found" << endl << endl;
	}


	getchar();

}

void MenuAddText()
{
	string line;
	string HiddenText = "";
	string content = "";
	cout << "write your text: ";
	cin >> HiddenText;

	ifstream picture(image);

	lines.clear();

	if (picture.is_open())
	{
		while (getline(picture, line))
		{
			lines.push_back(line);
		}
		picture.close();
	}


	for (int i = 0; i < lines.size(); i++)
	{
		content += lines[i];
	}

	ofstream myfile;
	myfile.open(image);
	myfile << content << "\n\n\n" << specLine << "\n" << HiddenText << "\n";
	cout << "\n Hidden text wrote !" << endl;
	myfile.close();
	getchar();
}

void MenuReadText()
{
	string line;
	string HiddenText; //Get the hidden text
	int isHiddenText = 0; //0 = false | 1 = true
	ifstream picture(image);

	lines.clear();

	if (picture.is_open())
	{
		while (getline(picture, line))
		{
			lines.push_back(line);

		}
		picture.close();
	}

	else cout << "Can't read file";

	for (int i = 0; i < lines.size(); i++)
	{
		if (isHiddenText == 1)
		{
			HiddenText += lines[i];
		}

		if (lines[i] == specLine)
		{
			isHiddenText = 1;
		}
	}
	
	if(HiddenText != "")
		cout << HiddenText << "\n";
	else
	{
		cout << "no hidden text" << "\n";
	}

}

void ArgsControl(char *argv[])
{
	if (argv[1] == "check")
	{
		CheckArgs(argv);
	}
	else if(argv[1] == "add")
	{
		AddArgs(argv);
	}
	else if (argv[1] == "read")
	{
		ReadArgs(argv);
	}

}

void CheckArgs(char *argv[])
{
	int check = 0;  // 0 = false | 1 = true
	string line;
	string HiddenText; //Get the hidden text
	ifstream picture(argv[2]);
	if (picture.is_open())
	{
		while (getline(picture, line))
		{
			lines.push_back(line);
		}
		picture.close();
	}

	else cout << "Can't read file";

	for (int i = 0; i < lines.size(); i++)
	{
		if (lines[i] == specLine)
		{
			check = 1;
		}
	}

	if (check == 1)
	{
		cout << "\nHidden text found" << endl << endl;
	}
	else if (check == 0)
	{
		cout << "\nNo hidden text found" << endl << endl;
	}


	getchar();
}
void AddArgs(char *argv[])
{
	string line;
	string HiddenText = "";
	string content = "";
	cout << "write your text: ";
	cin >> HiddenText;

	ifstream picture(argv[2]);

	lines.clear();

	if (picture.is_open())
	{
		while (getline(picture, line))
		{
			lines.push_back(line);
		}
		picture.close();
	}


	for (int i = 0; i < lines.size(); i++)
	{
		content += lines[i];
	}

	ofstream myfile;
	myfile.open(image);
	myfile << content << "\n\n\n" << specLine << "\n" << HiddenText << "\n";
	cout << "\n Hidden text wrote !" << endl;
	myfile.close();
	getchar();
}

void ReadArgs(char *argv[])
{
	string line;
	string HiddenText; //Get the hidden text
	int isHiddenText = 0; //0 = false | 1 = true
	ifstream picture(argv[2]);

	lines.clear();

	if (picture.is_open())
	{
		while (getline(picture, line))
		{
			lines.push_back(line);

		}
		picture.close();
	}

	else cout << "Can't read file";

	for (int i = 0; i < lines.size(); i++)
	{
		if (isHiddenText == 1)
		{
			HiddenText += lines[i];
		}

		if (lines[i] == specLine)
		{
			isHiddenText = 1;
		}
	}

	if (HiddenText != "")
		cout << HiddenText << "\n";
	else
	{
		cout << "no hidden text" << "\n";
	}
}
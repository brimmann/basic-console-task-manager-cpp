#include "specification.h"



int main()
	{
	char option;
	int tArr[3];
	init(tArr);
	while (1)
	{
		cout << "Choose an Option - a (Daily Tasks) - b (Special Task) - c ( Courses) - e (Exit): "; cin >> option;
		if (option == 'a')
		{
			DailyTasksManager(tArr);
		}
		else if (option == 'b')
		{
			SpecialTasksManager(tArr);
		}
		else if (option == 'c')
		{
			CoursesManager(tArr);
		}
		else if (option == 'e')
		{
			break;
		}
		else
		{
			cout << "Incorrect Input!\n";
		}
	}
}



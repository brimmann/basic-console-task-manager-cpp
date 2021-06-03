#include "specification.h"


//////////////// DTask Class Implementation

DTask::DTask() { status = false;}

void DTask::Create(short sId)
{
	id = sId;
	cout << "Title: "; cin.get(); cin.getline(title, 128);
	cout << "Estimated Time(in hours): "; cin >> eTime;
	cout << "Imortance (in scale of 1-5): "; cin >> importance;
}


void DTask::Display() const
{
	const short idWid = 3;
	const short titleWid = 129;
	const short eTimeWid = 2;
	const short importanceWid = 2;
	const short statusWid = 6;

	ADJUSTFEILD_R;
	cout.width(idWid);
	cout << "|" + id << "|";
	cout.width(titleWid);
	cout << title << "|";
	cout.width(eTimeWid);
	cout << eTime << "|";
	cout.width(importanceWid);
	cout << importance;
	cout.width(statusWid);
	if (status == false)
		cout << "Undon"  << "|";
	else
		cout << "Done" << "|";
	cout << endl;
	cout.fill('-');
	cout << '-' << endl; cout.fill(' ');
}

void DTask::UpdateStatus()
{
	status = true;
}



//////////////////////////////////////////////
//////////////////// STask Class Implementation


STask::STask() { status = false; }


void STask::GenerateDate()
{
	time_t now = time(nullptr);
	tm * timeCod = localtime(&now);
	string sDate = to_string(timeCod->tm_mday) + ":" + to_string(timeCod->tm_mon) + ":" + to_string(timeCod->tm_year);
	strcpy(date, sDate.c_str());
	wDay = timeCod->tm_wday;
}

void STask::Create(int gId)
{
	id = gId;
	cout << "Title: "; cin.get();cin.getline(title, 128);
	GenerateDate();
}


void STask::Edit()
{
	char option;
	cout << "Confirm Title: " << title << " c|e (confirm|eidt)"; cin >> option;
	if (option == 'e' || option == 'E')
	{
		cout << "Enter correct Title: "; cin >> title;
	}
	cout << "Confirmed!" << endl;
}


void STask::Display() const
{
	const short idWid = 7;
	const short titleWid = 129;
	const short dateWid = 11;
	const short statusWid = 6;
	ADJUSTFEILD_R;
	cout.width(idWid);
	cout << "|" + id << "|";
	cout.width(titleWid);
	cout << title << "|";
	cout.width(dateWid);
	cout << date << "|";
	cout.width(statusWid);
	if (status == false)
		cout << "Undon" << "|";
	else
		cout << "Done" << "|";
	cout << endl;
	cout.fill('-');
	cout << '-' << endl; cout.fill(' ');
}


///////////////////////////////////////
//////////////// Topic Class Implementation

Topic::Topic() { status = 0; }


void Topic::Create(short gId)
{
	id = gId;
	cout << "Title: "; cin.get();
		cin.getline(title, 128);
}

void Topic::Edit()
{
	char option;
	cout << "Confirm Title: " << title << " c|e (confirm|edit)"; cin >> option;
	if (option == 'e' || option == 'E')
	{
		cout << "Enter correct Title: "; cin.get(); cin.getline(title, 128);
	}
}

void Topic::UpdateStatus()
{
	status = true;
}

void Topic::Display() const
{
	const short idWid = 7;
	const short titleWid = 129;
	const short statusWid = 12;
	ADJUSTFEILD_R;
	cout.width(idWid);
	cout << "|" + id << "|";
	cout.width(titleWid);
	cout << title << "|";
	cout.width(statusWid);
	if (status == false)
		cout << "Not-Covered" << "|";
	else
		cout << "Covered" << "|";
	cout << endl;
	cout.fill('-');
	cout << '-' << endl; cout.fill(' ');
}


/////////////////////////
/////// Course class impelementation
void Course::CreateCourse()
{
	cout << "Title: "; cin.get();cin.getline(title, 128);
	cout << "Code: "; cin.get();cin.getline(code, 8);
	cout << "Credit Hourse: "; cin >> cr;
	cout << "Semester: "; cin >> semester;
}

void Course::CreateSyl()
{
	short temp;
	cout << "Enter number of topics: "; cin >> temp; topicsNum = temp;
	for (int i = 0; i < temp; i++)
		syl[i].Create(i+1);
}

void Course::EditCourse()
{
	char option;
	cout << "Confirm Title: " << title << " c|e (confirm|edit)";  cin >> option;
	if (option == 'e' || option == 'E')
	{
		cout << "Enter correct Title: ";cin.get();cin.getline(title, 128);
	}

	cout << "Confirm Code: " << code << " c|e (confirm|edit)";
	if (option == 'e' || option == 'E')
	{
		cout << "Enter correct Title: "; cin.get(); cin.getline(code, 8);
	}

	cout << "Confirm Credit Hours: " << cr << " c|e (confirm|edit)";
	if (option == 'e' || option == 'E')
	{
		cout << "Enter correct Title: "; cin >> cr;
	}

	cout << "Confirm Semester: " << semester << " c|e (confirm|edit)";
	if (option == 'e' || option == 'E')
	{
		cout << "Enter correct Title: "; cin >> semester;
	}

}



void Course::EditSyl()
{
	short temp;
	cout << "Enter topic ID: "; cin >> temp;
	syl[temp - 1].Edit();
}


void Course::DisplaySyl() const
{
	cout << "| " << code << "  | " << title << "   | " << cr << "CR    | " << semester << " |"<< endl;
	cout << "Sylbus: \n";
	for (int i = 0; i < topicsNum; i++)
		syl[i].Display();
}

void Course::Display()
{

}


//////////////////////////////////
/////Writer class Implementation

Writer::Writer(dTasksStruct* object)
{
	dTasks = object;
	strcpy(dTaskFile, "d_tasks_storage.dat");
	strcpy(dTaskTrackerFile, "d_tasks_tracker_storage.dat");
}

Writer::Writer(STask* object)
{
	sTask = object;
	strcpy(sTaskFile, "s_tasks_storage.dat");
	strcpy(sTaskTrackerFile, "s_tasks_tracker_storage.dat");
}

Writer::Writer(Course* object)
{
	course = object;
	strcpy(courseTrackerFile, "course_storage.dat");
	strcpy(courseTrackerFile, "course_tracker_storage.dat");
}


void Writer::AddDTasks(int lId)
{
	ofstream fout(dTaskFile, ios_base::binary | ios_base::app);
	fout.write((char*)dTasks, sizeof(dTasksStruct));
	fout.close();
	DTasksTracker(lId);
}

void Writer::AddSTask(int lId)
{
	ofstream fout(sTaskFile, ios_base::binary | ios_base::app);
	fout.write((char*)sTask, sizeof(STask));
	fout.close();
	STaskTracker(lId);
}

void Writer::AddCourse(short lId)
{
	ofstream fout(coursesFile, ios_base::binary | ios_base::app);
	fout.write((char*)course, sizeof(Course));
	fout.close();
	CourseTracker(lId);
}

void Writer::DTasksTracker(int lId)
{
	int temp = lId + 1;
	ofstream fout(dTaskTrackerFile, ios_base::binary | ios_base::app);
	fout.write((char*)&temp, sizeof(int));
	fout.write((char*)&(dTasks->date), 10);
	fout.close();

	fout.open("init.ini", ios_base::binary | ios_base::app);
	fout.write((char*)&temp, sizeof(int));
	fout.close();
}

void Writer::STaskTracker(int lId)
{
	int temp = lId + 1;
	ofstream fout(sTaskTrackerFile, ios_base::binary | ios_base::app);
	fout.write((char*)&temp, sizeof(int));
	fout.write((char*)&(dTasks->date), 10);
	fout.close();

	fout.open("init.ini", ios_base::binary | ios_base::app);
	fout.seekp(sizeof(int));
	fout.write((char*)&temp, sizeof(int));
	fout.close();
}

void Writer::CourseTracker(int lId)
{
	int temp = lId + 1;
	ofstream fout(courseTrackerFile, ios_base::binary | ios_base::app);
	fout.write((char*)&temp, sizeof(int));
	fout.write((char*)&(course->code), 8);
	fout.close();

	fout.open("init.ini", ios_base::binary | ios_base::app);
	fout.seekp(2 * sizeof(int));
	fout.write((char*)&temp, sizeof(int));
	fout.close();
}


void Writer::UpdatedDTasks(int pos)
{
	ofstream fout(dTaskFile, ios_base::binary | ios_base::app);
	fout.seekp(pos);
	fout.write((char*)dTasks, sizeof(dTasksStruct));
	fout.close();
}

void Writer::UpdateSTask(int pos)
{
	ofstream fout(sTaskFile, ios_base::binary | ios_base::app);
	fout.seekp(pos);
	fout.write((char*)sTask, sizeof(STask));
	fout.close();
}

void Writer::UpdateCourse(int pos)
{
	ofstream fout(coursesFile, ios_base::binary | ios_base::app);
	fout.seekp(pos);
	fout.write((char*)course, sizeof(Course));
	fout.close();
}


////////////////////////////////////
//// Reader Class Implementation





Reader::Reader()
{
	strcpy(dTaskFile, "d_tasks_storage.dat");
	strcpy(dTaskTrackerFile, "d_tasks_tracker_storage.dat");
	strcpy(sTaskFile, "s_tasks_storage.dat");
	strcpy(sTaskTrackerFile, "s_tasks_tracker_storage.dat");
	strcpy(courseTrackerFile, "course_storage.dat");
	strcpy(courseTrackerFile, "course_tracker_storage.dat");
}


void Reader::FindInDTasks()
{
	cout << "test";
	//ifstream fin(dTaskTrackerFile, ios_base::binary);
	
	/*int temp;
	char tArr[10];
	bool flag = false;
	while (!fin.eof())
	{
		fin.seekg(4, ios_base::cur);
		fin.read((char*)tArr, 10);
		if ((strcmp(tArr, keyword) == 0))
		{
			flag = true;
			fin.seekg(-14, ios_base::cur);
			fin.read((char*)&temp, sizeof(int));
			fin.close();
			break;
		}
	}

	if (flag == true)
		dTasksTN = temp;
	else
		cout << "Out of Date";*/

}



void Reader::FindInSTasks(const char* keyword)
{
	cout << "test";
	ifstream fin(sTaskTrackerFile, ios_base::binary);
	int temp;
	char tArr[10];
	bool flag = false;
	while (!fin.eof())
	{
		fin.seekg(4, ios_base::cur);
		fin.read((char*)tArr, 10);
		if ((strcmp(tArr, keyword) == 0))
		{
			flag = true;
			fin.seekg(-14, ios_base::cur);
			fin.read((char*)&temp, sizeof(int));
			fin.close();
			break;
		}
	}

	if (flag == true)
		sTaskTN = temp;
	else
		cout << "Out of Date";

}



void Reader::FindInCourses(const char* keyword)
{
	ifstream fin(courseTrackerFile, ios_base::binary);
	int temp;
	char tArr[8];
	bool flag = false;
	while (!fin.eof())
	{
		fin.seekg(4, ios_base::cur);
		fin.read((char*)tArr, 8);
		if ((strcmp(tArr, keyword) == 0))
		{
			flag = true;
			fin.seekg(-12, ios_base::cur);
			fin.read((char*)&temp, sizeof(int));
			fin.close();
			break;
		}
	}

	if (flag == true)
		courseTN = temp;
	else
		cout << "Out of Date";

}




dTasksStruct Reader::RetDTasks()
{
	ifstream fin(dTaskFile, ios_base::binary);
	fin.seekg(dTasksTN - 1);
	fin.read((char*)&dTasks, sizeof(dTasksStruct));
	return dTasks;
}


STask Reader::RetSTask()
{
	ifstream fin(sTaskFile, ios_base::binary);
	fin.seekg(sTaskTN - 1);
	fin.read((char*)&dTasks, sizeof(DTask));
	return sTask;
}


Course Reader::RetCourse()
{
	ifstream fin(coursesFile, ios_base::binary);
	fin.seekg(courseTN - 1);
	fin.read((char*)&dTasks, sizeof(Course));
	return course;
}





/////////////////////////


void GenerateDate(char* date)
{
	time_t now = time(nullptr);
	tm* timeCod = localtime(&now);
	string sDate = to_string(timeCod->tm_mday) + ":" + to_string(timeCod->tm_mon) + ":" + to_string(timeCod->tm_year);
	strcpy(date, sDate.c_str());
}
void DailyTasksManager(int arr[])
{
	while (1)
	{
		char option;

		cout << "Choose an Option - a (Create) - b ( Display) - r (Return): "; cin >> option;
		if (option == 'a')
		{
			dTasksStruct tTasks;
			short n;
			cout << "Number of Tasks: "; cin >> n;
			GenerateDate(tTasks.date);
			for (int i = 0; i < n; i++)
			{
				tTasks.dTasks[i].Create(i);
			}
			tTasks.nTasks = n;
			Writer obj(&tTasks);
			obj.AddDTasks(arr[0]);
		}
		else if (option == 'b')
		{
			dTasksStruct tTasks;
			char tempArr[10];
			cout << "Enter specific date must be formatted(D:M:Y): today (Current Date): "; cin.get(); cin.getline(tempArr, 10);
			Reader objec;
			cout << tempArr;
			objec.FindInDTasks();
			
			tTasks = objec.RetDTasks();
			cout << "Date: " << tTasks.date << endl;
			for (int i = 0; i < tTasks.nTasks; i++)
				tTasks.dTasks[i].Display();
		}
		else if (option == 'r')
		{
			break;
		}
		else
		{
			cout << "Incorrect Input!\n";
		}
	}
}

void init(int arr[])
{
	ifstream fin("init.ini", ios_base::binary);
	fin.read((char*)arr, 12);
}


void SpecialTasksManager(int arr[])
{
	while (1)
	{

		char option;
		cout << "Choose an Option - a (Create) - b ( Display) - c (edit) - r (Return): "; cin >> option;
		if (option == 'a')
		{
			STask task;
			task.Create(arr[1]);
			Writer object(&task);
			object.AddDTasks(arr[1]);
		}
		else if (option == 'b')
		{
			STask sTask;
			char temp[10];
			cout << "Enter Date: (must be formatted: M:D:Y): "; cin.get(); cin.getline(temp, 10);
			Reader object;
			object.FindInSTasks(temp);
			sTask = object.RetSTask();
			sTask.Display();
		}
		else if (option == 'c')
		{
			STask sTask;
			char temp[10];
			cout << "Enter Date: (must be formatted: M:D:Y): ";cin.get(); cin.getline(temp, 10);
			Reader object;
			object.FindInSTasks(temp);
			sTask = object.RetSTask();
			sTask.Edit();
		}
		else if (option == 'r')
		{
			break;
		}
		else
		{
			cout << "Incorrect Input!\n";
		}
	}
}

void CoursesManager(int arr[])
{
	while (1)
	{

		char option;
		cout << "Choose an Option - a (Create) - b ( Display) - c (edit) - r (Return): "; cin >> option;
		if (option == 'a')
		{
			Course course;
			course.CreateCourse();
			Writer object(&course);
			object.AddDTasks(arr[2]);
		}
		else if (option == 'b')
		{
			cout << "Not Available for now!\n";
		}
		else if (option == 'c')
		{
			Course course;
			char temp[10];
			cout << "Enter Course Code: ";cin.get(); cin.getline(temp, 10);
			Reader object;
			object.FindInCourses(temp);
			course = object.RetCourse();
			course.EditCourse();
		}
		else if (option == 'r')
		{
			break;
		}
		else
		{
			cout << "Incorrect Input!\n";
		}
	}
}
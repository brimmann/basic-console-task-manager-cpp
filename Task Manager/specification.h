#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <ctime>
#define ADJUSTFEILD_R cout.setf(ios_base::left, ios_base::adjustfield)
using namespace std;
class DTask
{
protected:
	int id;
	char title[128];
	bool status;
private:
	short eTime;
	short importance;
public:
	DTask();
	void Create(short);
	void Display() const;
	void UpdateStatus();
};


class STask : private DTask
{
private:
	short wDay;
	void GenerateDate();
public:
	char date[10];
	STask();
	void Create(int);
	void Edit();
	void Display() const;
};

class Topic
{
private:
	short id;
	char title[128];
	bool status;
public:
	Topic();
	void Create(short);
	void Edit();
	void UpdateStatus();
	void Display() const;
};


class Course
{
private:
	Topic syl[80];
	char title[128];
	short cr;
	short semester;
	short topicsNum;
public:
	char code[8];
	Course() {};
	void Display();
	void CreateCourse();
	void CreateSyl();
	void EditCourse();
	void EditSyl();
	void DisplaySyl() const;
};


///////////////////////////////////////////////
struct dTasksStruct
{
	DTask dTasks[10];
	char date[10];
	int nTasks;
};

class Writer
{
private:
	dTasksStruct * dTasks;
	STask * sTask;
	Course * course;
	char dTaskFile[20];
	char sTaskFile[20];
	char coursesFile[20];
	char dTaskTrackerFile[20];
	char sTaskTrackerFile[20];
	char courseTrackerFile[20];

	void DTasksTracker(int);
	void STaskTracker(int);
	void CourseTracker(int);
public:
	Writer(dTasksStruct *);
	Writer(STask *);
	Writer(Course *);
	void AddDTasks(int);
	void AddSTask(int);
	void AddCourse(short);
	void UpdatedDTasks(const int);
	void UpdateSTask(const int);
	void UpdateCourse(const int);
};


class Reader
{
private:
	dTasksStruct dTasks;
	STask sTask;
	Course course;

	int dTasksTN;
	int sTaskTN;
	int courseTN;

	char dTaskFile[20];
	char sTaskFile[20];
	char coursesFile[20];
	char dTaskTrackerFile[20];
	char sTaskTrackerFile[20];
	char courseTrackerFile[20];

public:
	Reader();
	void FindInDTasks();
	void FindInSTasks(const char*);
	void FindInCourses(const char*);

	dTasksStruct RetDTasks();
	STask RetSTask();
	Course RetCourse();
};


/////////////////Basic Functions

void DailyTasksManager(int[]);
void GenerateDate(char*);
void init(int[]);
void SpecialTasksManager(int []);
void CoursesManager(int []);







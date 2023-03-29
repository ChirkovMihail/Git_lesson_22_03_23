#pragma once
#include "Head.h"
#include "Solution_stud.h"

//contest
void scanf_file_contest(string& file_name, vector <string>& Name_contest)
{
	string contest;
	ifstream in(file_name);

	while (getline(in, contest))
	{
		Name_contest.push_back(contest);
	}
	in.close();
}

//tasks
void scanf_file_task(string& file_name, vector <string>& Name_task)
{
	string task;
	ifstream in(file_name);

	while (getline(in, task))
	{
		Name_task.push_back(task);
	}
	in.close();
}

//students
void scanf_file_student(string& file_name, vector <string>& Name_student)
{
	string student;
	ifstream in(file_name);

	while (getline(in, student))
	{
		Name_student.push_back(student);
	}
	in.close();
}

//compiler
void scanf_file_compiler(string& file_name, vector <string>& Name_compiler)
{
	string compiler;
	ifstream in(file_name);

	while (getline(in, compiler))
	{
		Name_compiler.push_back(compiler);
	}
	in.close();
}

//all base info
void scanf_all_info(vector <string>& Name_contest,
					vector <string>& Name_Tasks,
					vector <string>& Name_Student,
					vector <string>& Name_Compiler)
{
	string Loc_file_name_contest = Folder_base_put + File_contests;
	string Loc_file_name_tasks = Folder_base_put + File_tasks;
	string Loc_file_name_student = Folder_base_put + File_students;
	string Loc_file_name_compiler = Folder_base_put + File_compiler;

	scanf_file_contest(Loc_file_name_contest, Name_contest);
	scanf_file_task(Loc_file_name_tasks, Name_Tasks);
	scanf_file_student(Loc_file_name_student, Name_Student);
	scanf_file_compiler(Loc_file_name_compiler, Name_Compiler);
}

void scanf_info_solution(string FileName, Solution_stud& sol)
{
	ifstream in(FileName);
	string Str;
	string solution = "";

	getline(in, Str); //id посылки
	sol.set_Name_package(Str);

	getline(in, Str); // time
	sol.set_Date(Str);

	getline(in, Str); //nickname stud
	sol.set_Name_stud(Str);

	getline(in, Str); // compiler
	sol.set_Name_compiler(Str);

	while (getline(in, Str))
		solution += Str;

	sol.set_Solution(solution);

	in.close();
}
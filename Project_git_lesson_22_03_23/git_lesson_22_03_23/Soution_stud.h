#pragma once
#include "Head.h"

class Solution_stud {
private:
	string Name_package;
	string Name_contest;
	string Name_problem;
	string Name_compiler;
	string Name_stud;
	string Solution;
	string Date;
	int Time;
	string verdict;
	int dist_levenstein;
	string Name_stud_dist_levenstein;
	string Name_dist_levenstein_package;

public:

///////////////////////////////////////getters//////////////////////////////////////////////

	string get_Name_contest() {
		return Name_contest;
	}
	string get_Name_problem() {
		return Name_problem;
	}
	string get_Name_package() {
		return Name_package;
	}
	string get_Name_compiler() {
		return Name_compiler;
	}
	string get_Name_stud() {
		return Name_stud;
	}
	string get_Solution() {
		return Solution;
	}
	string get_Date() {
		return Date;
	}
	int get_Time() {
		return Time;
	}
	string get_verdict() {
		return verdict;
	}
	int get_dist_levenstein() {
		return dist_levenstein;
	}
	string get_Name_stud_dist_levenstein() {
		return Name_stud_dist_levenstein;
	}
	string get_Name_dist_levenstein_package() {
		return Name_dist_levenstein_package;
	}

///////////////////////////////////////setters//////////////////////////////////////////////

	void set_Name_contest(string &value) {
		Name_contest = value;
	}
	void set_Name_problem(string& value) {
		Name_problem = value;
	}
	void set_Name_package(string& value) {
		Name_package = value;
	}
	void set_Name_compiler(string& value) {
		Name_compiler = value;
	}
	void set_Name_stud(string& value) {
		Name_stud = value;
	}
	void set_Solution(string& value) {
		Solution = value;
	}
	void set_Date(string& value) {
		Date = value;
	}
	void set_Time(int &value) {
		Time = value;
	}
	void set_verdict(string& value) {
		verdict = value;
	}
	void set_dist_levenstein(int &value) {
		dist_levenstein = value;
	}
	void set_Name_stud_dist_levenstein(string& value) {
		Name_stud_dist_levenstein = value;
	}
	void set_Name_dist_levenstein_package(string& value) {
		Name_dist_levenstein_package = value;
	}

	Solution_stud() {
		Name_package = "None";
		Name_contest = "None";
		Name_problem = "None";
		Name_compiler = "None";
		Name_stud = "None";
		Solution = "None";
		Date = "None";
		Time = -1;
		verdict = "None";
		dist_levenstein = const_length_code;
		Name_stud_dist_levenstein = "None";
		Name_dist_levenstein_package = "None";
	}

	~Solution_stud() {
		Name_package.clear();
		Name_contest.clear();
		Name_problem.clear();
		Name_compiler.clear();
		Name_stud.clear();
		Solution.clear();
		Date.clear();
		verdict.clear();
		Name_stud_dist_levenstein.clear();
		Name_dist_levenstein_package.clear();
	}
};
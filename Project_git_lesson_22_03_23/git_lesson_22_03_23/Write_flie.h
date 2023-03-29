#pragma once
#include "Head.h"
#include "Solution_stud.h"

void write_info_stud(string& Name_student, vector <Solution_stud>& Stud)
{
	string File_info = Folder_base_put + Folder_base_stud;
	File_info += Name_student + '/';
	File_info += Name_student + ".txt";

	ofstream out(File_info);
	for (int i = 0; i < Stud.size(); ++i)
	{
		out << Stud[i].get_Name_contest() << " ";
		out << Stud[i].get_Name_problem() << ' ';
		out << Stud[i].get_Name_package() << ' ';
		out << Stud[i].get_verdict() << ' ';

		if (Stud[i].get_verdict() == "Coincidence") {
			out << Stud[i].get_Name_stud_dist_levenstein() << ' ';
			out << Stud[i].get_Name_dist_levenstein_package() << ' ';
			out << Stud[i].get_dist_levenstein() << ' ';
		}
		out << '\n';
	}

	out.close();
}

void write_info_all_stud(vector <pair <string, int> > &All_stud)
{
	string flie_info_all = Folder_base_put + "result.txt";

	ofstream out(flie_info_all);

	for (int i = 0; i < All_stud.size(); ++i) 
		out << All_stud[i].first << ' ' << All_stud[i].second << '\n';

	out.close();
}
#include"Head.h"
#include"Levenstein.h"
#include"Mini_algo.h"
#include"Scanf_file.h"
#include"Solution_stud.h"
#include"Write_flie.h"
#include "Change_String.h"

void solve()
{
	vector <string> Name_contest;
	vector <string> Name_tasks;
	vector <string> Name_student;
	vector <string> Name_compiler;
	vector <pair<string, int> > All_stud;

	scanf_all_info(Name_contest, Name_tasks, Name_student, Name_compiler);

	string Path;

	for (int id_stud = 0; id_stud < Name_student.size(); ++id_stud) {
		vector <Solution_stud> sol_stud;

		for (int id_contest = 0; id_contest < Name_contest.size(); ++id_contest) {
			for (int id_task = 0; id_task < Name_tasks.size(); ++id_task) {
				Solution_stud sol;
				Path = Generate_path_solution(Name_student[id_stud], Name_contest[id_contest], Name_tasks[id_task]);

				ifstream fin(Path);
				if (fin.is_open()) {
					scanf_info_solution(Path, sol);
					sol.set_Name_contest(Name_contest[id_contest]);
					sol.set_Name_problem(Name_tasks[id_task]);

					string Date = sol.get_Date();
					int timer = Time_solution(Date);
					sol.set_Time(timer);

					string verdict = "Coincidence";
					sol.set_verdict(verdict);

					string path_coach = Generate_path_coach(Name_contest[id_contest], Name_tasks[id_task]);
					ifstream fin_coach(path_coach);
					if (fin_coach.is_open()) {
						verdict = "OK";
						sol.set_verdict(verdict);
					}
					else
					{
						string solution = sol.get_Solution();
						solution = change_str(solution);
						sol.set_Solution(solution);
						for (int id_stud_c = 0; id_stud_c < Name_student.size(); ++id_stud_c) {
							if (id_stud != id_stud_c) {
								string path_c = Generate_path_solution(Name_student[id_stud], Name_contest[id_contest], Name_tasks[id_task]);
								ifstream fin_c(path_c);
								if (fin_c.is_open()) {
									Solution_stud sol_c;
									scanf_info_solution(path_c, sol_c);
									solution = sol_c.get_Solution();
									solution = change_str(solution);;
									sol.set_Solution(solution);

									string sol1 = sol.get_Solution();
									string sol2 = sol_c.get_Solution();
									int dist = Algo_levenstein(sol1, sol2);

									if (sol.get_dist_levenstein() > dist) {
										sol.set_dist_levenstein(dist);

										string pack = sol_c.get_Name_package();
										sol.set_Name_dist_levenstein_package(pack);
										
										sol.set_Name_stud_dist_levenstein(Name_student[id_stud_c]);
									}
								}
								fin_c.close();
							}
						}
					}
					fin_coach.close();
					sol_stud.push_back(sol);
					cout << Path << '\n';
				}
				fin.close();
			}
		}
		chack_time_solution(sol_stud);
		write_info_stud(Name_student[id_stud], sol_stud);
		Result_all_stud(Name_student[id_stud], sol_stud, All_stud);
	}
	write_info_all_stud(All_stud);
}

int main()
{
	solve();
}

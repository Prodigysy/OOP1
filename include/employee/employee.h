#pragma once
#include <string>
#include <stdexcept>
using namespace std;
namespace employees {
	enum EmployeeType {
		Staff,
		Freelance
	};

	class Employee {
	private:
		string full_name;
		int year_of_hiring;
		int current_year;
		EmployeeType type;
		int basic_rate_for_month;
		int basic_rate_for_hour;
		double percent_of_individual_allowance;
		int number_of_hours_in_month;
	public:
		void set_full_name(string full_name);
		void set_year_of_hiring(int year_of_hiring);
		void set_current_year (int current_year);
		void set_type (EmployeeType type);
		void set_basic_rate_for_month(int basic_rate_for_month);
		void set_basic_rate_for_hour(int basic_rate_for_hour);
		void set_percent_of_individual_allowance(double percent_of_individual_allowance);
		void set_number_of_hours_in_month(int number_of_hours_in_month);
		string get_full_name();
		int get_year_of_hiring();
		int get_current_year();
		EmployeeType get_type();
		int get_basic_rate_for_month();
		int get_basic_rate_for_hour();
		double get_percent_of_individual_allowance();
		int get_number_of_hours_in_month();

        Employee();
		Employee(string full_name, int year_of_hiring, EmployeeType type, int basic_rate_for_month, int current_year);
		Employee(string full_name, int year_of_hiring, EmployeeType type, int basic_rate_for_hour, double percent_of_individual_allowance, int number_of_hours_in_month);

		int compute_salary();
	};

    class EmployeeList {
        static const int CAPACITY = 10;
        Employee _employee[CAPACITY];
        int _size;

    public:
        EmployeeList();
        EmployeeList(Employee employees[], int size);
		EmployeeList(Employee employees[], int size,int);

		Employee get_employee_by_index(int index);
		int get_size();
		void set_size(int size);
		Employee& operator[](int index);
		void add_employer(int index, Employee employer);
		void del_employer(int index);
		void clear();
		int find_with_max_salary(Employee employees[]);
    };
}
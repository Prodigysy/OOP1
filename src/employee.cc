#include <employee/employee.h>

using namespace employees;

Employee::Employee() {
	full_name = "";
	year_of_hiring = 0;
	current_year = 0;
	type = Staff;
	basic_rate_for_month = 0;
	basic_rate_for_hour = 0;
	percent_of_individual_allowance = 0;
	number_of_hours_in_month = 0;
}

void Employee::set_full_name(string full_name) { this->full_name = full_name; }
void Employee::set_year_of_hiring(int year_of_hiring) { this->year_of_hiring = year_of_hiring; }
void Employee::set_current_year(int current_year) { this->current_year = current_year; }
void Employee::set_type(EmployeeType type) { this->type = type; }
void Employee::set_basic_rate_for_month(int basic_rate_for_month) { this->basic_rate_for_month = basic_rate_for_month; }
void Employee::set_basic_rate_for_hour(int basic_rate_for_hour) { this->basic_rate_for_hour = basic_rate_for_hour; }
void Employee::set_percent_of_individual_allowance(double percent_of_individual_allowance) { this->percent_of_individual_allowance = percent_of_individual_allowance; }
void Employee::set_number_of_hours_in_month(int number_of_hours_in_month) { this->number_of_hours_in_month = number_of_hours_in_month; }
string Employee::get_full_name() { return full_name; }
int Employee::get_year_of_hiring() { return year_of_hiring; }
int Employee::get_current_year() { return current_year; }
EmployeeType Employee::get_type() { return type; }
int Employee::get_basic_rate_for_month() { return basic_rate_for_month; }
int Employee::get_basic_rate_for_hour() { return basic_rate_for_hour; }
double Employee::get_percent_of_individual_allowance() { return percent_of_individual_allowance; }
int Employee::get_number_of_hours_in_month(){ return number_of_hours_in_month;}

Employee::Employee(string full_name, int year_of_hiring, EmployeeType type, int basic_rate_for_month,int current_year) {
    this->full_name = full_name;
    this->year_of_hiring = year_of_hiring;
    this->type = type;
    this->basic_rate_for_month = basic_rate_for_month;
    this->current_year = current_year;
}
Employee::Employee(string full_name, int year_of_hiring, EmployeeType type, int basic_rate_for_hour,
    double percent_of_individual_allowance, int number_of_hours_in_month) {
    this->full_name = full_name;
    this->year_of_hiring = year_of_hiring;
    this->type = type;
    this->basic_rate_for_hour = basic_rate_for_hour;
    this->percent_of_individual_allowance = percent_of_individual_allowance;
    this->number_of_hours_in_month = number_of_hours_in_month;
}

int Employee::compute_salary() {
    if (type == Staff) {
        int salary = basic_rate_for_month + ((current_year - year_of_hiring) * 0.005) * basic_rate_for_month;
        return salary;
    }
	if (type == Freelance) {
        int salary = ((1+(0.01*percent_of_individual_allowance)) * basic_rate_for_hour) * number_of_hours_in_month;
        return salary;
    }
    else {
        throw runtime_error("the method is not for that type.");
    }
}


EmployeeList::EmployeeList()
{
	this->_size = 6;
	for (int i = 0; i < _size; ++i) _employee[i] = Employee();
}
//копируем 
EmployeeList::EmployeeList(Employee employees[], int size) {
	this->_size = size;

	for (int i = 0; i < size; ++i) {
			this->_employee[i].set_full_name(employees[i].get_full_name());
			this->_employee[i].set_year_of_hiring(employees[i].get_year_of_hiring());
			this->_employee[i].set_type(employees[i].get_type());
			this->_employee[i].set_basic_rate_for_month(employees[i].get_basic_rate_for_month());
			this->_employee[i].set_current_year(employees[i].get_current_year());
	}
}
//создания объектов EmployeeList (почасовая ставка) 
EmployeeList::EmployeeList(Employee employees[], int size,int) {
	this->_size = size;

	for (int i = 0; i < size; ++i) {
			this->_employee[i].set_full_name(employees[i].get_full_name());
			this->_employee[i].set_year_of_hiring(employees[i].get_year_of_hiring());
			this->_employee[i].set_type(employees[i].get_type());
			this->_employee[i].set_basic_rate_for_hour(employees[i].get_basic_rate_for_month());
			this->_employee[i].set_percent_of_individual_allowance(employees[i].get_percent_of_individual_allowance());
			this->_employee[i].set_number_of_hours_in_month(employees[i].get_number_of_hours_in_month());
	}
}
//возвращает объект Employee по его индексу
Employee EmployeeList::get_employee_by_index(int index) { 
	return _employee[index]; 
}
//возвращает количество работников
int EmployeeList::get_size() { 
	return _size; 
}
//устанавливает количество работников
void EmployeeList::set_size(int size) {
	this->_size = size; 
}
//возвращает ссылку на объект Employee в массиве
Employee& EmployeeList::operator[](int index)
{
	if (index < 0 || index >= _size)
	{
		throw runtime_error("Index out of range.");
	}
	return _employee[index];
}
void EmployeeList::add_employer(int index, Employee employer)
{
	if (_size == CAPACITY)
	{
		throw runtime_error("Full capacity reached.");
	}

	if (index < 0 || index >= _size)
	{
		throw runtime_error("Index out of range.");
	}

	for (int i = _size - 1; i >= index; --i) { _employee[i] = _employee[i - 1]; }
	_employee[index] = employer;
	++_size;
}
void EmployeeList::clear() { _size = 0; }
void EmployeeList::del_employer(int index)
{
	if (_size == 0)
	{
		throw runtime_error("List is empty.");
	}
	for (int i = index; i < _size - 1; ++i) { _employee[i] = _employee[i + 1]; }
	--_size;
}

int EmployeeList::find_with_max_salary(Employee employees[]) {
	int index = 0;
	double max_salary = employees[0].compute_salary();
	for (int i = 1; i <= _size - 1; ++i)
	{
		double cur_salary = employees[i].compute_salary();
		if (cur_salary > max_salary)
		{
			index = i;
			max_salary = cur_salary;
		}
	}
	return index;
}
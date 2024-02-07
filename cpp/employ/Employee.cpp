#include <iostream>
#include "Employee.hpp"
// module employee;
using namespace std;
namespace Records {
    Employee::Employee(const string& firstName, const string& lastName)
        : m_firstName{ firstName }, m_lastName {lastName} {}
    
    void Employee::promote(int raiseAmount)
    {
        setSalary(getSalary() + raiseAmount);
    }

    void Employee::demote(int demeritAmount)
    {
        setSalary(getSalary() - demeritAmount);
    }

    void Employee::hire() { m_hired = true; }
    void Employee::fire() { m_hired = false; }

    void Employee::setFirstName(const string& firstName)
    {
        m_firstName = firstName;
    }

    const string& Employee::getFirstName() const
    {
        return m_firstName;
    }
}
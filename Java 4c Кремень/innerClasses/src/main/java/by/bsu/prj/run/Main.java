package by.bsu.prj.run;

import by.bsu.prj.entity.Department;

public class Main {
    public static void main(String[] args){
        Department department = new Department("Name","address");
        Department.Employee employee = department.new Employee("Ivan","Ivanov", Department.position.CHIEF);
        department.addEmployee(employee);
        Department.Employee employee2 = department.new Employee("Sanya","Saniev", Department.position.CLEANER);
        department.addEmployee(employee2);
        department.fireEmployee(employee2);
        System.out.println("All employees");
        department.showAllEmployees();
        System.out.println("Currently working employees");
        department.showCurrentlyWorking();
    }
}

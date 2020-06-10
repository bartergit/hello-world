package by.bsu.prj.entity;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class Department {
    private String name;
    private String address;
    private long number;
    private List<Employee> employeeList;
    public enum position {
        SECRETARY,
        CLEANER,
        CHIEF,
        DEPUTY_CHIEF,
        HEAD_OF_FINANCE
    }

    public void showAllEmployees(){
        employeeList.forEach(System.out::println);
    }

    public void showCurrentlyWorking(){
        employeeList.forEach(em -> {if (em.isCurrentlyWorking()) System.out.println(em);});
    }

    public void addEmployee(Employee employee){
        employeeList.add(employee);
    }

    public void fireEmployee(Employee employee){
        employeeList.get(employeeList.indexOf(employee)).setCurrentlyWorking(false);
    }

    public class Employee{
        private String name;
        private String surname;
        private position position;
        private int age;
        private long number;
        private boolean isCurrentlyWorking;
        public Employee(String name, String surname, Department.position position) {
            isCurrentlyWorking = true;
            this.name = name;
            this.surname = surname;
            this.position = position;
        }

        @Override
        public String toString() {
            return "Employee{" +
                    "name='" + name + '\'' +
                    ", surname='" + surname + '\'' +
                    ", position=" + position +
                    ", age=" + age +
                    ", number=" + number +
                    ", isCurrentlyWorking=" + isCurrentlyWorking +
                    '}';
        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        public String getSurname() {
            return surname;
        }

        public void setSurname(String surname) {
            this.surname = surname;
        }

        public Department.position getPosition() {
            return position;
        }

        public void setPosition(Department.position position) {
            this.position = position;
        }

        public int getAge() {
            return age;
        }

        public void setAge(int age) {
            this.age = age;
        }

        public long getNumber() {
            return number;
        }

        public void setNumber(long number) {
            this.number = number;
        }

        public boolean isCurrentlyWorking() {
            return isCurrentlyWorking;
        }

        public void setCurrentlyWorking(boolean currentlyWorking) {
            isCurrentlyWorking = currentlyWorking;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Employee employee = (Employee) o;
            return age == employee.age &&
                    number == employee.number &&
                    isCurrentlyWorking == employee.isCurrentlyWorking &&
                    name.equals(employee.name) &&
                    surname.equals(employee.surname) &&
                    position == employee.position;
        }
    }


    public Department(String name) {
        employeeList = new ArrayList<Employee>();
        this.name = name;
    }

    public Department(String name, String address) {
        employeeList = new ArrayList<Employee>();
        this.name = name;
        this.address = address;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public long getNumber() {
        return number;
    }

    public void setNumber(long number) {
        this.number = number;
    }

}

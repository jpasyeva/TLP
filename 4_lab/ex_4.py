import psycopg2
import datetime
from tabulate import tabulate



conn = psycopg2.connect(
    "host=localhost dbname=lab4 port=32776 user=postgres password=pass")

def start(conn):
    cur = conn.cursor()
    try:
        cur.execute(
            'CREATE TABLE employees ( \
            id serial primary key, full_name varchar, \
            started date, job_title varchar, level varchar,  \
            salary integer, department_name varchar, permission boolean)'
        )
        conn.commit()
        cur.execute(
            'CREATE TABLE departments ( \
            id serial primary key, department_name varchar, \
            head_of_department_full_name varchar, employee_quantity integer)'
        )
        conn.commit()
        cur.execute(
            'CREATE TABLE KPI( \
            id serial primary key, employee_id integer, \
            working_quarter integer, evaluation varchar)'
        )
        conn.commit()
        cur.execute(
            "INSERT INTO employees (full_name, started, job_title, level, salary, department_name, permission) VALUES\
            ('Cole White', '2020-05-01', 'Project Manager', 'Middle', 2500, 'Management Department', True), \
            ('Braiden Kane', '2020-05-01', 'Fullstack Developer', 'Senior', 2500, 'IT Department', True), \
            ('Jaylee Oconnor', '2020-05-01', 'Chief Marketer', 'Middle', 2000, 'Marketing Department', False), \
            ('Alena Mccann', '2020-06-10', 'Human Resources', 'Senior', 2000, 'HR Department', False), \
            ('Nikolas Crosby', '2020-06-10', 'Buisness Analyst', 'Middle', 1500, 'Management Department', True), \
            ('Amani Holden', '2020-06-25', 'Quality Assure', 'Junior', 900, 'IT Department', True), \
            ('Jayleen Shaw', '2020-06-25', 'Recruiter', 'Junior', 800, 'HR department', False), \
            ('Kelsie Wang', '2020-07-05', 'Frontend Developer', 'Middle', 1500, 'IT Department', True),  \
            ('Andres Bell', '2020-07-15', 'Backend Developer', 'Junior', 1500, 'IT Department', True)"
        )
        conn.commit() 
        cur.execute(
            "INSERT INTO departments (department_name, head_of_department_full_name, employee_quantity) VALUES \
            ('Management Department', 'Cole White', 2), ('IT Department', 'Braiden Kane', 4), \
            ('Marketing Department', 'Jaylee Oconnor', 1), ('HR Department', 'Alena Mccann', 2)"
        )
        conn.commit()
        cur.execute(
            "INSERT INTO KPI (employee_id, working_quarter, evaluation) VALUES \
            (1, 2, 'A'), (1, 3, 'B'), (1, 4, 'A'), (1, 1, 'B'), (1, 2, 'A'), (1, 3, 'A'), \
            (2, 2, 'B'), (2, 3, 'B'), (2, 4, 'A'), (2, 1, 'A'), (2, 2, 'C'), (2, 3, 'B'), \
            (3, 2, 'A'), (3, 3, 'A'), (3, 4, 'B'), (3, 1, 'B'), (3, 2, 'A'), (3, 3, 'A'), \
            (4, 2, 'A'), (4, 3, 'A'), (4, 4, 'A'), (4, 1, 'B'), (4, 2, 'A'), (4, 3, 'A'), \
            (5, 2, 'B'), (5, 3, 'C'), (5, 4, 'B'), (5, 1, 'D'), (5, 2, 'B'), (5, 3, 'C'), \
            (6, 2, 'B'), (6, 3, 'A'), (6, 4, 'C'), (6, 1, 'A'), (6, 2, 'B'), (6, 3, 'B'), \
            (7, 2, 'B'), (7, 3, 'B'), (7, 4, 'A'), (7, 1, 'C'), (7, 2, 'B'), (7, 3, 'B'), \
            (8, 3, 'B'), (8, 4, 'A'), (8, 1, 'B'), (8, 2, 'A'), (8, 3, 'A'), \
            (9, 3, 'B'), (9, 4, 'A'), (9, 1, 'B'), (9, 2, 'C'), (9, 3, 'A')"
        )
        conn.commit()
    except Exception as err:
        print(f'Something went wrong: {err}')


"""_________Практическое задание 4.1________"""

"""Ваша команда расширяется и руководство запланировало открыть новый отдел – отдел Интеллектуального анализа данных. 
На начальном этапе в команду наняли одного руководителя отдела и двух сотрудников. 
Добавьте необходимую информацию в соответствующие таблицы."""
def add_department(conn):
    cur = conn.cursor()
    cur.execute(
        "INSERT INTO employees (full_name, started, job_title, level, salary, department_name, permission) VALUES\
        ('Santino Blanchard', '2020-07-20', 'Data Scientist', 'Middle', 2500, 'Data Mining Department', True), \
        ('Gordon Donovan', '2020-07-25', 'Data Analyst', 'Senior', 3000, 'Data Mining Department', True), \
        ('Julia Donovan', '2020-07-25', 'Data Analyst', 'Junior', 200, 'Data Mining Department', True)",
        
    )
    conn.commit() 
    cur.execute(
        "INSERT INTO departments (department_name, head_of_department_full_name, employee_quantity) VALUES\
        ('Data Mining Department', 'Gordon Donovan', 2)"
    )
    conn.commit() 

"""Уникальный номер сотрудника, его ФИО и стаж работы – для всех сотрудников компании"""
def get_employees(conn):
    print("Уникальный номер сотрудника, его ФИО и стаж работы – для всех сотрудников компании")
    date = datetime.date.today()
    cur = conn.cursor()
    cur.execute(f"SELECT id, full_name, (CAST('{date}' AS date) - CAST(started AS date))/365 FROM employees")
    print(tabulate(cur.fetchall()))

"""Уникальный номер сотрудника, его ФИО и стаж работы – только первых 3-х сотрудников"""
def get_first_three_employees(conn):
    print("Уникальный номер сотрудника, его ФИО и стаж работы – только первых 3-х сотрудников")
    date = datetime.date.today()
    cur = conn.cursor()
    cur.execute(f"SELECT id, full_name, (CAST('{date}' AS date) - CAST(started AS date))/365 FROM employees \
                WHERE employees.id <= 3")
    print(tabulate(cur.fetchall()))

"""Уникальный номер сотрудников - водителей"""
def get_employees_with_permission(conn):
    print("Уникальный номер сотрудников - водителей")
    cur = conn.cursor()
    cur.execute("SELECT id, permission FROM employees \
                WHERE employees.permission")
    print(tabulate(cur.fetchall()))

"""Выведите номера сотрудников, которые хотя бы за 1 квартал получили оценку D или E"""
def get_employees_with_d_e(conn):
    print("Номера сотрудников, которые хотя бы за 1 квартал получили оценку D или E")
    cur = conn.cursor()
    cur.execute("SELECT e.id, p.evaluation \
                FROM employees AS e FULL JOIN KPI AS p \
                ON e.id = p.employee_id \
                WHERE p.evaluation = 'D'")
    print(tabulate(cur.fetchall()))

"""Выведите самую высокую зарплату в компании."""
def get_max_salary(conn):
    print("Cамая высокая зарплата в компании")
    cur = conn.cursor()
    cur.execute("SELECT MAX(salary) FROM employees")
    print(tabulate(cur.fetchall()))

start(conn)
add_department(conn)
get_employees(conn)
get_first_three_employees(conn)
get_employees_with_permission(conn)
get_employees_with_d_e(conn)
get_max_salary(conn)


"""_________Практическое задание 4.2________"""

"""Вывести фамилию сотрудника с самой высокой зарплатой."""
def get_employee_with_max_salary(conn):
    print("Фамилия сотрудника с самой высокой зарплатой")
    cur = conn.cursor()
    cur.execute("SELECT full_name, salary FROM employees \
                ORDER BY salary DESC \
                LIMIT 1")
    print(tabulate(cur.fetchall()))

"""Вывести фамилии сотрудников в алфавитном порядке"""
def get_employees_sorted(conn):
    print("Фамилии сотрудников в алфавитном порядке")
    cur = conn.cursor()
    cur.execute("SELECT full_name FROM employees \
                ORDER BY full_name")
    print(tabulate(cur.fetchall()))

"""Рассчитайте средний стаж для каждого уровня сотрудников"""
def get_aver_exp_for_level(conn):
    print("Средний стаж для каждого уровня сотрудников")
    date = datetime.date.today()
    cur = conn.cursor()
    cur.execute(f"SELECT level, AVG((CAST('{date}' AS date) - CAST(started AS date))/365) AS average_experience \
                FROM employees \
                GROUP BY level")
    print(tabulate(cur.fetchall()))

"""Выведите фамилию сотрудника и название отдела, в котором он работает"""
def get_employees_with_departments(conn):
    print("Фамилии сотрудников и название отделов, в котором они работают")
    cur = conn.cursor() 
    cur.execute("SELECT full_name, department_name FROM employees")
    print(tabulate(cur.fetchall()))

"""Выведите название отдела и фамилию сотрудника с самой высокой зарплатой в данном отделе и саму зарплату также"""
def get_employee_department_with_max_salary(conn):
    print("Название отдела и фамилия сотрудника с самой высокой зарплатой в данном отделе и его зарплата")
    cur = conn.cursor()
    cur.execute("SELECT DISTINCT department_name, full_name, salary FROM employees \
                ORDER BY salary DESC")
    print(tabulate(cur.fetchall()))

get_employee_with_max_salary(conn)
get_employees_sorted(conn)
get_aver_exp_for_level(conn)
get_employees_with_departments(conn)
get_employee_department_with_max_salary(conn)

# Write your MySQL query statement below
select d.name as Department, e.name as Employee, e.salary as Salary from Department d
left join Employee e
on d.id = e.departmentId
where (d.id, Salary) in
(
    select departmentId, max(salary) from employee
    group by departmentId
)
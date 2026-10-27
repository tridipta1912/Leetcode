# Write your MySQL query statement below
select un.unique_id, em.name from Employees em
left join EmployeeUNI un
on em.id = un.id
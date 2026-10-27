with CTE as
(
    select distinct salary as second_max from employee
    order by salary desc
    limit 1 offset 1
)
select 
case when count(second_max) = 0 then null
else second_max end as SecondHighestSalary from CTE
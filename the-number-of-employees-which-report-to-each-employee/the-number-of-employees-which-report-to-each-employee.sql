# Write your MySQL query statement below
select t1.employee_id, t1.name, count(*) as reports_count, round(avg(t2.age)) as average_age from Employees t1
left join Employees t2
    on t1.employee_id = t2.reports_to
where t2.reports_to is not null
group by t1.employee_id
order by t1.employee_id


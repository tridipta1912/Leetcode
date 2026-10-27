# Write your MySQL query statement below
select c.name as Customers from Customers c
where not exists (
    select 1 from Orders o
    where o.customerID = c.id
);
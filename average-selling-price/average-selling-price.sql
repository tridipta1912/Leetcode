# Write your MySQL query statement below
select t.product_id, round(coalesce(sum(t.price * u.units) / sum(u.units), 0), 2) as average_price from Prices t
left join UnitsSold u
on 
t.product_id = u.product_id
and u.purchase_date between t.start_date and t.end_date
group by t.product_id
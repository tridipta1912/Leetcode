select c.customer_id as customer_id from Customer c
group by customer_id
having count(distinct c.product_key) = (select count(*) from product)
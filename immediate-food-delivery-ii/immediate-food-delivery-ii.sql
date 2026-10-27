with first_order as
(
    select customer_id, min(order_date) as min_order_date from Delivery
    group by customer_id
)
select round(100 * count(d.customer_pref_delivery_date) / count(*), 2) as immediate_percentage from first_order f
left join Delivery d
on f.min_order_date = d.customer_pref_delivery_date and f.customer_id = d.customer_id
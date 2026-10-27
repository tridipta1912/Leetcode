select s.user_id as user_id, 
round(case 
    when e2.user_id is not null then 
    count(case when e2.action = 'confirmed' then 1 or 0 end) / count(e2.user_id)
    else 0.0 end, 2)
as confirmation_rate from signups s
left join confirmations e2
on s.user_id = e2.user_id
group by s.user_id

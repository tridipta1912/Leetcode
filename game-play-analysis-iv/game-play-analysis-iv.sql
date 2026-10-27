with minimum as
(
    select player_id, min(event_date) as minn from Activity
    group by player_id
)
select round(count(m.minn) / count(distinct a.player_id), 2) as fraction from activity a
left join minimum m
on DATEDIFF(a.event_date, m.minn) = 1 and a.player_id = m.player_id

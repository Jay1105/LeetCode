# Write your MySQL query statement below
select b.contest_id, 
round(count(b.contest_id) / (select count(user_id) from Users) * 100, 2) as percentage
from Users a join Register b
on a.user_id = b.user_id
group by b.contest_id
order by percentage desc, b.contest_id asc;
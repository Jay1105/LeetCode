# Write your MySQL query statement below
select concat(year(trans_date), '-', lpad(month(trans_date), 2, '0')) as month, 
country, count(id) as trans_count,
count(case when state = "approved" then 1 end) as approved_count,
sum(amount) as trans_total_amount,
coalesce(sum(case when state = "approved" then amount end), 0) as approved_total_amount
from Transactions
group by concat(year(trans_date), '-', month(trans_date)), country;
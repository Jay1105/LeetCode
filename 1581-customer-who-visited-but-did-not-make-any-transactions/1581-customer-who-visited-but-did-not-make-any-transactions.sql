# Write your MySQL query statement below
select customer_id, COUNT(customer_id) as count_no_trans
from Visits
where visit_id NOT IN (select visit_id from Transactions)
Group by customer_id
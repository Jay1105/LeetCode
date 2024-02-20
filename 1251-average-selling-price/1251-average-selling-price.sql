# Write your MySQL query statement below
select a.product_id, 
case 
    when round(sum(a.price * s.units) / sum(s.units), 2) is not null then round(sum(a.price * s.units) / sum(s.units), 2)
    else 0
end as average_price
from Prices a
left join UnitsSold s
on a.product_id = s.product_id and s.purchase_date between a.start_date and a.end_date
group by a.product_id;
# Write your MySQL query statement below
select user_id, coalesce(count(distinct follower_id), 0) as followers_count
from Followers
group by user_id;
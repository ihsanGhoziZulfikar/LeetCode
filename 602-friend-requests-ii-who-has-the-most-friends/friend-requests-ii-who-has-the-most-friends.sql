# Write your MySQL query statement below
with sub_req AS(
    SELECT requester_id, COUNT(requester_id) as c_req FROM requestaccepted GROUP BY requester_id
),
sub_acc AS(
    SELECT accepter_id, COUNT(accepter_id) as c_acc FROM requestaccepted GROUP BY accepter_id
)
select id, sum(num) as num from
(
    SELECT requester_id AS id, c_req as num FROM sub_req
    UNION ALL
    SELECT accepter_id AS id, c_acc as num FROM sub_acc
) as sub
group by id order by num desc limit 1
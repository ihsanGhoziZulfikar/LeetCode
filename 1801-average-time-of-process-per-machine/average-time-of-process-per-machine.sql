# Write your MySQL query statement below
WITH start_act AS(
    SELECT * FROM activity WHERE activity_type = 'start'
),
end_act AS(
    SELECT * FROM activity WHERE activity_type = 'end'
)
SELECT e.machine_id, ROUND(AVG(e.timestamp - s.timestamp),3) as processing_time FROM end_act e JOIN start_act s WHERE e.machine_id = s.machine_id AND e.process_id = s.process_id GROUP BY machine_id;

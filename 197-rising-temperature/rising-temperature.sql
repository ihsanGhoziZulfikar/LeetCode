# Write your MySQL query statement below
WITH subq AS(
    SELECT id, DATE_ADD(recordDate, INTERVAL 1 DAY) as yesterday, temperature FROM weather
)
SELECT w.id FROM weather w, subq s WHERE w.recordDate=s.yesterday AND w.temperature > s.temperature
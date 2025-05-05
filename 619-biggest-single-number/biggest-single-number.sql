# Write your MySQL query statement below
SELECT COALESCE (
    (SELECT num FROM mynumbers GROUP BY num HAVING COUNT(1) < 2 ORDER BY num DESC LIMIT 1)
, null) AS num
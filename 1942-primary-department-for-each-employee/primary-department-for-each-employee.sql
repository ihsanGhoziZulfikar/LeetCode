# Write your MySQL query statement below
-- WITH subq AS(
-- SELECT employee_id, department_id, COUNT(employee_id) as aa, primary_flag FROM employee GROUP BY employee_id
-- HAVING COUNT(CASE WHEN primary_flag='Y' THEN 1 END)=1 OR aa=1
-- )
-- -- SELECT DISTINCT employee_id, department_id FROM subq WHERE aa=1 OR primary_flag='Y'
-- SELECT * from subq

WITH subq AS(
    SELECT employee_id, department_id FROM employee WHERE primary_flag='Y'
),
subq2 AS(
    SELECT employee_id, department_id FROM employee GROUP BY employee_id HAVING COUNT(employee_id)=1 AND COUNT(CASE WHEN primary_flag='Y' THEN 1 END)=0
)

SELECT * FROM subq UNION SELECT * FROM subq2
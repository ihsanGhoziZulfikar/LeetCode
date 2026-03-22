# Write your MySQL query statement below
WITH sub AS (
    SELECT * FROM employees WHERE salary < 30000 
) 
SELECT s.employee_id FROM sub s 
WHERE s.manager_id NOT IN (select employee_id FROM employees) ORDER BY s.employee_id
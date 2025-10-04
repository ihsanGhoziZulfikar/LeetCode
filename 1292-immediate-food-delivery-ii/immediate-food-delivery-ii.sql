# Write your MySQL query statement below
WITH sub as (
    SELECT *, ROW_NUMBER() OVER (PARTITION BY customer_id ORDER BY order_date ASC) AS rn
    FROM delivery
)
SELECT 
ROUND(SUM(CASE WHEN order_date = customer_pref_delivery_date THEN 1 ELSE 0 END)/COUNT(customer_id)*100, 2) AS immediate_percentage
FROM sub WHERE rn = 1;
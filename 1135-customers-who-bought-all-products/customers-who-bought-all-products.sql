# Write your MySQL query statement below
WITH subq AS (
    SELECT c.customer_id, c.product_key, COUNT(DISTINCT c.product_key) AS c_pkey FROM customer c  GROUP BY  c.customer_id
) 
select s.customer_id from subq s where s.c_pkey = (select count(1) from product)

-- select * from subq

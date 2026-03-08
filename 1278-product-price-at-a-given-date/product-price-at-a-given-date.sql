# Write your MySQL query statement below
WITH subq AS(
    SELECT * FROM (
        SELECT DISTINCT 
            product_id, 
            new_price,
            ROW_NUMBER() OVER(PARTITION BY product_id ORDER BY change_date DESC) AS rn
        FROM products 
        WHERE change_date <= '2019-08-16' ORDER BY change_date DESC
        ) AS q
    WHERE rn = 1
)

SELECT DISTINCT p.product_id, COALESCE(s.new_price, 10) AS price FROM products p LEFT JOIN subq s ON p.product_id = s.product_id;
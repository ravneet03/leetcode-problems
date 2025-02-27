# Write your MySQL query statement below
select customer_id , count(customer_id)as count_no_trans from Visits v left join Transactions t on  t.visit_id = v.visit_id where t.visit_id is NULL group by v.customer_id ;
// Problem: Customers Who Never Order
// Platform: leetcode
// Rating/Difficulty: Easy
// Language: mysql
// Verdict: Accepted
// URL: https://leetcode.com/problems/customers-who-never-order/
// Solved on: 2026-09-22T20:55:04.501Z

# Write your MySQL query statement below
select name as Customers
from Customers left join Orders on Orders.customerId=Customers.id
where customerId is NULL;
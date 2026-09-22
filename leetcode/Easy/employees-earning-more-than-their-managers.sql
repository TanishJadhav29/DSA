// Problem: Employees Earning More Than Their Managers
// Platform: leetcode
// Rating/Difficulty: Easy
// Language: mysql
// Verdict: Accepted
// URL: https://leetcode.com/problems/employees-earning-more-than-their-managers/
// Solved on: 2026-09-22T20:50:53.537Z

# Write your MySQL query statement below
SELECT 
name as Employee 
from Employee as e1
where salary > (
    select salary from employee e2 where e1.managerId=e2.Id
)
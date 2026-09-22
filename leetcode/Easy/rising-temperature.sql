// Problem: Rising Temperature
// Platform: leetcode
// Rating/Difficulty: Easy
// Language: mysql
// Verdict: Accepted
// URL: https://leetcode.com/problems/rising-temperature/
// Solved on: 2026-09-22T21:42:37.815Z

# Write your MySQL query statement below
select w1.id from Weather as w1 where exists(
    select 1 from Weather as w2 
    where 
    date_sub(w1.recordDate,interval 1 day) = w2.recordDate and
    w1.temperature>w2.temperature
)
// Problem: Combine Two Tables
// Platform: leetcode
// Rating/Difficulty: Easy
// Language: mysql
// Verdict: Accepted
// URL: https://leetcode.com/problems/combine-two-tables/
// Solved on: 2026-09-22T15:16:34.281Z

# Write your MySQL query statement below
# person 
SELECT firstName, lastName, city, state 
FROM Person left join Address on Person.personId = Address.personId;  
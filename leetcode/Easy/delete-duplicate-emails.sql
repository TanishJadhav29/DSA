// Problem: Delete Duplicate Emails
// Platform: leetcode
// Rating/Difficulty: Easy
// Language: mysql
// Verdict: Accepted
// URL: https://leetcode.com/problems/delete-duplicate-emails/
// Solved on: 2026-09-22T21:37:40.137Z

DELETE p1
FROM Person p1
JOIN Person p2 
    ON p1.email = p2.email 
   AND p1.id > p2.id;
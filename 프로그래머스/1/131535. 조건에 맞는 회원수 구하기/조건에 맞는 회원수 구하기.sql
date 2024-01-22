-- 코드를 입력하세요
SELECT count(*) as USERS
from USER_INFO 
where JOINED like '2021%' and (20<=age and age<=29)
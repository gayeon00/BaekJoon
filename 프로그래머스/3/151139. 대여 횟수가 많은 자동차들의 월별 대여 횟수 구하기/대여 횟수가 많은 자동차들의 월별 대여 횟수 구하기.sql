-- 코드를 입력하세요
SELECT MONTH(START_DATE) AS MONTH, CAR_ID, COUNT(CAR_ID) AS RECORDS
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY 
WHERE (START_DATE BETWEEN '2022-08-01' AND '2022-11-01') AND (CAR_ID IN (SELECT CAR_ID
                                                                        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY 
                                                                        WHERE START_DATE BETWEEN '2022-08-01' AND '2022-11-01'
                                                                        GROUP BY CAR_ID
                                                                        HAVING COUNT(CAR_ID)>=5
                                                                        ORDER BY CAR_ID))
GROUP BY MONTH, CAR_ID
ORDER BY MONTH, CAR_ID DESC

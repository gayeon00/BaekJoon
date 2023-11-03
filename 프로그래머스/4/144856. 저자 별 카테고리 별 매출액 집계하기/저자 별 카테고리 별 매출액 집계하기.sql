-- 코드를 입력하세요
SELECT B.AUTHOR_ID, C.AUTHOR_NAME, B.CATEGORY, SUM((A.SALES * B.PRICE)) AS TOTAL_SALES
FROM BOOK_SALES A JOIN BOOK B ON A.BOOK_ID = B.BOOK_ID JOIN AUTHOR C ON B.AUTHOR_ID = C.AUTHOR_ID
WHERE A.SALES_DATE LIKE '2022-01%'
GROUP BY B.AUTHOR_ID, B.CATEGORY
ORDER BY  B.AUTHOR_ID, B.CATEGORY DESC
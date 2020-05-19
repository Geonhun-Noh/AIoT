INSERT INTO Products
VALUES ('BR06','BRS01','20 inch teddy bear',14.99,'comes with cap and jacket');

SELECT * FROM Orders WHERE order_num <= 20007  ;
SELECT * FROM Customers WHERE cust_name <> 'Fun4All';
SELECT * FROM OrderItems WHERE order_item >= 5;

SELECT * FROM vendors where vend_state = 'CA';
SELECT * FROM vendors where vend_state = 'IL'; 

SELECT * from customers order by cust_id DESC;
select * from orderitems order by order_num, quantity desc;

select * from products where prod_price < 9 order by prod_price;


SELECT * FROM Orders WHERE order_num >= 20007  order by order_num desc;
select * from orderitems where quantity <= 50 order by  item_price asc;
select * from orderitems where prod_id = 'BNBG01' order by item_price desc;
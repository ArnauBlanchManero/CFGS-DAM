-- 1. ¿Cuáles son las poblaciones en las que viven los clientes?
SELECT DISTINCT poblacion FROM cliente;

-- 2. ¿Cuáles son los clientes que viven en Madrid?
SELECT nombre FROM cliente WHERE poblacion='Madrid';

-- 3. ¿Saca el nombre de los clientes que viven en Madrid y Barcelona?
SELECT nombre FROM cliente WHERE poblacion='Madrid' OR poblacion='Barcelona';

-- 4. ¿Cuál es nombre y teléfono de los clientes que viven en Madrid y vive en la calle Amarillo?
SELECT nombre,telefono FROM cliente WHERE poblacion='Madrid' AND direccion='Calle Amarillo';

-- 5. Buscar el nombre de los clientes cuyo nombre empiece por M
SELECT nombre FROM cliente WHERE nombre LIKE 'M%';

-- 6. Busca el nombre de los clientes cuyo nombre empiece por M pero termine en s
SELECT nombre FROM cliente WHERE nombre LIKE 'M%s';

-- 7. Obtén el nombre de los productos que tengan un precio entre 1500 y 2000
SELECT nombre FROM producto WHERE precio BETWEEN 1500 AND 2000;

-- 8. El nombre de los productos que tenemos en la base de datos sin repeticiones
SELECT nombre FROM (
    SELECT nombre, count(nombre) as repeticiones 
    FROM producto GROUP BY nombre) as t1
WHERE repeticiones='1';

-- 9. Saca todos los productos que contenga una ‘a’ en su nombre del producto en la segunda puntuación
SELECT nombre FROM producto WHERE nombre LIKE '_a%';

-- 10. Saca el nombre de los productos que tengan como primer carácter será 4 y como el número de las décimas el 1.
SELECT nombre FROM producto WHERE precio LIKE '4%1_';

-- 11. Número de productos de cada venta
SELECT sum(cantidad) as numeroProductos FROM venta GROUP BY id_venta;

-- 12. Cantidad de dinero que tenemos invertido en productos de la tabla productos.
SELECT SUM(precio) AS total_invertido FROM producto;

-- 13. ¿El número de cliente (n_cliente) que haya comprado entre 10 y 20 artículos?
SELECT Cliente_n_cliente FROM venta WHERE cantidad BETWEEN 10 AND 20;

-- 14. ¿El número de clientes que haya comprado entre 20 y 30 artículos?
SELECT Cliente_n_cliente, SUM(cantidad) as cantidad_total FROM venta GROUP BY Cliente_n_cliente HAVING cantidad_total BETWEEN 20 AND 30;

-- 15. Cuenta el número de clientes que se llama Marcos, renombra la columna para que se llame total.
SELECT count(nombre) AS total FROM cliente WHERE nombre='Marcos';

-- 16. Cuenta el número de Marcos que vivan en la calle Amarillo
SELECT count(nombre) AS total FROM cliente WHERE nombre='Marcos' AND direccion='Calle Amarillo';

-- 17. De la tabla ventas, el máximo de unidades que se han vendido.
SELECT max(cantidad) FROM venta;

-- 18. Cuenta cuantas personas hay que se llamen de cada tipo.
SELECT count(nombre) AS cantidad_nombres FROM (
    SELECT DISTINCT nombre FROM cliente) AS t1;

-- 19. Junta mediante el producto cartesiano la tabla venta y la tabla cliente.
SELECT * FROM cliente, venta;

-- 20. Haz la misma operación con la reunión natural, renombra las tablas y evita que haya columnas repetidas.
SELECT * FROM cliente INNER JOIN venta ON cliente.n_cliente=venta.Cliente_n_cliente;

-- 21. Crea una tabla única con los datos de las tres tablas.
SELECT * FROM venta, cliente, producto;

-- 22. Une el nombre de los clientes con el nombre de los artículos (aunque no tenga sentido)
SELECT nombre FROM cliente UNION SELECT nombre FROM producto;

-- 23. A bea se le va la olla
SELECT id_venta, sum(total) total_venta FROM (SELECT id_venta, Producto_cod_producto, (cantidad*precio) as total FROM (SELECT Producto_cod_producto, cantidad, id_venta, precio FROM venta INNER JOIN producto on venta.Producto_cod_producto = producto.cod_producto) t1) t2 GROUP BY id_venta;

-- Sacar el código de oficina y la ciudad donde hay oficinas.
SELECT CodigoOficina,Ciudad FROM oficinas;

-- Sacar cuántos empleados hay en la compañía.
SELECT count(CodigoEmpleado) AS EmpleadosTotales FROM empleados;

-- Sacar cuántos clientes tiene cada país.
SELECT Pais,count(CodigoCliente) AS EmpleadosTotales FROM clientes GROUP BY Pais;

-- Sacar cuál fue el pago medio en 2008.
SELECT avg(Cantidad) AS CantidadMeda FROM pagos WHERE FechaPago LIKE '2008%';

-- Sacar cuántos pedidos están en cada estado ordenado descendente por el número de pedidos.
SELECT Estado,count(CodigoPedido) AS Cantidad FROM pedidos GROUP BY Estado ORDER BY Cantidad DESC;

-- Sacar el precio del producto más caro y del más barato.
SELECT nombre, precioVenta FROM productos WHERE 
    precioVenta = (SELECT max(PrecioVenta) FROM productos) 
    OR precioVenta = (SELECT min(PrecioVenta) FROM productos);

-- Sacar la ciudad y el teléfono de las oficinas de Estados Unidos.
SELECT Ciudad, Telefono FROM oficinas WHERE Pais='EEUU';

-- Sacar el nombre, los apellidos y el email de los empleados a cargo de Alberto Soria.
SELECT Nombre, Apellido1, Apellido2, Email FROM (
    SELECT CodigoEmpleado AS CodigoBuscado FROM empleados 
        WHERE Nombre='Alberto' AND Apellido1='Soria') t1, 
    empleados
WHERE CodigoJefe=CodigoBuscado;

SELECT Nombre, Apellido1, Apellido2, Email FROM empleados INNER JOIN
    (SELECT CodigoEmpleado FROM empleados 
        WHERE Nombre='Alberto' AND Apellido1='Soria') t1
        ON empleados.CodigoJefe=t1.CodigoEmpleado;

-- Sacar el cargo, nombre, apellidos y email del jefe de la empresa.
SELECT Puesto, Nombre, Apellido1, Apellido2, Email FROM empleados WHERE CodigoJefe IS NULL;

-- Sacar el nombre, apellidos y cargo de aquellos que no sean representantes de ventas.
SELECT Nombre, Apellido1, Apellido2, Puesto FROM empleados WHERE Puesto!='Representante Ventas';

-- Sacar el número de pedido, código de cliente, fecha requerida y fecha de entrega de los pedidos que no han sido entregados a tiempo.
SELECT CodigoPedido, CodigoCliente, FechaPedido, FechaEntrega
FROM pedidos LEFT JOIN
    (SELECT CodigoPedido as CodigoNO
    FROM pedidos 
    WHERE FechaEntrega<=FechaEsperada) t1
ON t1.CodigoNO=pedidos.CodigoPedido
WHERE CodigoNO IS NULL;

-- Sacar cuántos productos existen en cada línea de pedido.
SELECT CodigoPedido, sum(Cantidad) as ProductosTotales FROM detallepedidos GROUP BY CodigoPedido;

-- Sacar un listado de los 20 códigos de productos más pedidos ordenado por cantidad pedida.
SELECT codigoproducto, sum(cantidad) TotalCantidad
FROM detallepedidos 
GROUP BY codigoproducto
ORDER BY TotalCantidad DESC 
LIMIT 20;

-- Sacar el número de pedido, código de cliente, fecha requerida y fecha de entrega de los pedidos cuya fecha de entrega ha sido al menos dos días antes de la fecha requerida.
SELECT codigopedido, codigocliente, FechaEsperada, FechaEntrega
FROM pedidos
WHERE fechaesperada - 2 >= fechaentrega;

-- Sacar la facturación que ha tenido la empresa en toda la historia, indicando la base imponible, el IVA y el total facturado. 
-- NOTA: La base imponible se calcula sumando el coste del producto por el número de unidades vendidas. El IVA, es el 21% de la base imponible, y el total, la suma de los dos campos anteriores.
SELECT BaseImponible, IVA, (BaseImponible+IVA) total
FROM (SELECT sum(cantidad*preciounidad) BaseImponible, 
    sum(cantidad*preciounidad)*0.21 AS IVA
    FROM detallepedidos) t1;

-- Sacar la misma información que en la pregunta anterior, pero agrupada por código de producto filtrada por los códigos que empiecen por FR.
SELECT CodigoProducto, BaseImponible, IVA, (BaseImponible+IVA) total
FROM (SELECT CodigoProducto, sum(cantidad*preciounidad) BaseImponible, 
    sum(cantidad*preciounidad)*0.21 AS IVA
    FROM detallepedidos 
    GROUP BY CodigoProducto 
    HAVING CodigoProducto LIKE 'FR%') t1;

-- Obtener el nombre del producto más caro.
SELECT Nombre, PrecioVenta FROM productos
WHERE precioventa = (SELECT max(precioVenta) FROM productos);

-- Obtener el nombre del producto del que más unidades se hayan vendido en un mismo pedido.
SELECT Nombre FROM productos INNER JOIN 
    (SELECT CodigoProducto, cantidadMaxima FROM detallepedidos INNER JOIN 
        (SELECT max(Cantidad) cantidadMaxima FROM detallepedidos) t1
        ON detallepedidos.Cantidad=t1.cantidadMaxima) t2
ON productos.CodigoProducto=t2.CodigoProducto;

-- Sacar el producto que más unidades tiene en stock y el que menos unidades tiene en stock.
SELECT DISTINCT CodigoProducto, Nombre, CantidadEnStock 
FROM productos WHERE CantidadEnStock = (SELECT min(cantidadenstock) FROM productos) 
OR CantidadEnStock = (SELECT max(cantidadenstock) FROM productos);

-- Sacar la misma información que en la pregunta anterior pero solo de los clientes que no hayan hecho pagos.
SELECT NombreCliente, NombreEmpleado, CiudadOficina FROM 
    (SELECT DISTINCT clientes.CodigoCliente, NombreCliente, CodigoEmpleadoRepVentas FROM clientes 
    LEFT JOIN pagos ON clientes.CodigoCliente = pagos.CodigoCliente 
    WHERE pagos.CodigoCliente IS NULL) t3 
    INNER JOIN (SELECT CodigoEmpleado, Nombre AS NombreEmpleado, CiudadOficina FROM empleados 
    INNER JOIN (SELECT CodigoOficina, Ciudad AS CiudadOficina FROM oficinas) t1 
    ON t1.CodigoOficina = empleados.CodigoOficina) t2 
    ON t2.CodigoEmpleado = t3.CodigoEmpleadoRepVentas;

-- Obtener un listado con el nombre de los empleados junto con el nombre de sus jefes.
SELECT Nombre AS NombreEmpleado, NombreJefe FROM empleados INNER JOIN 
    (SELECT CodigoEmpleado, Nombre AS NombreJefe FROM empleados) t1 
    ON t1.CodigoEmpleado = empleados.CodigoJefe;

-- Sacar un listado con los nombres de los clientes y el total pagado por cada uno de ellos
SELECT 
    NombreCliente, SUM(totalPagado) totalPagadoCliente
FROM
    clientes
        INNER JOIN
    (SELECT 
        codigocliente, totalPagado
    FROM
        pedidos, (SELECT 
        codigopedido, SUM(precio) AS totalPagado
    FROM
        (SELECT 
        codigopedido, cantidad * preciounidad AS precio
    FROM
        detallepedidos) t1
    GROUP BY codigopedido) t2
    WHERE
        pedidos.codigopedido = t2.codigopedido) t3 ON clientes.CodigoCliente = t3.CodigoCliente
GROUP BY t3.CodigoCliente
ORDER BY clientes.CodigoCliente;

-- Sacar el nombre de los clientes que hayan hecho pedidos en 2008.
select NombreCliente, FechaPedido from clientes inner join
(SELECT FechaPedido, CodigoCliente FROM jardineria.pedidos where fechapedido like '2008%') t1
on clientes.CodigoCliente=t1.CodigoCliente;

-- Listar el nombre del cliente y el nombre y apellido de sus representantes de aquellos clientes que no hayan realizado pagos
select NombreCliente from clientes left join
(select distinct codigocliente from pagos)t1
on clientes.CodigoCliente=t1.CodigoCliente
where t1.CodigoCliente is null;

-- Sacar el nombre, apellidos, oficina y cargo de aquellos que no sean representantes de ventas.
select * from oficinas
inner join
(select Nombre, Apellido1, CodigoOficina, Puesto from empleados
where puesto!= 'RepresentanteVentas')t1
on oficinas.CodigoOficina=t1.CodigoOficina;

-- Sacar cuántos empleados tiene cada oficina, mostrando el nombre de la ciudad donde está la oficina.
select cantidadEmpleados, ciudadOficina from
(select codigoOficina, count(codigoempleado) as cantidadEmpleados from empleados group by codigoOficina) t2 inner join 
(select codigoOficina, Ciudad as ciudadOficina from oficinas) t1
on t2.codigoOficina=t1.codigoOficina;

-- Sacar un listado con el nombre de los empleados, y el nombre de sus respectivos jefes.
select Nombre as nombreEmpleado, nombreJefe  from empleados inner join
(select CodigoEmpleado, Nombre as nombreJefe from empleados)t1
on empleados.codigoJefe=t1.codigoEmpleado;

-- Sacar el nombre, apellido, oficina (ciudad) y cargo del empleado que no represente a ningún cliente.
select Nombre, Apellido1, Ciudad, Puesto from oficinas inner join
(select codigoOficina, Nombre, Apellido1, Puesto from empleados left join
(select distinct codigoempleadorepventas from clientes)t1
on empleados.codigoEmpleado=t1.codigoempleadorepventas 
where codigoempleadorepventas is null)t2
on oficinas.codigoOficina=t2.codigoOficina;

-- Sacar la media de unidades en stock de los productos agrupados por gama.
SELECT 
    AVG(CantidadEnStock) AS mediaUnidadesStock
FROM
    productos
GROUP BY gama;

-- Sacar los clientes que residan en la misma ciudad donde hay una oficina, indicando dónde está la oficina.
SELECT 
    NombreCliente,
    clientes.Ciudad ciudadClientes,
    oficinas.Ciudad ciudadOficina
FROM
    oficinas
        INNER JOIN
    clientes ON oficinas.Ciudad = clientes.Ciudad;

-- Sacar los clientes que residan en ciudades donde no hay oficinas ordenado por la ciudad donde residen.
SELECT NombreCliente FROM clientes LEFT JOIN (SELECT oficinas.Ciudad ciudadOficina FROM oficinas INNER JOIN clientes ON oficinas.Ciudad = clientes.Ciudad) t1 ON t1.ciudadOficina = clientes.Ciudad WHERE ciudadOficina IS NULL order by Ciudad;

-- Sacar un listado con el precio total de cada pedido.
select CodigoPedido, sum(cantidad*PrecioUnidad) totalPedido
from detallepedidos group by CodigoPedido;

-- Sacar los clientes que hayan hecho pedido en el 2008 por una cuantía superior a 2000 euros.
select t1.CodigoPedido, sum(cantidad*PrecioUnidad) totalPedido
from detallepedidos inner join
(select CodigoPedido, codigocliente from pedidos where fechapedido like '2008%')t1
on detallepedidos.codigopedido=t1.CodigoPedido group by t1.CodigoPedido
having totalPedido > 2000;

-- Obtener el nombre, apellido1 y cargo de los empleados que no representen a ningún cliente.
select Nombre, Apellido1, Puesto from empleados
where CodigoEmpleado not in 
(select CodigoEmpleadoRepVentas c from clientes);

-- Mostrar el nombre de los clientes que no hayan realizado pagos junto con el nombre de sus representantes de ventas.
select NombreCLiente,CodigoEmpleadoRepVentas from clientes
left join
(SELECT distinct codigocliente FROM pagos) t1
on clientes.CodigoCliente=t1.codigocliente
where t1.codigocliente is null;

-- Listar las ventas totales de los productos que hayan facturado más de 3000 euros. Se mostrará el nombre, unidades vendidas, total facturado y total facturado con impuestos (21% IVA).
SELECT 
    Nombre, UnidadesVendidas, precioTotal, TotalImpuestos
FROM
    Productos
        INNER JOIN
    (SELECT 
        codigoProducto,
            SUM(cantidad * preciounidad) precioTotal,
            SUM(cantidad) UnidadesVendidas,
            SUM(preciounidad * cantidad + preciounidad * cantidad * 0.21) TotalImpuestos
    FROM
        detallepedidos
    GROUP BY codigoProducto
    HAVING precioTotal > 3000) t1 ON productos.codigoProducto = t1.codigoproducto;
    
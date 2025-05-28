#Ejercicio 1
DELIMITER //
CREATE FUNCTION ejercicio1(idP int)
RETURNS float
deterministic
BEGIN
	DECLARE precioP float;
	set precioP = (select precio from productos where id_producto = idP);
	return precioP;
END //
DELIMITER ;

select supermercado.ejercicio1(1);

# Ejercicio 2
DELIMITER //
CREATE PROCEDURE ejercicio2()
BEGIN
	SELECT count(*) as numero_clientes from clientes where nombre like 'A%';
END //
DELIMITER ;

call supermercado.ejercicio2();

# Ejercicio 3
DELIMITER //
CREATE PROCEDURE ejercicio3()
BEGIN
	SELECT nombre_producto, nombre AS nombre_empleado
	FROM empleados INNER JOIN
		(SELECT nombreP AS nombre_producto, id_producto, id_empleado
		FROM secciones INNER JOIN 
			(SELECT nombre AS nombreP, id_producto AS idP
			FROM productos) t1 
		ON t1.idP = secciones.id_producto) t2 
	ON t2.id_empleado = empleados.id_empleado;
END //
DELIMITER ;

call supermercado.ejercicio3();

# Ejercicio 4
DELIMITER //
CREATE PROCEDURE ejercicio4()
BEGIN
	declare idP int default 1;
	declare aumento int;
	declare stockP int;
	declare maxP int;
	set maxP = (select count(*) from productos);
	while idP <= maxP do
		set stockP = (select stock from productos where id_producto = idP);
		set aumento = 10 * stockP / 100;
		update productos set stock = (stockP+aumento) where id_producto = idP;
		set idP = idP + 1;
	end while;
END //
DELIMITER ;

call supermercado.ejercicio4();

#Ejercicio 5
DELIMITER //
CREATE PROCEDURE ejercicio5(in nombreE varchar(100), in puestoE varchar(50))
BEGIN
	DECLARE salarioE decimal;
	DECLARE fechaE date;
	set salarioE = floor(rand()*3000);
	set fechaE = now();
	insert into empleados (nombre, puesto, salario, fecha_ingreso) values (nombreE,puestoE,salarioE,fechaE);
END //
DELIMITER ;

call supermercado.ejercicio5('Arnau Blanch', 'Encargado de sección');

# Ejercicio 6
DELIMITER //
CREATE PROCEDURE ejercicio6(in idE int)
BEGIN
	declare sueldoE decimal;
	set sueldoE = (select salario from empleados where id_empleado = idE);
	if sueldoE > 1500.00 then
		update empleados set puesto= 'Encargado' where id_empleado = idE;
	end if;
END //
DELIMITER ;

call supermercado.ejercicio6(20);

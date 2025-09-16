CREATE OR REPLACE FUNCTION mudar_salario (num1 NUMERIC num2 NUMERIC)
RETURNS BOOLEAN
AS
$$
	BEGIN
		UPDATE Func SET salario = salario * (1 + num1/100)
			WHERE EXTRACT (YEAR FROM dta_nasc) < 1972;
		UPDATE Func SET salario = salario * (1 + num2/100)
			WHERE EXTRACT (YEAR FROM dta_nasc) >= 1972;
		RETURN 't';
	END;
$$
LANGUAGE 'plpgsql';			
		
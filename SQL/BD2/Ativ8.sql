CREATE OR REPLACE FUNCTION mudar_salario (num1 NUMERIC num2 NUMERIC)
RETURNS BOOLEAN
AS
$$  
    DECLARE
        cs_func CURSOR FOR SELECT EXTRACT(YEAR FROM dta_nasc) FROM Func;
        v_data YEAR;
	BEGIN
		OPEN cs_func;
        FETCH cs_func INTO v_data;
        WHILE FOUND LOOP
            IF v_data < 1972 THEN
                UPDATE TABLE Func SET salario = salario (1 + num1/100);
            ELSE
                UPDATE TABLE Func SET salario = salario (1 + num2/100);
            END IF;
            FETCH cs_func INTO v_data;
        END LOOP;

        CLOSE cs_func;
		RETURN 't';
	END;
$$
LANGUAGE 'plpgsql';	
CREATE OR REPLACE FUNCTION exclui_registros (v_nro Depto.nro_depto%TYPE)
RETURNS BOOLEAN
AS 
$$	DECLARE
		v_proj Projeto.cod_proj%TYPE;
	BEGIN
		FOR v_proj IN SELECT cod_proj FROM Projeto
		WHERE nro_depto = v_nro LOOP
			DELETE FROM Participa
			WHERE cod_proj = v_proj;
		END LOOP;
		RETURN 't';
	END;
$$
LANGUAGE 'plpgsql';

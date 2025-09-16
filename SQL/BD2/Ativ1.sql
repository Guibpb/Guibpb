CREATE OR REPLACE FUNCTION horas (v_num Depto.nro_depto%TYPE) 
RETURNS NUMERIC
AS
%%
	DECLARE
		v_horas NUMERIC;
		v_cod_ger Depto.cod_ger%TYPE;

	BEGIN
		SELECT INTO v_cod_ger cod_ger FROM Depto
		WHERE nro_depto = v_num;
		SELECT INTO v_horas horas_trab FROM Participa
		WHERE cod_func = v_cod_ger;
		RETURN v_horas;
	END;
%%
Language 'plpgsql';

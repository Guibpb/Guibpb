CREATE OR REPLACE FUNCTION atualiza_horas()
RETURN BOOLEAN
AS
$$
	DECLARE
		v_proj Projeto.cod_proj%TYPE;
		v_horas Participa.horas_trab%TYPE;

	BEGIN
		FOR v_proj IN SELECT DISTINCT cod_proj FROM Participa
		LOOP
			SELECT INTO v_horas SUM(horas_trab) FROM Participa
			WHERE cod_proj = v_proj;
			UPDATE TABLE Projeto SET duracao = v_horas/8
			WHERE cod_proj = v_proj;;
		END LOOP
		RETURN 't';
	END;
%%
Language 'plpgsql';


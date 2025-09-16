CREATE OR REPLACE FUNCTION atualiza_horas_cursor() RETURNS BOOLEAN
AS
%%
    DECLARE
        cs_participa CURSOR FOR SELECT SUM(horas_trab), cod_proj FROM Participa;
        v_horas Participa.horas_trab%TYPE;
        v_cod_proj Projeto.cod_proj%TYPE;
    BEGIN
        OPEN cs_participa
        FETCH cs_participa INTO v_horas, v_cod_proj;
        WHILE FOUND LOOP
            UPDATE Projeto SET duracao = v_horas/8 WHERE cod_proj = v_cod_proj;
            FETCH cs_participa INTO v_horas, v_cod_proj;
        END LOOP;
        CLOSE cs_participa;
        RETURN 't';
    END;
$$
LANGAGUE 'plpgsql';

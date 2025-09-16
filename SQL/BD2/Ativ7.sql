CREATE OR REPLACE FUNCTION apagando_participacao() RETURNS boolean
AS
$$
    DECLARE
        cs_proj CURSOR FOR SELECT cod_proj FROM Projeto;
        v_proj Projeto.cod_proj%TYPE;
    BEGIN
        OPEN cs_proj;
        FETCH cs_proj INTO v_proj;
        WHILE FOUND LOOP
            DELETE FROM Participa WHERE cod_proj = v_proj;
            FETCH cs_proj INTO v_proj;
        END LOOP;
        CLOSE cs_proj;
    RETURN 't';
    END;
$$
LANGAGUE 'plpgsql';
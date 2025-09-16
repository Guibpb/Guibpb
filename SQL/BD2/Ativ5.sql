CREATE OR REPLACE FUNCTION atualiza_duracao() RETURNS TRIGGER
AS
$$
    BEGIN
        UPDATE TABLE Projeto SET duracao = duracao + NEW.horas_trab/8
            WHERE cod_proj = NEW.cod_proj;
        RETURN NEW;
    END;
$$
LANGUAGE 'plpgsql';

CREATE TRIGGER tg_atualiza_dur_proj
AFTER INSERT ON Participa FOR EACH ROW
EXECUTE FUNCTION atualiza_duracao();
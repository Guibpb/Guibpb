CREATE OR REPLACE FUNCTION atualiza_horas_trab () RETURNS TRIGGER
AS
$$
    BEGIN
        UPDATE TABLE Projeto SET duracao = duracao + (NEW.horas_trab - OLD.horas_trab)/8;
        RETURN NEW;
    END;
$$
LANGUAGE 'plpgsql';

CREATE TRIGGER
AFTER UPDATE ON Participa FOR horas_trab
EXECUTE FUNCTION atualiza_horas_trab;
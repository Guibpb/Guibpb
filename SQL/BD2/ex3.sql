-- Função do gatilho
CREATE OR REPLACE FUNCTION verifica_aumento_salario()
RETURNS TRIGGER AS
$$
DECLARE
    salario_chefe NUMERIC;
BEGIN
    -- Só verifica se houve aumento
    IF NEW.salario > OLD.salario THEN
        -- Buscar salário do chefe
        SELECT salario
        INTO salario_chefe
        FROM advogado
        WHERE id_adv = NEW.id_adv_chefe;

        -- Se não achou chefe, ignora
        IF salario_chefe IS NULL THEN
            RETURN NEW;
        END IF;

        -- Verifica se novo salário é maior que o do chefe
        IF NEW.salario > salario_chefe THEN
            RAISE NOTICE 'Advertência: o novo salário do advogado % (R$%) é maior que o do chefe (R$%)',
                NEW.nome, NEW.salario, salario_chefe;
        END IF;
    END IF;

    RETURN NEW; -- precisa retornar NEW em triggers de UPDATE
END;
$$ LANGUAGE plpgsql;


-- Gatilho
CREATE TRIGGER trg_verifica_aumento_salario
AFTER UPDATE OF salario ON advogado
FOR EACH ROW
EXECUTE FUNCTION verifica_aumento_salario();

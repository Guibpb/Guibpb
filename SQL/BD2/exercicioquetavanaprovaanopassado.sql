CREATE OR REPLACE FUNCTION qtd_processos_por_comarca(nome_advogado TEXT)
RETURNS TABLE(comarca TEXT, qtd_processos INT) AS
$$
BEGIN
    RETURN QUERY
    SELECT p.comarca, COUNT(*) AS qtd_processos
    FROM processo p
    JOIN advogado a ON a.id_adv = p.id_adv_responsavel
    WHERE a.nome = nome_advogado
    GROUP BY p.comarca
    ORDER BY p.comarca;
END;
$$ LANGUAGE plpgsql;

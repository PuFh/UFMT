-- Exemplo de uma porta and

-- Biblioteca e pacotes
-- Entidade
-- Arquitetura

-- entidade
entity and_gate is
    port(
        a,b     :   in bit;
        z       :   out bit
    );
end and_gate;

-- arqutietura
architecture main of and_gate is
begin
    z <= a and b;

end main;
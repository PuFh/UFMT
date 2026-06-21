-- somador completo

entity somador_completo is
    port(
        a,b,te   :   in  bit; -- esse te seria o cin
        s,ts     :   out bit -- esse ts seria o cout
    );
end;

architecture main of somador_completo is

begin
    s <= a xor b xor te;
    ts <= (a and te) or (te and a) or (a and b);
end main;
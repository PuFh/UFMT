-- mux 4:1

entity mux_4_1 is
    port(
        d0,d1,d2,d3 :   in bit;
        s0,s1       :   in bit;
        y           :   out bit
    );

end mux_4_1;

architecture main of mux_4_1 is 
    signal sel :    bit_vector(1 downto 0):= "00";
begin
    sel <= s1 & s0 -- o se é o msb e o s0 lsb
    y   <=  d0 when sel = "00" else
            d1 when sel = "01" else
            d2 when sel = "10" else
            d3;
end main;
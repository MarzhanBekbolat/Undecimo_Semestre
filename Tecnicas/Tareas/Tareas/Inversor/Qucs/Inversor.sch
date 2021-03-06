<Qucs Schematic 0.0.17>
<Properties>
  <View=0,0,800,800,1,0,0>
  <Grid=10,10,0>
  <DataSet=Inversor.dat>
  <DataDisplay=Inversor.dpl>
  <OpenDisplay=1>
  <Script=Inversor.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=Title>
  <FrameText1=Drawn By:>
  <FrameText2=Date:>
  <FrameText3=Revision:>
</Properties>
<Symbol>
</Symbol>
<Components>
  <R R1 1 300 110 -26 15 0 0 "50 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "US" 0>
  <GND * 1 370 420 0 0 0 0>
  <GND * 1 230 190 0 0 0 0>
  <GND * 1 160 400 0 0 0 0>
  <GND * 1 520 430 0 0 0 0>
  <.DC DC1 1 640 290 0 43 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
  <_MOSFET T2 1 370 220 8 -26 1 0 "pfet" 0 "-0.9214347V" 1 "2e-5" 1 "0.0" 0 "0.6 V" 0 "0.0" 1 "0.0 Ohm" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "1e-14 A" 0 "1.0" 0 "1 um" 0 "1 um" 0 "0.0" 0 "0.1 um" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 F" 0 "0.0 F" 0 "0.8 V" 0 "0.5" 0 "0.5" 0 "0.0" 0 "0.33" 0 "0.0 ps" 0 "0.0" 0 "0.0" 0 "1" 0 "600.0" 0 "0.0" 0 "1" 0 "1" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 m" 0 "0.0 m" 0 "0.0" 0 "1.0" 0 "1.0" 0 "26.85" 0 "26.85" 0>
  <_MOSFET T1 1 370 340 8 -26 0 0 "nfet" 0 "0.6696061V" 1 "2e-5" 1 "0.0" 0 "0.6 V" 0 "0.0" 1 "0.0 Ohm" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "1e-14 A" 0 "1.0" 0 "1 um" 0 "1 um" 0 "0.0" 0 "0.1 um" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 F" 0 "0.0 F" 0 "0.8 V" 0 "0.5" 0 "0.5" 0 "0.0" 0 "0.33" 0 "0.0 ps" 0 "0.0" 0 "0.0" 0 "1" 0 "600.0" 0 "0.0" 0 "1" 0 "1" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 m" 0 "0.0 m" 0 "0.0" 0 "1.0" 0 "1.0" 0 "26.85" 0 "26.85" 0>
  <C C1 1 520 360 17 -26 0 1 "20 pF" 1 "" 0 "neutral" 0>
  <.TR TR1 1 630 110 0 71 0 0 "lin" 1 "0" 1 "16 ms" 1 "1000" 0 "Trapezoidal" 0 "2" 0 "1 ns" 0 "1e-16" 0 "150" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "26.85" 0 "1e-3" 0 "1e-6" 0 "1" 0 "CroutLU" 0 "no" 0 "yes" 0 "0" 0>
  <Vdc VDD1 1 230 160 -64 -29 0 1 "1 V" 1>
  <Vrect V1 1 160 340 18 -26 0 1 "1 V" 1 "5 ms" 1 "5 ms" 1 "0.1 ms" 0 "0.1 ms" 0 "0 ns" 0>
</Components>
<Wires>
  <230 110 270 110 "" 0 0 0 "">
  <230 110 230 130 "" 0 0 0 "">
  <370 370 370 420 "" 0 0 0 "">
  <370 280 370 310 "" 0 0 0 "">
  <310 280 310 340 "" 0 0 0 "">
  <310 340 340 340 "" 0 0 0 "">
  <160 370 160 400 "" 0 0 0 "">
  <160 280 310 280 "" 0 0 0 "">
  <160 280 160 310 "" 0 0 0 "">
  <520 390 520 430 "" 0 0 0 "">
  <520 280 520 330 "" 0 0 0 "">
  <370 280 520 280 "" 0 0 0 "">
  <330 110 370 110 "" 0 0 0 "">
  <370 110 370 190 "" 0 0 0 "">
  <370 250 370 280 "" 0 0 0 "">
  <310 220 310 280 "" 0 0 0 "">
  <310 220 340 220 "" 0 0 0 "">
  <160 280 160 280 "Vin" 190 250 0 "">
  <520 280 520 280 "Vout" 550 250 0 "">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
</Paintings>

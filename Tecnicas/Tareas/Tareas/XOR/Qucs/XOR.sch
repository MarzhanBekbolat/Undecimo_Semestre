<Qucs Schematic 0.0.17>
<Properties>
  <View=0,21,1224,885,0.909091,64,240>
  <Grid=10,10,1>
  <DataSet=XOR.dat>
  <DataDisplay=XOR.dpl>
  <OpenDisplay=1>
  <Script=XOR.m>
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
  <GND * 1 100 370 0 0 0 0>
  <_MOSFET T1 1 310 190 8 -26 1 0 "pfet" 0 "-0.9214347V" 1 "2e-5" 1 "0.0" 0 "0.6 V" 0 "0.0" 1 "0.0 Ohm" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "1e-14 A" 0 "1.0" 0 "1 um" 0 "1 um" 0 "0.0" 0 "0.1 um" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 F" 0 "0.0 F" 0 "0.8 V" 0 "0.5" 0 "0.5" 0 "0.0" 0 "0.33" 0 "0.0 ps" 0 "0.0" 0 "0.0" 0 "1" 0 "600.0" 0 "0.0" 0 "1" 0 "1" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 m" 0 "0.0 m" 0 "0.0" 0 "1.0" 0 "1.0" 0 "26.85" 0 "26.85" 0>
  <_MOSFET T2 1 310 310 8 -26 0 0 "nfet" 0 "0.6696061V" 1 "2e-5" 1 "0.0" 0 "0.6 V" 0 "0.0" 1 "0.0 Ohm" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "1e-14 A" 0 "1.0" 0 "1 um" 0 "1 um" 0 "0.0" 0 "0.1 um" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 F" 0 "0.0 F" 0 "0.8 V" 0 "0.5" 0 "0.5" 0 "0.0" 0 "0.33" 0 "0.0 ps" 0 "0.0" 0 "0.0" 0 "1" 0 "600.0" 0 "0.0" 0 "1" 0 "1" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 m" 0 "0.0 m" 0 "0.0" 0 "1.0" 0 "1.0" 0 "26.85" 0 "26.85" 0>
  <GND * 1 310 70 0 0 0 2>
  <Vdc VDD1 1 310 100 30 -29 0 3 "5 V" 1>
  <GND * 1 100 830 0 0 0 0>
  <_MOSFET T3 1 310 650 8 -26 1 0 "pfet" 0 "-0.9214347V" 1 "2e-5" 1 "0.0" 0 "0.6 V" 0 "0.0" 1 "0.0 Ohm" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "1e-14 A" 0 "1.0" 0 "1 um" 0 "1 um" 0 "0.0" 0 "0.1 um" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 F" 0 "0.0 F" 0 "0.8 V" 0 "0.5" 0 "0.5" 0 "0.0" 0 "0.33" 0 "0.0 ps" 0 "0.0" 0 "0.0" 0 "1" 0 "600.0" 0 "0.0" 0 "1" 0 "1" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 m" 0 "0.0 m" 0 "0.0" 0 "1.0" 0 "1.0" 0 "26.85" 0 "26.85" 0>
  <_MOSFET T4 1 310 770 8 -26 0 0 "nfet" 0 "0.6696061V" 1 "2e-5" 1 "0.0" 0 "0.6 V" 0 "0.0" 1 "0.0 Ohm" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "1e-14 A" 0 "1.0" 0 "1 um" 0 "1 um" 0 "0.0" 0 "0.1 um" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 F" 0 "0.0 F" 0 "0.8 V" 0 "0.5" 0 "0.5" 0 "0.0" 0 "0.33" 0 "0.0 ps" 0 "0.0" 0 "0.0" 0 "1" 0 "600.0" 0 "0.0" 0 "1" 0 "1" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 m" 0 "0.0 m" 0 "0.0" 0 "1.0" 0 "1.0" 0 "26.85" 0 "26.85" 0>
  <GND * 1 310 530 0 0 0 2>
  <Vdc VDD2 1 310 560 30 -29 0 3 "5 V" 1>
  <Vrect A 1 100 310 18 -26 0 1 "5 V" 1 "5 ms" 1 "5 ms" 1 "0.1 ms" 0 "0.1 ms" 0 "5ms" 0>
  <Vrect A1 1 100 770 18 -26 0 1 "5 V" 1 "10 ms" 1 "10 ms" 1 "0.2 ms" 0 "0.2 ms" 0 "5ms" 0>
  <_MOSFET T5 1 840 410 8 -26 1 0 "pfet" 0 "-0.9214347V" 0 "2e-5" 0 "0.0" 0 "0.6 V" 0 "0.0" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "1e-14 A" 0 "1.0" 0 "1 um" 0 "1 um" 0 "0.0" 0 "0.1 um" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 F" 0 "0.0 F" 0 "0.8 V" 0 "0.5" 0 "0.5" 0 "0.0" 0 "0.33" 0 "0.0 ps" 0 "0.0" 0 "0.0" 0 "1" 0 "600.0" 0 "0.0" 0 "1" 0 "1" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 m" 0 "0.0 m" 0 "0.0" 0 "1.0" 0 "1.0" 0 "26.85" 0 "26.85" 0>
  <_MOSFET T6 1 840 530 8 -26 1 0 "pfet" 0 "-0.9214347V" 0 "2e-5" 0 "0.0" 0 "0.6 V" 0 "0.0" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "1e-14 A" 0 "1.0" 0 "1 um" 0 "1 um" 0 "0.0" 0 "0.1 um" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 F" 0 "0.0 F" 0 "0.8 V" 0 "0.5" 0 "0.5" 0 "0.0" 0 "0.33" 0 "0.0 ps" 0 "0.0" 0 "0.0" 0 "1" 0 "600.0" 0 "0.0" 0 "1" 0 "1" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 m" 0 "0.0 m" 0 "0.0" 0 "1.0" 0 "1.0" 0 "26.85" 0 "26.85" 0>
  <_MOSFET T7 1 960 410 -22 -26 0 2 "pfet" 0 "-0.9214347V" 0 "2e-5" 0 "0.0" 0 "0.6 V" 0 "0.0" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "1e-14 A" 0 "1.0" 0 "1 um" 0 "1 um" 0 "0.0" 0 "0.1 um" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 F" 0 "0.0 F" 0 "0.8 V" 0 "0.5" 0 "0.5" 0 "0.0" 0 "0.33" 0 "0.0 ps" 0 "0.0" 0 "0.0" 0 "1" 0 "600.0" 0 "0.0" 0 "1" 0 "1" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 m" 0 "0.0 m" 0 "0.0" 0 "1.0" 0 "1.0" 0 "26.85" 0 "26.85" 0>
  <_MOSFET T8 1 960 530 -22 -26 0 2 "pfet" 0 "-0.9214347V" 0 "2e-5" 0 "0.0" 0 "0.6 V" 0 "0.0" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "1e-14 A" 0 "1.0" 0 "1 um" 0 "1 um" 0 "0.0" 0 "0.1 um" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 F" 0 "0.0 F" 0 "0.8 V" 0 "0.5" 0 "0.5" 0 "0.0" 0 "0.33" 0 "0.0 ps" 0 "0.0" 0 "0.0" 0 "1" 0 "600.0" 0 "0.0" 0 "1" 0 "1" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 m" 0 "0.0 m" 0 "0.0" 0 "1.0" 0 "1.0" 0 "26.85" 0 "26.85" 0>
  <_MOSFET T11 1 960 700 8 -26 0 0 "nfet" 0 "0.6696061V" 0 "2e-5" 0 "0.0" 0 "0.6 V" 0 "0.0" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "1e-14 A" 0 "1.0" 0 "1 um" 0 "1 um" 0 "0.0" 0 "0.1 um" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 F" 0 "0.0 F" 0 "0.8 V" 0 "0.5" 0 "0.5" 0 "0.0" 0 "0.33" 0 "0.0 ps" 0 "0.0" 0 "0.0" 0 "1" 0 "600.0" 0 "0.0" 0 "1" 0 "1" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 m" 0 "0.0 m" 0 "0.0" 0 "1.0" 0 "1.0" 0 "26.85" 0 "26.85" 0>
  <_MOSFET T12 1 1040 700 -29 -26 1 2 "nfet" 0 "0.6696061V" 0 "2e-5" 0 "0.0" 0 "0.6 V" 0 "0.0" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "1e-14 A" 0 "1.0" 0 "1 um" 0 "1 um" 0 "0.0" 0 "0.1 um" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 F" 0 "0.0 F" 0 "0.8 V" 0 "0.5" 0 "0.5" 0 "0.0" 0 "0.33" 0 "0.0 ps" 0 "0.0" 0 "0.0" 0 "1" 0 "600.0" 0 "0.0" 0 "1" 0 "1" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 m" 0 "0.0 m" 0 "0.0" 0 "1.0" 0 "1.0" 0 "26.85" 0 "26.85" 0>
  <_MOSFET T10 1 840 700 -29 -26 1 2 "nfet" 0 "0.6696061V" 0 "2e-5" 0 "0.0" 0 "0.6 V" 0 "0.0" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "1e-14 A" 0 "1.0" 0 "1 um" 0 "1 um" 0 "0.0" 0 "0.1 um" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 F" 0 "0.0 F" 0 "0.8 V" 0 "0.5" 0 "0.5" 0 "0.0" 0 "0.33" 0 "0.0 ps" 0 "0.0" 0 "0.0" 0 "1" 0 "600.0" 0 "0.0" 0 "1" 0 "1" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 m" 0 "0.0 m" 0 "0.0" 0 "1.0" 0 "1.0" 0 "26.85" 0 "26.85" 0>
  <_MOSFET T9 1 760 700 8 -26 0 0 "nfet" 0 "0.6696061V" 0 "2e-5" 0 "0.0" 0 "0.6 V" 0 "0.0" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "0.0 Ohm" 0 "1e-14 A" 0 "1.0" 0 "1 um" 0 "1 um" 0 "0.0" 0 "0.1 um" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 F" 0 "0.0 F" 0 "0.8 V" 0 "0.5" 0 "0.5" 0 "0.0" 0 "0.33" 0 "0.0 ps" 0 "0.0" 0 "0.0" 0 "1" 0 "600.0" 0 "0.0" 0 "1" 0 "1" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0" 0 "0.0 m" 0 "0.0 m" 0 "0.0" 0 "1.0" 0 "1.0" 0 "26.85" 0 "26.85" 0>
  <GND * 1 800 760 0 0 0 0>
  <GND * 1 1000 760 0 0 0 0>
  <GND * 1 310 370 0 0 0 0>
  <GND * 1 460 370 0 0 0 0>
  <C C1 1 460 310 17 -26 0 1 "20 pF" 1 "" 0 "neutral" 0>
  <GND * 1 310 840 0 0 0 0>
  <GND * 1 460 840 0 0 0 0>
  <C C2 1 460 780 17 -26 0 1 "20 pF" 1 "" 0 "neutral" 0>
  <GND * 1 900 230 0 0 0 2>
  <Vdc VDD3 1 900 260 30 -29 0 3 "5 V" 1>
  <GND * 1 1120 720 0 0 0 0>
  <C C3 1 1120 660 17 -26 0 1 "20 pF" 1 "" 0 "neutral" 0>
  <.TR TR2 1 740 50 0 71 0 0 "lin" 1 "0" 1 "10 ms" 1 "100" 0 "Trapezoidal" 0 "2" 0 "1 ns" 0 "1e-16" 0 "150" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "26.85" 0 "1e-3" 0 "1e-6" 0 "1" 0 "CroutLU" 0 "no" 0 "yes" 0 "0" 0>
</Components>
<Wires>
  <310 250 310 280 "" 0 0 0 "">
  <250 250 250 310 "" 0 0 0 "">
  <250 310 280 310 "" 0 0 0 "">
  <100 340 100 370 "" 0 0 0 "">
  <100 250 200 250 "A" 170 220 41 "">
  <100 250 100 280 "" 0 0 0 "">
  <310 220 310 250 "" 0 0 0 "">
  <250 190 250 250 "" 0 0 0 "">
  <250 190 280 190 "" 0 0 0 "">
  <310 130 310 160 "" 0 0 0 "">
  <310 710 310 740 "" 0 0 0 "">
  <250 710 250 770 "" 0 0 0 "">
  <250 770 280 770 "" 0 0 0 "">
  <100 800 100 830 "" 0 0 0 "">
  <100 710 200 710 "B" 170 680 41 "">
  <100 710 100 740 "" 0 0 0 "">
  <310 680 310 710 "" 0 0 0 "">
  <250 650 250 710 "" 0 0 0 "">
  <250 650 280 650 "" 0 0 0 "">
  <310 590 310 620 "" 0 0 0 "">
  <840 440 840 500 "" 0 0 0 "">
  <840 560 840 580 "" 0 0 0 "">
  <840 580 900 580 "" 0 0 0 "">
  <840 360 840 380 "" 0 0 0 "">
  <840 360 900 360 "" 0 0 0 "">
  <960 360 960 380 "" 0 0 0 "">
  <960 440 960 500 "" 0 0 0 "">
  <960 560 960 580 "" 0 0 0 "">
  <960 760 1000 760 "" 0 0 0 "">
  <960 730 960 760 "" 0 0 0 "">
  <1040 730 1040 760 "" 0 0 0 "">
  <840 650 840 670 "" 0 0 0 "">
  <760 650 800 650 "" 0 0 0 "">
  <760 650 760 670 "" 0 0 0 "">
  <840 730 840 760 "" 0 0 0 "">
  <760 760 800 760 "" 0 0 0 "">
  <760 730 760 760 "" 0 0 0 "">
  <800 760 840 760 "" 0 0 0 "">
  <1000 760 1040 760 "" 0 0 0 "">
  <1040 640 1040 670 "" 0 0 0 "">
  <960 640 1000 640 "" 0 0 0 "">
  <960 640 960 670 "" 0 0 0 "">
  <800 650 840 650 "" 0 0 0 "">
  <800 620 800 650 "" 0 0 0 "">
  <800 620 900 620 "" 0 0 0 "">
  <1000 640 1040 640 "" 0 0 0 "">
  <1000 620 1000 640 "" 0 0 0 "">
  <900 580 960 580 "" 0 0 0 "">
  <900 620 1000 620 "" 0 0 0 "">
  <900 580 900 600 "" 0 0 0 "">
  <310 340 310 370 "" 0 0 0 "">
  <310 250 460 250 "" 0 0 0 "">
  <460 250 460 280 "" 0 0 0 "">
  <460 340 460 370 "" 0 0 0 "">
  <310 800 310 840 "" 0 0 0 "">
  <310 710 460 710 "" 0 0 0 "">
  <460 710 460 750 "" 0 0 0 "">
  <460 810 460 840 "" 0 0 0 "">
  <200 250 250 250 "" 0 0 0 "">
  <200 250 200 410 "" 0 0 0 "">
  <200 410 740 410 "" 0 0 0 "">
  <200 710 250 710 "" 0 0 0 "">
  <200 480 200 710 "" 0 0 0 "">
  <200 480 720 480 "" 0 0 0 "">
  <720 480 720 700 "" 0 0 0 "">
  <720 700 730 700 "" 0 0 0 "">
  <870 600 870 700 "" 0 0 0 "">
  <760 600 870 600 "" 0 0 0 "">
  <760 250 760 320 "" 0 0 0 "">
  <460 250 760 250 "" 0 0 0 "">
  <990 530 1020 530 "" 0 0 0 "">
  <1020 320 1020 530 "" 0 0 0 "">
  <760 320 760 600 "" 0 0 0 "">
  <760 320 1020 320 "" 0 0 0 "">
  <930 630 930 700 "" 0 0 0 "">
  <740 630 930 630 "" 0 0 0 "">
  <740 410 810 410 "" 0 0 0 "">
  <740 410 740 630 "" 0 0 0 "">
  <1070 700 1090 700 "" 0 0 0 "">
  <1090 700 1090 810 "" 0 0 0 "">
  <700 810 1090 810 "" 0 0 0 "">
  <700 710 700 810 "" 0 0 0 "">
  <460 710 700 710 "" 0 0 0 "">
  <700 530 700 710 "" 0 0 0 "">
  <700 530 810 530 "" 0 0 0 "">
  <720 340 720 480 "" 0 0 0 "">
  <720 340 1000 340 "" 0 0 0 "">
  <1000 340 1000 410 "" 0 0 0 "">
  <990 410 1000 410 "" 0 0 0 "">
  <900 360 960 360 "" 0 0 0 "">
  <900 290 900 360 "" 0 0 0 "">
  <900 600 900 620 "" 0 0 0 "">
  <1120 600 1120 630 "" 0 0 0 "">
  <1120 690 1120 720 "" 0 0 0 "">
  <900 600 1120 600 "Out" 1030 570 100 "">
  <460 250 460 250 "An" 490 220 0 "">
  <460 710 460 710 "Bn" 490 680 0 "">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
</Paintings>

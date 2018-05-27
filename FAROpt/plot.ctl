#set nokey
set border 0
set noxtics
set noytics
#set nortics
set rtics 10
set size square
set angles degrees
set rrange[-30:15]
set grid polar
set polar
plot  "2plot2.dat" usi 2:3 with lines title "2 MHz" lt 1 lw 1 lc 1, \
      "2plot5.dat" usi 2:3 with lines title "5 MHz" lt 1 lw 1 lc 1, \
      "2plot10.dat" usi 2:3 with lines title "10 MHz" lt 1 lw 1 lc 1, \
      "2plot15.dat" usi 2:3 with lines title "15 MHz" lt 1 lw 1 lc 1, \
      "2plot20.dat" usi 2:3 with lines title "20 MHz" lt 1 lw 1 lc 1, \
      "2plot25.dat" usi 2:3 with lines title "25 MHz" lt 1 lw 1 lc 1, \
      "2plot30.dat" usi 2:3 with lines title "30 MHz" lt 1 lw 1 lc 1
set term postscript
set out "Plot.ps"
replot

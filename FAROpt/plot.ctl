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
plot  "2plot.dat" usi 2:3 with lines lt 1 lw 2 
set term postscript
set out "Plot.ps"
replot


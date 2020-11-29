D:
cd D:\FlightGear 2020.3.2

SET FG_ROOT=D:\FlightGear 2020.3.2\data
.\\bin\fgfs --aircraft=ufo --fdm=null --native-fdm=socket,in,30,127.0.0.1,5502,udp --native-ctrls=socket,out,30,127.0.0.1,5505,udp --fog-fastest --disable-clouds --start-date-lat=2004:06:01:09:00:00 --disable-sound --in-air --enable-freeze --airport=LOWI --altitude=5000 --heading=0 --offset-distance=0 --offset-azimuth=0 --enable-terrasync

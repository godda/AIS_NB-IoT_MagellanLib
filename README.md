# AIS_NB-IoT_MagellanLib
modify of AIS NB-IoT MagellanLib to add signal function.
<br />
<br />
How to get signal in project.<br />
Example ::
<br />
<br />
  signal NBsig;<br />
  NBsig = magel.getSignal();<br />
  Serial.println(NBsig.csq);<br />
  Serial.println(NBsig.rssi);<br />
  Serial.println(NBsig.ber);<br />

# AIS_NB-IoT_MagellanLib
modify of AIS NB-IoT MagellanLib to add signal function.

Example ::
How to get signal in project.

  signal NBsig;
  NBsig = magel.getSignal();
  Serial.println(NBsig.csq);
  Serial.println(NBsig.rssi);
  Serial.println(NBsig.ber);

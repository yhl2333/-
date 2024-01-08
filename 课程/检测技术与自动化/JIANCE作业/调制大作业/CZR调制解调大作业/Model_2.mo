within ;
model Model_2
  Modelica.Electrical.Analog.Sources.PulseVoltage pulseVoltage(width = 25, period = 16)
    annotation (Placement(transformation(origin = {-367.6505780635822, 152.14817220708207}, 
      extent = {{-12.731994094973743, -12.7319940949737}, {12.731994094973743, 12.731994094973778}}, 
      rotation = 180.0)));
  Modelica.Electrical.Analog.Sources.ConstantVoltage V(V = 1)
    annotation (Placement(transformation(origin = {-507.3778284845759, -73.6620405604763}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Basic.Ground ground
    annotation (Placement(transformation(origin = {-507.2639855967612, -117.43178485301803}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));



  Modelica.Electrical.Analog.Ideal.ControlledIdealTwoWaySwitch s1
    annotation (Placement(transformation(origin = {-323.71225150098815, 190.09485407292067}, 
      extent = {{-14.821246298950882, -14.821246298950882}, {14.821246298950882, 14.821246298950882}}, 
      rotation = 180.0)));
  Modelica.Electrical.Analog.Ideal.ControlledIdealTwoWaySwitch s2
    annotation (Placement(transformation(origin = {-325.420992512726, 119.16679119767369}, 
      extent = {{-14.821246298950882, -14.821246298950882}, {14.821246298950882, 14.821246298950882}}, 
      rotation = 180.0)));
  Modelica.Electrical.Analog.Ideal.ControlledIdealTwoWaySwitch s3
    annotation (Placement(transformation(origin = {-325.420992512726, 56.8349640469515}, 
      extent = {{-14.821246298950882, -14.821246298950882}, {14.821246298950882, 14.821246298950882}}, 
      rotation = 180.0)));
  Modelica.Electrical.Analog.Ideal.ControlledIdealTwoWaySwitch s4
    annotation (Placement(transformation(origin = {-325.0766177770865, -11.695608345278963}, 
      extent = {{-14.821246298950882, -14.821246298950882}, {14.821246298950882, 14.821246298950882}}, 
      rotation = 180.0)));
  Modelica.Electrical.Analog.Basic.Resistor r1(R = 1000)
    annotation (Placement(transformation(origin = {-211.791111558792, 159.3391488707552}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Basic.Resistor r2(R = 1000)
    annotation (Placement(transformation(origin = {-127.75054339633192, 160.04103100849275}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Basic.Resistor r3(R = 1000)
    annotation (Placement(transformation(origin = {-52.33247629131452, 160.72978047977148}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Basic.Resistor r4(R = 1000)
    annotation (Placement(transformation(origin = {32.741216078063566, 159.36541420367297}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Basic.Resistor r5(R = 2000)
    annotation (Placement(transformation(origin = {-239.67168333852806, 88.17306499013225}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Basic.Resistor r6(R = 2000)
    annotation (Placement(transformation(origin = {-155.631115176068, 88.87494712786985}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Basic.Resistor r7(R = 2000)
    annotation (Placement(transformation(origin = {-80.2130480710506, 89.56369659914853}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Basic.Resistor r8(R = 2000)
    annotation (Placement(transformation(origin = {4.8606442983275215, 88.19933032305003}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Basic.Resistor r9(R = 750)
    annotation (Placement(transformation(origin = {-239.67168333852806, 24.119364161213326}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Basic.Resistor r10(R = 750)
    annotation (Placement(transformation(origin = {-155.631115176068, 24.82124629895091}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Basic.Resistor r11(R = 750)
    annotation (Placement(transformation(origin = {-80.21304807105062, 25.509995770229608}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Basic.Resistor r12(R = 750)
    annotation (Placement(transformation(origin = {4.8606442983275215, 24.1456294941311}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Basic.Resistor r13(R = 1500)
    annotation (Placement(transformation(origin = {-240.36043280980675, -52.33182715072218}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Basic.Resistor r14(R = 1500)
    annotation (Placement(transformation(origin = {-156.3198646473467, -51.629945012984564}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Basic.Resistor r15(R = 1500)
    annotation (Placement(transformation(origin = {-80.90179754232932, -50.941195541705866}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Basic.Resistor r16(R = 1500)
    annotation (Placement(transformation(origin = {4.171894827048824, -52.3055618178044}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Basic.Ground ground6
    annotation (Placement(transformation(origin = {-407.6258728872621, -114.3327097645137}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Analog.Sources.PulseVoltage pulseVoltage1(width = 25, period = 16, startTime = 4)
    annotation (Placement(transformation(origin = {-366.27419106172596, 84.88059974371424}, 
      extent = {{-12.731994094973743, -12.7319940949737}, {12.731994094973743, 12.731994094973778}}, 
      rotation = 180.0)));
  Modelica.Electrical.Analog.Sources.PulseVoltage pulseVoltage2(width = 25, period = 16, startTime = 8)
    annotation (Placement(transformation(origin = {-366.6191355816517, 18.306307398044595}, 
      extent = {{-12.731994094973743, -12.7319940949737}, {12.731994094973743, 12.731994094973778}}, 
      rotation = 180.0)));
  Modelica.Electrical.Analog.Sources.PulseVoltage pulseVoltage3(width = 25, period = 16, startTime = 12)
    annotation (Placement(transformation(origin = {-370.4135253008349, -62.06576574465501}, 
      extent = {{-12.731994094973743, -12.7319940949737}, {12.731994094973743, 12.731994094973778}}, 
      rotation = 180.0)));
  Modelica.Electrical.Analog.Ideal.IdealOpAmp3Pin opAmp
    annotation (Placement(transformation(origin = {-214.63567514151725, -105.05592675925851}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Ideal.IdealOpAmp3Pin opAmp1
    annotation (Placement(transformation(origin = {-130.20798327988075, -105.35037698495388}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Ideal.IdealOpAmp3Pin opAmp2
    annotation (Placement(transformation(origin = {-54.891471503055044, -105.52650019656079}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Ideal.IdealOpAmp3Pin opAmp3
    annotation (Placement(transformation(origin = {30.118426416332802, -105.32778758387056}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Basic.Ground ground1
    annotation (Placement(transformation(origin = {-248.63833717675385, -107.92967922124312}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Analog.Basic.Ground ground2
    annotation (Placement(transformation(origin = {-157.56276118840628, -109.44609626504248}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Analog.Basic.Ground ground3
    annotation (Placement(transformation(origin = {-84.31834878984236, -107.3731411971586}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Analog.Basic.Ground ground4
    annotation (Placement(transformation(origin = {5.970360833544639, -105.53051447015069}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Analog.Basic.Resistor r17(R = 100)
    annotation (Placement(transformation(origin = {-189.53642596502388, -119.24175391296565}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Basic.Resistor r18(R = 1500)
    annotation (Placement(transformation(origin = {-105.14287408613957, -118.68461790511715}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Basic.Resistor r19(R = 1500)
    annotation (Placement(transformation(origin = {-27.33065703787743, -117.68335775927557}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Basic.Resistor r20(R = 1500)
    annotation (Placement(transformation(origin = {58.6346783408094, -116.5390604497423}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Sensors.CurrentSensor currentSensor
    annotation (Placement(transformation(origin = {-203.05273194868877, -143.4372205257828}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 180.0)));
  Modelica.Electrical.Analog.Sensors.CurrentSensor currentSensor1
    annotation (Placement(transformation(origin = {-119.10251832010135, -144.45108213004053}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 180.0)));
  Modelica.Electrical.Analog.Sensors.CurrentSensor currentSensor2
    annotation (Placement(transformation(origin = {-40.575115453380974, -145.5953794395738}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 180.0)));
  Modelica.Electrical.Analog.Sensors.CurrentSensor currentSensor3
    annotation (Placement(transformation(origin = {42.97426608512501, -143.5996928486456}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 180.0)));
  Modelica.Blocks.Interaction.Show.RealValue realValue
    annotation (Placement(transformation(origin = {-168.5723911149741, -131.6558990353192}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Blocks.Interaction.Show.RealValue realValue1
    annotation (Placement(transformation(origin = {-87.41574594506969, -132.65783292630562}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Blocks.Interaction.Show.RealValue realValue2
    annotation (Placement(transformation(origin = {6.031033832803807, -133.96537255315303}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Blocks.Interaction.Show.RealValue realValue3
    annotation (Placement(transformation(origin = {86.35303692826692, -129.56216064694894}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
equation 
  connect(V.n, ground.p)
    annotation (Line(origin = {-509.0, -57.0}, 
      points = {{2.0, -27.0}, {2.0, -50.0}}, 
      color = {0, 0, 255}));
  connect(V.p, s1.n2)
    annotation (Line(origin = {-423.0, 63.0}, 
      points = {{-84.0, -127.0}, {-84.0, 127.0}, {84.0, 127.0}}, 
      color = {0, 0, 255}));
  connect(s2.n2, s1.n2)
    annotation (Line(origin = {-423.0, 155.0}, 
      points = {{83.0, -36.0}, {-84.0, -36.0}, {-84.0, 35.0}, {84.0, 35.0}}, 
      color = {0, 0, 255}));
  connect(s3.n2, s1.n2)
    annotation (Line(origin = {-423.0, 124.0}, 
      points = {{83.0, -67.0}, {-84.0, -67.0}, {-84.0, 66.0}, {84.0, 66.0}}, 
      color = {0, 0, 255}));
  connect(s4.n2, s1.n2)
    annotation (Line(origin = {-423.0, 89.0}, 
      points = {{83.0, -101.0}, {-82.0, -101.0}, {-82.0, -100.0}, {-84.0, -100.0}, {-84.0, 101.0}, {84.0, 101.0}}, 
      color = {0, 0, 255}));
  connect(r8.p, s2.p)
    annotation (Line(origin = {-153.0, 109.0}, 
      points = {{158.0, -11.0}, {158.0, 10.0}, {-158.0, 10.0}}, 
      color = {0, 0, 255}));
  connect(r12.p, s3.p)
    annotation (Line(origin = {-153.0, 46.0}, 
      points = {{158.0, -12.0}, {158.0, 11.0}, {-158.0, 11.0}}, 
      color = {0, 0, 255}));
  connect(r16.p, s4.p)
    annotation (Line(origin = {-153.0, -27.0}, 
      points = {{157.0, -15.0}, {157.0, 15.0}, {-157.0, 15.0}}, 
      color = {0, 0, 255}));
  connect(r5.p, s2.p)
    annotation (Line(origin = {-275.0, 109.0}, 
      points = {{35.0, -11.0}, {35.0, 10.0}, {-36.0, 10.0}}, 
      color = {0, 0, 255}));
  connect(r6.p, s2.p)
    annotation (Line(origin = {-233.0, 109.0}, 
      points = {{77.0, -10.0}, {77.0, 10.0}, {-78.0, 10.0}}, 
      color = {0, 0, 255}));
  connect(r7.p, s2.p)
    annotation (Line(origin = {-195.0, 110.0}, 
      points = {{115.0, -10.0}, {115.0, 9.0}, {-116.0, 9.0}}, 
      color = {0, 0, 255}));
  connect(r9.p, s3.p)
    annotation (Line(origin = {-275.0, 46.0}, 
      points = {{35.0, -12.0}, {35.0, 11.0}, {-36.0, 11.0}}, 
      color = {0, 0, 255}));
  connect(r10.p, s3.p)
    annotation (Line(origin = {-233.0, 46.0}, 
      points = {{77.0, -11.0}, {77.0, 11.0}, {-78.0, 11.0}}, 
      color = {0, 0, 255}));
  connect(r11.p, s3.p)
    annotation (Line(origin = {-195.0, 47.0}, 
      points = {{115.0, -11.0}, {115.0, 10.0}, {-116.0, 10.0}}, 
      color = {0, 0, 255}));
  connect(r13.p, s4.p)
    annotation (Line(origin = {-275.0, -27.0}, 
      points = {{35.0, -15.0}, {35.0, 15.0}, {-35.0, 15.0}}, 
      color = {0, 0, 255}));
  connect(r14.p, s4.p)
    annotation (Line(origin = {-233.0, -27.0}, 
      points = {{77.0, -15.0}, {77.0, 15.0}, {-77.0, 15.0}}, 
      color = {0, 0, 255}));
  connect(r15.p, s4.p)
    annotation (Line(origin = {-195.0, -26.0}, 
      points = {{114.0, -15.0}, {114.0, 14.0}, {-115.0, 14.0}}, 
      color = {0, 0, 255}));
  connect(r4.p, s1.p)
    annotation (Line(origin = {-138.0, 180.0}, 
      points = {{171.0, -11.0}, {171.0, 10.0}, {-171.0, 10.0}}, 
      color = {0, 0, 255}));
  connect(r3.p, s1.p)
    annotation (Line(origin = {-180.0, 181.0}, 
      points = {{128.0, -10.0}, {128.0, 9.0}, {-129.0, 9.0}}, 
      color = {0, 0, 255}));
  connect(r2.p, s1.p)
    annotation (Line(origin = {-218.0, 180.0}, 
      points = {{90.0, -10.0}, {90.0, 9.0}, {89.0, 9.0}, {89.0, 10.0}, {-91.0, 10.0}}, 
      color = {0, 0, 255}));
  connect(r1.p, s1.p)
    annotation (Line(origin = {-260.0, 180.0}, 
      points = {{48.0, -11.0}, {48.0, 10.0}, {-49.0, 10.0}}, 
      color = {0, 0, 255}));
  connect(pulseVoltage.n, ground6.p)
    annotation (Line(origin = {-394.0, 24.0}, 
      points = {{14.0, 128.0}, {-14.0, 128.0}, {-14.0, -128.0}}, 
      color = {0, 0, 255}));
  connect(pulseVoltage1.n, ground6.p)
    annotation (Line(origin = {-394.0, -9.0}, 
      points = {{15.0, 94.0}, {-15.0, 94.0}, {-15.0, 92.0}, {-14.0, 92.0}, {-14.0, -95.0}}, 
      color = {0, 0, 255}));
  connect(pulseVoltage2.n, ground6.p)
    annotation (Line(origin = {-394.0, -42.0}, 
      points = {{15.0, 60.0}, {-15.0, 60.0}, {-15.0, 61.0}, {-14.0, 61.0}, {-14.0, -62.0}}, 
      color = {0, 0, 255}));
  connect(pulseVoltage3.n, ground6.p)
    annotation (Line(origin = {-395.0, -83.0}, 
      points = {{12.0, 21.0}, {-13.0, 21.0}, {-13.0, -21.0}}, 
      color = {0, 0, 255}));
  connect(pulseVoltage3.p, s4.control)
    annotation (Line(origin = {-341.0, -44.0}, 
      points = {{-17.0, -18.0}, {16.0, -18.0}, {16.0, 17.0}}, 
      color = {0, 0, 255}));
  connect(pulseVoltage2.p, s3.control)
    annotation (Line(origin = {-339.0, 30.0}, 
      points = {{-15.0, -12.0}, {14.0, -12.0}, {14.0, 12.0}}, 
      color = {0, 0, 255}));
  connect(pulseVoltage1.p, s2.control)
    annotation (Line(origin = {-339.0, 95.0}, 
      points = {{-15.0, -10.0}, {14.0, -10.0}, {14.0, 9.0}}, 
      color = {0, 0, 255}));
  connect(pulseVoltage.p, s1.control)
    annotation (Line(origin = {-339.0, 164.0}, 
      points = {{-16.0, -12.0}, {15.0, -12.0}, {15.0, 11.0}}, 
      color = {0, 0, 255}));
  connect(ground1.p, opAmp.in_p)
    annotation (Line(origin = {-234.32874633067735, -87.68109057814125}, 
      points = {{-14.0, -10.0}, {-14.0, 10.0}, {14.0, 10.0}, {14.0, -7.0}}, 
      color = {0, 0, 255}));
  connect(ground2.p, opAmp1.in_p)
    annotation (Line(origin = {-146.32874633067735, -84.68109057814125}, 
      points = {{-11.0, -15.0}, {-11.0, 15.0}, {10.0, 15.0}, {10.0, -11.0}}, 
      color = {0, 0, 255}));
  connect(ground3.p, opAmp2.in_p)
    annotation (Line(origin = {-72.32874633067733, -83.68109057814125}, 
      points = {{-12.0, -14.0}, {-12.0, 13.0}, {11.0, 13.0}, {11.0, -12.0}}, 
      color = {0, 0, 255}));
  connect(ground4.p, opAmp3.in_p)
    annotation (Line(origin = {14.671253669322667, -82.68109057814125}, 
      points = {{-9.0, -13.0}, {-9.0, 12.0}, {9.0, 12.0}, {9.0, -13.0}}, 
      color = {0, 0, 255}));
  connect(r17.p, opAmp.in_n)
    annotation (Line(origin = {-198.32874633067735, -101.68109057814125}, 
      points = {{9.0, -8.0}, {9.0, 7.0}, {-10.0, 7.0}}, 
      color = {0, 0, 255}));
  connect(r18.p, opAmp1.in_n)
    annotation (Line(origin = {-114.32874633067735, -101.68109057814125}, 
      points = {{9.0, -7.0}, {9.0, 6.0}, {-10.0, 6.0}}, 
      color = {0, 0, 255}));
  connect(r19.p, opAmp2.in_n)
    annotation (Line(origin = {-38.32874633067733, -101.68109057814125}, 
      points = {{11.0, -6.0}, {11.0, 6.0}, {-11.0, 6.0}}, 
      color = {0, 0, 255}));
  connect(r20.p, opAmp3.in_n)
    annotation (Line(origin = {47.671253669322596, -100.68109057814125}, 
      points = {{11.0, -6.0}, {11.0, 5.0}, {-12.0, 5.0}}, 
      color = {0, 0, 255}));
  connect(r17.n, currentSensor.p)
    annotation (Line(origin = {-192.32874633067735, -136.68109057814127}, 
      points = {{3.0, 7.0}, {3.0, -7.0}, {-1.0, -7.0}}, 
      color = {0, 0, 255}));
  connect(currentSensor.n, opAmp.out)
    annotation (Line(origin = {-215.32874633067735, -128.68109057814127}, 
      points = {{2.0, -15.0}, {2.0, 14.0}, {1.0, 14.0}}, 
      color = {0, 0, 255}));
  connect(r18.n, currentSensor1.p)
    annotation (Line(origin = {-107.32874633067735, -136.68109057814127}, 
      points = {{2.0, 8.0}, {2.0, -8.0}, {-2.0, -8.0}}, 
      color = {0, 0, 255}));
  connect(currentSensor1.n, opAmp1.out)
    annotation (Line(origin = {-129.32874633067735, -129.68109057814127}, 
      points = {{0.0, -15.0}, {0.0, 14.0}, {-1.0, 14.0}}, 
      color = {0, 0, 255}));
  connect(r19.n, currentSensor2.p)
    annotation (Line(origin = {-28.328746330677333, -136.68109057814127}, 
      points = {{1.0, 9.0}, {1.0, -9.0}, {-2.0, -9.0}}, 
      color = {0, 0, 255}));
  connect(currentSensor2.n, opAmp2.out)
    annotation (Line(origin = {-52.32874633067733, -130.68109057814127}, 
      points = {{2.0, -15.0}, {-3.0, -15.0}, {-3.0, 15.0}}, 
      color = {0, 0, 255}));
  connect(opAmp3.out, currentSensor3.n)
    annotation (Line(origin = {31.671253669322667, -129.68109057814127}, 
      points = {{-2.0, 14.0}, {-2.0, -14.0}, {1.0, -14.0}}, 
      color = {0, 0, 255}));
  connect(r20.n, currentSensor3.p)
    annotation (Line(origin = {55.671253669322596, -134.68109057814127}, 
      points = {{3.0, 8.0}, {3.0, -8.0}, {-3.0, -8.0}, {-3.0, -9.0}}, 
      color = {0, 0, 255}));
  connect(currentSensor.i, realValue.numberPort)
    annotation (Line(origin = {-191.32874633067735, -131.68109057814127}, 
      points = {{-12.0, -1.0}, {11.0, -1.0}, {11.0, 0.0}}, 
      color = {0, 0, 127}));
  connect(currentSensor1.i, realValue1.numberPort)
    annotation (Line(origin = {-109.32874633067735, -132.68109057814127}, 
      points = {{-10.0, -1.0}, {10.0, -1.0}, {10.0, 0.0}}, 
      color = {0, 0, 127}));
  connect(currentSensor2.i, realValue2.numberPort)
    annotation (Line(origin = {-22.328746330677333, -133.68109057814127}, 
      points = {{-18.0, -1.0}, {17.0, -1.0}, {17.0, 0.0}}, 
      color = {0, 0, 127}));
  connect(currentSensor3.i, realValue3.numberPort)
    annotation (Line(origin = {58.671253669322596, -130.68109057814127}, 
      points = {{-16.0, -2.0}, {-16.0, 2.0}, {16.0, 2.0}, {16.0, 1.0}}, 
      color = {0, 0, 127}));
  connect(r1.n, opAmp.in_n)
    annotation (Line(origin = {-210.0, 27.0}, 
      points = {{-2.0, 122.0}, {-2.0, -122.0}, {1.0, -122.0}}, 
      color = {0, 0, 255}));
  connect(r2.n, opAmp1.in_n)
    annotation (Line(origin = {-126.0, 28.0}, 
      points = {{-2.0, 122.0}, {-2.0, -123.0}, {2.0, -123.0}}, 
      color = {0, 0, 255}));
  connect(r3.n, opAmp2.in_n)
    annotation (Line(origin = {-50.0, 28.0}, 
      points = {{-2.0, 123.0}, {-2.0, -124.0}, {1.0, -124.0}}, 
      color = {0, 0, 255}));
  connect(r4.n, opAmp3.in_n)
    annotation (Line(origin = {35.0, 27.0}, 
      points = {{-2.0, 122.0}, {-2.0, -122.0}, {1.0, -122.0}}, 
      color = {0, 0, 255}));
  connect(r5.n, opAmp.in_n)
    annotation (Line(origin = {-224.0, -8.0}, 
      points = {{-16.0, 86.0}, {-16.0, 79.0}, {12.0, 79.0}, {12.0, -87.0}, {15.0, -87.0}}, 
      color = {0, 0, 255}));
  connect(r9.n, opAmp.in_n)
    annotation (Line(origin = {-224.0, -40.0}, 
      points = {{-16.0, 54.0}, {-16.0, 47.0}, {12.0, 47.0}, {12.0, -55.0}, {15.0, -55.0}}, 
      color = {0, 0, 255}));
  connect(r13.n, opAmp.in_n)
    annotation (Line(origin = {-224.0, -78.0}, 
      points = {{-16.0, 16.0}, {-16.0, 13.0}, {12.0, 13.0}, {12.0, -17.0}, {15.0, -17.0}}, 
      color = {0, 0, 255}));
  connect(r6.n, opAmp1.in_n)
    annotation (Line(origin = {-140.0, -8.0}, 
      points = {{-16.0, 87.0}, {-16.0, 82.0}, {12.0, 82.0}, {12.0, -87.0}, {16.0, -87.0}}, 
      color = {0, 0, 255}));
  connect(r10.n, opAmp1.in_n)
    annotation (Line(origin = {-140.0, -40.0}, 
      points = {{-16.0, 55.0}, {-16.0, 50.0}, {12.0, 50.0}, {12.0, -55.0}, {16.0, -55.0}}, 
      color = {0, 0, 255}));
  connect(r14.n, opAmp1.in_n)
    annotation (Line(origin = {-140.0, -78.0}, 
      points = {{-16.0, 16.0}, {-16.0, 14.0}, {12.0, 14.0}, {12.0, -17.0}, {16.0, -17.0}}, 
      color = {0, 0, 255}));
  connect(r7.n, opAmp2.in_n)
    annotation (Line(origin = {-64.0, -8.0}, 
      points = {{-16.0, 88.0}, {-16.0, 84.0}, {12.0, 84.0}, {12.0, -88.0}, {15.0, -88.0}}, 
      color = {0, 0, 255}));
  connect(r11.n, opAmp2.in_n)
    annotation (Line(origin = {-64.0, -40.0}, 
      points = {{-16.0, 56.0}, {-16.0, 50.0}, {12.0, 50.0}, {12.0, -56.0}, {15.0, -56.0}}, 
      color = {0, 0, 255}));
  connect(r15.n, opAmp2.in_n)
    annotation (Line(origin = {-65.0, -78.0}, 
      points = {{-16.0, 17.0}, {-16.0, 14.0}, {13.0, 14.0}, {13.0, -18.0}, {16.0, -18.0}}, 
      color = {0, 0, 255}));
  connect(r8.n, opAmp3.in_n)
    annotation (Line(origin = {21.0, -8.0}, 
      points = {{-16.0, 86.0}, {-16.0, 83.0}, {12.0, 83.0}, {12.0, -87.0}, {15.0, -87.0}}, 
      color = {0, 0, 255}));
  connect(r12.n, opAmp3.in_n)
    annotation (Line(origin = {21.0, -40.0}, 
      points = {{-16.0, 54.0}, {-16.0, 52.0}, {12.0, 52.0}, {12.0, -55.0}, {15.0, -55.0}}, 
      color = {0, 0, 255}));
  connect(r16.n, opAmp3.in_n)
    annotation (Line(origin = {20.0, -78.0}, 
      points = {{-16.0, 16.0}, {-16.0, 13.0}, {13.0, 13.0}, {13.0, -17.0}, {16.0, -17.0}}, 
      color = {0, 0, 255}));
end Model_2;
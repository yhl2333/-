within ;
model Model3
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
  Modelica.Electrical.Analog.Ideal.ControlledIdealClosingSwitch s5
    annotation (Placement(transformation(origin = {-211.6705008635281, -100.03391077846737}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 90.0)));
  Modelica.Electrical.Analog.Ideal.ControlledIdealClosingSwitch s6
    annotation (Placement(transformation(origin = {-127.66422204309457, -100.69583230344512}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 90.0)));
  Modelica.Electrical.Analog.Ideal.ControlledIdealClosingSwitch s7
    annotation (Placement(transformation(origin = {-51.46284173222444, -100.38224637623985}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 90.0)));
  Modelica.Electrical.Analog.Ideal.ControlledIdealClosingSwitch s8
    annotation (Placement(transformation(origin = {33.205358613186846, -99.44148859462419}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 90.0)));
  Modelica.Electrical.Analog.Basic.Ground ground2
    annotation (Placement(transformation(origin = {-212.38388353144126, -194.35644730944082}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Analog.Basic.Ground ground3
    annotation (Placement(transformation(origin = {-127.11767130786781, -197.83352253002877}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Analog.Basic.Ground ground4
    annotation (Placement(transformation(origin = {-51.47251648242343, -195.51045688422678}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Analog.Basic.Ground ground5
    annotation (Placement(transformation(origin = {33.38251778440518, -196.4221102463963}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
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
  Modelica.Electrical.Analog.Sources.PulseVoltage pulseVoltage4(period = 4, width = 25)
    annotation (Placement(transformation(origin = {-277.9553130880018, -133.50548472589577}, 
      extent = {{-12.731994094973743, -12.7319940949737}, {12.731994094973743, 12.731994094973778}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Sources.PulseVoltage pulseVoltage5(period = 4, width = 25, startTime = 1)
    annotation (Placement(transformation(origin = {-160.65132046582724, -135.92652567251406}, 
      extent = {{-12.731994094973743, -12.7319940949737}, {12.731994094973743, 12.731994094973778}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Sources.PulseVoltage pulseVoltage6(period = 4, width = 25, startTime = 2)
    annotation (Placement(transformation(origin = {-81.98472780391148, -137.30664133324944}, 
      extent = {{-12.731994094973743, -12.7319940949737}, {12.731994094973743, 12.731994094973778}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Sources.PulseVoltage pulseVoltage7(period = 4, width = 25, startTime = 3)
    annotation (Placement(transformation(origin = {-5.733337548282577, -134.8914389269625}, 
      extent = {{-12.731994094973743, -12.7319940949737}, {12.731994094973743, 12.731994094973778}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Basic.Ground ground7
    annotation (Placement(transformation(origin = {-277.40324780780827, -174.2396021678398}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Analog.Basic.Ground ground8
    annotation (Placement(transformation(origin = {-160.75210821065326, -173.45544554242196}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Analog.Basic.Ground ground9
    annotation (Placement(transformation(origin = {-82.3736504742193, -175.0609635986057}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Analog.Basic.Ground ground10
    annotation (Placement(transformation(origin = {-5.055807208022173, -173.8063129979372}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Analog.Sensors.CurrentSensor currentSensor
    annotation (Placement(transformation(origin = {-210.72683184700023, -142.00470290778202}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Blocks.Interaction.Show.RealValue realValue
    annotation (Placement(transformation(origin = {-222.50765696550522, -213.768426695778}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Analog.Sensors.CurrentSensor currentSensor1
    annotation (Placement(transformation(origin = {-128.28740685003982, -145.4262207371681}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Blocks.Interaction.Show.RealValue realValue1
    annotation (Placement(transformation(origin = {-123.15344237534589, -220.86707269759856}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Blocks.Interaction.Show.RealValue realValue2
    annotation (Placement(transformation(origin = {-45.9337507542206, -219.58007783724648}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}})));
  Modelica.Electrical.Analog.Sensors.CurrentSensor currentSensor2
    annotation (Placement(transformation(origin = {-50.44439206862255, -149.3993077924194}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Electrical.Analog.Sensors.CurrentSensor currentSensor3
    annotation (Placement(transformation(origin = {32.65870462839803, -144.25132835101098}, 
      extent = {{-10.0, -10.0}, {10.0, 10.0}}, 
      rotation = 270.0)));
  Modelica.Blocks.Interaction.Show.RealValue realValue3
    annotation (Placement(transformation(origin = {37.24109987722673, -214.72805727865486}, 
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
  connect(r1.n, s5.n)
    annotation (Line(origin = {-212.0, 30.0}, 
      points = {{0.0, 119.0}, {0.0, -120.0}}, 
      color = {0, 0, 255}));
  connect(r2.n, s6.n)
    annotation (Line(origin = {-129.0, 31.0}, 
      points = {{1.0, 119.0}, {1.0, -122.0}}, 
      color = {0, 0, 255}));
  connect(r3.n, s7.n)
    annotation (Line(origin = {-49.0, 30.0}, 
      points = {{-3.0, 121.0}, {-3.0, -120.0}, {-2.0, -120.0}}, 
      color = {0, 0, 255}));
  connect(r4.n, s8.n)
    annotation (Line(origin = {31.0, 30.0}, 
      points = {{2.0, 119.0}, {2.0, -119.0}}, 
      color = {0, 0, 255}));
  connect(r5.n, s5.n)
    annotation (Line(origin = {-226.0, -6.0}, 
      points = {{-14.0, 84.0}, {-14.0, 82.0}, {14.0, 82.0}, {14.0, -84.0}}, 
      color = {0, 0, 255}));
  connect(r6.n, s6.n)
    annotation (Line(origin = {-142.0, -6.0}, 
      points = {{-14.0, 85.0}, {-14.0, 82.0}, {14.0, 82.0}, {14.0, -85.0}}, 
      color = {0, 0, 255}));
  connect(r7.n, s7.n)
    annotation (Line(origin = {-65.0, -5.0}, 
      points = {{-15.0, 85.0}, {-15.0, 81.0}, {12.0, 81.0}, {12.0, 82.0}, {13.0, 82.0}, {13.0, -85.0}, {14.0, -85.0}}, 
      color = {0, 0, 255}));
  connect(r8.n, s8.n)
    annotation (Line(origin = {20.0, -5.0}, 
      points = {{-15.0, 83.0}, {-15.0, 82.0}, {14.0, 82.0}, {14.0, 84.0}, {13.0, 84.0}, {13.0, -84.0}}, 
      color = {0, 0, 255}));
  connect(r9.n, s5.n)
    annotation (Line(origin = {-226.0, -38.0}, 
      points = {{-14.0, 52.0}, {-14.0, 50.0}, {14.0, 50.0}, {14.0, -52.0}}, 
      color = {0, 0, 255}));
  connect(r10.n, s6.n)
    annotation (Line(origin = {-142.0, -38.0}, 
      points = {{-14.0, 53.0}, {-14.0, 51.0}, {14.0, 51.0}, {14.0, -53.0}}, 
      color = {0, 0, 255}));
  connect(r11.n, s7.n)
    annotation (Line(origin = {-65.0, -37.0}, 
      points = {{-15.0, 53.0}, {-15.0, 50.0}, {13.0, 50.0}, {13.0, -53.0}, {14.0, -53.0}}, 
      color = {0, 0, 255}));
  connect(r12.n, s8.n)
    annotation (Line(origin = {19.0, -37.0}, 
      points = {{-14.0, 51.0}, {14.0, 51.0}, {14.0, -52.0}}, 
      color = {0, 0, 255}));
  connect(r13.n, s5.n)
    annotation (Line(origin = {-226.0, -76.0}, 
      points = {{-14.0, 14.0}, {-14.0, 12.0}, {14.0, 12.0}, {14.0, -14.0}}, 
      color = {0, 0, 255}));
  connect(r14.n, s6.n)
    annotation (Line(origin = {-142.0, -76.0}, 
      points = {{-14.0, 14.0}, {-14.0, 11.0}, {14.0, 11.0}, {14.0, -15.0}}, 
      color = {0, 0, 255}));
  connect(r15.n, s7.n)
    annotation (Line(origin = {-66.0, -75.0}, 
      points = {{-15.0, 14.0}, {-15.0, 12.0}, {14.0, 12.0}, {14.0, -15.0}, {15.0, -15.0}}, 
      color = {0, 0, 255}));
  connect(r16.n, s8.n)
    annotation (Line(origin = {19.0, -75.0}, 
      points = {{-15.0, 13.0}, {-15.0, 12.0}, {14.0, 12.0}, {14.0, -14.0}}, 
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
  connect(pulseVoltage4.n, ground7.p)
    annotation (Line(origin = {-277.0, -155.0}, 
      points = {{-1.0, 9.0}, {-1.0, -9.0}, {0.0, -9.0}}, 
      color = {0, 0, 255}));
  connect(pulseVoltage5.n, ground8.p)
    annotation (Line(origin = {-161.0, -156.0}, 
      points = {{0.0, 7.0}, {0.0, -7.0}}, 
      color = {0, 0, 255}));
  connect(pulseVoltage6.n, ground9.p)
    annotation (Line(origin = {-82.0, -157.0}, 
      points = {{0.0, 7.0}, {0.0, -8.0}}, 
      color = {0, 0, 255}));
  connect(pulseVoltage7.n, ground10.p)
    annotation (Line(origin = {-5.0, -156.0}, 
      points = {{-1.0, 8.0}, {-1.0, -8.0}, {0.0, -8.0}}, 
      color = {0, 0, 255}));
  connect(pulseVoltage4.p, s5.control)
    annotation (Line(origin = {-250.0, -110.0}, 
      points = {{-28.0, -11.0}, {-28.0, 10.0}, {28.0, 10.0}}, 
      color = {0, 0, 255}));
  connect(pulseVoltage5.p, s6.control)
    annotation (Line(origin = {-149.0, -112.0}, 
      points = {{-12.0, -11.0}, {-12.0, 11.0}, {11.0, 11.0}}, 
      color = {0, 0, 255}));
  connect(pulseVoltage6.p, s7.control)
    annotation (Line(origin = {-71.0, -112.0}, 
      points = {{-11.0, -13.0}, {-11.0, 12.0}, {10.0, 12.0}}, 
      color = {0, 0, 255}));
  connect(pulseVoltage7.p, s8.control)
    annotation (Line(origin = {9.0, -110.0}, 
      points = {{-15.0, -12.0}, {-15.0, 11.0}, {14.0, 11.0}}, 
      color = {0, 0, 255}));
  connect(s5.p, currentSensor.p)
    annotation (Line(origin = {-211.0, -121.0}, 
      points = {{-1.0, 11.0}, {-1.0, -11.0}, {0.0, -11.0}}, 
      color = {0, 0, 255}));
  connect(currentSensor.n, ground2.p)
    annotation (Line(origin = {-211.0, -168.0}, 
      points = {{0.0, 16.0}, {0.0, -16.0}, {-1.0, -16.0}}, 
      color = {0, 0, 255}));
  connect(currentSensor.i, realValue.numberPort)
    annotation (Line(origin = {-228.0, -178.0}, 
      points = {{6.0, 36.0}, {-17.0, 36.0}, {-17.0, -36.0}, {-6.0, -36.0}}, 
      color = {0, 0, 127}));
  connect(s6.p, currentSensor1.p)
    annotation (Line(origin = {-128.0, -123.0}, 
      points = {{0.0, 12.0}, {0.0, -12.0}}, 
      color = {0, 0, 255}));
  connect(currentSensor1.n, ground3.p)
    annotation (Line(origin = {-127.0, -171.0}, 
      points = {{-1.0, 16.0}, {-1.0, -17.0}, {0.0, -17.0}}, 
      color = {0, 0, 255}));
  connect(currentSensor1.i, realValue1.numberPort)
    annotation (Line(origin = {-138.0, -183.0}, 
      points = {{-1.0, 38.0}, {-4.0, 38.0}, {-4.0, -38.0}, {3.0, -38.0}}, 
      color = {0, 0, 127}));
  connect(s7.p, currentSensor2.p)
    annotation (Line(origin = {-52.0, -124.0}, 
      points = {{1.0, 14.0}, {1.0, -15.0}, {2.0, -15.0}}, 
      color = {0, 0, 255}));
  connect(currentSensor2.n, ground4.p)
    annotation (Line(origin = {-50.0, -172.0}, 
      points = {{0.0, 13.0}, {0.0, -14.0}, {-1.0, -14.0}}, 
      color = {0, 0, 255}));
  connect(currentSensor2.i, realValue2.numberPort)
    annotation (Line(origin = {-63.0, -184.0}, 
      points = {{2.0, 35.0}, {-7.0, 35.0}, {-7.0, -36.0}, {6.0, -36.0}}, 
      color = {0, 0, 127}));
  connect(s8.p, currentSensor3.p)
    annotation (Line(origin = {33.0, -121.0}, 
      points = {{0.0, 12.0}, {0.0, -13.0}}, 
      color = {0, 0, 255}));
  connect(currentSensor3.n, ground5.p)
    annotation (Line(origin = {33.0, -170.0}, 
      points = {{0.0, 16.0}, {0.0, -16.0}}, 
      color = {0, 0, 255}));
  connect(currentSensor3.i, realValue3.numberPort)
    annotation (Line(origin = {20.0, -179.0}, 
      points = {{2.0, 35.0}, {-7.0, 35.0}, {-7.0, -36.0}, {6.0, -36.0}}, 
      color = {0, 0, 127}));
end Model3;
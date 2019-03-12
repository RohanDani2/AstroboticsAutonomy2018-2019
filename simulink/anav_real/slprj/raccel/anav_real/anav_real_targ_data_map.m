  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% rtP.limit
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.mapDim
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 558;
	
	  ;% rtP.mode
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 560;
	
	  ;% rtP.sObs
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 561;
	
	  ;% rtP.verticies
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 801;
	
	  ;% rtP.visualObj
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5093;
	
	  ;% rtP.hokuyoPort_Value
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6257;
	
	  ;% rtP.pozyxPort_Value
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 6258;
	
	  ;% rtP.vehicleRad_Value
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 6259;
	
	  ;% rtP.Gain_Gain
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 6260;
	
	  ;% rtP.velConst_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 6261;
	
	  ;% rtP.turnConst_Value
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 6262;
	
	  ;% rtP.isTeleOp_Value
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 6263;
	
	  ;% rtP.doVis_Value
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 6264;
	
	  ;% rtP.DataStoreMemory_InitialValue
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 6265;
	
	  ;% rtP.DataStoreMemory1_InitialValue
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 6267;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% rtB.a4yf2mjntq
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.bihr3dlknt
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 40;
	
	  ;% rtB.caboiln2oj
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 41;
	
	  ;% rtB.nt4wgp4qph
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 42;
	
	  ;% rtB.pfhqhr1gju
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 43;
	
	  ;% rtB.gmumll0z2v
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 44;
	
	  ;% rtB.hcyznxmk0r
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 45;
	
	  ;% rtB.nmf2aoyssm
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 6210;
	
	  ;% rtB.h1obb2nc31
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 6211;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% rtDW.irqtpqf4mz
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.pgjmsvvkae
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 2;
	
	  ;% rtDW.mn4hlzccjn
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% rtDW.gkteqaogoh
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 2055;
	
	  ;% rtDW.jrjyklivwq
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 2057;
	
	  ;% rtDW.mnkxa541wi
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 2059;
	
	  ;% rtDW.pfra4oyvtl
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 2061;
	
	  ;% rtDW.dhr4mxnvua
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 2063;
	
	  ;% rtDW.likqxler4y
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 2064;
	
	  ;% rtDW.nxxhtxi2pq
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 2065;
	
	  ;% rtDW.gplbfb5auy
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 2066;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.kakhnbjo3s
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% rtDW.ouzu4kamsj
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.gesvnspaab
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.j1l4gcbtpq
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.khdufyvkjm
	  section.data(4).logicalSrcIdx = 15;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.fgjqzsh1cz
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 271903700;
  targMap.checksum1 = 3622760240;
  targMap.checksum2 = 3832336147;
  targMap.checksum3 = 1235955264;

